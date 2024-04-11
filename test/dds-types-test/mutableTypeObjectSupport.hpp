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
 * @file mutableTypeObjectSupport.hpp
 * Header file containing the API required to register the TypeObject representation of the described types in the IDL file
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_MUTABLE_TYPE_OBJECT_SUPPORT_HPP_
#define _FAST_DDS_GENERATED_MUTABLE_TYPE_OBJECT_SUPPORT_HPP_

#include "helpers/basic_inner_typesTypeObjectSupport.hpp"

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

/**
 * @brief Register every TypeObject representation defined in the IDL file in Fast DDS TypeObjectRegistry.
 */
eProsima_user_DllExport void register_mutable_type_objects();

#ifndef DOXYGEN_SHOULD_SKIP_THIS_PUBLIC

/**
 * @brief Register MutableShortStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableShortStruct_type_identifier();
/**
 * @brief Register MutableUShortStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableUShortStruct_type_identifier();
/**
 * @brief Register MutableLongStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableLongStruct_type_identifier();
/**
 * @brief Register MutableULongStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableULongStruct_type_identifier();
/**
 * @brief Register MutableLongLongStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableLongLongStruct_type_identifier();
/**
 * @brief Register MutableULongLongStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableULongLongStruct_type_identifier();
/**
 * @brief Register MutableFloatStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableFloatStruct_type_identifier();
/**
 * @brief Register MutableDoubleStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableDoubleStruct_type_identifier();
/**
 * @brief Register MutableLongDoubleStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableLongDoubleStruct_type_identifier();
/**
 * @brief Register MutableBooleanStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableBooleanStruct_type_identifier();
/**
 * @brief Register MutableOctetStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableOctetStruct_type_identifier();
/**
 * @brief Register MutableCharStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableCharStruct_type_identifier();
/**
 * @brief Register MutableWCharStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableWCharStruct_type_identifier();
/**
 * @brief Register MutableUnionStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableUnionStruct_type_identifier();
/**
 * @brief Register MutableEmptyStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableEmptyStruct_type_identifier();
/**
 * @brief Register MutableEmptyInheritanceStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableEmptyInheritanceStruct_type_identifier();
/**
 * @brief Register MutableInheritanceStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableInheritanceStruct_type_identifier();
/**
 * @brief Register MutableInheritanceEmptyStruct related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableInheritanceEmptyStruct_type_identifier();
/**
 * @brief Register MutableExtensibilityInheritance related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_MutableExtensibilityInheritance_type_identifier();


#endif // DOXYGEN_SHOULD_SKIP_THIS_PUBLIC

#endif // _FAST_DDS_GENERATED_MUTABLE_TYPE_OBJECT_SUPPORT_HPP_
