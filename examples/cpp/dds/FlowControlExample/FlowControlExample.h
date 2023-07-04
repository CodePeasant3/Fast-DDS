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
 * @file FlowControlExample.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_FLOWCONTROLEXAMPLE_H_
#define _FAST_DDS_GENERATED_FLOWCONTROLEXAMPLE_H_


#include <fastcdr/CdrSizeCalculator.hpp>
#include <fastcdr/cdr/fixed_size_string.hpp>
#include <fastcdr/xcdr/optional.hpp>

#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

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
#if defined(FLOWCONTROLEXAMPLE_SOURCE)
#define FLOWCONTROLEXAMPLE_DllAPI __declspec( dllexport )
#else
#define FLOWCONTROLEXAMPLE_DllAPI __declspec( dllimport )
#endif // FLOWCONTROLEXAMPLE_SOURCE
#else
#define FLOWCONTROLEXAMPLE_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define FLOWCONTROLEXAMPLE_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the structure FlowControlExample defined by the user in the IDL file.
 * @ingroup FlowControlExample
 */
class FlowControlExample
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport FlowControlExample();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~FlowControlExample();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object FlowControlExample that will be copied.
     */
    eProsima_user_DllExport FlowControlExample(
            const FlowControlExample& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object FlowControlExample that will be copied.
     */
    eProsima_user_DllExport FlowControlExample(
            FlowControlExample&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object FlowControlExample that will be copied.
     */
    eProsima_user_DllExport FlowControlExample& operator =(
            const FlowControlExample& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object FlowControlExample that will be copied.
     */
    eProsima_user_DllExport FlowControlExample& operator =(
            FlowControlExample&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x FlowControlExample object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const FlowControlExample& x) const;

    /*!
     * @brief Comparison operator.
     * @param x FlowControlExample object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const FlowControlExample& x) const;

    /*!
     * @brief This function copies the value in member message
     * @param _message New value to be copied in member message
     */
    eProsima_user_DllExport void message(
            const std::array<char, 600000>& _message);

    /*!
     * @brief This function moves the value in member message
     * @param _message New value to be moved in member message
     */
    eProsima_user_DllExport void message(
            std::array<char, 600000>&& _message);

    /*!
     * @brief This function returns a constant reference to member message
     * @return Constant reference to member message
     */
    eProsima_user_DllExport const std::array<char, 600000>& message() const;

    /*!
     * @brief This function returns a reference to member message
     * @return Reference to member message
     */
    eProsima_user_DllExport std::array<char, 600000>& message();
    /*!
     * @brief This function sets a value in member wasFast
     * @param _wasFast New value for member wasFast
     */
    eProsima_user_DllExport void wasFast(
            char _wasFast);

    /*!
     * @brief This function returns the value of member wasFast
     * @return Value of member wasFast
     */
    eProsima_user_DllExport char wasFast() const;

    /*!
     * @brief This function returns a reference to member wasFast
     * @return Reference to member wasFast
     */
    eProsima_user_DllExport char& wasFast();


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
    eProsima_user_DllExport static size_t calculate_serialized_size(
            eprosima::fastcdr::CdrSizeCalculator& calculator,
            const FlowControlExample& data,
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
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
            size_t current_alignment = 0);

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

    std::array<char, 600000> m_message{0};
    char m_wasFast{0};

};

#endif // _FAST_DDS_GENERATED_FLOWCONTROLEXAMPLE_H_