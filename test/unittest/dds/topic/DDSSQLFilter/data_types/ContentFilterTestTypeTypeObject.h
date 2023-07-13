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
 * @file ContentFilterTestTypeTypeObject.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_CONTENTFILTERTESTTYPE_TYPE_OBJECT_H_
#define _FAST_DDS_GENERATED_CONTENTFILTERTESTTYPE_TYPE_OBJECT_H_


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
#if defined(ContentFilterTestType_SOURCE)
#define ContentFilterTestType_DllAPI __declspec( dllexport )
#else
#define ContentFilterTestType_DllAPI __declspec( dllimport )
#endif // ContentFilterTestType_SOURCE
#else
#define ContentFilterTestType_DllAPI
#endif
#else
#define ContentFilterTestType_DllAPI
#endif // _WIN32

using namespace eprosima::fastrtps::types;

eProsima_user_DllExport void registerContentFilterTestTypeTypes();

eProsima_user_DllExport const TypeIdentifier* GetColorIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetColorObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalColorObject();
eProsima_user_DllExport const TypeObject* GetCompleteColorObject();

eProsima_user_DllExport const TypeIdentifier* GetMaterialIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMaterialObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalMaterialObject();
eProsima_user_DllExport const TypeObject* GetCompleteMaterialObject();

eProsima_user_DllExport const TypeIdentifier* GetStructTypeIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetStructTypeObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalStructTypeObject();
eProsima_user_DllExport const TypeObject* GetCompleteStructTypeObject();



eProsima_user_DllExport const TypeIdentifier* GetContentFilterTestTypeIdentifier(bool complete = false);
eProsima_user_DllExport const TypeObject* GetContentFilterTestTypeObject(bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalContentFilterTestTypeObject();
eProsima_user_DllExport const TypeObject* GetCompleteContentFilterTestTypeObject();


#endif // _FAST_DDS_GENERATED_CONTENTFILTERTESTTYPE_TYPE_OBJECT_H_