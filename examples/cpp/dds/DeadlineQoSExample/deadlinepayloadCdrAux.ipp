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
 * @file deadlinepayloadCdrAux.hpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_DEADLINEPAYLOADCDRAUX_IPP_
#define _FAST_DDS_GENERATED_DEADLINEPAYLOADCDRAUX_IPP_

#include "deadlinepayloadCdrAux.hpp"

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

namespace eprosima {
namespace fastcdr {

size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const HelloMsg& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.deadlinekey(), current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.payload(), current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}
void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const HelloMsg& data)
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
);

    scdr             << eprosima::fastcdr::MemberId(0) << data.deadlinekey()
                << eprosima::fastcdr::MemberId(1) << data.payload()
    ;

    scdr.end_serialize_type(current_state);
}

void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        HelloMsg& data)
{
    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.deadlinekey();
                                            break;
                                        
                                        case 1:
                                                dcdr >> data.payload();
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
        const HelloMsg& data)
{
    static_cast<void>(scdr);
    static_cast<void>(data);
                            scdr << data.deadlinekey();
                
                
}


} // namespace fastcdr
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_DEADLINEPAYLOADCDRAUX_IPP_