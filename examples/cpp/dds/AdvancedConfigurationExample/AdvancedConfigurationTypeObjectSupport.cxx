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
 * @file AdvancedConfigurationTypeObjectSupport.cxx
 * Source file containing the implementation to register the TypeObject representation of the described types in the IDL file
 *
 * This file was generated by the tool fastddsgen.
 */

#include "AdvancedConfigurationTypeObjectSupport.hpp"

#include <mutex>
#include <string>

#include <fastcdr/xcdr/external.hpp>
#include <fastcdr/xcdr/optional.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/log/Log.hpp>
#include <fastdds/dds/xtypes/common.hpp>
#include <fastdds/dds/xtypes/type_representation/ITypeObjectRegistry.hpp>
#include <fastdds/dds/xtypes/type_representation/TypeObject.hpp>
#include <fastdds/dds/xtypes/type_representation/TypeObjectUtils.hpp>

#include "AdvancedConfiguration.hpp"


using namespace eprosima::fastdds::dds::xtypes;

void register_AdvancedConfiguration_type_objects()
{
    static std::once_flag once_flag;
    std::call_once(once_flag, []()
            {
                TypeIdentifier type_id;
                register_AdvancedConfiguration_type_identifier(type_id);

            });
}

// TypeIdentifier is returned by reference: dependent structures/unions are registered in this same method
void register_AdvancedConfiguration_type_identifier(
        TypeIdentifier& type_id)
{
    {
        StructTypeFlag struct_flags_AdvancedConfiguration = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::NOT_APPLIED,
                false, false);
        ReturnCode_t return_code_AdvancedConfiguration;
        TypeIdentifierPair type_ids_AdvancedConfiguration;
        QualifiedTypeName type_name_AdvancedConfiguration = "AdvancedConfiguration";
        eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin_AdvancedConfiguration;
        eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom_AdvancedConfiguration;
        CompleteTypeDetail detail_AdvancedConfiguration = TypeObjectUtils::build_complete_type_detail(type_ann_builtin_AdvancedConfiguration, ann_custom_AdvancedConfiguration, type_name_AdvancedConfiguration.to_string());
        CompleteStructHeader header_AdvancedConfiguration;
        header_AdvancedConfiguration = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail_AdvancedConfiguration);
        CompleteStructMemberSeq member_seq_AdvancedConfiguration;
        {
            return_code_AdvancedConfiguration =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_uint32_t", type_ids_AdvancedConfiguration);

            if (return_code_AdvancedConfiguration != eprosima::fastdds::dds::RETCODE_OK)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "index Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                type_id = TypeIdentifier();
                return;
            }
            StructMemberFlag member_flags_index = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, false, false);
            CommonStructMember common_index;
            MemberId member_id_index = 0x00000000;
            if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1()._d() || TK_NONE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common_index = TypeObjectUtils::build_common_struct_member(member_id_index, member_flags_index, type_ids_AdvancedConfiguration.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common_index = TypeObjectUtils::build_common_struct_member(member_id_index, member_flags_index, type_ids_AdvancedConfiguration.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure index member TypeIdentifier inconsistent.");
                type_id = TypeIdentifier();
                return;
            }
            MemberName name_index = "index";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_index;
            ann_custom_AdvancedConfiguration.reset();
            CompleteMemberDetail detail_index = TypeObjectUtils::build_complete_member_detail(name_index, member_ann_builtin_index, ann_custom_AdvancedConfiguration);
            CompleteStructMember member_index = TypeObjectUtils::build_complete_struct_member(common_index, detail_index);
            TypeObjectUtils::add_complete_struct_member(member_seq_AdvancedConfiguration, member_index);
        }
        {
            return_code_AdvancedConfiguration =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "anonymous_array_char_20", type_ids_AdvancedConfiguration);

            if (return_code_AdvancedConfiguration != eprosima::fastdds::dds::RETCODE_OK)
            {
                return_code_AdvancedConfiguration =
                    eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                    "_char", type_ids_AdvancedConfiguration);

                if (return_code_AdvancedConfiguration != eprosima::fastdds::dds::RETCODE_OK)
                {
                    EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                            "Array element TypeIdentifier unknown to TypeObjectRegistry.");
                    type_id = TypeIdentifier();
                    return;
                }
                TypeIdentifier* element_identifier_anonymous_array_char_20 {nullptr};
                if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1()._d() || TK_NONE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                        (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                        (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().key_identifier()->_d())))
                {
                    element_identifier_anonymous_array_char_20 = new TypeIdentifier(type_ids_AdvancedConfiguration.type_identifier1());
                }
                else if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                        (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                        (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().key_identifier()->_d())))
                {
                    element_identifier_anonymous_array_char_20 = new TypeIdentifier(type_ids_AdvancedConfiguration.type_identifier2());
                }
                else
                {
                    EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Array element TypeIdentifier inconsistent.");
                    type_id = TypeIdentifier();
                    return;
                }
                EquivalenceKind equiv_kind_anonymous_array_char_20 = EK_COMPLETE;
                if (TK_NONE == type_ids_AdvancedConfiguration.type_identifier2()._d())
                {
                    equiv_kind_anonymous_array_char_20 = EK_BOTH;
                }
                CollectionElementFlag element_flags_anonymous_array_char_20 = 0;
                PlainCollectionHeader header_anonymous_array_char_20 = TypeObjectUtils::build_plain_collection_header(equiv_kind_anonymous_array_char_20, element_flags_anonymous_array_char_20);
                {
                    SBoundSeq array_bound_seq;
                        TypeObjectUtils::add_array_dimension(array_bound_seq, static_cast<SBound>(20));

                    PlainArraySElemDefn array_sdefn = TypeObjectUtils::build_plain_array_s_elem_defn(header_anonymous_array_char_20, array_bound_seq,
                                eprosima::fastcdr::external<TypeIdentifier>(element_identifier_anonymous_array_char_20));
                    if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                            TypeObjectUtils::build_and_register_s_array_type_identifier(array_sdefn, "anonymous_array_char_20"))
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                            "anonymous_array_char_20 already registered in TypeObjectRegistry for a different type.");
                    }
                }
                return_code_AdvancedConfiguration =
                    eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                    "anonymous_array_char_20", type_ids_AdvancedConfiguration);
                if (return_code_AdvancedConfiguration != eprosima::fastdds::dds::RETCODE_OK)
                {
                    EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                "anonymous_array_char_20: Given Array TypeIdentifier unknown to TypeObjectRegistry.");
                    type_id = TypeIdentifier();
                    return;
                }
            }
            StructMemberFlag member_flags_message = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, false, false);
            CommonStructMember common_message;
            MemberId member_id_message = 0x00000001;
            if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1()._d() || TK_NONE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common_message = TypeObjectUtils::build_common_struct_member(member_id_message, member_flags_message, type_ids_AdvancedConfiguration.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common_message = TypeObjectUtils::build_common_struct_member(member_id_message, member_flags_message, type_ids_AdvancedConfiguration.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure message member TypeIdentifier inconsistent.");
                type_id = TypeIdentifier();
                return;
            }
            MemberName name_message = "message";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_message;
            ann_custom_AdvancedConfiguration.reset();
            CompleteMemberDetail detail_message = TypeObjectUtils::build_complete_member_detail(name_message, member_ann_builtin_message, ann_custom_AdvancedConfiguration);
            CompleteStructMember member_message = TypeObjectUtils::build_complete_struct_member(common_message, detail_message);
            TypeObjectUtils::add_complete_struct_member(member_seq_AdvancedConfiguration, member_message);
        }
        {
            return_code_AdvancedConfiguration =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "anonymous_sequence_uint8_t_unbounded", type_ids_AdvancedConfiguration);

            if (return_code_AdvancedConfiguration != eprosima::fastdds::dds::RETCODE_OK)
            {
                return_code_AdvancedConfiguration =
                    eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                    "_byte", type_ids_AdvancedConfiguration);

                if (return_code_AdvancedConfiguration != eprosima::fastdds::dds::RETCODE_OK)
                {
                    EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                            "Sequence element TypeIdentifier unknown to TypeObjectRegistry.");
                    type_id = TypeIdentifier();
                    return;
                }
                TypeIdentifier* element_identifier_anonymous_sequence_uint8_t_unbounded {nullptr};
                if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1()._d() || TK_NONE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                        (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                        (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                        (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().key_identifier()->_d())))
                {
                    element_identifier_anonymous_sequence_uint8_t_unbounded = new TypeIdentifier(type_ids_AdvancedConfiguration.type_identifier1());
                }
                else if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                        (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                        (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                        (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().key_identifier()->_d())))
                {
                    element_identifier_anonymous_sequence_uint8_t_unbounded = new TypeIdentifier(type_ids_AdvancedConfiguration.type_identifier2());
                }
                else
                {
                    EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Sequence element TypeIdentifier inconsistent.");
                    type_id = TypeIdentifier();
                    return;
                }
                EquivalenceKind equiv_kind_anonymous_sequence_uint8_t_unbounded = EK_COMPLETE;
                if (TK_NONE == type_ids_AdvancedConfiguration.type_identifier2()._d())
                {
                    equiv_kind_anonymous_sequence_uint8_t_unbounded = EK_BOTH;
                }
                CollectionElementFlag element_flags_anonymous_sequence_uint8_t_unbounded = 0;
                PlainCollectionHeader header_anonymous_sequence_uint8_t_unbounded = TypeObjectUtils::build_plain_collection_header(equiv_kind_anonymous_sequence_uint8_t_unbounded, element_flags_anonymous_sequence_uint8_t_unbounded);
                {
                    SBound bound = 0;
                    PlainSequenceSElemDefn seq_sdefn = TypeObjectUtils::build_plain_sequence_s_elem_defn(header_anonymous_sequence_uint8_t_unbounded, bound,
                                eprosima::fastcdr::external<TypeIdentifier>(element_identifier_anonymous_sequence_uint8_t_unbounded));
                    if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                            TypeObjectUtils::build_and_register_s_sequence_type_identifier(seq_sdefn, "anonymous_sequence_uint8_t_unbounded"))
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                            "anonymous_sequence_uint8_t_unbounded already registered in TypeObjectRegistry for a different type.");
                    }
                }
                return_code_AdvancedConfiguration =
                    eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                    "anonymous_sequence_uint8_t_unbounded", type_ids_AdvancedConfiguration);
                if (return_code_AdvancedConfiguration != eprosima::fastdds::dds::RETCODE_OK)
                {
                    EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                "anonymous_sequence_uint8_t_unbounded: Given Sequence TypeIdentifier unknown to TypeObjectRegistry.");
                    type_id = TypeIdentifier();
                    return;
                }
            }
            StructMemberFlag member_flags_data = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, false, false);
            CommonStructMember common_data;
            MemberId member_id_data = 0x00000002;
            if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1()._d() || TK_NONE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common_data = TypeObjectUtils::build_common_struct_member(member_id_data, member_flags_data, type_ids_AdvancedConfiguration.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_AdvancedConfiguration.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_AdvancedConfiguration.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common_data = TypeObjectUtils::build_common_struct_member(member_id_data, member_flags_data, type_ids_AdvancedConfiguration.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure data member TypeIdentifier inconsistent.");
                type_id = TypeIdentifier();
                return;
            }
            MemberName name_data = "data";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_data;
            ann_custom_AdvancedConfiguration.reset();
            CompleteMemberDetail detail_data = TypeObjectUtils::build_complete_member_detail(name_data, member_ann_builtin_data, ann_custom_AdvancedConfiguration);
            CompleteStructMember member_data = TypeObjectUtils::build_complete_struct_member(common_data, detail_data);
            TypeObjectUtils::add_complete_struct_member(member_seq_AdvancedConfiguration, member_data);
        }
        CompleteStructType struct_type_AdvancedConfiguration = TypeObjectUtils::build_complete_struct_type(struct_flags_AdvancedConfiguration, header_AdvancedConfiguration, member_seq_AdvancedConfiguration);
        if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                TypeObjectUtils::build_and_register_struct_type_object(struct_type_AdvancedConfiguration, type_name_AdvancedConfiguration.to_string(), type_id))
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                    "AdvancedConfiguration already registered in TypeObjectRegistry for a different type.");
        }
        return_code_AdvancedConfiguration =
            eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
            "AdvancedConfiguration", type_ids_AdvancedConfiguration);
        if (return_code_AdvancedConfiguration != eprosima::fastdds::dds::RETCODE_OK)
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "AdvancedConfiguration: Given Struct TypeIdentifier unknown to TypeObjectRegistry.");
            type_id = TypeIdentifier();
            return;
        }
    }
}

