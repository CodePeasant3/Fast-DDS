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
 * @file TypeLookupTypesCdrAux.ipp
 * This source file contains some declarations of CDR related functions.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_DDS_BUILTIN_TYPELOOKUPTYPESCDRAUX_IPP_
#define _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_DDS_BUILTIN_TYPELOOKUPTYPESCDRAUX_IPP_

#include "TypeLookupTypesCdrAux.hpp"

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

namespace eprosima {
namespace fastcdr {



template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypes_In& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0x0c536065),
                data.type_ids(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypes_In& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0x0c536065) << data.type_ids()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_getTypes_In& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0x0c536065:
                                                dcdr >> data.type_ids();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypes_In& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(scdr);
    static_cast<void>(data);
}




template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypes_Out& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0x02804ad1),
                data.types(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0x0b8e6577),
                data.complete_to_minimal(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypes_Out& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0x02804ad1) << data.types()
        << eprosima::fastcdr::MemberId(0x0b8e6577) << data.complete_to_minimal()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_getTypes_Out& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0x02804ad1:
                                                dcdr >> data.types();
                                            break;

                                        case 0x0b8e6577:
                                                dcdr >> data.complete_to_minimal();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypes_Out& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(scdr);
    static_cast<void>(data);
}




template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypes_Result& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

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
        case eprosima::fastdds::dds::RETCODE_OK:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.result(), current_alignment);
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
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypes_Result& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr << eprosima::fastcdr::MemberId(0) << data._d();

    switch (data._d())
    {
                case eprosima::fastdds::dds::RETCODE_OK:
                    scdr << eprosima::fastcdr::MemberId(1) << data.result();
                    break;

        default:
            break;
    }

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_getTypes_Result& data)
{
    using namespace eprosima::fastdds::dds::builtin;

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
                                                        case eprosima::fastdds::dds::RETCODE_OK:
                                                            dcdr >> data.result();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_In& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0x0c536065),
                data.type_ids(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0x0508e3d2),
                data.continuation_point(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_In& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0x0c536065) << data.type_ids()
        << eprosima::fastcdr::MemberId(0x0508e3d2) << data.continuation_point()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_In& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0x0c536065:
                                                dcdr >> data.type_ids();
                                            break;

                                        case 0x0508e3d2:
                                                dcdr >> data.continuation_point();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_In& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(scdr);
    static_cast<void>(data);
}




template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_Out& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0x0ba4dfc9),
                data.dependent_typeids(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0x0508e3d2),
                data.continuation_point(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_Out& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0x0ba4dfc9) << data.dependent_typeids()
        << eprosima::fastcdr::MemberId(0x0508e3d2) << data.continuation_point()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_Out& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0x0ba4dfc9:
                                                dcdr >> data.dependent_typeids();
                                            break;

                                        case 0x0508e3d2:
                                                dcdr >> data.continuation_point();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_Out& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(scdr);
    static_cast<void>(data);
}




template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_Result& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

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
        case eprosima::fastdds::dds::RETCODE_OK:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.result(), current_alignment);
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
        const eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_Result& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr << eprosima::fastcdr::MemberId(0) << data._d();

    switch (data._d())
    {
                case eprosima::fastdds::dds::RETCODE_OK:
                    scdr << eprosima::fastcdr::MemberId(1) << data.result();
                    break;

        default:
            break;
    }

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_getTypeDependencies_Result& data)
{
    using namespace eprosima::fastdds::dds::builtin;

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
                                                        case eprosima::fastdds::dds::RETCODE_OK:
                                                            dcdr >> data.result();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_Call& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

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
        case TypeLookup_getTypes_HashId:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.getTypes(), current_alignment);
                    break;

        case TypeLookup_getDependencies_HashId:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                                data.getTypeDependencies(), current_alignment);
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
        const eprosima::fastdds::dds::builtin::TypeLookup_Call& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr << eprosima::fastcdr::MemberId(0) << data._d();

    switch (data._d())
    {
                case TypeLookup_getTypes_HashId:
                    scdr << eprosima::fastcdr::MemberId(1) << data.getTypes();
                    break;

                case TypeLookup_getDependencies_HashId:
                    scdr << eprosima::fastcdr::MemberId(2) << data.getTypeDependencies();
                    break;

        default:
            break;
    }

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_Call& data)
{
    using namespace eprosima::fastdds::dds::builtin;

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
                                                        case TypeLookup_getTypes_HashId:
                                                            dcdr >> data.getTypes();
                                                            break;

                                                        case TypeLookup_getDependencies_HashId:
                                                            dcdr >> data.getTypeDependencies();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_Request& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.header(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                data.data(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::dds::builtin::TypeLookup_Request& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.header()
        << eprosima::fastcdr::MemberId(1) << data.data()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_Request& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.header();
                                            break;

                                        case 1:
                                                dcdr >> data.data();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_Request& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(scdr);
    static_cast<void>(data);
}




template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const eprosima::fastdds::dds::builtin::TypeLookup_Return& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

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
        case TypeLookup_getTypes_HashId:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.getType(), current_alignment);
                    break;

        case TypeLookup_getDependencies_HashId:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                                data.getTypeDependencies(), current_alignment);
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
        const eprosima::fastdds::dds::builtin::TypeLookup_Return& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr << eprosima::fastcdr::MemberId(0) << data._d();

    switch (data._d())
    {
                case TypeLookup_getTypes_HashId:
                    scdr << eprosima::fastcdr::MemberId(1) << data.getType();
                    break;

                case TypeLookup_getDependencies_HashId:
                    scdr << eprosima::fastcdr::MemberId(2) << data.getTypeDependencies();
                    break;

        default:
            break;
    }

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_Return& data)
{
    using namespace eprosima::fastdds::dds::builtin;

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
                                                        case TypeLookup_getTypes_HashId:
                                                            dcdr >> data.getType();
                                                            break;

                                                        case TypeLookup_getDependencies_HashId:
                                                            dcdr >> data.getTypeDependencies();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_Reply& data,
        size_t& current_alignment)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.header(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                data.return_value(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const eprosima::fastdds::dds::builtin::TypeLookup_Reply& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.header()
        << eprosima::fastcdr::MemberId(1) << data.return_value()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastdds::dds::builtin::TypeLookup_Reply& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.header();
                                            break;

                                        case 1:
                                                dcdr >> data.return_value();
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
        const eprosima::fastdds::dds::builtin::TypeLookup_Reply& data)
{
    using namespace eprosima::fastdds::dds::builtin;

    static_cast<void>(scdr);
    static_cast<void>(data);
}



} // namespace fastcdr
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_DDS_BUILTIN_TYPELOOKUPTYPESCDRAUX_IPP_

