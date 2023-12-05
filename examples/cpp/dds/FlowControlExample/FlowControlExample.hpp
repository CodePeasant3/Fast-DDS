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
 * @file FlowControlExample.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_FLOWCONTROLEXAMPLE_HPP_
#define _FAST_DDS_GENERATED_FLOWCONTROLEXAMPLE_HPP_

#include <array>
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
    eProsima_user_DllExport FlowControlExample()
    {
    }

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~FlowControlExample()
    {
    }

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object FlowControlExample that will be copied.
     */
    eProsima_user_DllExport FlowControlExample(
            const FlowControlExample& x)
    {
        m_message = x.m_message;

        m_wasFast = x.m_wasFast;

    }

    /*!
     * @brief Move constructor.
     * @param x Reference to the object FlowControlExample that will be copied.
     */
    eProsima_user_DllExport FlowControlExample(
            FlowControlExample&& x) noexcept
    {
        m_message = std::move(x.m_message);
        m_wasFast = x.m_wasFast;
    }

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object FlowControlExample that will be copied.
     */
    eProsima_user_DllExport FlowControlExample& operator =(
            const FlowControlExample& x)
    {

        m_message = x.m_message;

        m_wasFast = x.m_wasFast;

        return *this;
    }

    /*!
     * @brief Move assignment.
     * @param x Reference to the object FlowControlExample that will be copied.
     */
    eProsima_user_DllExport FlowControlExample& operator =(
            FlowControlExample&& x) noexcept
    {

        m_message = std::move(x.m_message);
        m_wasFast = x.m_wasFast;
        return *this;
    }

    /*!
     * @brief Comparison operator.
     * @param x FlowControlExample object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const FlowControlExample& x) const
    {
        return (m_message == x.m_message &&
               m_wasFast == x.m_wasFast);
    }

    /*!
     * @brief Comparison operator.
     * @param x FlowControlExample object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const FlowControlExample& x) const
    {
        return !(*this == x);
    }

    /*!
     * @brief This function copies the value in member message
     * @param _message New value to be copied in member message
     */
    eProsima_user_DllExport void message(
            const std::array<char, 600000>& _message)
    {
        m_message = _message;
    }

    /*!
     * @brief This function moves the value in member message
     * @param _message New value to be moved in member message
     */
    eProsima_user_DllExport void message(
            std::array<char, 600000>&& _message)
    {
        m_message = std::move(_message);
    }

    /*!
     * @brief This function returns a constant reference to member message
     * @return Constant reference to member message
     */
    eProsima_user_DllExport const std::array<char, 600000>& message() const
    {
        return m_message;
    }

    /*!
     * @brief This function returns a reference to member message
     * @return Reference to member message
     */
    eProsima_user_DllExport std::array<char, 600000>& message()
    {
        return m_message;
    }

    /*!
     * @brief This function sets a value in member wasFast
     * @param _wasFast New value for member wasFast
     */
    eProsima_user_DllExport void wasFast(
            char _wasFast)
    {
        m_wasFast = _wasFast;
    }

    /*!
     * @brief This function returns the value of member wasFast
     * @return Value of member wasFast
     */
    eProsima_user_DllExport char wasFast() const
    {
        return m_wasFast;
    }

    /*!
     * @brief This function returns a reference to member wasFast
     * @return Reference to member wasFast
     */
    eProsima_user_DllExport char& wasFast()
    {
        return m_wasFast;
    }

private:

    std::array<char, 600000> m_message;
    char m_wasFast{0};

};

#endif // _FAST_DDS_GENERATED_FLOWCONTROLEXAMPLE_HPP_


