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
 * @file new_features_4_2.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_NEW_FEATURES_4_2_H_
#define _FAST_DDS_GENERATED_NEW_FEATURES_4_2_H_


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
#if defined(NEW_FEATURES_4_2_SOURCE)
#define NEW_FEATURES_4_2_DllAPI __declspec( dllexport )
#else
#define NEW_FEATURES_4_2_DllAPI __declspec( dllimport )
#endif // NEW_FEATURES_4_2_SOURCE
#else
#define NEW_FEATURES_4_2_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define NEW_FEATURES_4_2_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
class CdrSizeCalculator;} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the structure NewAliases defined by the user in the IDL file.
 * @ingroup new_features_4_2
 */
class NewAliases
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport NewAliases();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~NewAliases();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object NewAliases that will be copied.
     */
    eProsima_user_DllExport NewAliases(
            const NewAliases& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object NewAliases that will be copied.
     */
    eProsima_user_DllExport NewAliases(
            NewAliases&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object NewAliases that will be copied.
     */
    eProsima_user_DllExport NewAliases& operator =(
            const NewAliases& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object NewAliases that will be copied.
     */
    eProsima_user_DllExport NewAliases& operator =(
            NewAliases&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x NewAliases object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const NewAliases& x) const;

    /*!
     * @brief Comparison operator.
     * @param x NewAliases object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const NewAliases& x) const;

    /*!
     * @brief This function sets a value in member int8_
     * @param _int8_ New value for member int8_
     */
    eProsima_user_DllExport void int8_(
            int8_t _int8_);

    /*!
     * @brief This function returns the value of member int8_
     * @return Value of member int8_
     */
    eProsima_user_DllExport int8_t int8_() const;

    /*!
     * @brief This function returns a reference to member int8_
     * @return Reference to member int8_
     */
    eProsima_user_DllExport int8_t& int8_();

    /*!
     * @brief This function sets a value in member uint8_
     * @param _uint8_ New value for member uint8_
     */
    eProsima_user_DllExport void uint8_(
            uint8_t _uint8_);

    /*!
     * @brief This function returns the value of member uint8_
     * @return Value of member uint8_
     */
    eProsima_user_DllExport uint8_t uint8_() const;

    /*!
     * @brief This function returns a reference to member uint8_
     * @return Reference to member uint8_
     */
    eProsima_user_DllExport uint8_t& uint8_();

    /*!
     * @brief This function sets a value in member int16_
     * @param _int16_ New value for member int16_
     */
    eProsima_user_DllExport void int16_(
            int16_t _int16_);

    /*!
     * @brief This function returns the value of member int16_
     * @return Value of member int16_
     */
    eProsima_user_DllExport int16_t int16_() const;

    /*!
     * @brief This function returns a reference to member int16_
     * @return Reference to member int16_
     */
    eProsima_user_DllExport int16_t& int16_();

    /*!
     * @brief This function sets a value in member uint16_
     * @param _uint16_ New value for member uint16_
     */
    eProsima_user_DllExport void uint16_(
            uint16_t _uint16_);

    /*!
     * @brief This function returns the value of member uint16_
     * @return Value of member uint16_
     */
    eProsima_user_DllExport uint16_t uint16_() const;

    /*!
     * @brief This function returns a reference to member uint16_
     * @return Reference to member uint16_
     */
    eProsima_user_DllExport uint16_t& uint16_();

    /*!
     * @brief This function sets a value in member int32_
     * @param _int32_ New value for member int32_
     */
    eProsima_user_DllExport void int32_(
            int32_t _int32_);

    /*!
     * @brief This function returns the value of member int32_
     * @return Value of member int32_
     */
    eProsima_user_DllExport int32_t int32_() const;

    /*!
     * @brief This function returns a reference to member int32_
     * @return Reference to member int32_
     */
    eProsima_user_DllExport int32_t& int32_();

    /*!
     * @brief This function sets a value in member uint32_
     * @param _uint32_ New value for member uint32_
     */
    eProsima_user_DllExport void uint32_(
            uint32_t _uint32_);

    /*!
     * @brief This function returns the value of member uint32_
     * @return Value of member uint32_
     */
    eProsima_user_DllExport uint32_t uint32_() const;

    /*!
     * @brief This function returns a reference to member uint32_
     * @return Reference to member uint32_
     */
    eProsima_user_DllExport uint32_t& uint32_();

    /*!
     * @brief This function sets a value in member int64_
     * @param _int64_ New value for member int64_
     */
    eProsima_user_DllExport void int64_(
            int64_t _int64_);

    /*!
     * @brief This function returns the value of member int64_
     * @return Value of member int64_
     */
    eProsima_user_DllExport int64_t int64_() const;

    /*!
     * @brief This function returns a reference to member int64_
     * @return Reference to member int64_
     */
    eProsima_user_DllExport int64_t& int64_();

    /*!
     * @brief This function sets a value in member uint64_
     * @param _uint64_ New value for member uint64_
     */
    eProsima_user_DllExport void uint64_(
            uint64_t _uint64_);

    /*!
     * @brief This function returns the value of member uint64_
     * @return Value of member uint64_
     */
    eProsima_user_DllExport uint64_t uint64_() const;

    /*!
     * @brief This function returns a reference to member uint64_
     * @return Reference to member uint64_
     */
    eProsima_user_DllExport uint64_t& uint64_();

    /*!
     * @brief This function copies the value in member local_string
     * @param _local_string New value to be copied in member local_string
     */
    eProsima_user_DllExport void local_string(
            const std::string& _local_string);

    /*!
     * @brief This function moves the value in member local_string
     * @param _local_string New value to be moved in member local_string
     */
    eProsima_user_DllExport void local_string(
            std::string&& _local_string);

    /*!
     * @brief This function returns a constant reference to member local_string
     * @return Constant reference to member local_string
     */
    eProsima_user_DllExport const std::string& local_string() const;

    /*!
     * @brief This function returns a reference to member local_string
     * @return Reference to member local_string
     */
    eProsima_user_DllExport std::string& local_string();



private:

    int8_t m_int8_{0};
    uint8_t m_uint8_{0};
    int16_t m_int16_{0};
    uint16_t m_uint16_{0};
    int32_t m_int32_{0};
    uint32_t m_uint32_{0};
    int64_t m_int64_{0};
    uint64_t m_uint64_{555}
    ;
    std::string m_local_string;

};
/*!
 * @brief This class represents the union WCharUnion defined by the user in the IDL file.
 * @ingroup new_features_4_2
 */
class WCharUnion
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport WCharUnion();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~WCharUnion();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object WCharUnion that will be copied.
     */
    eProsima_user_DllExport WCharUnion(
            const WCharUnion& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object WCharUnion that will be copied.
     */
    eProsima_user_DllExport WCharUnion(
            WCharUnion&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object WCharUnion that will be copied.
     */
    eProsima_user_DllExport WCharUnion& operator =(
            const WCharUnion& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object WCharUnion that will be copied.
     */
    eProsima_user_DllExport WCharUnion& operator =(
            WCharUnion&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x WCharUnion object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const WCharUnion& x) const;

    /*!
     * @brief Comparison operator.
     * @param x WCharUnion object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const WCharUnion& x) const;

    /*!
     * @brief This function sets the discriminator value.
     * @param __d New value for the discriminator.
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the new value doesn't correspond to the selected union member.
     */
    eProsima_user_DllExport void _d(
            wchar_t __d);

    /*!
     * @brief This function returns the value of the discriminator.
     * @return Value of the discriminator
     */
    eProsima_user_DllExport wchar_t _d() const;

    /*!
     * @brief This function returns a reference to the discriminator.
     * @return Reference to the discriminator.
     */
    eProsima_user_DllExport wchar_t& _d();

    /*!
     * @brief This function sets a value in member case_zero
     * @param _case_zero New value for member case_zero
     */
    eProsima_user_DllExport void case_zero(
            int32_t _case_zero);

    /*!
     * @brief This function returns the value of member case_zero
     * @return Value of member case_zero
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t case_zero() const;

    /*!
     * @brief This function returns a reference to member case_zero
     * @return Reference to member case_zero
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t& case_zero();

    /*!
     * @brief This function sets a value in member case_one
     * @param _case_one New value for member case_one
     */
    eProsima_user_DllExport void case_one(
            int32_t _case_one);

    /*!
     * @brief This function returns the value of member case_one
     * @return Value of member case_one
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t case_one() const;

    /*!
     * @brief This function returns a reference to member case_one
     * @return Reference to member case_one
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t& case_one();




private:

    wchar_t m__d;

    int32_t m_case_zero{0};
    int32_t m_case_one{0};
};
/*!
 * @brief This class represents the union OctetUnion defined by the user in the IDL file.
 * @ingroup new_features_4_2
 */
class OctetUnion
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport OctetUnion();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~OctetUnion();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object OctetUnion that will be copied.
     */
    eProsima_user_DllExport OctetUnion(
            const OctetUnion& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object OctetUnion that will be copied.
     */
    eProsima_user_DllExport OctetUnion(
            OctetUnion&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object OctetUnion that will be copied.
     */
    eProsima_user_DllExport OctetUnion& operator =(
            const OctetUnion& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object OctetUnion that will be copied.
     */
    eProsima_user_DllExport OctetUnion& operator =(
            OctetUnion&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x OctetUnion object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const OctetUnion& x) const;

    /*!
     * @brief Comparison operator.
     * @param x OctetUnion object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const OctetUnion& x) const;

    /*!
     * @brief This function sets the discriminator value.
     * @param __d New value for the discriminator.
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the new value doesn't correspond to the selected union member.
     */
    eProsima_user_DllExport void _d(
            uint8_t __d);

    /*!
     * @brief This function returns the value of the discriminator.
     * @return Value of the discriminator
     */
    eProsima_user_DllExport uint8_t _d() const;

    /*!
     * @brief This function returns a reference to the discriminator.
     * @return Reference to the discriminator.
     */
    eProsima_user_DllExport uint8_t& _d();

    /*!
     * @brief This function sets a value in member case_five
     * @param _case_five New value for member case_five
     */
    eProsima_user_DllExport void case_five(
            int32_t _case_five);

    /*!
     * @brief This function returns the value of member case_five
     * @return Value of member case_five
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t case_five() const;

    /*!
     * @brief This function returns a reference to member case_five
     * @return Reference to member case_five
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t& case_five();

    /*!
     * @brief This function sets a value in member case_seven
     * @param _case_seven New value for member case_seven
     */
    eProsima_user_DllExport void case_seven(
            int32_t _case_seven);

    /*!
     * @brief This function returns the value of member case_seven
     * @return Value of member case_seven
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t case_seven() const;

    /*!
     * @brief This function returns a reference to member case_seven
     * @return Reference to member case_seven
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t& case_seven();




private:

    uint8_t m__d;

    int32_t m_case_five{0};
    int32_t m_case_seven{0};
};
/*!
 * @brief This class represents the union Int8Union defined by the user in the IDL file.
 * @ingroup new_features_4_2
 */
class Int8Union
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Int8Union();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Int8Union();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Int8Union that will be copied.
     */
    eProsima_user_DllExport Int8Union(
            const Int8Union& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Int8Union that will be copied.
     */
    eProsima_user_DllExport Int8Union(
            Int8Union&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Int8Union that will be copied.
     */
    eProsima_user_DllExport Int8Union& operator =(
            const Int8Union& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Int8Union that will be copied.
     */
    eProsima_user_DllExport Int8Union& operator =(
            Int8Union&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x Int8Union object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const Int8Union& x) const;

    /*!
     * @brief Comparison operator.
     * @param x Int8Union object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const Int8Union& x) const;

    /*!
     * @brief This function sets the discriminator value.
     * @param __d New value for the discriminator.
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the new value doesn't correspond to the selected union member.
     */
    eProsima_user_DllExport void _d(
            int8_t __d);

    /*!
     * @brief This function returns the value of the discriminator.
     * @return Value of the discriminator
     */
    eProsima_user_DllExport int8_t _d() const;

    /*!
     * @brief This function returns a reference to the discriminator.
     * @return Reference to the discriminator.
     */
    eProsima_user_DllExport int8_t& _d();

    /*!
     * @brief This function sets a value in member case_three
     * @param _case_three New value for member case_three
     */
    eProsima_user_DllExport void case_three(
            int32_t _case_three);

    /*!
     * @brief This function returns the value of member case_three
     * @return Value of member case_three
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t case_three() const;

    /*!
     * @brief This function returns a reference to member case_three
     * @return Reference to member case_three
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t& case_three();

    /*!
     * @brief This function sets a value in member case_six
     * @param _case_six New value for member case_six
     */
    eProsima_user_DllExport void case_six(
            int32_t _case_six);

    /*!
     * @brief This function returns the value of member case_six
     * @return Value of member case_six
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t case_six() const;

    /*!
     * @brief This function returns a reference to member case_six
     * @return Reference to member case_six
     * @exception eprosima::fastcdr::BadParamException This exception is thrown if the requested union member is not the current selection.
     */
    eProsima_user_DllExport int32_t& case_six();




private:

    int8_t m__d;

    int32_t m_case_three{0};
    int32_t m_case_six{0};
};
namespace bitmodule {
    /*!
     * @brief This class represents the structure ParentBitset defined by the user in the IDL file.
     * @ingroup new_features_4_2
     */
    class ParentBitset
    {
    public:

        /*!
         * @brief Default constructor.
         */
        eProsima_user_DllExport ParentBitset();

        /*!
         * @brief Default destructor.
         */
        eProsima_user_DllExport ~ParentBitset();

        /*!
         * @brief Copy constructor.
         * @param x Reference to the object bitmodule::ParentBitset that will be copied.
         */
        eProsima_user_DllExport ParentBitset(
                const ParentBitset& x);

        /*!
         * @brief Move constructor.
         * @param x Reference to the object bitmodule::ParentBitset that will be copied.
         */
        eProsima_user_DllExport ParentBitset(
                ParentBitset&& x) noexcept;

        /*!
         * @brief Copy assignment.
         * @param x Reference to the object bitmodule::ParentBitset that will be copied.
         */
        eProsima_user_DllExport ParentBitset& operator =(
                const ParentBitset& x);

        /*!
         * @brief Move assignment.
         * @param x Reference to the object bitmodule::ParentBitset that will be copied.
         */
        eProsima_user_DllExport ParentBitset& operator =(
                ParentBitset&& x) noexcept;

        /*!
         * @brief Comparison operator.
         * @param x bitmodule::ParentBitset object to compare.
         */
        eProsima_user_DllExport bool operator ==(
                const ParentBitset& x) const;

        /*!
         * @brief Comparison operator.
         * @param x bitmodule::ParentBitset object to compare.
         */
        eProsima_user_DllExport bool operator !=(
                const ParentBitset& x) const;

        /*!
         * @brief This function sets a value in member parent_bitfield
         * @param _parent_bitfield New value for member parent_bitfield
         */
        eProsima_user_DllExport void parent_bitfield(
                uint32_t _parent_bitfield);

        /*!
         * @brief This function returns the value of member parent_bitfield
         * @return Value of member parent_bitfield
         */
        eProsima_user_DllExport uint32_t parent_bitfield() const;

        eProsima_user_DllExport const std::bitset<17>& bitset() const;

        eProsima_user_DllExport std::bitset<17>& bitset();



    private:

        std::bitset<17> m_bitset;
    };
    /*!
     * @brief This class represents the structure MyBitset defined by the user in the IDL file.
     * @ingroup new_features_4_2
     */
    class MyBitset : public bitmodule::ParentBitset 
    {
    public:

        /*!
         * @brief Default constructor.
         */
        eProsima_user_DllExport MyBitset();

        /*!
         * @brief Default destructor.
         */
        eProsima_user_DllExport ~MyBitset();

        /*!
         * @brief Copy constructor.
         * @param x Reference to the object bitmodule::MyBitset that will be copied.
         */
        eProsima_user_DllExport MyBitset(
                const MyBitset& x);

        /*!
         * @brief Move constructor.
         * @param x Reference to the object bitmodule::MyBitset that will be copied.
         */
        eProsima_user_DllExport MyBitset(
                MyBitset&& x) noexcept;

        /*!
         * @brief Copy assignment.
         * @param x Reference to the object bitmodule::MyBitset that will be copied.
         */
        eProsima_user_DllExport MyBitset& operator =(
                const MyBitset& x);

        /*!
         * @brief Move assignment.
         * @param x Reference to the object bitmodule::MyBitset that will be copied.
         */
        eProsima_user_DllExport MyBitset& operator =(
                MyBitset&& x) noexcept;

        /*!
         * @brief Comparison operator.
         * @param x bitmodule::MyBitset object to compare.
         */
        eProsima_user_DllExport bool operator ==(
                const MyBitset& x) const;

        /*!
         * @brief Comparison operator.
         * @param x bitmodule::MyBitset object to compare.
         */
        eProsima_user_DllExport bool operator !=(
                const MyBitset& x) const;

        /*!
         * @brief This function sets a value in member a
         * @param _a New value for member a
         */
        eProsima_user_DllExport void a(
                char _a);

        /*!
         * @brief This function returns the value of member a
         * @return Value of member a
         */
        eProsima_user_DllExport char a() const;
        /*!
         * @brief This function sets a value in member b
         * @param _b New value for member b
         */
        eProsima_user_DllExport void b(
                bool _b);

        /*!
         * @brief This function returns the value of member b
         * @return Value of member b
         */
        eProsima_user_DllExport bool b() const;

        /*!
         * @brief This function sets a value in member c
         * @param _c New value for member c
         */
        eProsima_user_DllExport void c(
                uint16_t _c);

        /*!
         * @brief This function returns the value of member c
         * @return Value of member c
         */
        eProsima_user_DllExport uint16_t c() const;
        /*!
         * @brief This function sets a value in member d
         * @param _d New value for member d
         */
        eProsima_user_DllExport void d(
                int16_t _d);

        /*!
         * @brief This function returns the value of member d
         * @return Value of member d
         */
        eProsima_user_DllExport int16_t d() const;
        /*!
         * @brief This function sets a value in member e
         * @param _e New value for member e
         */
        eProsima_user_DllExport void e(
                int16_t _e);

        /*!
         * @brief This function returns the value of member e
         * @return Value of member e
         */
        eProsima_user_DllExport int16_t e() const;
        /*!
         * @brief This function sets a value in member f
         * @param _f New value for member f
         */
        eProsima_user_DllExport void f(
                int16_t _f);

        /*!
         * @brief This function returns the value of member f
         * @return Value of member f
         */
        eProsima_user_DllExport int16_t f() const;

        eProsima_user_DllExport const std::bitset<54>& bitset() const;

        eProsima_user_DllExport std::bitset<54>& bitset();



    private:

        std::bitset<54> m_bitset;
    };
    /*!
     * @brief This class represents the bitmask MyBitMask defined by the user in the IDL file.
     * @ingroup new_features_4_2
     */
    enum MyBitMask : uint8_t
    {
        flag0 = 0x01ull << 0,
        flag1 = 0x01ull << 1,
        flag4 = 0x01ull << 4,
        flag6 = 0x01ull << 6,
        flag7 = 0x01ull << 7
    };
    /*!
     * @brief This class represents the structure BitsetBitmask defined by the user in the IDL file.
     * @ingroup new_features_4_2
     */
    class BitsetBitmask
    {
    public:

        /*!
         * @brief Default constructor.
         */
        eProsima_user_DllExport BitsetBitmask();

        /*!
         * @brief Default destructor.
         */
        eProsima_user_DllExport ~BitsetBitmask();

        /*!
         * @brief Copy constructor.
         * @param x Reference to the object bitmodule::BitsetBitmask that will be copied.
         */
        eProsima_user_DllExport BitsetBitmask(
                const BitsetBitmask& x);

        /*!
         * @brief Move constructor.
         * @param x Reference to the object bitmodule::BitsetBitmask that will be copied.
         */
        eProsima_user_DllExport BitsetBitmask(
                BitsetBitmask&& x) noexcept;

        /*!
         * @brief Copy assignment.
         * @param x Reference to the object bitmodule::BitsetBitmask that will be copied.
         */
        eProsima_user_DllExport BitsetBitmask& operator =(
                const BitsetBitmask& x);

        /*!
         * @brief Move assignment.
         * @param x Reference to the object bitmodule::BitsetBitmask that will be copied.
         */
        eProsima_user_DllExport BitsetBitmask& operator =(
                BitsetBitmask&& x) noexcept;

        /*!
         * @brief Comparison operator.
         * @param x bitmodule::BitsetBitmask object to compare.
         */
        eProsima_user_DllExport bool operator ==(
                const BitsetBitmask& x) const;

        /*!
         * @brief Comparison operator.
         * @param x bitmodule::BitsetBitmask object to compare.
         */
        eProsima_user_DllExport bool operator !=(
                const BitsetBitmask& x) const;

        /*!
         * @brief This function copies the value in member mybitset
         * @param _mybitset New value to be copied in member mybitset
         */
        eProsima_user_DllExport void mybitset(
                const bitmodule::MyBitset& _mybitset);

        /*!
         * @brief This function moves the value in member mybitset
         * @param _mybitset New value to be moved in member mybitset
         */
        eProsima_user_DllExport void mybitset(
                bitmodule::MyBitset&& _mybitset);

        /*!
         * @brief This function returns a constant reference to member mybitset
         * @return Constant reference to member mybitset
         */
        eProsima_user_DllExport const bitmodule::MyBitset& mybitset() const;

        /*!
         * @brief This function returns a reference to member mybitset
         * @return Reference to member mybitset
         */
        eProsima_user_DllExport bitmodule::MyBitset& mybitset();
        /*!
         * @brief This function sets a value in member mybitmask
         * @param _mybitmask New value for member mybitmask
         */
        eProsima_user_DllExport void mybitmask(
                bitmodule::MyBitMask _mybitmask);

        /*!
         * @brief This function returns the value of member mybitmask
         * @return Value of member mybitmask
         */
        eProsima_user_DllExport bitmodule::MyBitMask mybitmask() const;

        /*!
         * @brief This function returns a reference to member mybitmask
         * @return Reference to member mybitmask
         */
        eProsima_user_DllExport bitmodule::MyBitMask& mybitmask();




    private:

        bitmodule::MyBitset m_mybitset;
        bitmodule::MyBitMask m_mybitmask{bitmodule::flag0};

    };
    /*!
     * @brief This class represents the structure BM2 defined by the user in the IDL file.
     * @ingroup new_features_4_2
     */
    class BM2 : public bitmodule::BitsetBitmask 
    {
    public:

        /*!
         * @brief Default constructor.
         */
        eProsima_user_DllExport BM2();

        /*!
         * @brief Default destructor.
         */
        eProsima_user_DllExport ~BM2();

        /*!
         * @brief Copy constructor.
         * @param x Reference to the object bitmodule::BM2 that will be copied.
         */
        eProsima_user_DllExport BM2(
                const BM2& x);

        /*!
         * @brief Move constructor.
         * @param x Reference to the object bitmodule::BM2 that will be copied.
         */
        eProsima_user_DllExport BM2(
                BM2&& x) noexcept;

        /*!
         * @brief Copy assignment.
         * @param x Reference to the object bitmodule::BM2 that will be copied.
         */
        eProsima_user_DllExport BM2& operator =(
                const BM2& x);

        /*!
         * @brief Move assignment.
         * @param x Reference to the object bitmodule::BM2 that will be copied.
         */
        eProsima_user_DllExport BM2& operator =(
                BM2&& x) noexcept;

        /*!
         * @brief Comparison operator.
         * @param x bitmodule::BM2 object to compare.
         */
        eProsima_user_DllExport bool operator ==(
                const BM2& x) const;

        /*!
         * @brief Comparison operator.
         * @param x bitmodule::BM2 object to compare.
         */
        eProsima_user_DllExport bool operator !=(
                const BM2& x) const;

        /*!
         * @brief This function sets a value in member two
         * @param _two New value for member two
         */
        eProsima_user_DllExport void two(
                bitmodule::MyBitMask _two);

        /*!
         * @brief This function returns the value of member two
         * @return Value of member two
         */
        eProsima_user_DllExport bitmodule::MyBitMask two() const;

        /*!
         * @brief This function returns a reference to member two
         * @return Reference to member two
         */
        eProsima_user_DllExport bitmodule::MyBitMask& two();

        /*!
         * @brief This function sets a value in member mylong
         * @param _mylong New value for member mylong
         */
        eProsima_user_DllExport void mylong(
                int32_t _mylong);

        /*!
         * @brief This function returns the value of member mylong
         * @return Value of member mylong
         */
        eProsima_user_DllExport int32_t mylong() const;

        /*!
         * @brief This function returns a reference to member mylong
         * @return Reference to member mylong
         */
        eProsima_user_DllExport int32_t& mylong();




    private:

        bitmodule::MyBitMask m_two{bitmodule::flag0};
        int32_t m_mylong{0};

    };
} // namespace bitmodule
/*!
 * @brief This class represents the structure StructTest defined by the user in the IDL file.
 * @ingroup new_features_4_2
 */
class StructTest : public NewAliases 
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport StructTest();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~StructTest();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object StructTest that will be copied.
     */
    eProsima_user_DllExport StructTest(
            const StructTest& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object StructTest that will be copied.
     */
    eProsima_user_DllExport StructTest(
            StructTest&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object StructTest that will be copied.
     */
    eProsima_user_DllExport StructTest& operator =(
            const StructTest& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object StructTest that will be copied.
     */
    eProsima_user_DllExport StructTest& operator =(
            StructTest&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x StructTest object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const StructTest& x) const;

    /*!
     * @brief Comparison operator.
     * @param x StructTest object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const StructTest& x) const;

    /*!
     * @brief This function copies the value in member charUnion
     * @param _charUnion New value to be copied in member charUnion
     */
    eProsima_user_DllExport void charUnion(
            const WCharUnion& _charUnion);

    /*!
     * @brief This function moves the value in member charUnion
     * @param _charUnion New value to be moved in member charUnion
     */
    eProsima_user_DllExport void charUnion(
            WCharUnion&& _charUnion);

    /*!
     * @brief This function returns a constant reference to member charUnion
     * @return Constant reference to member charUnion
     */
    eProsima_user_DllExport const WCharUnion& charUnion() const;

    /*!
     * @brief This function returns a reference to member charUnion
     * @return Reference to member charUnion
     */
    eProsima_user_DllExport WCharUnion& charUnion();
    /*!
     * @brief This function copies the value in member octetUnion
     * @param _octetUnion New value to be copied in member octetUnion
     */
    eProsima_user_DllExport void octetUnion(
            const OctetUnion& _octetUnion);

    /*!
     * @brief This function moves the value in member octetUnion
     * @param _octetUnion New value to be moved in member octetUnion
     */
    eProsima_user_DllExport void octetUnion(
            OctetUnion&& _octetUnion);

    /*!
     * @brief This function returns a constant reference to member octetUnion
     * @return Constant reference to member octetUnion
     */
    eProsima_user_DllExport const OctetUnion& octetUnion() const;

    /*!
     * @brief This function returns a reference to member octetUnion
     * @return Reference to member octetUnion
     */
    eProsima_user_DllExport OctetUnion& octetUnion();
    /*!
     * @brief This function copies the value in member int8Union
     * @param _int8Union New value to be copied in member int8Union
     */
    eProsima_user_DllExport void int8Union(
            const Int8Union& _int8Union);

    /*!
     * @brief This function moves the value in member int8Union
     * @param _int8Union New value to be moved in member int8Union
     */
    eProsima_user_DllExport void int8Union(
            Int8Union&& _int8Union);

    /*!
     * @brief This function returns a constant reference to member int8Union
     * @return Constant reference to member int8Union
     */
    eProsima_user_DllExport const Int8Union& int8Union() const;

    /*!
     * @brief This function returns a reference to member int8Union
     * @return Reference to member int8Union
     */
    eProsima_user_DllExport Int8Union& int8Union();
    /*!
     * @brief This function copies the value in member myStructBits
     * @param _myStructBits New value to be copied in member myStructBits
     */
    eProsima_user_DllExport void myStructBits(
            const bitmodule::BM2& _myStructBits);

    /*!
     * @brief This function moves the value in member myStructBits
     * @param _myStructBits New value to be moved in member myStructBits
     */
    eProsima_user_DllExport void myStructBits(
            bitmodule::BM2&& _myStructBits);

    /*!
     * @brief This function returns a constant reference to member myStructBits
     * @return Constant reference to member myStructBits
     */
    eProsima_user_DllExport const bitmodule::BM2& myStructBits() const;

    /*!
     * @brief This function returns a reference to member myStructBits
     * @return Reference to member myStructBits
     */
    eProsima_user_DllExport bitmodule::BM2& myStructBits();



private:

    WCharUnion m_charUnion;
    OctetUnion m_octetUnion;
    Int8Union m_int8Union;
    bitmodule::BM2 m_myStructBits;

};

#endif // _FAST_DDS_GENERATED_NEW_FEATURES_4_2_H_