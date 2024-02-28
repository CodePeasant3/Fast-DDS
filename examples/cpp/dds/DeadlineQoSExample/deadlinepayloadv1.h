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
 * @file deadlinepayload.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#include <fastcdr/config.h>

#if FASTCDR_VERSION_MAJOR == 1

#ifndef _FAST_DDS_GENERATED_DEADLINEPAYLOAD_H_
#define _FAST_DDS_GENERATED_DEADLINEPAYLOAD_H_


#include <fastcdr/cdr/fixed_size_string.hpp>

#include <array>
#include <bitset>
#include <cstdint>
#include <map>
#include <stdint.h>
#include <string>
#include <vector>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(DEADLINEPAYLOAD_SOURCE)
#define DEADLINEPAYLOAD_DllAPI __declspec( dllexport )
#else
#define DEADLINEPAYLOAD_DllAPI __declspec( dllimport )
#endif // DEADLINEPAYLOAD_SOURCE
#else
#define DEADLINEPAYLOAD_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define DEADLINEPAYLOAD_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima





/*!
 * @brief This class represents the structure HelloMsg defined by the user in the IDL file.
 * @ingroup deadlinepayload
 */
class HelloMsg
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport HelloMsg();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~HelloMsg();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object HelloMsg that will be copied.
     */
    eProsima_user_DllExport HelloMsg(
            const HelloMsg& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object HelloMsg that will be copied.
     */
    eProsima_user_DllExport HelloMsg(
            HelloMsg&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object HelloMsg that will be copied.
     */
    eProsima_user_DllExport HelloMsg& operator =(
            const HelloMsg& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object HelloMsg that will be copied.
     */
    eProsima_user_DllExport HelloMsg& operator =(
            HelloMsg&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x HelloMsg object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const HelloMsg& x) const;

    /*!
     * @brief Comparison operator.
     * @param x HelloMsg object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const HelloMsg& x) const;

    /*!
     * @brief This function sets a value in member deadlinekey
     * @param _deadlinekey New value for member deadlinekey
     */
    eProsima_user_DllExport void deadlinekey(
            uint16_t _deadlinekey);

    /*!
     * @brief This function returns the value of member deadlinekey
     * @return Value of member deadlinekey
     */
    eProsima_user_DllExport uint16_t deadlinekey() const;

    /*!
     * @brief This function returns a reference to member deadlinekey
     * @return Reference to member deadlinekey
     */
    eProsima_user_DllExport uint16_t& deadlinekey();


    /*!
     * @brief This function copies the value in member payload
     * @param _payload New value to be copied in member payload
     */
    eProsima_user_DllExport void payload(
            const eprosima::fastcdr::fixed_string<256>& _payload);

    /*!
     * @brief This function moves the value in member payload
     * @param _payload New value to be moved in member payload
     */
    eProsima_user_DllExport void payload(
            eprosima::fastcdr::fixed_string<256>&& _payload);

    /*!
     * @brief This function returns a constant reference to member payload
     * @return Constant reference to member payload
     */
    eProsima_user_DllExport const eprosima::fastcdr::fixed_string<256>& payload() const;

    /*!
     * @brief This function returns a reference to member payload
     * @return Reference to member payload
     */
    eProsima_user_DllExport eprosima::fastcdr::fixed_string<256>& payload();


    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const HelloMsg& data,
            size_t current_alignment = 0);



    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
            eprosima::fastcdr::Cdr& cdr);




    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;

private:

    uint16_t m_deadlinekey;
    eprosima::fastcdr::fixed_string<256> m_payload;

};


#endif // _FAST_DDS_GENERATED_DEADLINEPAYLOAD_H_



#endif // FASTCDR_VERSION_MAJOR == 1
