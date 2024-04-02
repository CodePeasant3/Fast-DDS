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

/*!
 * @file monitorservice_typesCdrAux.ipp
 * This source file contains some declarations of CDR related functions.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_STATISTICS_MONITORSERVICE_TYPESCDRAUX_IPP_
#define _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_STATISTICS_MONITORSERVICE_TYPESCDRAUX_IPP_

#include "monitorservice_typesCdrAux.hpp"

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

namespace eprosima {
namespace fastcdr {





template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::Connection& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.mode(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                data.guid(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                data.announced_locators(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3),
                data.used_locators(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::Connection& data)
{
    using namespace eprosima::fastdds::statistics;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.mode()
        << eprosima::fastcdr::MemberId(1) << data.guid()
        << eprosima::fastcdr::MemberId(2) << data.announced_locators()
        << eprosima::fastcdr::MemberId(3) << data.used_locators()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::statistics::Connection& data)
{
    using namespace eprosima::fastdds::statistics;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.mode();
                                            break;

                                        case 1:
                                                dcdr >> data.guid();
                                            break;

                                        case 2:
                                                dcdr >> data.announced_locators();
                                            break;

                                        case 3:
                                                dcdr >> data.used_locators();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::Connection& data)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(scdr);
    static_cast<void>(data);
}




template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::QosPolicyCount_s& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.policy_id(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                data.count(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::QosPolicyCount_s& data)
{
    using namespace eprosima::fastdds::statistics;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.policy_id()
        << eprosima::fastcdr::MemberId(1) << data.count()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::statistics::QosPolicyCount_s& data)
{
    using namespace eprosima::fastdds::statistics;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.policy_id();
                                            break;

                                        case 1:
                                                dcdr >> data.count();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::QosPolicyCount_s& data)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(scdr);
    static_cast<void>(data);
}




template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::BaseStatus_s& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.total_count(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::BaseStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.total_count()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::statistics::BaseStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.total_count();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::BaseStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(scdr);
    static_cast<void>(data);
}








template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::IncompatibleQoSStatus_s& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.total_count(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                data.last_policy_id(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                data.policies(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::IncompatibleQoSStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.total_count()
        << eprosima::fastcdr::MemberId(1) << data.last_policy_id()
        << eprosima::fastcdr::MemberId(2) << data.policies()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::statistics::IncompatibleQoSStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.total_count();
                                            break;

                                        case 1:
                                                dcdr >> data.last_policy_id();
                                            break;

                                        case 2:
                                                dcdr >> data.policies();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::IncompatibleQoSStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(scdr);
    static_cast<void>(data);
}




template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::LivelinessChangedStatus_s& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.alive_count(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                data.not_alive_count(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                data.last_publication_handle(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::LivelinessChangedStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.alive_count()
        << eprosima::fastcdr::MemberId(1) << data.not_alive_count()
        << eprosima::fastcdr::MemberId(2) << data.last_publication_handle()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::statistics::LivelinessChangedStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.alive_count();
                                            break;

                                        case 1:
                                                dcdr >> data.not_alive_count();
                                            break;

                                        case 2:
                                                dcdr >> data.last_publication_handle();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::LivelinessChangedStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(scdr);
    static_cast<void>(data);
}




template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::DeadlineMissedStatus_s& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.total_count(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                data.total_count_change(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                data.last_instance_handle(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::DeadlineMissedStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.total_count()
        << eprosima::fastcdr::MemberId(1) << data.total_count_change()
        << eprosima::fastcdr::MemberId(2) << data.last_instance_handle()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::statistics::DeadlineMissedStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.total_count();
                                            break;

                                        case 1:
                                                dcdr >> data.total_count_change();
                                            break;

                                        case 2:
                                                dcdr >> data.last_instance_handle();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::DeadlineMissedStatus_s& data)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(scdr);
    static_cast<void>(data);
}











template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::MonitorServiceData& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};

    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data._d(),
                    current_alignment);

    switch (data._d())
    {
        case eprosima::fastdds::statistics::PROXY:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.entity_proxy(), current_alignment);
                    break;

        case eprosima::fastdds::statistics::CONNECTION_LIST:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                                data.connection_list(), current_alignment);
                    break;

        case eprosima::fastdds::statistics::INCOMPATIBLE_QOS:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3),
                                data.incompatible_qos_status(), current_alignment);
                    break;

        case eprosima::fastdds::statistics::INCONSISTENT_TOPIC:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(4),
                                data.inconsistent_topic_status(), current_alignment);
                    break;

        case eprosima::fastdds::statistics::LIVELINESS_LOST:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(5),
                                data.liveliness_lost_status(), current_alignment);
                    break;

        case eprosima::fastdds::statistics::LIVELINESS_CHANGED:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(6),
                                data.liveliness_changed_status(), current_alignment);
                    break;

        case eprosima::fastdds::statistics::DEADLINE_MISSED:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(7),
                                data.deadline_missed_status(), current_alignment);
                    break;

        case eprosima::fastdds::statistics::SAMPLE_LOST:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(8),
                                data.sample_lost_status(), current_alignment);
                    break;

        case eprosima::fastdds::statistics::STATUSES_SIZE:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(9),
                                data.statuses_size(), current_alignment);
                    break;

        default:
            break;
    }

    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}


template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::MonitorServiceData& data)
{
    using namespace eprosima::fastdds::statistics;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr << eprosima::fastcdr::MemberId(0) << data._d();

    switch (data._d())
    {
                case eprosima::fastdds::statistics::PROXY:
                    scdr << eprosima::fastcdr::MemberId(1) << data.entity_proxy();
                    break;

                case eprosima::fastdds::statistics::CONNECTION_LIST:
                    scdr << eprosima::fastcdr::MemberId(2) << data.connection_list();
                    break;

                case eprosima::fastdds::statistics::INCOMPATIBLE_QOS:
                    scdr << eprosima::fastcdr::MemberId(3) << data.incompatible_qos_status();
                    break;

                case eprosima::fastdds::statistics::INCONSISTENT_TOPIC:
                    scdr << eprosima::fastcdr::MemberId(4) << data.inconsistent_topic_status();
                    break;

                case eprosima::fastdds::statistics::LIVELINESS_LOST:
                    scdr << eprosima::fastcdr::MemberId(5) << data.liveliness_lost_status();
                    break;

                case eprosima::fastdds::statistics::LIVELINESS_CHANGED:
                    scdr << eprosima::fastcdr::MemberId(6) << data.liveliness_changed_status();
                    break;

                case eprosima::fastdds::statistics::DEADLINE_MISSED:
                    scdr << eprosima::fastcdr::MemberId(7) << data.deadline_missed_status();
                    break;

                case eprosima::fastdds::statistics::SAMPLE_LOST:
                    scdr << eprosima::fastcdr::MemberId(8) << data.sample_lost_status();
                    break;

                case eprosima::fastdds::statistics::STATUSES_SIZE:
                    scdr << eprosima::fastcdr::MemberId(9) << data.statuses_size();
                    break;

        default:
            break;
    }

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::statistics::MonitorServiceData& data)
{
    using namespace eprosima::fastdds::statistics;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                    case 0:
                        dcdr >> data._d();
                        break;
                    default:
                        switch (data._d())
                        {
                                                        case eprosima::fastdds::statistics::PROXY:
                                                            dcdr >> data.entity_proxy();
                                                            break;

                                                        case eprosima::fastdds::statistics::CONNECTION_LIST:
                                                            dcdr >> data.connection_list();
                                                            break;

                                                        case eprosima::fastdds::statistics::INCOMPATIBLE_QOS:
                                                            dcdr >> data.incompatible_qos_status();
                                                            break;

                                                        case eprosima::fastdds::statistics::INCONSISTENT_TOPIC:
                                                            dcdr >> data.inconsistent_topic_status();
                                                            break;

                                                        case eprosima::fastdds::statistics::LIVELINESS_LOST:
                                                            dcdr >> data.liveliness_lost_status();
                                                            break;

                                                        case eprosima::fastdds::statistics::LIVELINESS_CHANGED:
                                                            dcdr >> data.liveliness_changed_status();
                                                            break;

                                                        case eprosima::fastdds::statistics::DEADLINE_MISSED:
                                                            dcdr >> data.deadline_missed_status();
                                                            break;

                                                        case eprosima::fastdds::statistics::SAMPLE_LOST:
                                                            dcdr >> data.sample_lost_status();
                                                            break;

                                                        case eprosima::fastdds::statistics::STATUSES_SIZE:
                                                            dcdr >> data.statuses_size();
                                                            break;

                            default:
                                break;
                        }
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}



template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::statistics::MonitorServiceStatusData& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.local_entity(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                data.status_kind(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                data.value(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::MonitorServiceStatusData& data)
{
    using namespace eprosima::fastdds::statistics;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.local_entity()
        << eprosima::fastcdr::MemberId(1) << data.status_kind()
        << eprosima::fastcdr::MemberId(2) << data.value()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::statistics::MonitorServiceStatusData& data)
{
    using namespace eprosima::fastdds::statistics;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.local_entity();
                                            break;

                                        case 1:
                                                dcdr >> data.status_kind();
                                            break;

                                        case 2:
                                                dcdr >> data.value();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::statistics::MonitorServiceStatusData& data)
{
    using namespace eprosima::fastdds::statistics;

    static_cast<void>(scdr);
    static_cast<void>(data);
                                scdr << data.local_entity();

                            scdr << data.status_kind();


}






} // namespace fastcdr
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_STATISTICS_MONITORSERVICE_TYPESCDRAUX_IPP_

