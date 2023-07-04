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
 * @file WideEnum.cpp
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

#include "WideEnum.h"
#include "WideEnumTypeObject.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

#define MyEnumWideStruct_max_cdr_typesize 8ULL;

#define SimpleWideUnionStruct_max_cdr_typesize 16ULL;

#define MyEnumWideStruct_max_key_cdr_typesize 0ULL;

#define SimpleWideUnionStruct_max_key_cdr_typesize 0ULL;



MyEnumWideStruct::MyEnumWideStruct()
{

    // Just to register all known types
    registerWideEnumTypes();
}

MyEnumWideStruct::~MyEnumWideStruct()
{
}

MyEnumWideStruct::MyEnumWideStruct(
        const MyEnumWideStruct& x)
{
    m_my_enum_wide = x.m_my_enum_wide;
}

MyEnumWideStruct::MyEnumWideStruct(
        MyEnumWideStruct&& x) noexcept 
{
    m_my_enum_wide = x.m_my_enum_wide;
}

MyEnumWideStruct& MyEnumWideStruct::operator =(
        const MyEnumWideStruct& x)
{

    m_my_enum_wide = x.m_my_enum_wide;

    return *this;
}

MyEnumWideStruct& MyEnumWideStruct::operator =(
        MyEnumWideStruct&& x) noexcept
{

    m_my_enum_wide = x.m_my_enum_wide;

    return *this;
}

bool MyEnumWideStruct::operator ==(
        const MyEnumWideStruct& x) const
{

    return (m_my_enum_wide == x.m_my_enum_wide);
}

bool MyEnumWideStruct::operator !=(
        const MyEnumWideStruct& x) const
{
    return !(*this == x);
}

size_t MyEnumWideStruct::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return MyEnumWideStruct_max_cdr_typesize;
}

size_t MyEnumWideStruct::calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const MyEnumWideStruct& data,
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


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.m_my_enum_wide, current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

void MyEnumWideStruct::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
);

    scdr << eprosima::fastcdr::MemberId(0) << m_my_enum_wide;

    scdr.end_serialize_type(current_state);
}

void MyEnumWideStruct::deserialize(
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
                        dcdr >> m_my_enum_wide;
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
 * @brief This function sets a value in member my_enum_wide
 * @param _my_enum_wide New value for member my_enum_wide
 */
void MyEnumWideStruct::my_enum_wide(
        MyEnumWide _my_enum_wide)
{
    m_my_enum_wide = _my_enum_wide;
}

/*!
 * @brief This function returns the value of member my_enum_wide
 * @return Value of member my_enum_wide
 */
MyEnumWide MyEnumWideStruct::my_enum_wide() const
{
    return m_my_enum_wide;
}

/*!
 * @brief This function returns a reference to member my_enum_wide
 * @return Reference to member my_enum_wide
 */
MyEnumWide& MyEnumWideStruct::my_enum_wide()
{
    return m_my_enum_wide;
}


size_t MyEnumWideStruct::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return MyEnumWideStruct_max_key_cdr_typesize;
}

bool MyEnumWideStruct::isKeyDefined()
{
    return false;
}

void MyEnumWideStruct::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
}

SimpleWideUnion::SimpleWideUnion()
{
    m__d = A;



}

SimpleWideUnion::~SimpleWideUnion()
{
}

SimpleWideUnion::SimpleWideUnion(
        const SimpleWideUnion& x)
{
    m__d = x.m__d;

    switch(m__d)
    {
        case A:
        m_first = x.m_first;
        break;
        case B:
        m_second = x.m_second;
        break;
        case D:
        m_third = x.m_third;
        break;
        default:
        break;
    }
}

SimpleWideUnion::SimpleWideUnion(
        SimpleWideUnion&& x) noexcept
{
    m__d = x.m__d;

    switch(m__d)
    {
        case A:
        m_first = x.m_first;
        break;
        case B:
        m_second = x.m_second;
        break;
        case D:
        m_third = x.m_third;
        break;
        default:
        break;
    }
}

