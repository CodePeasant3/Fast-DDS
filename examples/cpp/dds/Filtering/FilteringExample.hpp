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
 * @file FilteringExample.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_FILTERINGEXAMPLE_HPP_
#define _FAST_DDS_GENERATED_FILTERINGEXAMPLE_HPP_

#include <cstdint>
#include <utility>

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
#if defined(FILTERINGEXAMPLE_SOURCE)
#define FILTERINGEXAMPLE_DllAPI __declspec( dllexport )
#else
#define FILTERINGEXAMPLE_DllAPI __declspec( dllimport )
#endif // FILTERINGEXAMPLE_SOURCE
#else
#define FILTERINGEXAMPLE_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define FILTERINGEXAMPLE_DllAPI
#endif // _WIN32

/*!
 * @brief This class represents the structure FilteringExample defined by the user in the IDL file.
 * @ingroup FilteringExample
 */
class FilteringExample
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport FilteringExample()
    {
    }

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~FilteringExample()
    {
    }

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object FilteringExample that will be copied.
     */
    eProsima_user_DllExport FilteringExample(
            const FilteringExample& x)
    {
                    m_sampleNumber = x.m_sampleNumber;

    }

    /*!
     * @brief Move constructor.
     * @param x Reference to the object FilteringExample that will be copied.
     */
    eProsima_user_DllExport FilteringExample(
            FilteringExample&& x) noexcept
    {
        m_sampleNumber = x.m_sampleNumber;
    }

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object FilteringExample that will be copied.
     */
    eProsima_user_DllExport FilteringExample& operator =(
            const FilteringExample& x)
    {

                    m_sampleNumber = x.m_sampleNumber;

        return *this;
    }

    /*!
     * @brief Move assignment.
     * @param x Reference to the object FilteringExample that will be copied.
     */
    eProsima_user_DllExport FilteringExample& operator =(
            FilteringExample&& x) noexcept
    {

        m_sampleNumber = x.m_sampleNumber;
        return *this;
    }

    /*!
     * @brief Comparison operator.
     * @param x FilteringExample object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const FilteringExample& x) const
    {
        return (m_sampleNumber == x.m_sampleNumber);
    }

    /*!
     * @brief Comparison operator.
     * @param x FilteringExample object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const FilteringExample& x) const
    {
        return !(*this == x);
    }

    /*!
     * @brief This function sets a value in member sampleNumber
     * @param _sampleNumber New value for member sampleNumber
     */
    eProsima_user_DllExport void sampleNumber(
            int32_t _sampleNumber)
    {
        m_sampleNumber = _sampleNumber;
    }

    /*!
     * @brief This function returns the value of member sampleNumber
     * @return Value of member sampleNumber
     */
    eProsima_user_DllExport int32_t sampleNumber() const
    {
        return m_sampleNumber;
    }

    /*!
     * @brief This function returns a reference to member sampleNumber
     * @return Reference to member sampleNumber
     */
    eProsima_user_DllExport int32_t& sampleNumber()
    {
        return m_sampleNumber;
    }



private:

    int32_t m_sampleNumber{0};

};

#endif // _FAST_DDS_GENERATED_FILTERINGEXAMPLE_HPP_


