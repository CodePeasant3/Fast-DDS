// Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#include "DynamicTypeImpl.hpp"

#include <cassert>

namespace eprosima {
namespace fastdds {
namespace dds {

DynamicTypeImpl::DynamicTypeImpl(
        const TypeDescriptorImpl& descriptor) noexcept
{
    type_descriptor_.copy_from(descriptor);
}

ReturnCode_t DynamicTypeImpl::get_descriptor(
        traits<TypeDescriptor>::ref_type& descriptor) noexcept
{
    if (!descriptor)
    {
        return RETCODE_BAD_PARAMETER;
    }

    traits<TypeDescriptor>::narrow<TypeDescriptorImpl>(descriptor)->copy_from(type_descriptor_);
    return RETCODE_OK;
}

ObjectName DynamicTypeImpl::get_name() noexcept
{
    return type_descriptor_.name();
}

TypeKind DynamicTypeImpl::get_kind() noexcept
{
    return type_descriptor_.kind();
}

ReturnCode_t DynamicTypeImpl::get_member_by_name(
        traits<DynamicTypeMember>::ref_type& member,
        const ObjectName& name) noexcept
{
    auto it = member_by_name_.find(name);

    if (member_by_name_.end() == it)
    {
        return RETCODE_BAD_PARAMETER;
    }

    member = it->second;
    return RETCODE_OK;
}

ReturnCode_t DynamicTypeImpl::get_all_members_by_name(
        DynamicTypeMembersByName& member) noexcept
{
    member = member_by_name_;
    return RETCODE_OK;
}

ReturnCode_t DynamicTypeImpl::get_member(
        traits<DynamicTypeMember>::ref_type& member,
        MemberId id) noexcept
{
    auto it = member_.find(id);

    if (member_.end() == it)
    {
        return RETCODE_BAD_PARAMETER;
    }

    member = it->second;
    return RETCODE_OK;
}

ReturnCode_t DynamicTypeImpl::get_all_members(
        DynamicTypeMembersById& member) noexcept
{
    member = member_;
    return RETCODE_OK;
}

uint32_t DynamicTypeImpl::get_member_count() noexcept
{
    return static_cast<uint32_t>(members_.size());
}

ReturnCode_t DynamicTypeImpl::get_member_by_index(
        traits<DynamicTypeMember>::ref_type& member,
        uint32_t index) noexcept
{
    if (index >= members_.size())
    {
        return RETCODE_BAD_PARAMETER;
    }

    member = members_.at(index);
    return RETCODE_OK;
}

uint32_t DynamicTypeImpl::get_annotation_count() noexcept
{
    return static_cast<uint32_t>(annotation_.size());
}

ReturnCode_t DynamicTypeImpl::get_annotation(
        traits<AnnotationDescriptor>::ref_type& descriptor,
        uint32_t idx) noexcept
{
    if (!descriptor || idx >= annotation_.size())
    {
        return RETCODE_BAD_PARAMETER;
    }

    traits<AnnotationDescriptor>::narrow<AnnotationDescriptorImpl>(descriptor)->copy_from(annotation_.at(idx));
    return RETCODE_OK;
}

uint32_t DynamicTypeImpl::get_verbatim_text_count() noexcept
{
    return static_cast<uint32_t>(verbatim_.size());
}

ReturnCode_t DynamicTypeImpl::get_verbatim_text(
        traits<VerbatimTextDescriptor>::ref_type& descriptor,
        uint32_t idx) noexcept
{
    if (!descriptor || idx >= verbatim_.size())
    {
        return RETCODE_BAD_PARAMETER;
    }

    traits<VerbatimTextDescriptor>::narrow<VerbatimTextDescriptorImpl>(descriptor)->copy_from(verbatim_.at(idx));
    return RETCODE_OK;
}

bool DynamicTypeImpl::equals(
        traits<DynamicType>::ref_type other) noexcept
{
    bool ret_value = true;
    auto impl = traits<DynamicType>::narrow<DynamicTypeImpl>(other);

    if (ret_value &= type_descriptor_.equals(impl->type_descriptor_))
    {
        if (ret_value &= annotation_.size() == impl->annotation_.size())
        {
            for (size_t count {0}; ret_value && count < annotation_.size(); ++count)
            {
                ret_value &= annotation_.at(count).equals(impl->annotation_.at(count));
            }
        }

        ret_value &= member_.size() == impl->member_.size();
        assert(TK_ANNOTATION == type_descriptor_.kind() ||
                TK_BITSET == type_descriptor_.kind() ||
                TK_STRUCTURE == type_descriptor_.kind() ||
                TK_UNION ==  type_descriptor_.kind() ||
                0 == member_.size());
        assert(TK_ANNOTATION == type_descriptor_.kind() ||
                TK_BITSET == impl->type_descriptor_.kind() ||
                TK_STRUCTURE == impl->type_descriptor_.kind() ||
                TK_UNION ==  impl->type_descriptor_.kind() ||
                0 == impl->member_.size());
        assert((TK_ANNOTATION != type_descriptor_.kind() &&
                TK_BITSET != type_descriptor_.kind() &&
                TK_STRUCTURE != type_descriptor_.kind() &&
                TK_UNION != type_descriptor_.kind()) ||
                0 < member_.size());
        assert((TK_ANNOTATION != type_descriptor_.kind() &&
                TK_BITSET != impl->type_descriptor_.kind() &&
                TK_STRUCTURE != impl->type_descriptor_.kind() &&
                TK_UNION != impl->type_descriptor_.kind()) ||
                0 < member_.size());

        assert(member_by_name_.size() == members_.size());
        assert(impl->member_by_name_.size() == impl->members_.size());
        if (ret_value &= member_by_name_.size() == impl->member_by_name_.size())
        {
            auto it = member_by_name_.begin();
            auto impl_it = impl->member_by_name_.begin();

            while (ret_value && member_by_name_.end() != it)
            {
                ret_value &= it->second->equals(impl_it->second);
                ++it;
                ++impl_it;
            }
        }

        if (ret_value &= verbatim_.size() == impl->verbatim_.size())
        {
            for (size_t count {0}; ret_value && count < verbatim_.size(); ++count)
            {
                ret_value &= verbatim_.at(count).equals(impl->verbatim_.at(count));
            }
        }
    }

    return ret_value;
}

traits<DynamicType>::ref_type DynamicTypeImpl::_this ()
{
    return shared_from_this();
}

} // namespace dds
} // namespace fastdds
} // namespace eprosima
