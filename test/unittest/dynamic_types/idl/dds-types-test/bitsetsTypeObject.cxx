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
 * @file bitsetsTypeObject.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "bitsets.h"
#include "bitsetsTypeObject.h"
#include <mutex>
#include <utility>
#include <sstream>
#include <fastrtps/rtps/common/SerializedPayload.h>
#include <fastrtps/utils/md5.h>
#include <fastrtps/types/TypeObjectFactory.h>
#include <fastrtps/types/TypeNamesGenerator.h>
#include <fastrtps/types/AnnotationParameterValue.h>
#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

using namespace eprosima::fastrtps::rtps;

void registerbitsetsTypes()
{
    static std::once_flag once_flag;
    std::call_once(once_flag, []()
            {
                TypeObjectFactory *factory = TypeObjectFactory::get_instance();
                factory->add_type_object("InnerEnumHelper", GetInnerEnumHelperIdentifier(true),
                GetInnerEnumHelperObject(true));
                factory->add_type_object("InnerEnumHelper", GetInnerEnumHelperIdentifier(false),
                GetInnerEnumHelperObject(false));

                factory->add_type_object("InnerBitMaskHelper", GetInnerBitMaskHelperIdentifier(true),
                GetInnerBitMaskHelperObject(true));
                factory->add_type_object("InnerBitMaskHelper", GetInnerBitMaskHelperIdentifier(false),
                GetInnerBitMaskHelperObject(false));

                factory->add_type_object("InnerAliasHelper", GetInnerAliasHelperIdentifier(true),
                GetInnerAliasHelperObject(true));
                factory->add_type_object("InnerAliasHelper", GetInnerAliasHelperIdentifier(false),
                GetInnerAliasHelperObject(false));

                factory->add_type_object("InnerStructureHelper", GetInnerStructureHelperIdentifier(true),
                GetInnerStructureHelperObject(true));
                factory->add_type_object("InnerStructureHelper", GetInnerStructureHelperIdentifier(false),
                GetInnerStructureHelperObject(false));

                factory->add_type_object("InnerEmptyStructureHelper", GetInnerEmptyStructureHelperIdentifier(true),
                GetInnerEmptyStructureHelperObject(true));
                factory->add_type_object("InnerEmptyStructureHelper", GetInnerEmptyStructureHelperIdentifier(false),
                GetInnerEmptyStructureHelperObject(false));

                factory->add_type_object("InnerUnionHelper", GetInnerUnionHelperIdentifier(true),
                GetInnerUnionHelperObject(true));
                factory->add_type_object("InnerUnionHelper", GetInnerUnionHelperIdentifier(false),
                GetInnerUnionHelperObject(false));

                factory->add_type_object("InnerBitsetHelper", GetInnerBitsetHelperIdentifier(true),
                GetInnerBitsetHelperObject(true));
                factory->add_type_object("InnerBitsetHelper", GetInnerBitsetHelperIdentifier(false),
                GetInnerBitsetHelperObject(false));

                factory->add_type_object("Inner_alias_bounded_string_helper", GetInner_alias_bounded_string_helperIdentifier(true),
                GetInner_alias_bounded_string_helperObject(true));
                factory->add_type_object("Inner_alias_bounded_string_helper", GetInner_alias_bounded_string_helperIdentifier(false),
                GetInner_alias_bounded_string_helperObject(false));

                factory->add_type_object("Inner_alias_bounded_wstring_helper", GetInner_alias_bounded_wstring_helperIdentifier(true),
                GetInner_alias_bounded_wstring_helperObject(true));
                factory->add_type_object("Inner_alias_bounded_wstring_helper", GetInner_alias_bounded_wstring_helperIdentifier(false),
                GetInner_alias_bounded_wstring_helperObject(false));

                factory->add_type_object("Inner_alias_array_helper", GetInner_alias_array_helperIdentifier(true),
                GetInner_alias_array_helperObject(true));
                factory->add_type_object("Inner_alias_array_helper", GetInner_alias_array_helperIdentifier(false),
                GetInner_alias_array_helperObject(false));

                factory->add_type_object("Inner_alias_sequence_helper", GetInner_alias_sequence_helperIdentifier(true),
                GetInner_alias_sequence_helperObject(true));
                factory->add_type_object("Inner_alias_sequence_helper", GetInner_alias_sequence_helperIdentifier(false),
                GetInner_alias_sequence_helperObject(false));

                factory->add_type_object("Inner_alias_map_helper", GetInner_alias_map_helperIdentifier(true),
                GetInner_alias_map_helperObject(true));
                factory->add_type_object("Inner_alias_map_helper", GetInner_alias_map_helperIdentifier(false),
                GetInner_alias_map_helperObject(false));

                factory->add_type_object("BitsetStruct", GetBitsetStructIdentifier(true),
                GetBitsetStructObject(true));
                factory->add_type_object("BitsetStruct", GetBitsetStructIdentifier(false),
                GetBitsetStructObject(false));

            });
}

