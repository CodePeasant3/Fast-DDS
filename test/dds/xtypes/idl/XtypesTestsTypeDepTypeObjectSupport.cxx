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
 * @file XtypesTestsTypeDepTypeObjectSupport.cxx
 * Source file containing the implementation to register the TypeObject representation of the described types in the IDL file
 *
 * This file was generated by the tool fastddsgen.
 */

#include "XtypesTestsTypeDepTypeObjectSupport.hpp"

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

#include "XtypesTestsTypeDep.hpp"

#include "XtypesTestsType1.hpp"
#include "XtypesTestsType2.hpp"
#include "XtypesTestsType3.hpp"

using namespace eprosima::fastdds::dds::xtypes;

void register_XtypesTestsTypeDep_type_objects()
{
    static std::once_flag once_flag;
    std::call_once(once_flag, []()
            {
                register_Type1_type_identifier();

                register_Type2_type_identifier();

                register_Type3_type_identifier();

                register_TypeDep_type_identifier();

            });
}

void register_TypeDep_type_identifier()
{
    {
        StructTypeFlag struct_flags = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::NOT_APPLIED,
                false, false);
        ReturnCode_t return_code;
        TypeIdentifierPair type_ids;
        QualifiedTypeName type_name = "TypeDep";
        eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin;
        eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom;
        CompleteTypeDetail detail = TypeObjectUtils::build_complete_type_detail(type_ann_builtin, ann_custom, type_name.to_string());
        CompleteStructHeader header;
        header = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail);
        CompleteStructMemberSeq member_seq;
        {
            StructMemberFlag member_flags = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, false, false);
            return_code =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "Type1", type_ids);

            if (return_code != eprosima::fastdds::dds::RETCODE_OK)
            {
                {
                    StructTypeFlag struct_flags = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::NOT_APPLIED,
                            false, false);
                    ReturnCode_t return_code;
                    TypeIdentifierPair type_ids;
                    QualifiedTypeName type_name = "Type1";
                    eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin;
                    eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom;
                    CompleteTypeDetail detail = TypeObjectUtils::build_complete_type_detail(type_ann_builtin, ann_custom, type_name.to_string());
                    CompleteStructHeader header;
                    header = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail);
                    CompleteStructMemberSeq member_seq;
                    {
                        StructMemberFlag member_flags = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                                false, false, false, false);
                        return_code =
                            eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                            "_uint16_t", type_ids);

                        if (return_code != eprosima::fastdds::dds::RETCODE_OK)
                        {
                            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                    "index Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                            return;
                        }
                        CommonStructMember common;
                        MemberId member_id = 0x00000000;
                        if (EK_COMPLETE == type_ids.type_identifier1()._d() || TK_NONE == type_ids.type_identifier2()._d() ||
                                (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().array_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().array_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_MAP_SMALL == type_ids.type_identifier1()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier1().map_sdefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                                (TI_PLAIN_MAP_LARGE == type_ids.type_identifier1()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier1().map_ldefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier1().map_ldefn().key_identifier()->_d())))
                        {
                            common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier1());
                        }
                        else if (EK_COMPLETE == type_ids.type_identifier2()._d() ||
                                (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().array_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().array_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_MAP_SMALL == type_ids.type_identifier2()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier2().map_sdefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                                (TI_PLAIN_MAP_LARGE == type_ids.type_identifier2()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier2().map_ldefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier2().map_ldefn().key_identifier()->_d())))
                        {
                            common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier2());
                        }
                        else
                        {
                            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                    "Structure index member TypeIdentifier inconsistent.");
                            return;
                        }
                        MemberName name = "index";
                        eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin;
                        ann_custom.reset();
                        CompleteMemberDetail detail = TypeObjectUtils::build_complete_member_detail(name, member_ann_builtin, ann_custom);
                        CompleteStructMember member = TypeObjectUtils::build_complete_struct_member(common, detail);
                        TypeObjectUtils::add_complete_struct_member(member_seq, member);
                    }
                    CompleteStructType struct_type = TypeObjectUtils::build_complete_struct_type(struct_flags, header, member_seq);
                    if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                            TypeObjectUtils::build_and_register_struct_type_object(struct_type, type_name.to_string()))
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                "Type1 already registered in TypeObjectRegistry for a different type.");
                    }
                    return_code =
                        eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                        "Type1", type_ids);
                    if (return_code != eprosima::fastdds::dds::RETCODE_OK)
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                    "Type1: Given Struct TypeIdentifier unknown to TypeObjectRegistry.");
                        return;
                    }
                }
            }
            CommonStructMember common;
            MemberId member_id = 0x00000000;
            if (EK_COMPLETE == type_ids.type_identifier1()._d() || TK_NONE == type_ids.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure var_type1 member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name = "var_type1";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin;
            ann_custom.reset();
            CompleteMemberDetail detail = TypeObjectUtils::build_complete_member_detail(name, member_ann_builtin, ann_custom);
            CompleteStructMember member = TypeObjectUtils::build_complete_struct_member(common, detail);
            TypeObjectUtils::add_complete_struct_member(member_seq, member);
        }
        {
            StructMemberFlag member_flags = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, false, false);
            return_code =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "Type2", type_ids);

            if (return_code != eprosima::fastdds::dds::RETCODE_OK)
            {
                {
                    StructTypeFlag struct_flags = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::NOT_APPLIED,
                            false, false);
                    ReturnCode_t return_code;
                    TypeIdentifierPair type_ids;
                    QualifiedTypeName type_name = "Type2";
                    eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin;
                    eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom;
                    CompleteTypeDetail detail = TypeObjectUtils::build_complete_type_detail(type_ann_builtin, ann_custom, type_name.to_string());
                    CompleteStructHeader header;
                    header = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail);
                    CompleteStructMemberSeq member_seq;
                    {
                        StructMemberFlag member_flags = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                                false, false, false, false);
                        return_code =
                            eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                            "_int16_t", type_ids);

                        if (return_code != eprosima::fastdds::dds::RETCODE_OK)
                        {
                            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                    "index Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                            return;
                        }
                        CommonStructMember common;
                        MemberId member_id = 0x00000000;
                        if (EK_COMPLETE == type_ids.type_identifier1()._d() || TK_NONE == type_ids.type_identifier2()._d() ||
                                (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().array_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().array_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_MAP_SMALL == type_ids.type_identifier1()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier1().map_sdefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                                (TI_PLAIN_MAP_LARGE == type_ids.type_identifier1()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier1().map_ldefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier1().map_ldefn().key_identifier()->_d())))
                        {
                            common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier1());
                        }
                        else if (EK_COMPLETE == type_ids.type_identifier2()._d() ||
                                (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().array_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().array_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_MAP_SMALL == type_ids.type_identifier2()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier2().map_sdefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                                (TI_PLAIN_MAP_LARGE == type_ids.type_identifier2()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier2().map_ldefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier2().map_ldefn().key_identifier()->_d())))
                        {
                            common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier2());
                        }
                        else
                        {
                            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                    "Structure index member TypeIdentifier inconsistent.");
                            return;
                        }
                        MemberName name = "index";
                        eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin;
                        ann_custom.reset();
                        CompleteMemberDetail detail = TypeObjectUtils::build_complete_member_detail(name, member_ann_builtin, ann_custom);
                        CompleteStructMember member = TypeObjectUtils::build_complete_struct_member(common, detail);
                        TypeObjectUtils::add_complete_struct_member(member_seq, member);
                    }
                    CompleteStructType struct_type = TypeObjectUtils::build_complete_struct_type(struct_flags, header, member_seq);
                    if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                            TypeObjectUtils::build_and_register_struct_type_object(struct_type, type_name.to_string()))
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                "Type2 already registered in TypeObjectRegistry for a different type.");
                    }
                    return_code =
                        eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                        "Type2", type_ids);
                    if (return_code != eprosima::fastdds::dds::RETCODE_OK)
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                    "Type2: Given Struct TypeIdentifier unknown to TypeObjectRegistry.");
                        return;
                    }
                }
            }
            CommonStructMember common;
            MemberId member_id = 0x00000001;
            if (EK_COMPLETE == type_ids.type_identifier1()._d() || TK_NONE == type_ids.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure var_type2 member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name = "var_type2";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin;
            ann_custom.reset();
            CompleteMemberDetail detail = TypeObjectUtils::build_complete_member_detail(name, member_ann_builtin, ann_custom);
            CompleteStructMember member = TypeObjectUtils::build_complete_struct_member(common, detail);
            TypeObjectUtils::add_complete_struct_member(member_seq, member);
        }
        {
            StructMemberFlag member_flags = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, false, false);
            return_code =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "Type3", type_ids);

            if (return_code != eprosima::fastdds::dds::RETCODE_OK)
            {
                {
                    StructTypeFlag struct_flags = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::NOT_APPLIED,
                            false, false);
                    ReturnCode_t return_code;
                    TypeIdentifierPair type_ids;
                    QualifiedTypeName type_name = "Type3";
                    eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin;
                    eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom;
                    CompleteTypeDetail detail = TypeObjectUtils::build_complete_type_detail(type_ann_builtin, ann_custom, type_name.to_string());
                    CompleteStructHeader header;
                    header = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail);
                    CompleteStructMemberSeq member_seq;
                    {
                        StructMemberFlag member_flags = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                                false, false, false, false);
                        return_code =
                            eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                            "_int32_t", type_ids);

                        if (return_code != eprosima::fastdds::dds::RETCODE_OK)
                        {
                            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                    "index Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                            return;
                        }
                        CommonStructMember common;
                        MemberId member_id = 0x00000000;
                        if (EK_COMPLETE == type_ids.type_identifier1()._d() || TK_NONE == type_ids.type_identifier2()._d() ||
                                (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().array_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier1()._d() &&
                                EK_COMPLETE == type_ids.type_identifier1().array_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_MAP_SMALL == type_ids.type_identifier1()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier1().map_sdefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                                (TI_PLAIN_MAP_LARGE == type_ids.type_identifier1()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier1().map_ldefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier1().map_ldefn().key_identifier()->_d())))
                        {
                            common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier1());
                        }
                        else if (EK_COMPLETE == type_ids.type_identifier2()._d() ||
                                (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().array_sdefn().header().equiv_kind()) ||
                                (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier2()._d() &&
                                EK_COMPLETE == type_ids.type_identifier2().array_ldefn().header().equiv_kind()) ||
                                (TI_PLAIN_MAP_SMALL == type_ids.type_identifier2()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier2().map_sdefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                                (TI_PLAIN_MAP_LARGE == type_ids.type_identifier2()._d() &&
                                (EK_COMPLETE == type_ids.type_identifier2().map_ldefn().header().equiv_kind() ||
                                EK_COMPLETE == type_ids.type_identifier2().map_ldefn().key_identifier()->_d())))
                        {
                            common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier2());
                        }
                        else
                        {
                            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                    "Structure index member TypeIdentifier inconsistent.");
                            return;
                        }
                        MemberName name = "index";
                        eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin;
                        ann_custom.reset();
                        CompleteMemberDetail detail = TypeObjectUtils::build_complete_member_detail(name, member_ann_builtin, ann_custom);
                        CompleteStructMember member = TypeObjectUtils::build_complete_struct_member(common, detail);
                        TypeObjectUtils::add_complete_struct_member(member_seq, member);
                    }
                    CompleteStructType struct_type = TypeObjectUtils::build_complete_struct_type(struct_flags, header, member_seq);
                    if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                            TypeObjectUtils::build_and_register_struct_type_object(struct_type, type_name.to_string()))
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                "Type3 already registered in TypeObjectRegistry for a different type.");
                    }
                    return_code =
                        eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                        "Type3", type_ids);
                    if (return_code != eprosima::fastdds::dds::RETCODE_OK)
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                                    "Type3: Given Struct TypeIdentifier unknown to TypeObjectRegistry.");
                        return;
                    }
                }
            }
            CommonStructMember common;
            MemberId member_id = 0x00000002;
            if (EK_COMPLETE == type_ids.type_identifier1()._d() || TK_NONE == type_ids.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common = TypeObjectUtils::build_common_struct_member(member_id, member_flags, type_ids.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure var_type3 member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name = "var_type3";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin;
            ann_custom.reset();
            CompleteMemberDetail detail = TypeObjectUtils::build_complete_member_detail(name, member_ann_builtin, ann_custom);
            CompleteStructMember member = TypeObjectUtils::build_complete_struct_member(common, detail);
            TypeObjectUtils::add_complete_struct_member(member_seq, member);
        }
        CompleteStructType struct_type = TypeObjectUtils::build_complete_struct_type(struct_flags, header, member_seq);
        if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                TypeObjectUtils::build_and_register_struct_type_object(struct_type, type_name.to_string()))
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                    "TypeDep already registered in TypeObjectRegistry for a different type.");
        }
        return_code =
            eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
            "TypeDep", type_ids);
        if (return_code != eprosima::fastdds::dds::RETCODE_OK)
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "TypeDep: Given Struct TypeIdentifier unknown to TypeObjectRegistry.");
            return;
        }
    }
}

