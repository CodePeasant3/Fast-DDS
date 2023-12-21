// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/**
 * @file TestSubscriber.cpp
 *
 */

#include "TestSubscriber.h"

#include <gtest/gtest.h>
#include <asio.hpp>

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/rtps/transport/TCPv4TransportDescriptor.h>
#include <fastdds/rtps/transport/TCPv6TransportDescriptor.h>
#include <fastdds/rtps/transport/UDPv4TransportDescriptor.h>
#include <fastdds/rtps/transport/UDPv6TransportDescriptor.h>
#include <fastrtps/types/DynamicType.h>
#include <fastrtps/types/DynamicTypePtr.h>
#include <fastrtps/utils/IPLocator.h>

using namespace eprosima::fastdds::dds;
using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

TestSubscriber::TestSubscriber()
    : mp_participant(nullptr)
    , mp_subscriber(nullptr)
    , reader_(nullptr)
    , topic_(nullptr)
    , m_Data(nullptr)
    , m_bInitialized(false)
    , using_typelookup_(false)
    , dataRepresentationQos_(nullptr)
    , typeConsistencyQos_(nullptr)
    , part_listener_(this)
    , m_subListener(this)
{
}

bool TestSubscriber::init(
        const std::string& topicName,
        int domain,
        eprosima::fastdds::dds::TypeSupport type,
        const eprosima::fastrtps::types::TypeObject* type_object,
        const eprosima::fastrtps::types::TypeIdentifier* type_identifier,
        const eprosima::fastdds::dds::xtypes::TypeInformation* type_info,
        const std::string& name,
        const eprosima::fastdds::dds::DataRepresentationQosPolicy* dataRepresentationQos,
        const eprosima::fastdds::dds::TypeConsistencyEnforcementQosPolicy* typeConsistencyQos,
        bool use_typelookup)
{
    dataRepresentationQos_ = dataRepresentationQos;
    typeConsistencyQos_ = typeConsistencyQos;

    m_Name = name;
    m_Type.swap(type);
    using_typelookup_ = use_typelookup;
    DomainParticipantQos pqos;
    pqos.wire_protocol().builtin.discovery_config.leaseDuration = c_TimeInfinite;
    pqos.wire_protocol().builtin.discovery_config.leaseDuration_announcementperiod = Duration_t(1, 0);
    pqos.name(m_Name.c_str());

    //Do not enable entities on creation
    DomainParticipantFactoryQos factory_qos;
    factory_qos.entity_factory().autoenable_created_entities = false;
    DomainParticipantFactory::get_instance()->set_qos(factory_qos);

    mp_participant = DomainParticipantFactory::get_instance()->create_participant(domain, pqos, &part_listener_);
    if (mp_participant == nullptr)
    {
        std::cout << "ERROR" << std::endl;
        return false;
    }
    mp_participant->enable();

    std::ostringstream t;
    t << topicName << "_" << asio::ip::host_name() << "_" << domain;
    topic_name_ = t.str();

    //REGISTER THE TYPE
    if (m_Type != nullptr)
    {
        if (type_object != nullptr)
        {
            //TODO(XTypes)
            //m_Type->type_object(*type_object);
        }
        if (type_identifier != nullptr)
        {
            //TODO(XTypes)
            //m_Type->type_identifier(*type_identifier);
        }
        if (type_info != nullptr)
        {
            m_Type->type_information(*type_info);
        }

        m_Type->auto_fill_type_information(false);
        m_Type.register_type(mp_participant);

        //CREATE THE TOPIC
        topic_ = mp_participant->create_topic(
            topic_name_,
            m_Type->getName(),
            TOPIC_QOS_DEFAULT);

        if (topic_ == nullptr)
        {
            return false;
        }

        //CREATE THE SUBSCRIBER
        mp_subscriber = mp_participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);

        if (mp_subscriber == nullptr)
        {
            return false;
        }

        //CREATE THE DATAREADER
        reader_qos = mp_subscriber->get_default_datareader_qos();
        if (typeConsistencyQos_ != nullptr)
        {
            reader_qos.type_consistency().type_consistency = *typeConsistencyQos_;
        }
        if (dataRepresentationQos_ != nullptr)
        {
            reader_qos.type_consistency().representation = *dataRepresentationQos_;
        }
        reader_ = mp_subscriber->create_datareader(topic_, reader_qos, &m_subListener);

        if (reader_ == nullptr)
        {
            return false;
        }

        m_Data = m_Type->createData();
    }
    m_bInitialized = true;

    return true;
}

