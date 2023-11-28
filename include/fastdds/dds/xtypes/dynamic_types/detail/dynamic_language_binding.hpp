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
 * @file dynamic_language_binding.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_DDS_DYNAMIC_LANGUAGE_BINDING_HPP_
#define _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_DDS_DYNAMIC_LANGUAGE_BINDING_HPP_

#include <cstdint>
#include <map>
#include <vector>

#include <fastcdr/cdr/fixed_size_string.hpp>
#include <fastcdr/exceptions/BadParamException.h>


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
#if defined(DYNAMIC_LANGUAGE_BINDING_SOURCE)
#define DYNAMIC_LANGUAGE_BINDING_DllAPI __declspec( dllexport )
#else
#define DYNAMIC_LANGUAGE_BINDING_DllAPI __declspec( dllimport )
#endif // DYNAMIC_LANGUAGE_BINDING_SOURCE
#else
#define DYNAMIC_LANGUAGE_BINDING_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define DYNAMIC_LANGUAGE_BINDING_DllAPI
#endif // _WIN32

namespace eprosima {

namespace fastdds {

namespace dds {


class DynamicTypeMember;

typedef std::vector<std::string> IncludePathSeq;

typedef eprosima::fastcdr::fixed_string<256> ObjectName;

typedef uint8_t TypeKind;

const TypeKind TK_NONE = 0x00;
const TypeKind TK_BOOLEAN = 0x01;
const TypeKind TK_BYTE = 0x02;
const TypeKind TK_INT16 = 0x03;
const TypeKind TK_INT32 = 0x04;
const TypeKind TK_INT64 = 0x05;
const TypeKind TK_UINT16 = 0x06;
const TypeKind TK_UINT32 = 0x07;
const TypeKind TK_UINT64 = 0x08;
const TypeKind TK_FLOAT32 = 0x09;
const TypeKind TK_FLOAT64 = 0x0A;
const TypeKind TK_FLOAT128 = 0x0B;
const TypeKind TK_INT8 = 0x0C;
const TypeKind TK_UINT8 = 0x0D;
const TypeKind TK_CHAR8 = 0x10;
const TypeKind TK_CHAR16 = 0x11;
const TypeKind TK_STRING8 = 0x20;
const TypeKind TK_STRING16 = 0x21;
const TypeKind TK_ALIAS = 0x30;
const TypeKind TK_ENUM = 0x40;
const TypeKind TK_BITMASK = 0x41;
const TypeKind TK_ANNOTATION = 0x50;
const TypeKind TK_STRUCTURE = 0x51;
const TypeKind TK_UNION = 0x52;
const TypeKind TK_BITSET = 0x53;
const TypeKind TK_SEQUENCE = 0x60;
const TypeKind TK_ARRAY = 0x61;
const TypeKind TK_MAP = 0x62;


typedef std::map<ObjectName, ObjectName> Parameters;

/*!
 * @brief This class represents the enumeration ExtensibilityKind defined by the user in the IDL file.
 * @ingroup dynamic_language_binding
 */
enum ExtensibilityKind : uint32_t
{
    FINAL,
    APPENDABLE,
    MUTABLE
};
/*!
 * @brief This class represents the enumeration TryConstructKind defined by the user in the IDL file.
 * @ingroup dynamic_language_binding
 */
enum TryConstructKind : uint32_t
{
    USE_DEFAULT,
    DISCARD,
    TRIM
};
typedef uint32_t MemberId;

typedef std::vector<int32_t> UnionCaseLabelSeq;

typedef std::vector<int32_t> Int32Seq;

typedef std::vector<uint32_t> UInt32Seq;

typedef std::vector<int8_t> Int8Seq;

typedef std::vector<uint8_t> UInt8Seq;

typedef std::vector<int16_t> Int16Seq;

typedef std::vector<uint16_t> UInt16Seq;

typedef std::vector<int64_t> Int64Seq;

typedef std::vector<uint64_t> UInt64Seq;

typedef std::vector<float> Float32Seq;

typedef std::vector<double> Float64Seq;

typedef std::vector<long double> Float128Seq;

typedef std::vector<char> CharSeq;

typedef std::vector<wchar_t> WcharSeq;

typedef std::vector<bool> BooleanSeq;

typedef std::vector<uint8_t> ByteSeq;

typedef std::vector<std::string> StringSeq;

typedef std::vector<std::wstring> WstringSeq;


} // namespace dds

} // namespace fastdds

} // namespace eprosima


#endif // _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_DDS_DYNAMIC_LANGUAGE_BINDING_HPP_