SimpleWideUnion& SimpleWideUnion::operator =(
        const SimpleWideUnion& x)
{
    m__d = x.m__d;

    switch(m__d)
    {
        case A:
        m_first = x.m_first;
        break;
        case B:
        m_second = x.m_second;
        break;
        case D:
        m_third = x.m_third;
        break;
        default:
        break;
    }

    return *this;
}

SimpleWideUnion& SimpleWideUnion::operator =(
        SimpleWideUnion&& x) noexcept
{
    m__d = x.m__d;

    switch(m__d)
    {
        case A:
        m_first = x.m_first;
        break;
        case B:
        m_second = x.m_second;
        break;
        case D:
        m_third = x.m_third;
        break;
        default:
        break;
    }

    return *this;
}

bool SimpleWideUnion::operator ==(
        const SimpleWideUnion& x) const
{
    if (m__d != x.m__d)
    {
        return false;
    }

    switch(m__d)
    {
        case A:
            return (m_first == x.m_first);
            break;
        case B:
            return (m_second == x.m_second);
            break;
        case D:
            return (m_third == x.m_third);
            break;
        default:
        break;
    }
    return false;
}

bool SimpleWideUnion::operator !=(
        const SimpleWideUnion& x) const
{
    return !(*this == x);
}

void SimpleWideUnion::_d(
        int32_t __d)
{
    bool b = false;

    switch(m__d)
    {
        case A:
        switch(__d)
        {
            case A:
            b = true;
            break;
            default:
            break;
        }
        break;
        case B:
        switch(__d)
        {
            case B:
            b = true;
            break;
            default:
            break;
        }
        break;
        case D:
        switch(__d)
        {
            case D:
            b = true;
            break;
            default:
            break;
        }
        break;
    }

    if(!b)
    {
        throw BadParamException("Discriminator doesn't correspond with the selected union member");
    }

    m__d = __d;
}

int32_t SimpleWideUnion::_d() const
{
    return m__d;
}

int32_t& SimpleWideUnion::_d()
{
    return m__d;
}

void SimpleWideUnion::first(
        int32_t _first)
{
    m_first = _first;
    m__d = A;
}

int32_t SimpleWideUnion::first() const
{
    bool b = false;

    switch(m__d)
    {
        case A:
        b = true;
        break;
        default:
        break;
    }
    if(!b)
    {
        throw BadParamException("This member is not been selected");
    }

    return m_first;
}

int32_t& SimpleWideUnion::first()
{
    bool b = false;

    switch(m__d)
    {
        case A:
        b = true;
        break;
        default:
        break;
    }
    if(!b)
    {
        throw BadParamException("This member is not been selected");
    }

    return m_first;
}
void SimpleWideUnion::second(
        int64_t _second)
{
    m_second = _second;
    m__d = B;
}

int64_t SimpleWideUnion::second() const
{
    bool b = false;

    switch(m__d)
    {
        case B:
        b = true;
        break;
        default:
        break;
    }
    if(!b)
    {
        throw BadParamException("This member is not been selected");
    }

    return m_second;
}

int64_t& SimpleWideUnion::second()
{
    bool b = false;

    switch(m__d)
    {
        case B:
        b = true;
        break;
        default:
        break;
    }
    if(!b)
    {
        throw BadParamException("This member is not been selected");
    }

    return m_second;
}
void SimpleWideUnion::third(
        uint8_t _third)
{
    m_third = _third;
    m__d = D;
}

uint8_t SimpleWideUnion::third() const
{
    bool b = false;

    switch(m__d)
    {
        case D:
        b = true;
        break;
        default:
        break;
    }
    if(!b)
    {
        throw BadParamException("This member is not been selected");
    }

    return m_third;
}

uint8_t& SimpleWideUnion::third()
{
    bool b = false;

    switch(m__d)
    {
        case D:
        b = true;
        break;
        default:
        break;
    }
    if(!b)
    {
        throw BadParamException("This member is not been selected");
    }

    return m_third;
}

