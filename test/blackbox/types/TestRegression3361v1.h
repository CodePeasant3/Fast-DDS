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
 * @file TestRegression3361.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#include <fastcdr/config.h>

#if FASTCDR_VERSION_MAJOR == 1

#ifndef _FAST_DDS_GENERATED_TESTREGRESSION3361_H_
#define _FAST_DDS_GENERATED_TESTREGRESSION3361_H_

#include "TestIncludeRegression3361.h"

#include <fastrtps/utils/fixed_size_string.hpp>

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
#if defined(TESTREGRESSION3361_SOURCE)
#define TESTREGRESSION3361_DllAPI __declspec( dllexport )
#else
#define TESTREGRESSION3361_DllAPI __declspec( dllimport )
#endif // TESTREGRESSION3361_SOURCE
#else
#define TESTREGRESSION3361_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define TESTREGRESSION3361_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima





/*!
 * @brief This class represents the structure TestRegression3361 defined by the user in the IDL file.
 * @ingroup TestRegression3361
 */
class TestRegression3361
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport TestRegression3361();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~TestRegression3361();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object TestRegression3361 that will be copied.
     */
    eProsima_user_DllExport TestRegression3361(
            const TestRegression3361& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object TestRegression3361 that will be copied.
     */
    eProsima_user_DllExport TestRegression3361(
            TestRegression3361&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object TestRegression3361 that will be copied.
     */
    eProsima_user_DllExport TestRegression3361& operator =(
            const TestRegression3361& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object TestRegression3361 that will be copied.
     */
    eProsima_user_DllExport TestRegression3361& operator =(
            TestRegression3361&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x TestRegression3361 object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const TestRegression3361& x) const;

    /*!
     * @brief Comparison operator.
     * @param x TestRegression3361 object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const TestRegression3361& x) const;

    /*!
     * @brief This function copies the value in member uuid
     * @param _uuid New value to be copied in member uuid
     */
    eProsima_user_DllExport void uuid(
            const TestModule::MACHINEID& _uuid);

    /*!
     * @brief This function moves the value in member uuid
     * @param _uuid New value to be moved in member uuid
     */
    eProsima_user_DllExport void uuid(
            TestModule::MACHINEID&& _uuid);

    /*!
     * @brief This function returns a constant reference to member uuid
     * @return Constant reference to member uuid
     */
    eProsima_user_DllExport const TestModule::MACHINEID& uuid() const;

    /*!
     * @brief This function returns a reference to member uuid
     * @return Reference to member uuid
     */
    eProsima_user_DllExport TestModule::MACHINEID& uuid();


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
            const TestRegression3361& data,
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

    TestModule::MACHINEID m_uuid;

};


#endif // _FAST_DDS_GENERATED_TESTREGRESSION3361_H_



#endif // FASTCDR_VERSION_MAJOR == 1
