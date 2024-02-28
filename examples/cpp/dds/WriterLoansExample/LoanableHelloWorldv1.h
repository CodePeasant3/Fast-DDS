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
 * @file LoanableHelloWorld.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#include <fastcdr/config.h>

#if FASTCDR_VERSION_MAJOR == 1

#ifndef _FAST_DDS_GENERATED_LOANABLEHELLOWORLD_H_
#define _FAST_DDS_GENERATED_LOANABLEHELLOWORLD_H_


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
#if defined(LOANABLEHELLOWORLD_SOURCE)
#define LOANABLEHELLOWORLD_DllAPI __declspec( dllexport )
#else
#define LOANABLEHELLOWORLD_DllAPI __declspec( dllimport )
#endif // LOANABLEHELLOWORLD_SOURCE
#else
#define LOANABLEHELLOWORLD_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define LOANABLEHELLOWORLD_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima





/*!
 * @brief This class represents the structure LoanableHelloWorld defined by the user in the IDL file.
 * @ingroup LoanableHelloWorld
 */
class LoanableHelloWorld
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport LoanableHelloWorld();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~LoanableHelloWorld();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object LoanableHelloWorld that will be copied.
     */
    eProsima_user_DllExport LoanableHelloWorld(
            const LoanableHelloWorld& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object LoanableHelloWorld that will be copied.
     */
    eProsima_user_DllExport LoanableHelloWorld(
            LoanableHelloWorld&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object LoanableHelloWorld that will be copied.
     */
    eProsima_user_DllExport LoanableHelloWorld& operator =(
            const LoanableHelloWorld& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object LoanableHelloWorld that will be copied.
     */
    eProsima_user_DllExport LoanableHelloWorld& operator =(
            LoanableHelloWorld&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x LoanableHelloWorld object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const LoanableHelloWorld& x) const;

    /*!
     * @brief Comparison operator.
     * @param x LoanableHelloWorld object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const LoanableHelloWorld& x) const;

    /*!
     * @brief This function sets a value in member index
     * @param _index New value for member index
     */
    eProsima_user_DllExport void index(
            uint32_t _index);

    /*!
     * @brief This function returns the value of member index
     * @return Value of member index
     */
    eProsima_user_DllExport uint32_t index() const;

    /*!
     * @brief This function returns a reference to member index
     * @return Reference to member index
     */
    eProsima_user_DllExport uint32_t& index();


    /*!
     * @brief This function copies the value in member message
     * @param _message New value to be copied in member message
     */
    eProsima_user_DllExport void message(
            const std::array<char, 256>& _message);

    /*!
     * @brief This function moves the value in member message
     * @param _message New value to be moved in member message
     */
    eProsima_user_DllExport void message(
            std::array<char, 256>&& _message);

    /*!
     * @brief This function returns a constant reference to member message
     * @return Constant reference to member message
     */
    eProsima_user_DllExport const std::array<char, 256>& message() const;

    /*!
     * @brief This function returns a reference to member message
     * @return Reference to member message
     */
    eProsima_user_DllExport std::array<char, 256>& message();


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
            const LoanableHelloWorld& data,
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

    uint32_t m_index;
    std::array<char, 256> m_message;

};


#endif // _FAST_DDS_GENERATED_LOANABLEHELLOWORLD_H_



#endif // FASTCDR_VERSION_MAJOR == 1
