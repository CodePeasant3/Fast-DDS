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
 * @file TypesBase.cpp
 */

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>
#include <fastrtps/types/TypesBase.h>

namespace eprosima {
namespace fastcdr {
size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator&,
        const eprosima::fastrtps::types::MemberFlag&,
        size_t current_alignment)
{
    return 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);
}

void serialize(
        eprosima::fastcdr::Cdr& cdr,
        const eprosima::fastrtps::types::MemberFlag& data)
{
    //cdr << m_MemberFlag;
    cdr << data.bitset();
}

void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastrtps::types::MemberFlag& data)
{
    //cdr >> (uint16_t)m_MemberFlag;
    cdr >> data.bitset();
}

size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator&,
        const eprosima::fastrtps::types::TypeFlag&,
        size_t current_alignment)
{
    return 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);
}

void serialize(
        eprosima::fastcdr::Cdr& cdr,
        const eprosima::fastrtps::types::TypeFlag& data)
{
    cdr << data.bitset();
}

void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        eprosima::fastrtps::types::TypeFlag& data)
{
    cdr >> data.bitset();
}

} // namespace fastcdr
} // namespace eprosima
