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
 * @file bitsets.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_BITSETS_HPP_
#define _FAST_DDS_GENERATED_BITSETS_HPP_

#include <cstdint>
#include <utility>
#include "helpers/basic_inner_types.hpp"

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
#if defined(BITSETS_SOURCE)
#define BITSETS_DllAPI __declspec( dllexport )
#else
#define BITSETS_DllAPI __declspec( dllimport )
#endif // BITSETS_SOURCE
#else
#define BITSETS_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define BITSETS_DllAPI
#endif // _WIN32

/*!
 * @brief This structure represents the bitset InnerTypedBitsetHelper defined by the user in the IDL file.
 * @ingroup bitsets
 */
struct InnerTypedBitsetHelper
{
        bool boolean_bitfield : 1;

        uint8_t byte_bitfield : 8;

        int8_t int8_bitfield : 8;

        uint8_t uint8_bitfield : 8;

        int16_t short_bitfield : 16;

        uint16_t ushort_bitfield : 16;


    /*!
     * @brief Comparison operator.
     * @param x InnerTypedBitsetHelper object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const InnerTypedBitsetHelper& x) const
    {
        return (boolean_bitfield == x.boolean_bitfield &&
           byte_bitfield == x.byte_bitfield &&
           int8_bitfield == x.int8_bitfield &&
           uint8_bitfield == x.uint8_bitfield &&
           short_bitfield == x.short_bitfield &&
           ushort_bitfield == x.ushort_bitfield);
    }

    /*!
     * @brief Comparison operator.
     * @param x InnerTypedBitsetHelper object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const InnerTypedBitsetHelper& x) const
    {
        return !(*this == x);
    }
};
/*!
 * @brief This structure represents the bitset InnerTypedBitsetHelper2 defined by the user in the IDL file.
 * @ingroup bitsets
 */
struct InnerTypedBitsetHelper2
{
        int32_t long_bitfield : 32;

        uint32_t ulong_bitfield : 32;


    /*!
     * @brief Comparison operator.
     * @param x InnerTypedBitsetHelper2 object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const InnerTypedBitsetHelper2& x) const
    {
        return (long_bitfield == x.long_bitfield &&
           ulong_bitfield == x.ulong_bitfield);
    }

    /*!
     * @brief Comparison operator.
     * @param x InnerTypedBitsetHelper2 object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const InnerTypedBitsetHelper2& x) const
    {
        return !(*this == x);
    }
};
/*!
 * @brief This structure represents the bitset InnerTypedBitsetHelper3 defined by the user in the IDL file.
 * @ingroup bitsets
 */
struct InnerTypedBitsetHelper3
{
        int64_t long_long_bitfield : 64;


    /*!
     * @brief Comparison operator.
     * @param x InnerTypedBitsetHelper3 object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const InnerTypedBitsetHelper3& x) const
    {
        return (long_long_bitfield == x.long_long_bitfield);
    }

    /*!
     * @brief Comparison operator.
     * @param x InnerTypedBitsetHelper3 object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const InnerTypedBitsetHelper3& x) const
    {
        return !(*this == x);
    }
};
/*!
 * @brief This structure represents the bitset InnerTypedBitsetHelper4 defined by the user in the IDL file.
 * @ingroup bitsets
 */
struct InnerTypedBitsetHelper4
{
        uint64_t ulong_long_bitfield : 64;


    /*!
     * @brief Comparison operator.
     * @param x InnerTypedBitsetHelper4 object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const InnerTypedBitsetHelper4& x) const
    {
        return (ulong_long_bitfield == x.ulong_long_bitfield);
    }

    /*!
     * @brief Comparison operator.
     * @param x InnerTypedBitsetHelper4 object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const InnerTypedBitsetHelper4& x) const
    {
        return !(*this == x);
    }
};
/*!
 * @brief This class represents the structure BitsetStruct defined by the user in the IDL file.
 * @ingroup bitsets
 */
class BitsetStruct
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport BitsetStruct()
    {
    }

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~BitsetStruct()
    {
    }

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object BitsetStruct that will be copied.
     */
    eProsima_user_DllExport BitsetStruct(
            const BitsetStruct& x)
    {
                    m_var_InnerBitsetHelper = x.m_var_InnerBitsetHelper;

                    m_var_InnerTypedBitsetHelper = x.m_var_InnerTypedBitsetHelper;

                    m_var_InnerTypedBitsetHelper2 = x.m_var_InnerTypedBitsetHelper2;

                    m_var_InnerTypedBitsetHelper3 = x.m_var_InnerTypedBitsetHelper3;

                    m_var_InnerTypedBitsetHelper4 = x.m_var_InnerTypedBitsetHelper4;

    }