TestSubscriber::~TestSubscriber()
{
    if (m_Type != nullptr)
    {
        m_Type->deleteData(m_Data);
    }

    if (reader_ != nullptr)
    {
        mp_subscriber->delete_datareader(reader_);
    }
    if (mp_subscriber != nullptr)
    {
        mp_participant->delete_subscriber(mp_subscriber);
    }
    if (topic_ != nullptr)
    {
        mp_participant->delete_topic(topic_);
    }
    DomainParticipantFactory::get_instance()->delete_participant(mp_participant);
}

TestSubscriber::SubListener::SubListener(
        TestSubscriber* parent)
    : mParent(parent)
    , n_matched(0)
    , n_samples(0)
{
}

void TestSubscriber::waitDiscovery(
        bool expectMatch,
        int maxWait)
{
    std::unique_lock<std::mutex> lock(m_mDiscovery);

    if (m_subListener.n_matched == 0)
    {
        m_cvDiscovery.wait_for(lock, std::chrono::seconds(maxWait));
    }

    if (expectMatch)
    {
        ASSERT_GE(m_subListener.n_matched, 1);
    }
    else
    {
        ASSERT_EQ(m_subListener.n_matched, 0);
    }
}

void TestSubscriber::waitTypeDiscovery(
        bool expectMatch,
        int maxWait)
{
    std::unique_lock<std::mutex> lock(mtx_type_discovery_);

    if (!part_listener_.discovered_)
    {
        cv_type_discovery_.wait_for(lock, std::chrono::seconds(maxWait));
    }

    if (expectMatch)
    {
        ASSERT_TRUE(part_listener_.discovered_);
    }
    else
    {
        ASSERT_FALSE(part_listener_.discovered_);
    }
}

void TestSubscriber::matched(
        bool unmatched)
{
    std::unique_lock<std::mutex> lock(m_mDiscovery);
    if (unmatched)
    {
        --m_subListener.n_matched;
    }
    else
    {
        ++m_subListener.n_matched;
    }
    if (m_subListener.n_matched >= 1)
    {
        m_cvDiscovery.notify_one();
    }
}

void TestSubscriber::SubListener::on_subscription_matched(
        eprosima::fastdds::dds::DataReader*,
        const eprosima::fastdds::dds::SubscriptionMatchedStatus& info)
{
    if (info.current_count_change > 0)
    {
        mParent->matched();
        std::cout << mParent->m_Name << " matched." << std::endl;
    }
    else if (info.current_count_change < 0)
    {
        mParent->matched(true);
        std::cout << mParent->m_Name << " unmatched." << std::endl;
    }
}

void TestSubscriber::SubListener::on_data_available(
        eprosima::fastdds::dds::DataReader* reader)
{
    SampleInfo info;
    if (RETCODE_OK == reader->take_next_sample(mParent->m_Data, &info))
    {
        if (info.valid_data)
        {
            ++n_samples;
            mParent->cv_.notify_one();
            //std::cout << mParent->m_Name << " received a total of " << n_samples << " samples." << std::endl;
        }
    }
}

DataReader* TestSubscriber::create_datareader()
{
    assert (topic_ == nullptr);
    assert (mp_subscriber == nullptr);

    //CREATE THE TOPIC
    topic_ = mp_participant->create_topic(
        topic_name_,
        disc_type_->get_name(),
        TOPIC_QOS_DEFAULT);

    if (topic_ == nullptr)
    {
        return nullptr;
    }

    mp_subscriber = mp_participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);

    if (mp_subscriber == nullptr)
    {
        return nullptr;
    }

    reader_qos = mp_subscriber->get_default_datareader_qos();
    if (typeConsistencyQos_ != nullptr)
    {
        reader_qos.type_consistency().type_consistency = *typeConsistencyQos_;
    }
    if (dataRepresentationQos_ != nullptr)
    {
        reader_qos.type_consistency().representation = *dataRepresentationQos_;
    }
    reader_ = mp_subscriber->create_datareader(topic_, reader_qos, &m_subListener);
    return reader_;
}

void TestSubscriber::delete_datareader(
        eprosima::fastdds::dds::DataReader* reader)
{
    mp_subscriber->delete_datareader(reader);
}

bool TestSubscriber::register_discovered_type()
{
    TypeSupport type(disc_type_);
    type->auto_fill_type_information(true);
    return type.register_type(mp_participant, disc_type_->get_name()) == RETCODE_OK;
}

void TestSubscriber::run()
{
    std::cout << m_Name << " running..." << std::endl;
    std::cin.ignore();
}
