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
 * @file structuresTypeObject.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_STRUCTURES_TYPE_OBJECT_H_
#define _FAST_DDS_GENERATED_STRUCTURES_TYPE_OBJECT_H_

#include "helpers/basic_inner_typesTypeObject.h"

#include <fastrtps/types/TypeObject.h>
#include <map>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(structures_SOURCE)
#define structures_DllAPI __declspec( dllexport )
#else
#define structures_DllAPI __declspec( dllimport )
#endif // structures_SOURCE
#else
#define structures_DllAPI
#endif
#else
#define structures_DllAPI
#endif // _WIN32

using namespace eprosima::fastrtps::types;

eProsima_user_DllExport void registerstructuresTypes();

eProsima_user_DllExport const TypeIdentifier* GetInnerAliasHelperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInnerAliasHelperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInnerAliasHelperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInnerAliasHelperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_bounded_string_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_bounded_string_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_bounded_string_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_bounded_string_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_bounded_wstring_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_bounded_wstring_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_bounded_wstring_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_bounded_wstring_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_array_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_array_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_array_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_array_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_sequence_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_sequence_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_sequence_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_sequence_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetInner_alias_map_helperIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetInner_alias_map_helperObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInner_alias_map_helperObject();
eProsima_user_DllExport const TypeObject* GetCompleteInner_alias_map_helperObject();

eProsima_user_DllExport const TypeIdentifier* GetShortStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetShortStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalShortStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteShortStructObject();

eProsima_user_DllExport const TypeIdentifier* GetUnsignedShortStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetUnsignedShortStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalUnsignedShortStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteUnsignedShortStructObject();

eProsima_user_DllExport const TypeIdentifier* GetLongStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetLongStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalLongStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteLongStructObject();

eProsima_user_DllExport const TypeIdentifier* GetUnsignedLongStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetUnsignedLongStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalUnsignedLongStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteUnsignedLongStructObject();

eProsima_user_DllExport const TypeIdentifier* GetLongLongStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetLongLongStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalLongLongStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteLongLongStructObject();

eProsima_user_DllExport const TypeIdentifier* GetUnsignedLongLongStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetUnsignedLongLongStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalUnsignedLongLongStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteUnsignedLongLongStructObject();

eProsima_user_DllExport const TypeIdentifier* GetFloatStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetFloatStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalFloatStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteFloatStructObject();

eProsima_user_DllExport const TypeIdentifier* GetDoubleStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetDoubleStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalDoubleStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteDoubleStructObject();

eProsima_user_DllExport const TypeIdentifier* GetLongDoubleStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetLongDoubleStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalLongDoubleStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteLongDoubleStructObject();

eProsima_user_DllExport const TypeIdentifier* GetBooleanStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBooleanStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBooleanStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBooleanStructObject();

eProsima_user_DllExport const TypeIdentifier* GetOctetStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetOctetStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalOctetStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteOctetStructObject();

eProsima_user_DllExport const TypeIdentifier* GetChar8StructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetChar8StructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalChar8StructObject();
eProsima_user_DllExport const TypeObject* GetCompleteChar8StructObject();

eProsima_user_DllExport const TypeIdentifier* GetChar16StructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetChar16StructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalChar16StructObject();
eProsima_user_DllExport const TypeObject* GetCompleteChar16StructObject();

eProsima_user_DllExport const TypeIdentifier* GetStringStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetStringStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalStringStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteStringStructObject();

eProsima_user_DllExport const TypeIdentifier* GetWStringStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetWStringStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalWStringStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteWStringStructObject();

eProsima_user_DllExport const TypeIdentifier* GetBoundedStringStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBoundedStringStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBoundedStringStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBoundedStringStructObject();

eProsima_user_DllExport const TypeIdentifier* GetBoundedWStringStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBoundedWStringStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBoundedWStringStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBoundedWStringStructObject();

eProsima_user_DllExport const TypeIdentifier* GetEnumStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetEnumStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalEnumStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteEnumStructObject();

eProsima_user_DllExport const TypeIdentifier* GetBitMaskStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBitMaskStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBitMaskStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBitMaskStructObject();

eProsima_user_DllExport const TypeIdentifier* GetAliasStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetAliasStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalAliasStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteAliasStructObject();

eProsima_user_DllExport const TypeIdentifier* GetShortArrayStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetShortArrayStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalShortArrayStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteShortArrayStructObject();

eProsima_user_DllExport const TypeIdentifier* GetSequenceStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetSequenceStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalSequenceStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteSequenceStructObject();

eProsima_user_DllExport const TypeIdentifier* GetMapStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMapStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMapStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteMapStructObject();

eProsima_user_DllExport const TypeIdentifier* GetUnionStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetUnionStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalUnionStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteUnionStructObject();

eProsima_user_DllExport const TypeIdentifier* GetStructureStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetStructureStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalStructureStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteStructureStructObject();

eProsima_user_DllExport const TypeIdentifier* GetBitsetStructIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetBitsetStructObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalBitsetStructObject();
eProsima_user_DllExport const TypeObject* GetCompleteBitsetStructObject();

eProsima_user_DllExport const TypeIdentifier* GetEmptyStructureIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetEmptyStructureObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalEmptyStructureObject();
eProsima_user_DllExport const TypeObject* GetCompleteEmptyStructureObject();

eProsima_user_DllExport const TypeIdentifier* GetStructuresIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetStructuresObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalStructuresObject();
eProsima_user_DllExport const TypeObject* GetCompleteStructuresObject();


#endif // _FAST_DDS_GENERATED_STRUCTURES_TYPE_OBJECT_H_