    /*!
     * @brief Move constructor.
     * @param x Reference to the object BitsetStruct that will be copied.
     */
    eProsima_user_DllExport BitsetStruct(
            BitsetStruct&& x) noexcept
    {
        m_var_InnerBitsetHelper = std::move(x.m_var_InnerBitsetHelper);
        m_var_InnerTypedBitsetHelper = std::move(x.m_var_InnerTypedBitsetHelper);
        m_var_InnerTypedBitsetHelper2 = std::move(x.m_var_InnerTypedBitsetHelper2);
        m_var_InnerTypedBitsetHelper3 = std::move(x.m_var_InnerTypedBitsetHelper3);
        m_var_InnerTypedBitsetHelper4 = std::move(x.m_var_InnerTypedBitsetHelper4);
    }

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object BitsetStruct that will be copied.
     */
    eProsima_user_DllExport BitsetStruct& operator =(
            const BitsetStruct& x)
    {

                    m_var_InnerBitsetHelper = x.m_var_InnerBitsetHelper;

                    m_var_InnerTypedBitsetHelper = x.m_var_InnerTypedBitsetHelper;

                    m_var_InnerTypedBitsetHelper2 = x.m_var_InnerTypedBitsetHelper2;

                    m_var_InnerTypedBitsetHelper3 = x.m_var_InnerTypedBitsetHelper3;

                    m_var_InnerTypedBitsetHelper4 = x.m_var_InnerTypedBitsetHelper4;

        return *this;
    }

    /*!
     * @brief Move assignment.
     * @param x Reference to the object BitsetStruct that will be copied.
     */
    eProsima_user_DllExport BitsetStruct& operator =(
            BitsetStruct&& x) noexcept
    {

        m_var_InnerBitsetHelper = std::move(x.m_var_InnerBitsetHelper);
        m_var_InnerTypedBitsetHelper = std::move(x.m_var_InnerTypedBitsetHelper);
        m_var_InnerTypedBitsetHelper2 = std::move(x.m_var_InnerTypedBitsetHelper2);
        m_var_InnerTypedBitsetHelper3 = std::move(x.m_var_InnerTypedBitsetHelper3);
        m_var_InnerTypedBitsetHelper4 = std::move(x.m_var_InnerTypedBitsetHelper4);
        return *this;
    }

    /*!
     * @brief Comparison operator.
     * @param x BitsetStruct object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const BitsetStruct& x) const
    {
        return (m_var_InnerBitsetHelper == x.m_var_InnerBitsetHelper &&
           m_var_InnerTypedBitsetHelper == x.m_var_InnerTypedBitsetHelper &&
           m_var_InnerTypedBitsetHelper2 == x.m_var_InnerTypedBitsetHelper2 &&
           m_var_InnerTypedBitsetHelper3 == x.m_var_InnerTypedBitsetHelper3 &&
           m_var_InnerTypedBitsetHelper4 == x.m_var_InnerTypedBitsetHelper4);
    }

    /*!
     * @brief Comparison operator.
     * @param x BitsetStruct object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const BitsetStruct& x) const
    {
        return !(*this == x);
    }

    /*!
     * @brief This function copies the value in member var_InnerBitsetHelper
     * @param _var_InnerBitsetHelper New value to be copied in member var_InnerBitsetHelper
     */
    eProsima_user_DllExport void var_InnerBitsetHelper(
            const InnerBitsetHelper& _var_InnerBitsetHelper)
    {
        m_var_InnerBitsetHelper = _var_InnerBitsetHelper;
    }

