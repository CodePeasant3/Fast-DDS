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
 * @file deadlinepayload.cpp
 * This source file contains the implementation of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "deadlinepayload.h"

#if FASTCDR_VERSION_MAJOR == 1

#include <fastcdr/Cdr.h>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

namespace helper { namespace internal {

enum class Size {
    UInt8,
    UInt16,
    UInt32,
    UInt64,
};

constexpr Size get_size(int s) {
    return (s <= 8 ) ? Size::UInt8:
           (s <= 16) ? Size::UInt16:
           (s <= 32) ? Size::UInt32: Size::UInt64;
}

template<Size s>
struct FindTypeH;

template<>
struct FindTypeH<Size::UInt8> {
    using type = std::uint8_t;
};

template<>
struct FindTypeH<Size::UInt16> {
    using type = std::uint16_t;
};

template<>
struct FindTypeH<Size::UInt32> {
    using type = std::uint32_t;
};

template<>
struct FindTypeH<Size::UInt64> {
    using type = std::uint64_t;
};
}

template<int S>
struct FindType {
    using type = typename internal::FindTypeH<internal::get_size(S)>::type;
};
}

#define HelloMsg_max_cdr_typesize 269ULL;




HelloMsg::HelloMsg()
{
    // unsigned short m_deadlinekey
    m_deadlinekey = 0;
    // /type_d() m_payload


}

HelloMsg::~HelloMsg()
{
}

HelloMsg::HelloMsg(
        const HelloMsg& x)
{
    m_deadlinekey = x.m_deadlinekey;


    m_payload = x.m_payload;

}

HelloMsg::HelloMsg(
        HelloMsg&& x) noexcept
{
    m_deadlinekey = x.m_deadlinekey;


    m_payload = std::move(x.m_payload);

}

HelloMsg& HelloMsg::operator =(
        const HelloMsg& x)
{
    m_deadlinekey = x.m_deadlinekey;


    m_payload = x.m_payload;

    return *this;
}

HelloMsg& HelloMsg::operator =(
        HelloMsg&& x) noexcept
{
    m_deadlinekey = x.m_deadlinekey;


    m_payload = std::move(x.m_payload);

    return *this;
}

bool HelloMsg::operator ==(
        const HelloMsg& x) const
{
    return (m_deadlinekey == x.m_deadlinekey &&
           m_payload == x.m_payload);
}

bool HelloMsg::operator !=(
        const HelloMsg& x) const
{
    return !(*this == x);
}

size_t HelloMsg::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return HelloMsg_max_cdr_typesize;
}

size_t HelloMsg::getCdrSerializedSize(
        const HelloMsg& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;

    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.payload().size() + 1;


    return current_alignment - initial_alignment;
}


void HelloMsg::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{
    scdr << m_deadlinekey;

    scdr << m_payload.c_str();

}

void HelloMsg::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{
    dcdr >> m_deadlinekey;



    {
        std::string aux;
        dcdr >> aux;
        m_payload = aux.c_str();
    }


}


bool HelloMsg::isKeyDefined()
{
    return true;
}

void HelloMsg::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;

    scdr << m_deadlinekey;


}

/*!
 * @brief This function sets a value in member deadlinekey
 * @param _deadlinekey New value for member deadlinekey
 */
void HelloMsg::deadlinekey(
        uint16_t _deadlinekey)
{
    m_deadlinekey = _deadlinekey;
}

/*!
 * @brief This function returns the value of member deadlinekey
 * @return Value of member deadlinekey
 */
uint16_t HelloMsg::deadlinekey() const
{
    return m_deadlinekey;
}

/*!
 * @brief This function returns a reference to member deadlinekey
 * @return Reference to member deadlinekey
 */
uint16_t& HelloMsg::deadlinekey()
{
    return m_deadlinekey;
}


/*!
 * @brief This function copies the value in member payload
 * @param _payload New value to be copied in member payload
 */
void HelloMsg::payload(
        const eprosima::fastcdr::fixed_string<256>& _payload)
{
    m_payload = _payload;
}

/*!
 * @brief This function moves the value in member payload
 * @param _payload New value to be moved in member payload
 */
void HelloMsg::payload(
        eprosima::fastcdr::fixed_string<256>&& _payload)
{
    m_payload = std::move(_payload);
}

/*!
 * @brief This function returns a constant reference to member payload
 * @return Constant reference to member payload
 */
const eprosima::fastcdr::fixed_string<256>& HelloMsg::payload() const
{
    return m_payload;
}

/*!
 * @brief This function returns a reference to member payload
 * @return Reference to member payload
 */
eprosima::fastcdr::fixed_string<256>& HelloMsg::payload()
{
    return m_payload;
}




#endif // FASTCDR_VERSION_MAJOR == 1