size_t SimpleWideUnion::calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const SimpleWideUnion& data,
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

    // TODO Member id del discriminador
    current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.m__d,
            current_alignment);

    switch(data.m__d)
    {
                        case A:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.m_first, current_alignment);
                        break;
                
                        case B:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                                data.m_second, current_alignment);
                        break;
                
                        case D:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3),
                                data.m_third, current_alignment);
                        break;
                
            default:
                break;
    }

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

void SimpleWideUnion::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
);

    scdr << eprosima::fastcdr::MemberId(0) << m__d;

    switch(m__d)
    {
        case A:
        scdr << eprosima::fastcdr::MemberId(1) << m_first;
        break;
        case B:
        scdr << eprosima::fastcdr::MemberId(2) << m_second;
        break;
        case D:
        scdr << eprosima::fastcdr::MemberId(3) << m_third;
        break;
        default:
        break;
    }

    scdr.end_serialize_type(current_state);
}

void SimpleWideUnion::deserialize(
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
                        dcdr >> m__d;
                        break;
                                        case 1:
                                            dcdr >> m_first;
                                            ret_value = false;
                                            break;
                                        
                                        case 2:
                                            dcdr >> m_second;
                                            ret_value = false;
                                            break;
                                        
                                        case 3:
                                            dcdr >> m_third;
                                            ret_value = false;
                                            break;
                                        
                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}


SimpleWideUnionStruct::SimpleWideUnionStruct()
{

    // Just to register all known types
    registerWideEnumTypes();
}

SimpleWideUnionStruct::~SimpleWideUnionStruct()
{
}

SimpleWideUnionStruct::SimpleWideUnionStruct(
        const SimpleWideUnionStruct& x)
{
    m_my_union = x.m_my_union;
}

SimpleWideUnionStruct::SimpleWideUnionStruct(
        SimpleWideUnionStruct&& x) noexcept 
{
    m_my_union = std::move(x.m_my_union);
}

SimpleWideUnionStruct& SimpleWideUnionStruct::operator =(
        const SimpleWideUnionStruct& x)
{

    m_my_union = x.m_my_union;

    return *this;
}

SimpleWideUnionStruct& SimpleWideUnionStruct::operator =(
        SimpleWideUnionStruct&& x) noexcept
{

    m_my_union = std::move(x.m_my_union);

    return *this;
}

bool SimpleWideUnionStruct::operator ==(
        const SimpleWideUnionStruct& x) const
{

    return (m_my_union == x.m_my_union);
}

bool SimpleWideUnionStruct::operator !=(
        const SimpleWideUnionStruct& x) const
{
    return !(*this == x);
}

size_t SimpleWideUnionStruct::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return SimpleWideUnionStruct_max_cdr_typesize;
}

size_t SimpleWideUnionStruct::calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const SimpleWideUnionStruct& data,
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


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.m_my_union, current_alignment);

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

void SimpleWideUnionStruct::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
);

    scdr << eprosima::fastcdr::MemberId(0) << m_my_union;

    scdr.end_serialize_type(current_state);
}

void SimpleWideUnionStruct::deserialize(
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
                        dcdr >> m_my_union;
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
 * @brief This function copies the value in member my_union
 * @param _my_union New value to be copied in member my_union
 */
void SimpleWideUnionStruct::my_union(
        const SimpleWideUnion& _my_union)
{
    m_my_union = _my_union;
}

/*!
 * @brief This function moves the value in member my_union
 * @param _my_union New value to be moved in member my_union
 */
void SimpleWideUnionStruct::my_union(
        SimpleWideUnion&& _my_union)
{
    m_my_union = std::move(_my_union);
}

/*!
 * @brief This function returns a constant reference to member my_union
 * @return Constant reference to member my_union
 */
const SimpleWideUnion& SimpleWideUnionStruct::my_union() const
{
    return m_my_union;
}

/*!
 * @brief This function returns a reference to member my_union
 * @return Reference to member my_union
 */
SimpleWideUnion& SimpleWideUnionStruct::my_union()
{
    return m_my_union;
}


size_t SimpleWideUnionStruct::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return SimpleWideUnionStruct_max_key_cdr_typesize;
}

bool SimpleWideUnionStruct::isKeyDefined()
{
    return false;
}

void SimpleWideUnionStruct::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
}