    /*!
     * @brief This function moves the value in member var_InnerBitsetHelper
     * @param _var_InnerBitsetHelper New value to be moved in member var_InnerBitsetHelper
     */
    eProsima_user_DllExport void var_InnerBitsetHelper(
            InnerBitsetHelper&& _var_InnerBitsetHelper)
    {
        m_var_InnerBitsetHelper = std::move(_var_InnerBitsetHelper);
    }

    /*!
     * @brief This function returns a constant reference to member var_InnerBitsetHelper
     * @return Constant reference to member var_InnerBitsetHelper
     */
    eProsima_user_DllExport const InnerBitsetHelper& var_InnerBitsetHelper() const
    {
        return m_var_InnerBitsetHelper;
    }

    /*!
     * @brief This function returns a reference to member var_InnerBitsetHelper
     * @return Reference to member var_InnerBitsetHelper
     */
    eProsima_user_DllExport InnerBitsetHelper& var_InnerBitsetHelper()
    {
        return m_var_InnerBitsetHelper;
    }


    /*!
     * @brief This function copies the value in member var_InnerTypedBitsetHelper
     * @param _var_InnerTypedBitsetHelper New value to be copied in member var_InnerTypedBitsetHelper
     */
    eProsima_user_DllExport void var_InnerTypedBitsetHelper(
            const InnerTypedBitsetHelper& _var_InnerTypedBitsetHelper)
    {
        m_var_InnerTypedBitsetHelper = _var_InnerTypedBitsetHelper;
    }

    /*!
     * @brief This function moves the value in member var_InnerTypedBitsetHelper
     * @param _var_InnerTypedBitsetHelper New value to be moved in member var_InnerTypedBitsetHelper
     */
    eProsima_user_DllExport void var_InnerTypedBitsetHelper(
            InnerTypedBitsetHelper&& _var_InnerTypedBitsetHelper)
    {
        m_var_InnerTypedBitsetHelper = std::move(_var_InnerTypedBitsetHelper);
    }

    /*!
     * @brief This function returns a constant reference to member var_InnerTypedBitsetHelper
     * @return Constant reference to member var_InnerTypedBitsetHelper
     */
    eProsima_user_DllExport const InnerTypedBitsetHelper& var_InnerTypedBitsetHelper() const
    {
        return m_var_InnerTypedBitsetHelper;
    }

    /*!
     * @brief This function returns a reference to member var_InnerTypedBitsetHelper
     * @return Reference to member var_InnerTypedBitsetHelper
     */
    eProsima_user_DllExport InnerTypedBitsetHelper& var_InnerTypedBitsetHelper()
    {
        return m_var_InnerTypedBitsetHelper;
    }


    /*!
     * @brief This function copies the value in member var_InnerTypedBitsetHelper2
     * @param _var_InnerTypedBitsetHelper2 New value to be copied in member var_InnerTypedBitsetHelper2
     */
    eProsima_user_DllExport void var_InnerTypedBitsetHelper2(
            const InnerTypedBitsetHelper2& _var_InnerTypedBitsetHelper2)
    {
        m_var_InnerTypedBitsetHelper2 = _var_InnerTypedBitsetHelper2;
    }

    /*!
     * @brief This function moves the value in member var_InnerTypedBitsetHelper2
     * @param _var_InnerTypedBitsetHelper2 New value to be moved in member var_InnerTypedBitsetHelper2
     */
    eProsima_user_DllExport void var_InnerTypedBitsetHelper2(
            InnerTypedBitsetHelper2&& _var_InnerTypedBitsetHelper2)
    {
        m_var_InnerTypedBitsetHelper2 = std::move(_var_InnerTypedBitsetHelper2);
    }

    /*!
     * @brief This function returns a constant reference to member var_InnerTypedBitsetHelper2
     * @return Constant reference to member var_InnerTypedBitsetHelper2
     */
    eProsima_user_DllExport const InnerTypedBitsetHelper2& var_InnerTypedBitsetHelper2() const
    {
        return m_var_InnerTypedBitsetHelper2;
    }

