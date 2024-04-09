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
 * @file Configuration.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_CONFIGURATION_H_
#define _FAST_DDS_GENERATED_CONFIGURATION_H_

#include <array>
#include <bitset>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include <fastcdr/cdr/fixed_size_string.hpp>
#include <fastcdr/xcdr/external.hpp>
#include <fastcdr/xcdr/optional.hpp>



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
#if defined(CONFIGURATION_SOURCE)
#define CONFIGURATION_DllAPI __declspec( dllexport )
#else
#define CONFIGURATION_DllAPI __declspec( dllimport )
#endif // CONFIGURATION_SOURCE
#else
#define CONFIGURATION_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define CONFIGURATION_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
class CdrSizeCalculator;
} // namespace fastcdr
} // namespace eprosima







/*!
 * @brief This class represents the structure Configuration defined by the user in the IDL file.
 * @ingroup Configuration
 */
class Configuration
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Configuration();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Configuration();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Configuration that will be copied.
     */
    eProsima_user_DllExport Configuration(
            const Configuration& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Configuration that will be copied.
     */
    eProsima_user_DllExport Configuration(
            Configuration&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Configuration that will be copied.
     */
    eProsima_user_DllExport Configuration& operator =(
            const Configuration& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Configuration that will be copied.
     */
    eProsima_user_DllExport Configuration& operator =(
            Configuration&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x Configuration object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const Configuration& x) const;

    /*!
     * @brief Comparison operator.
     * @param x Configuration object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const Configuration& x) const;

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
            const std::array<char, 20>& _message);

    /*!
     * @brief This function moves the value in member message
     * @param _message New value to be moved in member message
     */
    eProsima_user_DllExport void message(
            std::array<char, 20>&& _message);

    /*!
     * @brief This function returns a constant reference to member message
     * @return Constant reference to member message
     */
    eProsima_user_DllExport const std::array<char, 20>& message() const;

    /*!
     * @brief This function returns a reference to member message
     * @return Reference to member message
     */
    eProsima_user_DllExport std::array<char, 20>& message();


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

    uint32_t m_index{0};
    std::array<char, 20> m_message{0};
    std::vector<uint8_t> m_data;

};

#endif // _FAST_DDS_GENERATED_CONFIGURATION_H_



