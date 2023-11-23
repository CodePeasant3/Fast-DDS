// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * PublisherImpl.cpp
 *
 */

#include <fastdds/publisher/PublisherImpl.hpp>

#include <functional>

#include <fastdds/dds/domain/DomainParticipantListener.hpp>
#include <fastdds/dds/log/Log.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/PublisherListener.hpp>
#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/rtps/participant/RTPSParticipant.h>
#include <fastrtps/attributes/PublisherAttributes.h>

#include <fastdds/domain/DomainParticipantImpl.hpp>
#include <fastdds/publisher/DataWriterImpl.hpp>
#include <fastdds/topic/TopicDescriptionImpl.hpp>
#include <fastdds/utils/QosConverters.hpp>
#ifdef FASTDDS_STATISTICS
#include <statistics/types/monitorservice_types.h>
#endif //FASTDDS_STATISTICS
#include <xmlparser/XMLProfileManager.h>

namespace eprosima {
namespace fastdds {
namespace dds {

using fastrtps::xmlparser::XMLProfileManager;
using fastrtps::xmlparser::XMLP_ret;
using fastrtps::rtps::InstanceHandle_t;
using fastrtps::Duration_t;
using fastrtps::PublisherAttributes;

PublisherImpl::PublisherImpl(
        DomainParticipantImpl* p,
        const PublisherQos& qos,
        PublisherListener* listen)
    : participant_(p)
    , qos_(&qos == &PUBLISHER_QOS_DEFAULT ? participant_->get_default_publisher_qos() : qos)
    , listener_(listen)
    , publisher_listener_(this)
    , user_publisher_(nullptr)
    , rtps_participant_(p->get_rtps_participant())
    , default_datawriter_qos_(DATAWRITER_QOS_DEFAULT)
{
    PublisherAttributes pub_attr;
    XMLProfileManager::getDefaultPublisherAttributes(pub_attr);
    utils::set_qos_from_attributes(default_datawriter_qos_, pub_attr);
}

ReturnCode_t PublisherImpl::enable()
{
    if (qos_.entity_factory().autoenable_created_entities)
    {
        std::lock_guard<std::mutex> lock(mtx_writers_);
        for (auto topic_writers : writers_)
        {
            for (DataWriterImpl* dw : topic_writers.second)
            {
                dw->user_datawriter_->enable();
            }
        }
    }

    return RETCODE_OK;
}

void PublisherImpl::disable()
{
    set_listener(nullptr);
    user_publisher_->set_listener(nullptr);
    {
        std::lock_guard<std::mutex> lock(mtx_writers_);
        for (auto it = writers_.begin(); it != writers_.end(); ++it)
        {
            for (DataWriterImpl* dw : it->second)
            {
                dw->disable();
            }
        }
    }
}

PublisherImpl::~PublisherImpl()
{
    {
        std::lock_guard<std::mutex> lock(mtx_writers_);
        for (auto it = writers_.begin(); it != writers_.end(); ++it)
        {
            for (DataWriterImpl* dw : it->second)
            {
                delete dw;
            }
        }
        writers_.clear();
    }

    delete user_publisher_;
}

const PublisherQos& PublisherImpl::get_qos() const
{
    return qos_;
}

ReturnCode_t PublisherImpl::set_qos(
        const PublisherQos& qos)
{
    bool enabled = user_publisher_->is_enabled();

    const PublisherQos& qos_to_set = (&qos == &PUBLISHER_QOS_DEFAULT) ?
            participant_->get_default_publisher_qos() : qos;

    if (&qos != &PUBLISHER_QOS_DEFAULT)
    {
        ReturnCode_t ret_val = check_qos(qos_to_set);
        if (RETCODE_OK != ret_val)
        {
            return ret_val;
        }
    }

    if (enabled && !can_qos_be_updated(qos_, qos_to_set))
    {
        return RETCODE_IMMUTABLE_POLICY;
    }
    set_qos(qos_, qos_to_set, !enabled);

    if (enabled)
    {
        std::lock_guard<std::mutex> lock(mtx_writers_);
        for (auto topic_writers : writers_)
        {
            for (auto writer : topic_writers.second)
            {
                writer->publisher_qos_updated();
            }
        }
    }

    return RETCODE_OK;
}

const PublisherListener* PublisherImpl::get_listener() const
{
    return listener_;
}

ReturnCode_t PublisherImpl::set_listener(
        PublisherListener* listener)
{
    listener_ = listener;
    return RETCODE_OK;
}

void PublisherImpl::PublisherWriterListener::on_publication_matched(
        DataWriter* writer,
        const PublicationMatchedStatus& info)
{
    if (publisher_->listener_ != nullptr)
    {
        publisher_->listener_->on_publication_matched(writer, info);
    }
}

void PublisherImpl::PublisherWriterListener::on_liveliness_lost(
        DataWriter* writer,
        const LivelinessLostStatus& status)
{
    if (publisher_->listener_ != nullptr)
    {
        publisher_->listener_->on_liveliness_lost(writer, status);
    }
}

void PublisherImpl::PublisherWriterListener::on_offered_deadline_missed(
        DataWriter* writer,
        const OfferedDeadlineMissedStatus& status)
{
    if (publisher_->listener_ != nullptr)
    {
        publisher_->listener_->on_offered_deadline_missed(writer, status);
    }
}

DataWriterImpl* PublisherImpl::create_datawriter_impl(
        const TypeSupport& type,
        Topic* topic,
        const DataWriterQos& qos,
        DataWriterListener* listener,
        std::shared_ptr<fastrtps::rtps::IPayloadPool> payload_pool)
{
    return new DataWriterImpl(this, type, topic, qos, listener, payload_pool);
}

DataWriter* PublisherImpl::create_datawriter(
        Topic* topic,
        const DataWriterQos& qos,
        DataWriterListener* listener,
        const StatusMask& mask,
        std::shared_ptr<fastrtps::rtps::IPayloadPool> payload_pool)
{
    EPROSIMA_LOG_INFO(PUBLISHER, "CREATING WRITER IN TOPIC: " << topic->get_name());
    //Look for the correct type registration
    TypeSupport type_support = participant_->find_type(topic->get_type_name());

    /// Preconditions
    // Check the type was registered.
    if (type_support.empty())
    {
        EPROSIMA_LOG_ERROR(PUBLISHER, "Type: " << topic->get_type_name() << " Not Registered");
        return nullptr;
    }

    if (RETCODE_OK != DataWriterImpl::check_qos_including_resource_limits(qos, type_support))
    {
        return nullptr;
    }

    DataWriterImpl* impl = create_datawriter_impl(type_support, topic, qos, listener, payload_pool);
    return create_datawriter(topic, impl, mask);
}

DataWriter* PublisherImpl::create_datawriter(
        Topic* topic,
        DataWriterImpl* impl,
        const StatusMask& mask)
{
    topic->get_impl()->reference();

    DataWriter* writer = new DataWriter(impl, mask);
    impl->user_datawriter_ = writer;

    {
        std::lock_guard<std::mutex> lock(mtx_writers_);
        writers_[topic->get_name()].push_back(impl);
    }

    if (user_publisher_->is_enabled() && qos_.entity_factory().autoenable_created_entities)
    {
        if (RETCODE_OK != writer->enable())
        {
            delete_datawriter(writer);
            return nullptr;
        }
    }

    return writer;
}

DataWriter* PublisherImpl::create_datawriter_with_profile(
        Topic* topic,
        const std::string& profile_name,
        DataWriterListener* listener,
        const StatusMask& mask,
        std::shared_ptr<fastrtps::rtps::IPayloadPool> payload_pool)
{
    // TODO (ILG): Change when we have full XML support for DDS QoS profiles
    PublisherAttributes attr;
    if (XMLP_ret::XML_OK == XMLProfileManager::fillPublisherAttributes(profile_name, attr))
    {
        DataWriterQos qos = default_datawriter_qos_;
        utils::set_qos_from_attributes(qos, attr);
        return create_datawriter(topic, qos, listener, mask, payload_pool);
    }

    return nullptr;
}

ReturnCode_t PublisherImpl::delete_datawriter(
        const DataWriter* writer)
{
    if (user_publisher_ != writer->get_publisher())
    {
        return RETCODE_PRECONDITION_NOT_MET;
    }
    std::unique_lock<std::mutex> lock(mtx_writers_);
    auto vit = writers_.find(writer->get_topic()->get_name());
    if (vit != writers_.end())
    {
        auto dw_it = std::find(vit->second.begin(), vit->second.end(), writer->impl_);
        if (dw_it != vit->second.end())
        {
            //First extract the writer from the maps to free the mutex
            DataWriterImpl* writer_impl = *dw_it;
            ReturnCode_t ret_code = writer_impl->check_delete_preconditions();
            if (RETCODE_OK != ret_code)
            {
                return ret_code;
            }
            writer_impl->set_listener(nullptr);
            vit->second.erase(dw_it);
            if (vit->second.empty())
            {
                writers_.erase(vit);
            }
            lock.unlock();

            //Now we can delete it
            writer_impl->get_topic()->get_impl()->dereference();
            delete (writer_impl);
            return RETCODE_OK;
        }
    }
    return RETCODE_ERROR;
}

DataWriter* PublisherImpl::lookup_datawriter(
        const std::string& topic_name) const
{
    std::lock_guard<std::mutex> lock(mtx_writers_);
    auto it = writers_.find(topic_name);
    if (it != writers_.end() && it->second.size() > 0)
    {
        return it->second.front()->user_datawriter_;
    }
    return nullptr;
}

bool PublisherImpl::get_datawriters(
        std::vector<DataWriter*>& writers) const
{
    std::lock_guard<std::mutex> lock(mtx_writers_);
    for (auto vit : writers_)
    {
        for (DataWriterImpl* dw : vit.second)
        {
            writers.push_back(dw->user_datawriter_);
        }
    }
    return true;
}

bool PublisherImpl::has_datawriters() const
{
    if (writers_.empty())
    {
        return false;
    }
    return true;
}

bool PublisherImpl::contains_entity(
        const fastrtps::rtps::InstanceHandle_t& handle) const
{
    std::lock_guard<std::mutex> lock(mtx_writers_);
    for (auto vit : writers_)
    {
        for (DataWriterImpl* dw : vit.second)
        {
            InstanceHandle_t h(dw->guid());
            if (h == handle)
            {
                return true;
            }
        }
    }
    return false;
}

/* TODO
   bool PublisherImpl::suspend_publications()
   {
    EPROSIMA_LOG_ERROR(PUBLISHER, "Operation not implemented");
    return false;
   }
 */

/* TODO
   bool PublisherImpl::resume_publications()
   {
    EPROSIMA_LOG_ERROR(PUBLISHER, "Operation not implemented");
    return false;
   }
 */

/* TODO
   bool PublisherImpl::begin_coherent_changes()
   {
    EPROSIMA_LOG_ERROR(PUBLISHER, "Operation not implemented");
    return false;
   }
 */

/* TODO
   bool PublisherImpl::end_coherent_changes()
   {
    EPROSIMA_LOG_ERROR(PUBLISHER, "Operation not implemented");
    return false;
   }
 */


ReturnCode_t PublisherImpl::set_default_datawriter_qos(
        const DataWriterQos& qos)
{
    if (&qos == &DATAWRITER_QOS_DEFAULT)
    {
        reset_default_datawriter_qos();
        return RETCODE_OK;
    }

    ReturnCode_t ret_val = DataWriterImpl::check_qos(qos);
    if (RETCODE_OK != ret_val)
    {
        return ret_val;
    }
    DataWriterImpl::set_qos(default_datawriter_qos_, qos, true);
    return RETCODE_OK;
}

void PublisherImpl::reset_default_datawriter_qos()
{
    // TODO (ILG): Change when we have full XML support for DDS QoS profiles
    DataWriterImpl::set_qos(default_datawriter_qos_, DATAWRITER_QOS_DEFAULT, true);
    PublisherAttributes attr;
    XMLProfileManager::getDefaultPublisherAttributes(attr);
    utils::set_qos_from_attributes(default_datawriter_qos_, attr);
}

const DataWriterQos& PublisherImpl::get_default_datawriter_qos() const
{
    return default_datawriter_qos_;
}

ReturnCode_t PublisherImpl::get_datawriter_qos_from_profile(
        const std::string& profile_name,
        DataWriterQos& qos) const
{
    PublisherAttributes attr;
    if (XMLP_ret::XML_OK == XMLProfileManager::fillPublisherAttributes(profile_name, attr, false))
    {
        qos = default_datawriter_qos_;
        utils::set_qos_from_attributes(qos, attr);
        return RETCODE_OK;
    }

    return RETCODE_BAD_PARAMETER;
}

/* TODO
   bool PublisherImpl::copy_from_topic_qos(
        fastrtps::WriterQos&,
        const fastrtps::TopicAttributes&) const
   {
    EPROSIMA_LOG_ERROR(PUBLISHER, "Operation not implemented");
    return false;
   }
 */

ReturnCode_t PublisherImpl::wait_for_acknowledgments(
        const Duration_t& max_wait)
{
    Duration_t current = max_wait;
    Duration_t begin, end;
    std::lock_guard<std::mutex> lock(mtx_writers_);
    for (auto& vit : writers_)
    {
        for (DataWriterImpl* dw : vit.second)
        {
            participant_->get_current_time(begin);
            if (RETCODE_OK != dw->wait_for_acknowledgments(current))
            {
                return RETCODE_ERROR;
            }
            // Check ellapsed time and decrement
            participant_->get_current_time(end);
            current = current - (end - begin);
            if (current < fastrtps::c_TimeZero)
            {
                return RETCODE_TIMEOUT;
            }
        }
    }
    return RETCODE_OK;
}

const DomainParticipant* PublisherImpl::get_participant() const
{
    return const_cast<const DomainParticipantImpl*>(participant_)->get_participant();
}

const Publisher* PublisherImpl::get_publisher() const
{
    return user_publisher_;
}

ReturnCode_t PublisherImpl::delete_contained_entities()
{
    // Let's be optimistic
    ReturnCode_t result = RETCODE_OK;

    bool can_be_deleted = true;

    std::lock_guard<std::mutex> lock(mtx_writers_);
    for (auto writer: writers_)
    {
        for (DataWriterImpl* dw: writer.second)
        {
            can_be_deleted = dw->check_delete_preconditions() == RETCODE_OK;
            if (!can_be_deleted)
            {
                return RETCODE_PRECONDITION_NOT_MET;
            }
        }
    }

    // We traverse the map trying to delete all writers;
    auto writer_iterator = writers_.begin();
    while (writer_iterator != writers_.end())
    {
        //First extract the writer from the maps to free the mutex
        auto it = writer_iterator->second.begin();
        DataWriterImpl* writer_impl = *it;
        ReturnCode_t ret_code = writer_impl->check_delete_preconditions();
        if (RETCODE_OK != ret_code)
        {
            return RETCODE_ERROR;
        }
        writer_impl->set_listener(nullptr);
        it = writer_iterator->second.erase(it);
        if (writer_iterator->second.empty())
        {
            writer_iterator = writers_.erase(writer_iterator);
        }

        writer_impl->get_topic()->get_impl()->dereference();
        delete (writer_impl);
    }
    return result;
}

bool PublisherImpl::can_be_deleted()
{
    bool can_be_deleted = true;

    std::lock_guard<std::mutex> lock(mtx_writers_);
    for (auto topic_writers : writers_)
    {
        for (DataWriterImpl* dw : topic_writers.second)
        {
            can_be_deleted = can_be_deleted && (dw->check_delete_preconditions() == RETCODE_OK);
            if (!can_be_deleted)
            {
                return can_be_deleted;
            }
        }

    }

    return can_be_deleted;
}

const InstanceHandle_t& PublisherImpl::get_instance_handle() const
{
    return handle_;
}

bool PublisherImpl::type_in_use(
        const std::string& type_name) const
{
    for (auto it : writers_)
    {
        for (DataWriterImpl* writer : it.second)
        {
            if (writer->get_topic()->get_type_name() == type_name)
            {
                return true; // Is in use
            }
        }
    }
    return false;
}

void PublisherImpl::set_qos(
        PublisherQos& to,
        const PublisherQos& from,
        bool first_time)
{
    if (first_time && !(to.presentation() == from.presentation()))
    {
        to.presentation(from.presentation());
        to.presentation().hasChanged = true;
    }
    if (!(to.partition() == from.partition()))
    {
        to.partition() = from.partition();
        to.partition().hasChanged = true;
    }
    if (!(to.group_data() == from.group_data()))
    {
        to.group_data() = from.group_data();
        to.group_data().hasChanged = true;
    }
    if (!(to.entity_factory() == from.entity_factory()))
    {
        to.entity_factory() = from.entity_factory();
    }
}

ReturnCode_t PublisherImpl::check_qos(
        const PublisherQos& qos)
{
    (void) qos;
    return RETCODE_OK;
}

bool PublisherImpl::can_qos_be_updated(
        const PublisherQos& to,
        const PublisherQos& from)
{
    (void) to;
    (void) from;
    return true;
}

PublisherListener* PublisherImpl::get_listener_for(
        const StatusMask& status)
{
    if (listener_ != nullptr &&
            user_publisher_->get_status_mask().is_active(status))
    {
        return listener_;
    }
    return participant_->get_listener_for(status);
}

#ifdef FASTDDS_STATISTICS
bool PublisherImpl::get_monitoring_status(
        const uint32_t& status_id,
        statistics::rtps::DDSEntityStatus*& status,
        const fastrtps::rtps::GUID_t& entity_guid)
{
    bool ret = false;
    std::vector<DataWriter*> writers;
    if (get_datawriters(writers))
    {
        for (auto& writer : writers)
        {
            if (writer->guid() == entity_guid)
            {
                switch (status_id)
                {
                    case statistics::INCOMPATIBLE_QOS:
                    {
                        writer->get_offered_incompatible_qos_status(*static_cast<OfferedIncompatibleQosStatus*>(status));
                        ret = true;
                        break;
                    }
                    //! TODO
                    /*case statistics::INCONSISTENT_TOPIC:
                       {
                        writer->get_inconsistent_topic_status();
                        ret = true;
                        break;
                       }*/
                    case statistics::LIVELINESS_LOST:
                    {
                        writer->get_liveliness_lost_status(*static_cast<LivelinessLostStatus*>(status));
                        ret = true;
                        break;
                    }
                    case statistics::DEADLINE_MISSED:
                    {
                        writer->get_offered_deadline_missed_status(*static_cast<DeadlineMissedStatus*>(status));
                        ret = true;
                        break;
                    }
                    default:
                    {
                        EPROSIMA_LOG_ERROR(PUBLISHER, "Queried status not available for this entity " << status_id);
                        break;
                    }
                }

                break;
            }
        }
    }
    else
    {
        EPROSIMA_LOG_ERROR(PUBLISHER, "Could not retrieve datawriters");
    }


    return ret;
}

#endif //FASTDDS_STATISTICS

} // dds
} // fastdds
} // eprosima