const TypeIdentifier* GetBitsetStructIdentifier(bool complete)
{
    const TypeIdentifier * c_identifier = TypeObjectFactory::get_instance()->get_type_identifier("BitsetStruct", complete);
    if (c_identifier != nullptr && (!complete || c_identifier->_d() == EK_COMPLETE))
    {
        return c_identifier;
    }

    GetBitsetStructObject(complete); // Generated inside
    return TypeObjectFactory::get_instance()->get_type_identifier("BitsetStruct", complete);
}

const TypeObject* GetBitsetStructObject(bool complete)
{
    const TypeObject* c_type_object = TypeObjectFactory::get_instance()->get_type_object("BitsetStruct", complete);
    if (c_type_object != nullptr)
    {
        return c_type_object;
    }
    else if (complete)
    {
        return GetCompleteBitsetStructObject();
    }
    //else
    return GetMinimalBitsetStructObject();
}

const TypeObject* GetMinimalBitsetStructObject()
{
    const TypeObject* c_type_object = TypeObjectFactory::get_instance()->get_type_object("BitsetStruct", false);
    if (c_type_object != nullptr)
    {
        return c_type_object;
    }

    TypeObject *type_object = new TypeObject();
    type_object->_d(EK_MINIMAL);
    type_object->minimal()._d(TK_STRUCTURE);

    type_object->minimal().struct_type().struct_flags().IS_FINAL(false);
    type_object->minimal().struct_type().struct_flags().IS_APPENDABLE(false);
    type_object->minimal().struct_type().struct_flags().IS_MUTABLE(false);
    type_object->minimal().struct_type().struct_flags().IS_NESTED(false);
    type_object->minimal().struct_type().struct_flags().IS_AUTOID_HASH(false); // Unsupported

    MemberId memberId = 0;
    MinimalStructMember mst_var_InnerBitsetHelper;
    mst_var_InnerBitsetHelper.common().member_id(memberId++);
    mst_var_InnerBitsetHelper.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
    mst_var_InnerBitsetHelper.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
    mst_var_InnerBitsetHelper.common().member_flags().IS_EXTERNAL(false); // Unsupported
    mst_var_InnerBitsetHelper.common().member_flags().IS_OPTIONAL(false);
    mst_var_InnerBitsetHelper.common().member_flags().IS_MUST_UNDERSTAND(false);
    mst_var_InnerBitsetHelper.common().member_flags().IS_KEY(false);
    mst_var_InnerBitsetHelper.common().member_flags().IS_DEFAULT(false); // Doesn't apply
    mst_var_InnerBitsetHelper.common().member_type_id(*GetInnerBitsetHelperIdentifier(false));
    MD5 var_InnerBitsetHelper_hash("var_InnerBitsetHelper");
    for(int i = 0; i < 4; ++i)
    {
        mst_var_InnerBitsetHelper.detail().name_hash()[i] = var_InnerBitsetHelper_hash.digest[i];
    }
    type_object->minimal().struct_type().member_seq().emplace_back(mst_var_InnerBitsetHelper);


    // Header
    // TODO Inheritance
    //type_object->minimal().struct_type().header().base_type()._d(EK_MINIMAL);
    //type_object->minimal().struct_type().header().base_type().equivalence_hash()[0..13];

    TypeIdentifier identifier;
    identifier._d(EK_MINIMAL);

    SerializedPayload_t payload(static_cast<uint32_t>(
        MinimalStructType::getCdrSerializedSize(type_object->minimal().struct_type()) + 4));
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
    // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
    eprosima::fastcdr::Cdr ser(
        fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
        eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
    payload.encapsulation = CDR_LE;

    type_object->serialize(ser);
    payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
    MD5 objectHash;
    objectHash.update((char*)payload.data, payload.length);
    objectHash.finalize();
    for(int i = 0; i < 14; ++i)
    {
        identifier.equivalence_hash()[i] = objectHash.digest[i];
    }

    TypeObjectFactory::get_instance()->add_type_object("BitsetStruct", &identifier, type_object);
    delete type_object;
    return TypeObjectFactory::get_instance()->get_type_object("BitsetStruct", false);
}

const TypeObject* GetCompleteBitsetStructObject()
{
    const TypeObject* c_type_object = TypeObjectFactory::get_instance()->get_type_object("BitsetStruct", true);
    if (c_type_object != nullptr && c_type_object->_d() == EK_COMPLETE)
    {
        return c_type_object;
    }

    TypeObject *type_object = new TypeObject();
    type_object->_d(EK_COMPLETE);
    type_object->complete()._d(TK_STRUCTURE);

    type_object->complete().struct_type().struct_flags().IS_FINAL(false);
    type_object->complete().struct_type().struct_flags().IS_APPENDABLE(false);
    type_object->complete().struct_type().struct_flags().IS_MUTABLE(false);
    type_object->complete().struct_type().struct_flags().IS_NESTED(false);
    type_object->complete().struct_type().struct_flags().IS_AUTOID_HASH(false); // Unsupported

    MemberId memberId = 0;
    CompleteStructMember cst_var_InnerBitsetHelper;
    cst_var_InnerBitsetHelper.common().member_id(memberId++);
    cst_var_InnerBitsetHelper.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
    cst_var_InnerBitsetHelper.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
    cst_var_InnerBitsetHelper.common().member_flags().IS_EXTERNAL(false); // Unsupported
    cst_var_InnerBitsetHelper.common().member_flags().IS_OPTIONAL(false);
    cst_var_InnerBitsetHelper.common().member_flags().IS_MUST_UNDERSTAND(false);
    cst_var_InnerBitsetHelper.common().member_flags().IS_KEY(false);
    cst_var_InnerBitsetHelper.common().member_flags().IS_DEFAULT(false); // Doesn't apply
    cst_var_InnerBitsetHelper.common().member_type_id(*GetInnerBitsetHelperIdentifier(true));
    cst_var_InnerBitsetHelper.detail().name("var_InnerBitsetHelper");

    type_object->complete().struct_type().member_seq().emplace_back(cst_var_InnerBitsetHelper);


    // Header
    type_object->complete().struct_type().header().detail().type_name("BitsetStruct");
    // TODO inheritance


    TypeIdentifier identifier;
    identifier._d(EK_COMPLETE);

    SerializedPayload_t payload(static_cast<uint32_t>(
        CompleteStructType::getCdrSerializedSize(type_object->complete().struct_type()) + 4));
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
    // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
    eprosima::fastcdr::Cdr ser(
        fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
        eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
    payload.encapsulation = CDR_LE;

    type_object->serialize(ser);
    payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
    MD5 objectHash;
    objectHash.update((char*)payload.data, payload.length);
    objectHash.finalize();
    for(int i = 0; i < 14; ++i)
    {
        identifier.equivalence_hash()[i] = objectHash.digest[i];
    }

    TypeObjectFactory::get_instance()->add_type_object("BitsetStruct", &identifier, type_object);
    delete type_object;
    return TypeObjectFactory::get_instance()->get_type_object("BitsetStruct", true);
}