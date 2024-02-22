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
 * @file TypeIdentifier.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include <utility>

#include <fastdds/dds/log/Log.hpp>
#include <fastdds/rtps/common/CdrSerialization.hpp>
#include <fastrtps/types/TypeIdentifier.h>
#include <fastrtps/types/TypeObjectFactory.h>

using namespace eprosima::fastcdr::exception;

#include "TypeIdentifierCdrAux.ipp"

namespace eprosima {
namespace fastrtps {

using namespace rtps;

namespace types {

TypeIdentifier::TypeIdentifier()
{
    m__d = 0x00; // Default
    memset(&m_equivalence_hash, 0, 14);
}

TypeIdentifier::~TypeIdentifier()
{
}

TypeIdentifier::TypeIdentifier(
        const TypeIdentifier& x)
{
    m__d = x.m__d;
    memset(&m_equivalence_hash, 0, 14);

    switch (m__d)
    {
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
            m_string_sdefn = x.m_string_sdefn;
            break;
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
            m_string_ldefn = x.m_string_ldefn;
            break;
        case TI_PLAIN_SEQUENCE_SMALL:
            m_seq_sdefn = x.m_seq_sdefn;
            break;
        case TI_PLAIN_SEQUENCE_LARGE:
            m_seq_ldefn = x.m_seq_ldefn;
            break;
        case TI_PLAIN_ARRAY_SMALL:
            m_array_sdefn = x.m_array_sdefn;
            break;
        case TI_PLAIN_ARRAY_LARGE:
            m_array_ldefn = x.m_array_ldefn;
            break;
        case TI_PLAIN_MAP_SMALL:
            m_map_sdefn = x.m_map_sdefn;
            break;
        case TI_PLAIN_MAP_LARGE:
            m_map_ldefn = x.m_map_ldefn;
            break;
        case TI_STRONGLY_CONNECTED_COMPONENT:
            m_sc_component_id = x.m_sc_component_id;
            break;
        case EK_COMPLETE:
        case EK_MINIMAL:
            memcpy(&m_equivalence_hash, &x.m_equivalence_hash, 14);
            break;
        default:
            m_extended_defn = x.m_extended_defn;
            break;
    }
}

TypeIdentifier::TypeIdentifier(
        TypeIdentifier&& x)
{
    m__d = x.m__d;
    memset(&m_equivalence_hash, 0, 14);

    switch (m__d)
    {
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
            m_string_sdefn = x.m_string_sdefn;
            break;
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
            m_string_ldefn = x.m_string_ldefn;
            break;
        case TI_PLAIN_SEQUENCE_SMALL:
            m_seq_sdefn = x.m_seq_sdefn;
            break;
        case TI_PLAIN_SEQUENCE_LARGE:
            m_seq_ldefn = x.m_seq_ldefn;
            break;
        case TI_PLAIN_ARRAY_SMALL:
            m_array_sdefn = x.m_array_sdefn;
            break;
        case TI_PLAIN_ARRAY_LARGE:
            m_array_ldefn = x.m_array_ldefn;
            break;
        case TI_PLAIN_MAP_SMALL:
            m_map_sdefn = x.m_map_sdefn;
            break;
        case TI_PLAIN_MAP_LARGE:
            m_map_ldefn = x.m_map_ldefn;
            break;
        case TI_STRONGLY_CONNECTED_COMPONENT:
            m_sc_component_id = x.m_sc_component_id;
            break;
        case EK_COMPLETE:
        case EK_MINIMAL:
            memcpy(&m_equivalence_hash, &x.m_equivalence_hash, 14);
            break;
        default:
            m_extended_defn = x.m_extended_defn;
            break;
    }
}

TypeIdentifier& TypeIdentifier::operator =(
        const TypeIdentifier& x)
{
    m__d = x.m__d;

    switch (m__d)
    {
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
            m_string_sdefn = x.m_string_sdefn;
            break;
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
            m_string_ldefn = x.m_string_ldefn;
            break;
        case TI_PLAIN_SEQUENCE_SMALL:
            m_seq_sdefn = x.m_seq_sdefn;
            break;
        case TI_PLAIN_SEQUENCE_LARGE:
            m_seq_ldefn = x.m_seq_ldefn;
            break;
        case TI_PLAIN_ARRAY_SMALL:
            m_array_sdefn = x.m_array_sdefn;
            break;
        case TI_PLAIN_ARRAY_LARGE:
            m_array_ldefn = x.m_array_ldefn;
            break;
        case TI_PLAIN_MAP_SMALL:
            m_map_sdefn = x.m_map_sdefn;
            break;
        case TI_PLAIN_MAP_LARGE:
            m_map_ldefn = x.m_map_ldefn;
            break;
        case TI_STRONGLY_CONNECTED_COMPONENT:
            m_sc_component_id = x.m_sc_component_id;
            break;
        case EK_COMPLETE:
        case EK_MINIMAL:
            memcpy(&m_equivalence_hash, &x.m_equivalence_hash, 14);
            break;
        default:
            m_extended_defn = x.m_extended_defn;
            break;
    }

    return *this;
}

TypeIdentifier& TypeIdentifier::operator =(
        TypeIdentifier&& x)
{
    m__d = x.m__d;

    switch (m__d)
    {
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
            m_string_sdefn = x.m_string_sdefn;
            break;
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
            m_string_ldefn = x.m_string_ldefn;
            break;
        case TI_PLAIN_SEQUENCE_SMALL:
            m_seq_sdefn = x.m_seq_sdefn;
            break;
        case TI_PLAIN_SEQUENCE_LARGE:
            m_seq_ldefn = x.m_seq_ldefn;
            break;
        case TI_PLAIN_ARRAY_SMALL:
            m_array_sdefn = x.m_array_sdefn;
            break;
        case TI_PLAIN_ARRAY_LARGE:
            m_array_ldefn = x.m_array_ldefn;
            break;
        case TI_PLAIN_MAP_SMALL:
            m_map_sdefn = x.m_map_sdefn;
            break;
        case TI_PLAIN_MAP_LARGE:
            m_map_ldefn = x.m_map_ldefn;
            break;
        case TI_STRONGLY_CONNECTED_COMPONENT:
            m_sc_component_id = x.m_sc_component_id;
            break;
        case EK_COMPLETE:
        case EK_MINIMAL:
            memcpy(&m_equivalence_hash, &x.m_equivalence_hash, 14);
            break;
        default:
            m_extended_defn = x.m_extended_defn;
            break;
    }

    return *this;
}

void TypeIdentifier::_d(
        octet __d)                 // Special case to ease... sets the current active member
{
    bool b = false;
    m__d = __d;

    switch (m__d)
    {
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
            switch (__d)
            {
                case TI_STRING8_SMALL:
                case TI_STRING16_SMALL:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
            switch (__d)
            {
                case TI_STRING8_LARGE:
                case TI_STRING16_LARGE:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        case TI_PLAIN_SEQUENCE_SMALL:
            switch (__d)
            {
                case TI_PLAIN_SEQUENCE_SMALL:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        case TI_PLAIN_SEQUENCE_LARGE:
            switch (__d)
            {
                case TI_PLAIN_SEQUENCE_LARGE:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        case TI_PLAIN_ARRAY_SMALL:
            switch (__d)
            {
                case TI_PLAIN_ARRAY_SMALL:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        case TI_PLAIN_ARRAY_LARGE:
            switch (__d)
            {
                case TI_PLAIN_ARRAY_LARGE:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        case TI_PLAIN_MAP_SMALL:
            switch (__d)
            {
                case TI_PLAIN_MAP_SMALL:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        case TI_PLAIN_MAP_LARGE:
            switch (__d)
            {
                case TI_PLAIN_MAP_LARGE:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        case TI_STRONGLY_CONNECTED_COMPONENT:
            switch (__d)
            {
                case TI_STRONGLY_CONNECTED_COMPONENT:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        case EK_COMPLETE:
        case EK_MINIMAL:
            switch (__d)
            {
                case EK_COMPLETE:
                case EK_MINIMAL:
                    b = true;
                    break;
                default:
                    break;
            }
            break;
        default:
            switch (__d)
            {
                case TI_PLAIN_ARRAY_SMALL:
                case TI_PLAIN_SEQUENCE_LARGE:
                case TI_PLAIN_SEQUENCE_SMALL:
                case TI_STRING8_LARGE:
                case TI_STRING16_LARGE:
                case TI_STRING8_SMALL:
                case TI_STRING16_SMALL:
                case TI_PLAIN_ARRAY_LARGE:
                case TI_PLAIN_MAP_SMALL:
                case TI_PLAIN_MAP_LARGE:
                case TI_STRONGLY_CONNECTED_COMPONENT:
                case EK_COMPLETE:
                case EK_MINIMAL:
                    break;
                default:
                    b = true;
                    break;
            }
            break;
    }

    if (!b)
    {
        throw BadParamException("Discriminator doesn't correspond with the selected union member");
    }

    m__d = __d;
}

octet TypeIdentifier::_d() const
{
    return m__d;
}

octet& TypeIdentifier::_d()
{
    return m__d;
}

void TypeIdentifier::string_sdefn(
        StringSTypeDefn _string_sdefn)
{
    m_string_sdefn = _string_sdefn;
    m__d = TI_STRING8_SMALL;
}

const StringSTypeDefn& TypeIdentifier::string_sdefn() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_string_sdefn;
}

StringSTypeDefn& TypeIdentifier::string_sdefn()
{
    bool b = false;

    switch (m__d)
    {
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_string_sdefn;
}

void TypeIdentifier::string_ldefn(
        StringLTypeDefn _string_ldefn)
{
    m_string_ldefn = _string_ldefn;
    m__d = TI_STRING8_LARGE;
}

const StringLTypeDefn& TypeIdentifier::string_ldefn() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_string_ldefn;
}

StringLTypeDefn& TypeIdentifier::string_ldefn()
{
    bool b = false;

    switch (m__d)
    {
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_string_ldefn;
}

void TypeIdentifier::seq_sdefn(
        PlainSequenceSElemDefn _seq_sdefn)
{
    m_seq_sdefn = _seq_sdefn;
    m__d = TI_PLAIN_SEQUENCE_SMALL;
}

const PlainSequenceSElemDefn& TypeIdentifier::seq_sdefn() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_SEQUENCE_SMALL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_seq_sdefn;
}

PlainSequenceSElemDefn& TypeIdentifier::seq_sdefn()
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_SEQUENCE_SMALL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_seq_sdefn;
}

void TypeIdentifier::seq_ldefn(
        PlainSequenceLElemDefn _seq_ldefn)
{
    m_seq_ldefn = _seq_ldefn;
    m__d = TI_PLAIN_SEQUENCE_LARGE;
}

const PlainSequenceLElemDefn& TypeIdentifier::seq_ldefn() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_SEQUENCE_LARGE:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_seq_ldefn;
}

PlainSequenceLElemDefn& TypeIdentifier::seq_ldefn()
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_SEQUENCE_LARGE:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_seq_ldefn;
}

void TypeIdentifier::array_sdefn(
        PlainArraySElemDefn _array_sdefn)
{
    m_array_sdefn = _array_sdefn;
    m__d = TI_PLAIN_ARRAY_SMALL;
}

const PlainArraySElemDefn& TypeIdentifier::array_sdefn() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_ARRAY_SMALL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_array_sdefn;
}

PlainArraySElemDefn& TypeIdentifier::array_sdefn()
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_ARRAY_SMALL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_array_sdefn;
}

void TypeIdentifier::array_ldefn(
        PlainArrayLElemDefn _array_ldefn)
{
    m_array_ldefn = _array_ldefn;
    m__d = TI_PLAIN_ARRAY_LARGE;
}

const PlainArrayLElemDefn& TypeIdentifier::array_ldefn() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_ARRAY_LARGE:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_array_ldefn;
}

PlainArrayLElemDefn& TypeIdentifier::array_ldefn()
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_ARRAY_LARGE:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_array_ldefn;
}

void TypeIdentifier::map_sdefn(
        PlainMapSTypeDefn _map_sdefn)
{
    m_map_sdefn = _map_sdefn;
    m__d = TI_PLAIN_MAP_SMALL;
}

const PlainMapSTypeDefn& TypeIdentifier::map_sdefn() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_MAP_SMALL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_map_sdefn;
}

PlainMapSTypeDefn& TypeIdentifier::map_sdefn()
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_MAP_SMALL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_map_sdefn;
}

void TypeIdentifier::map_ldefn(
        PlainMapLTypeDefn _map_ldefn)
{
    m_map_ldefn = _map_ldefn;
    m__d = TI_PLAIN_MAP_LARGE;
}

const PlainMapLTypeDefn& TypeIdentifier::map_ldefn() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_MAP_LARGE:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_map_ldefn;
}

PlainMapLTypeDefn& TypeIdentifier::map_ldefn()
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_MAP_LARGE:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_map_ldefn;
}

