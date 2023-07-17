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
 * @file Data1mb.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_DATA1MB_H_
#define _FAST_DDS_GENERATED_DATA1MB_H_


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
#if defined(DATA1MB_SOURCE)
#define DATA1MB_DllAPI __declspec( dllexport )
#else
#define DATA1MB_DllAPI __declspec( dllimport )
#endif // DATA1MB_SOURCE
#else
#define DATA1MB_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define DATA1MB_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
class CdrSizeCalculator;} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the structure Data1mb defined by the user in the IDL file.
 * @ingroup Data1mb
 */
class Data1mb
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Data1mb();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Data1mb();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Data1mb that will be copied.
     */
    eProsima_user_DllExport Data1mb(
            const Data1mb& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Data1mb that will be copied.
     */
    eProsima_user_DllExport Data1mb(
            Data1mb&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Data1mb that will be copied.
     */
    eProsima_user_DllExport Data1mb& operator =(
            const Data1mb& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Data1mb that will be copied.
     */
    eProsima_user_DllExport Data1mb& operator =(
            Data1mb&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x Data1mb object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const Data1mb& x) const;

    /*!
     * @brief Comparison operator.
     * @param x Data1mb object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const Data1mb& x) const;

    /*!
     * @brief This function copies the value in member data
     * @param _data New value to be copied in member data
     */
    eProsima_user_DllExport void data(
            const std::vector<uint8_t>& _data);

    /*!
     * @brief This function moves the value in member data
     * @param _data New value to be moved in member data
     */
    eProsima_user_DllExport void data(
            std::vector<uint8_t>&& _data);

    /*!
     * @brief This function returns a constant reference to member data
     * @return Constant reference to member data
     */
    eProsima_user_DllExport const std::vector<uint8_t>& data() const;

    /*!
     * @brief This function returns a reference to member data
     * @return Reference to member data
     */
    eProsima_user_DllExport std::vector<uint8_t>& data();



private:

    std::vector<uint8_t> m_data;

};

#endif // _FAST_DDS_GENERATED_DATA1MB_H_