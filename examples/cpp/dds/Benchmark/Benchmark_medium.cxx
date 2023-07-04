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
 * @file Benchmark_medium.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "Benchmark_medium.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

#define BenchMarkMedium_max_cdr_typesize 524296ULL;
#define BenchMarkMedium_max_key_cdr_typesize 0ULL;

BenchMarkMedium::BenchMarkMedium()
{



}

BenchMarkMedium::~BenchMarkMedium()
{


}

BenchMarkMedium::BenchMarkMedium(
        const BenchMarkMedium& x)
{
    m_data = x.m_data;
    m_index = x.m_index;
}

BenchMarkMedium::BenchMarkMedium(
        BenchMarkMedium&& x) noexcept 
{
    m_data = std::move(x.m_data);
    m_index = x.m_index;
}

BenchMarkMedium& BenchMarkMedium::operator =(
        const BenchMarkMedium& x)
{

    m_data = x.m_data;
    m_index = x.m_index;

    return *this;
}

BenchMarkMedium& BenchMarkMedium::operator =(
        BenchMarkMedium&& x) noexcept
{

    m_data = std::move(x.m_data);
    m_index = x.m_index;

    return *this;
}

bool BenchMarkMedium::operator ==(
        const BenchMarkMedium& x) const
{

    return (m_data == x.m_data && m_index == x.m_index);
}

bool BenchMarkMedium::operator !=(
        const BenchMarkMedium& x) const
{
    return !(*this == x);
}

size_t BenchMarkMedium::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return BenchMarkMedium_max_cdr_typesize;
}

size_t BenchMarkMedium::calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const BenchMarkMedium& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.m_data, current_alignment);
                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1), data.m_index, current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

void BenchMarkMedium::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
);

    scdr << eprosima::fastcdr::MemberId(0) << m_data;scdr << eprosima::fastcdr::MemberId(1) << m_index;

    scdr.end_serialize_type(current_state);
}

void BenchMarkMedium::deserialize(
        eprosima::fastcdr::Cdr& cdr)
{
    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            [this](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                            dcdr >> m_data;
                                            break;
                                        
                    case 1:
                        dcdr >> m_index;
ret_value = false;
                        break;
                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

/*!
 * @brief This function copies the value in member data
 * @param _data New value to be copied in member data
 */
void BenchMarkMedium::data(
        const std::array<char, 524288>& _data)
{
    m_data = _data;
}

/*!
 * @brief This function moves the value in member data
 * @param _data New value to be moved in member data
 */
void BenchMarkMedium::data(
        std::array<char, 524288>&& _data)
{
    m_data = std::move(_data);
}

/*!
 * @brief This function returns a constant reference to member data
 * @return Constant reference to member data
 */
const std::array<char, 524288>& BenchMarkMedium::data() const
{
    return m_data;
}

/*!
 * @brief This function returns a reference to member data
 * @return Reference to member data
 */
std::array<char, 524288>& BenchMarkMedium::data()
{
    return m_data;
}
/*!
 * @brief This function sets a value in member index
 * @param _index New value for member index
 */
void BenchMarkMedium::index(
        uint32_t _index)
{
    m_index = _index;
}

/*!
 * @brief This function returns the value of member index
 * @return Value of member index
 */
uint32_t BenchMarkMedium::index() const
{
    return m_index;
}

/*!
 * @brief This function returns a reference to member index
 * @return Reference to member index
 */
uint32_t& BenchMarkMedium::index()
{
    return m_index;
}



size_t BenchMarkMedium::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return BenchMarkMedium_max_key_cdr_typesize;
}

bool BenchMarkMedium::isKeyDefined()
{
    return false;
}

void BenchMarkMedium::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
}