void TypeIdentifier::sc_component_id(
        StronglyConnectedComponentId _sc_component_id)
{
    m_sc_component_id = _sc_component_id;
    m__d = TI_STRONGLY_CONNECTED_COMPONENT;
}

StronglyConnectedComponentId TypeIdentifier::sc_component_id() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_STRONGLY_CONNECTED_COMPONENT:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_sc_component_id;
}

StronglyConnectedComponentId& TypeIdentifier::sc_component_id()
{
    bool b = false;

    switch (m__d)
    {
        case TI_STRONGLY_CONNECTED_COMPONENT:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_sc_component_id;
}

void TypeIdentifier::equivalence_hash(
        EquivalenceHash _equivalence_hash)
{
    memcpy(m_equivalence_hash, _equivalence_hash, 14);
    m__d = EK_COMPLETE;
}

const octet* TypeIdentifier::equivalence_hash() const
{
    bool b = false;

    switch (m__d)
    {
        case EK_COMPLETE:
        case EK_MINIMAL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return (octet*)&m_equivalence_hash;
}

octet* TypeIdentifier::equivalence_hash()
{
    bool b = false;

    switch (m__d)
    {
        case EK_COMPLETE:
        case EK_MINIMAL:
            b = true;
            break;
        default:
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return (octet*)&m_equivalence_hash;
}

std::string TypeIdentifier::equivalence_hash_to_string() const
{
    std::stringstream ss;
    if (m__d >= EK_MINIMAL)
    {
        ss << std::hex << m_equivalence_hash[0];
        for (uint8_t i = 1; i < 14; ++i)
        {
            ss << std::hex << ":" << (uint32_t)m_equivalence_hash[i];
        }
    }
    return ss.str();
}

void TypeIdentifier::extended_defn(
        ExtendedTypeDefn _extended_defn)
{
    m_extended_defn = _extended_defn;
    m__d = 0x00; // Default
}

const ExtendedTypeDefn& TypeIdentifier::extended_defn() const
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_ARRAY_SMALL:
        case TI_PLAIN_SEQUENCE_LARGE:
        case TI_PLAIN_SEQUENCE_SMALL:
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
        case TI_PLAIN_ARRAY_LARGE:
        case TI_PLAIN_MAP_SMALL:
        case TI_PLAIN_MAP_LARGE:
        case TI_STRONGLY_CONNECTED_COMPONENT:
        case EK_COMPLETE:
        case EK_MINIMAL:
            break;
        default:
            b = true;
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }


    return m_extended_defn;
}

ExtendedTypeDefn& TypeIdentifier::extended_defn()
{
    bool b = false;

    switch (m__d)
    {
        case TI_PLAIN_ARRAY_SMALL:
        case TI_PLAIN_SEQUENCE_LARGE:
        case TI_PLAIN_SEQUENCE_SMALL:
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
        case TI_PLAIN_ARRAY_LARGE:
        case TI_PLAIN_MAP_SMALL:
        case TI_PLAIN_MAP_LARGE:
        case TI_STRONGLY_CONNECTED_COMPONENT:
        case EK_COMPLETE:
        case EK_MINIMAL:
            break;
        default:
            b = true;
            break;
    }
    if (!b)
    {
        throw BadParamException("This member is not been selected");
    }

    return m_extended_defn;
}

// size_t TypeIdentifier::getMaxCdrSerializedSize(size_t current_alignment)
// {
//     size_t initial_alignment = current_alignment;
//     size_t reset_alignment = 0;
//     size_t union_max_size_serialized = 0;

//     current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


//         reset_alignment = current_alignment;

//         reset_alignment += StringSTypeDefn::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += StringLTypeDefn::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += PlainSequenceSElemDefn::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += PlainSequenceLElemDefn::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += PlainArraySElemDefn::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += PlainArrayLElemDefn::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += PlainMapSTypeDefn::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += PlainMapLTypeDefn::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += StronglyConnectedComponentId::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += 14 + eprosima::fastcdr::Cdr::alignment(reset_alignment, 14);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;


//         reset_alignment = current_alignment;

//         reset_alignment += ExtendedTypeDefn::getMaxCdrSerializedSize(reset_alignment);


//         if(union_max_size_serialized < reset_alignment)
//             union_max_size_serialized = reset_alignment;



//     return union_max_size_serialized - initial_alignment;
// }

bool TypeIdentifier::operator ==(
        const TypeIdentifier& other) const
{
    if (this == &other)
    {
        return true;                 // Same memory!

    }
    if (this->_d() != other._d())
    {
        return false;
    }

    switch (this->_d())
    {
        case TK_NONE:
        case TK_BOOLEAN:
        case TK_BYTE:
        case TK_INT16:
        case TK_INT32:
        case TK_INT64:
        case TK_UINT16:
        case TK_UINT32:
        case TK_UINT64:
        case TK_FLOAT32:
        case TK_FLOAT64:
        case TK_FLOAT128:
        case TK_CHAR8:
        case TK_CHAR16:
            return true;
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
            return this->string_sdefn().bound() == other.string_sdefn().bound();

        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
            return this->string_ldefn().bound() == other.string_ldefn().bound();

        case TI_PLAIN_SEQUENCE_SMALL:
            return this->seq_sdefn().bound() == other.seq_sdefn().bound()
                   && *this->seq_sdefn().element_identifier() == *other.seq_sdefn().element_identifier();

        case TI_PLAIN_SEQUENCE_LARGE:
            return this->seq_ldefn().bound() == other.seq_ldefn().bound()
                   && *this->seq_ldefn().element_identifier() == *other.seq_ldefn().element_identifier();

        case TI_PLAIN_ARRAY_SMALL:
        {
            if (this->array_sdefn().array_bound_seq().size() != other.array_sdefn().array_bound_seq().size())
            {
                return false;
            }
            for (uint32_t idx = 0; idx < this->array_sdefn().array_bound_seq().size(); ++idx)
            {
                if (this->array_sdefn().array_bound_seq()[idx] != other.array_sdefn().array_bound_seq()[idx])
                {
                    return false;
                }
            }
            return *this->array_sdefn().element_identifier() == *other.array_sdefn().element_identifier();
        }

        case TI_PLAIN_ARRAY_LARGE:
        {
            if (this->array_ldefn().array_bound_seq().size() != other.array_ldefn().array_bound_seq().size())
            {
                return false;
            }
            for (uint32_t idx = 0; idx < this->array_ldefn().array_bound_seq().size(); ++idx)
            {
                if (this->array_ldefn().array_bound_seq()[idx] != other.array_ldefn().array_bound_seq()[idx])
                {
                    return false;
                }
            }
            return *this->array_ldefn().element_identifier() == *other.array_ldefn().element_identifier();
        }

        case TI_PLAIN_MAP_SMALL:
            return this->map_sdefn().bound() == other.map_sdefn().bound()
                   && *this->map_sdefn().key_identifier() == *other.map_sdefn().key_identifier()
                   && *this->map_sdefn().element_identifier() == *other.map_sdefn().element_identifier();

        case TI_PLAIN_MAP_LARGE:
            return this->map_ldefn().bound() == other.map_ldefn().bound()
                   && *this->map_ldefn().key_identifier() == *other.map_ldefn().key_identifier()
                   && *this->map_ldefn().element_identifier() == *other.map_ldefn().element_identifier();

        case EK_MINIMAL:
        case EK_COMPLETE:
        {
            //return memcmp(this->equivalence_hash(), other.equivalence_hash(), 14) == 0;
            for (int i = 0; i < 14; ++i)
            {
                if (this->equivalence_hash()[i] != other.equivalence_hash()[i])
                {
                    return false;
                }
            }
            return true;
        }
        default:
            break;
    }
    return false;
}

bool TypeIdentifier::consistent(
        const TypeIdentifier& x,
        const fastdds::dds::TypeConsistencyEnforcementQosPolicy& consistency) const
{
    if (this == &x)
    {
        return true;             // Same memory!

    }
    switch (this->_d())
    {
        case TK_NONE:
        case TK_BOOLEAN:
        case TK_BYTE:
        case TK_INT16:
        case TK_INT32:
        case TK_INT64:
        case TK_UINT16:
        case TK_UINT32:
        case TK_UINT64:
        case TK_FLOAT32:
        case TK_FLOAT64:
        case TK_FLOAT128:
        case TK_CHAR8:
        case TK_CHAR16:
            if (this->_d() != x._d())
            {
                return false;
            }
            return true;
        case TI_STRING8_SMALL:
        case TI_STRING16_SMALL:
        case TI_STRING8_LARGE:
        case TI_STRING16_LARGE:
            if (_d() == TI_STRING8_SMALL && x._d() == TI_STRING8_SMALL)
            {
                return this->string_sdefn().consistent(x.string_sdefn(), consistency);
            }
            else if (_d() == TI_STRING8_SMALL && x._d() == TI_STRING8_LARGE)
            {
                return this->string_sdefn().consistent(x.string_ldefn(), consistency);
            }
            else if (_d() == TI_STRING16_SMALL && x._d() == TI_STRING16_SMALL)
            {
                return this->string_sdefn().consistent(x.string_sdefn(), consistency);
            }
            else if (_d() == TI_STRING16_SMALL && x._d() == TI_STRING16_LARGE)
            {
                return this->string_sdefn().consistent(x.string_ldefn(), consistency);
            }
            else if (_d() == TI_STRING8_LARGE && x._d() == TI_STRING8_SMALL)
            {
                return this->string_ldefn().consistent(x.string_sdefn(), consistency);
            }
            else if (_d() == TI_STRING8_LARGE && x._d() == TI_STRING8_LARGE)
            {
                return this->string_ldefn().consistent(x.string_ldefn(), consistency);
            }
            else if (_d() == TI_STRING16_LARGE && x._d() == TI_STRING16_SMALL)
            {
                return this->string_ldefn().consistent(x.string_sdefn(), consistency);
            }
            else if (_d() == TI_STRING16_LARGE && x._d() == TI_STRING16_LARGE)
            {
                return this->string_ldefn().consistent(x.string_ldefn(), consistency);
            }
            else
            {
                return false;
            }

        case TI_PLAIN_SEQUENCE_SMALL:
            return this->seq_sdefn().consistent(x.seq_sdefn(), consistency);

        case TI_PLAIN_SEQUENCE_LARGE:
            return this->seq_ldefn().consistent(x.seq_ldefn(), consistency);

        case TI_PLAIN_ARRAY_SMALL:
            return this->array_sdefn().consistent(x.array_sdefn(), consistency);

        case TI_PLAIN_ARRAY_LARGE:
            return this->array_ldefn().consistent(x.array_ldefn(), consistency);

        case TI_PLAIN_MAP_SMALL:
            return this->map_sdefn().consistent(x.map_sdefn(), consistency);

        case TI_PLAIN_MAP_LARGE:
            return this->map_ldefn().consistent(x.map_ldefn(), consistency);

        case EK_MINIMAL:
        case EK_COMPLETE:
        {
            if (this->_d() != x._d())
            {
                return false;
            }

            const TypeObject* localObj = TypeObjectFactory::get_instance()->get_type_object(this);
            const TypeObject* remoteObj = TypeObjectFactory::get_instance()->get_type_object(&x);
            if (localObj == nullptr)
            {
                EPROSIMA_LOG_WARNING(XTYPES, "Local TypeIdentifier doesn't have a related TypeObject");
                return false;
            }
            if (remoteObj == nullptr)
            {
                EPROSIMA_LOG_WARNING(XTYPES, "Remote TypeIdentifier doesn't have a related TypeObject");
                return false;
            }
            return localObj->consistent(*remoteObj, consistency);
        }
        default:
            break;
    }
    return false;
}

} // namespace types
} // namespace fastrtps
} // namespace eprosima