    /*!
     * @brief This function returns a reference to member var_InnerTypedBitsetHelper2
     * @return Reference to member var_InnerTypedBitsetHelper2
     */
    eProsima_user_DllExport InnerTypedBitsetHelper2& var_InnerTypedBitsetHelper2()
    {
        return m_var_InnerTypedBitsetHelper2;
    }


    /*!
     * @brief This function copies the value in member var_InnerTypedBitsetHelper3
     * @param _var_InnerTypedBitsetHelper3 New value to be copied in member var_InnerTypedBitsetHelper3
     */
    eProsima_user_DllExport void var_InnerTypedBitsetHelper3(
            const InnerTypedBitsetHelper3& _var_InnerTypedBitsetHelper3)
    {
        m_var_InnerTypedBitsetHelper3 = _var_InnerTypedBitsetHelper3;
    }

    /*!
     * @brief This function moves the value in member var_InnerTypedBitsetHelper3
     * @param _var_InnerTypedBitsetHelper3 New value to be moved in member var_InnerTypedBitsetHelper3
     */
    eProsima_user_DllExport void var_InnerTypedBitsetHelper3(
            InnerTypedBitsetHelper3&& _var_InnerTypedBitsetHelper3)
    {
        m_var_InnerTypedBitsetHelper3 = std::move(_var_InnerTypedBitsetHelper3);
    }

    /*!
     * @brief This function returns a constant reference to member var_InnerTypedBitsetHelper3
     * @return Constant reference to member var_InnerTypedBitsetHelper3
     */
    eProsima_user_DllExport const InnerTypedBitsetHelper3& var_InnerTypedBitsetHelper3() const
    {
        return m_var_InnerTypedBitsetHelper3;
    }

    /*!
     * @brief This function returns a reference to member var_InnerTypedBitsetHelper3
     * @return Reference to member var_InnerTypedBitsetHelper3
     */
    eProsima_user_DllExport InnerTypedBitsetHelper3& var_InnerTypedBitsetHelper3()
    {
        return m_var_InnerTypedBitsetHelper3;
    }


    /*!
     * @brief This function copies the value in member var_InnerTypedBitsetHelper4
     * @param _var_InnerTypedBitsetHelper4 New value to be copied in member var_InnerTypedBitsetHelper4
     */
    eProsima_user_DllExport void var_InnerTypedBitsetHelper4(
            const InnerTypedBitsetHelper4& _var_InnerTypedBitsetHelper4)
    {
        m_var_InnerTypedBitsetHelper4 = _var_InnerTypedBitsetHelper4;
    }

    /*!
     * @brief This function moves the value in member var_InnerTypedBitsetHelper4
     * @param _var_InnerTypedBitsetHelper4 New value to be moved in member var_InnerTypedBitsetHelper4
     */
    eProsima_user_DllExport void var_InnerTypedBitsetHelper4(
            InnerTypedBitsetHelper4&& _var_InnerTypedBitsetHelper4)
    {
        m_var_InnerTypedBitsetHelper4 = std::move(_var_InnerTypedBitsetHelper4);
    }

    /*!
     * @brief This function returns a constant reference to member var_InnerTypedBitsetHelper4
     * @return Constant reference to member var_InnerTypedBitsetHelper4
     */
    eProsima_user_DllExport const InnerTypedBitsetHelper4& var_InnerTypedBitsetHelper4() const
    {
        return m_var_InnerTypedBitsetHelper4;
    }

    /*!
     * @brief This function returns a reference to member var_InnerTypedBitsetHelper4
     * @return Reference to member var_InnerTypedBitsetHelper4
     */
    eProsima_user_DllExport InnerTypedBitsetHelper4& var_InnerTypedBitsetHelper4()
    {
        return m_var_InnerTypedBitsetHelper4;
    }



private:

    InnerBitsetHelper m_var_InnerBitsetHelper{};
    InnerTypedBitsetHelper m_var_InnerTypedBitsetHelper{};
    InnerTypedBitsetHelper2 m_var_InnerTypedBitsetHelper2{};
    InnerTypedBitsetHelper3 m_var_InnerTypedBitsetHelper3{};
    InnerTypedBitsetHelper4 m_var_InnerTypedBitsetHelper4{};

};

#endif // _FAST_DDS_GENERATED_BITSETS_HPP_


