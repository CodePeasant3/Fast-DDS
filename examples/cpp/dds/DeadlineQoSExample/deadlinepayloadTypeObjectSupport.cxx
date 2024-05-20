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
 * @file deadlinepayloadTypeObjectSupport.cxx
 * Source file containing the implementation to register the TypeObject representation of the described types in the IDL file
 *
 * This file was generated by the tool fastddsgen.
 */

#include "deadlinepayloadTypeObjectSupport.hpp"

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

#include "deadlinepayload.hpp"


using namespace eprosima::fastdds::dds::xtypes;

void register_deadlinepayload_type_objects()
{
    static std::once_flag once_flag;
    std::call_once(once_flag, []()
            {
                TypeIdentifier type_id;
                register_HelloMsg_type_identifier(type_id);

            });
}

// TypeIdentifier is returned by reference: dependent structures/unions are registered in this same method
void register_HelloMsg_type_identifier(
        TypeIdentifier& type_id)
{
    {
        StructTypeFlag struct_flags_HelloMsg = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::NOT_APPLIED,
                false, false);
        ReturnCode_t return_code_HelloMsg;
        TypeIdentifierPair type_ids_HelloMsg;
        QualifiedTypeName type_name_HelloMsg = "HelloMsg";
        eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin_HelloMsg;
        eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom_HelloMsg;
        CompleteTypeDetail detail_HelloMsg = TypeObjectUtils::build_complete_type_detail(type_ann_builtin_HelloMsg, ann_custom_HelloMsg, type_name_HelloMsg.to_string());
        CompleteStructHeader header_HelloMsg;
        header_HelloMsg = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail_HelloMsg);
        CompleteStructMemberSeq member_seq_HelloMsg;
        {
            return_code_HelloMsg =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_uint16_t", type_ids_HelloMsg);

            if (return_code_HelloMsg != eprosima::fastdds::dds::RETCODE_OK)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "deadlinekey Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                type_id = TypeIdentifier();
                return;
            }
            StructMemberFlag member_flags_deadlinekey = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, true, false);
            CommonStructMember common_deadlinekey;
            MemberId member_id_deadlinekey = 0x00000000;
            if (EK_COMPLETE == type_ids_HelloMsg.type_identifier1()._d() || TK_NONE == type_ids_HelloMsg.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_HelloMsg.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_HelloMsg.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_HelloMsg.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_HelloMsg.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_HelloMsg.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_HelloMsg.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_HelloMsg.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_HelloMsg.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common_deadlinekey = TypeObjectUtils::build_common_struct_member(member_id_deadlinekey, member_flags_deadlinekey, type_ids_HelloMsg.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids_HelloMsg.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_HelloMsg.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_HelloMsg.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_HelloMsg.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_HelloMsg.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_HelloMsg.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_HelloMsg.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_HelloMsg.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_HelloMsg.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common_deadlinekey = TypeObjectUtils::build_common_struct_member(member_id_deadlinekey, member_flags_deadlinekey, type_ids_HelloMsg.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure deadlinekey member TypeIdentifier inconsistent.");
                type_id = TypeIdentifier();
                return;
            }
            MemberName name_deadlinekey = "deadlinekey";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_deadlinekey;
            ann_custom_HelloMsg.reset();
            AppliedAnnotationSeq tmp_ann_custom_deadlinekey;
            eprosima::fastcdr::optional<std::string> unit_deadlinekey;
            eprosima::fastcdr::optional<AnnotationParameterValue> min_deadlinekey;
            eprosima::fastcdr::optional<AnnotationParameterValue> max_deadlinekey;
            eprosima::fastcdr::optional<std::string> hash_id_deadlinekey;
            if (unit_deadlinekey.has_value() || min_deadlinekey.has_value() || max_deadlinekey.has_value() || hash_id_deadlinekey.has_value())
            {
                member_ann_builtin_deadlinekey = TypeObjectUtils::build_applied_builtin_member_annotations(unit_deadlinekey, min_deadlinekey, max_deadlinekey, hash_id_deadlinekey);
            }
            if (!tmp_ann_custom_deadlinekey.empty())
            {
                ann_custom_HelloMsg = tmp_ann_custom_deadlinekey;
            }
            CompleteMemberDetail detail_deadlinekey = TypeObjectUtils::build_complete_member_detail(name_deadlinekey, member_ann_builtin_deadlinekey, ann_custom_HelloMsg);
            CompleteStructMember member_deadlinekey = TypeObjectUtils::build_complete_struct_member(common_deadlinekey, detail_deadlinekey);
            TypeObjectUtils::add_complete_struct_member(member_seq_HelloMsg, member_deadlinekey);
        }
        {
            return_code_HelloMsg =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "anonymous_string_256", type_ids_HelloMsg);

            if (return_code_HelloMsg != eprosima::fastdds::dds::RETCODE_OK)
            {
                {
                    LBound bound = 256;
                    StringLTypeDefn string_ldefn = TypeObjectUtils::build_string_l_type_defn(bound);
                    if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                            TypeObjectUtils::build_and_register_l_string_type_identifier(string_ldefn,
                            "anonymous_string_256"))
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                            "anonymous_string_256 already registered in TypeObjectRegistry for a different type.");
                    }
                }
                return_code_HelloMsg =
                    eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                    "anonymous_string_256", type_ids_HelloMsg);
                if (return_code_HelloMsg != eprosima::fastdds::dds::RETCODE_OK)
                {
                    EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                "anonymous_string_256: Given String TypeIdentifier unknown to TypeObjectRegistry.");
                    type_id = TypeIdentifier();
                    return;
                }
            }
            StructMemberFlag member_flags_payload = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, false, false);
            CommonStructMember common_payload;
            MemberId member_id_payload = 0x00000001;
            if (EK_COMPLETE == type_ids_HelloMsg.type_identifier1()._d() || TK_NONE == type_ids_HelloMsg.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_HelloMsg.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_HelloMsg.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_HelloMsg.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_HelloMsg.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_HelloMsg.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_HelloMsg.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_HelloMsg.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_HelloMsg.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common_payload = TypeObjectUtils::build_common_struct_member(member_id_payload, member_flags_payload, type_ids_HelloMsg.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids_HelloMsg.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_HelloMsg.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_HelloMsg.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_HelloMsg.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_HelloMsg.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_HelloMsg.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_HelloMsg.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_HelloMsg.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_HelloMsg.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_HelloMsg.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common_payload = TypeObjectUtils::build_common_struct_member(member_id_payload, member_flags_payload, type_ids_HelloMsg.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure payload member TypeIdentifier inconsistent.");
                type_id = TypeIdentifier();
                return;
            }
            MemberName name_payload = "payload";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_payload;
            ann_custom_HelloMsg.reset();
            CompleteMemberDetail detail_payload = TypeObjectUtils::build_complete_member_detail(name_payload, member_ann_builtin_payload, ann_custom_HelloMsg);
            CompleteStructMember member_payload = TypeObjectUtils::build_complete_struct_member(common_payload, detail_payload);
            TypeObjectUtils::add_complete_struct_member(member_seq_HelloMsg, member_payload);
        }
        CompleteStructType struct_type_HelloMsg = TypeObjectUtils::build_complete_struct_type(struct_flags_HelloMsg, header_HelloMsg, member_seq_HelloMsg);
        if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                TypeObjectUtils::build_and_register_struct_type_object(struct_type_HelloMsg, type_name_HelloMsg.to_string(), type_id))
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                    "HelloMsg already registered in TypeObjectRegistry for a different type.");
        }
        return_code_HelloMsg =
            eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
            "HelloMsg", type_ids_HelloMsg);
        if (return_code_HelloMsg != eprosima::fastdds::dds::RETCODE_OK)
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "HelloMsg: Given Struct TypeIdentifier unknown to TypeObjectRegistry.");
            type_id = TypeIdentifier();
            return;
        }
    }
}

