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

#include <fastrtps/types/v1_3/DynamicType.hpp>
#include <dynamic-types/v1_3/AnnotationDescriptorImpl.hpp>
#include <dynamic-types/v1_3/DynamicTypeBuilderFactoryImpl.hpp>
#include <dynamic-types/v1_3/DynamicTypeImpl.hpp>
#include <fastdds/dds/log/Log.hpp>

#include <iomanip>

using namespace eprosima::fastrtps::types::v1_3;

bool AnnotationDescriptorImpl::operator ==(
        const AnnotationDescriptorImpl& other) const
{
    if ( type_ == other.type_ || (type_ && other.type_ && type_->equals(*other.type_)))
    {
        return value_ == other.value_;
    }
    return true;
}

bool AnnotationDescriptorImpl::operator !=(
        const AnnotationDescriptorImpl& other) const
{
    return !(*this == other);
}

bool AnnotationDescriptorImpl::operator <(
        const AnnotationDescriptorImpl& other) const
{
    auto name = type_->get_name();
    auto other_name = other.type_->get_name();
    return name == other_name ? value_ < other.value_ : name < other_name;
}

bool AnnotationDescriptorImpl::key_annotation() const
{
    auto it = value_.find(ANNOTATION_KEY_ID);
    if (it == value_.end())
    {
        it = value_.find(ANNOTATION_EPKEY_ID); // Legacy "@Key"
    }
    return (it != value_.end() && it->second == CONST_TRUE);
}

ReturnCode_t AnnotationDescriptorImpl::get_value(
        std::string& value) const
{
    return get_value(value, "value");
}

ReturnCode_t AnnotationDescriptorImpl::get_value(
        std::string& value,
        const std::string& key) const
{
    auto it = value_.find(key);
    if (it != value_.end())
    {
        value = it->second;
        return ReturnCode_t::RETCODE_OK;
    }
    return ReturnCode_t::RETCODE_BAD_PARAMETER;
}

ReturnCode_t AnnotationDescriptorImpl::get_all_value(
        std::map<std::string, std::string>& value) const
{
    value = value_;
    return ReturnCode_t::RETCODE_OK;
}

bool AnnotationDescriptorImpl::is_consistent() const
{
    if (!type_ || type_->get_kind() != TypeKind::TK_ANNOTATION)
    {
        return false;
    }

    //TODO: Check consistency of value_
    return true;
}

ReturnCode_t AnnotationDescriptorImpl::set_value(
        const std::string& key,
        const std::string& value)
{
    value_[key] = value;
    return ReturnCode_t::RETCODE_OK;
}

AnnotationDescriptor AnnotationDescriptorImpl::get_descriptor() const
{
    AnnotationDescriptor res{value_};

    if (type_)
    {
        res.set_type(type_->get_interface());
    }

    return res;
}

std::ostream& eprosima::fastrtps::types::v1_3::operator <<(
        std::ostream& os,
        const AnnotationDescriptorImpl& ad)
{
    using namespace std;

    // indentation increment
    ++os.iword(DynamicTypeBuilderFactoryImpl::indentation_index);

    auto manips = [](ostream& os) -> ostream&
            {
                long indent = os.iword(DynamicTypeBuilderFactoryImpl::indentation_index);
                return os << string(indent, '\t') << setw(10) << left;
            };

    // without type the annotation is not consistent and cannot be created
    assert(ad.type());

    // show type
    os << manips << "annotation:" << ad.type()->get_name() << endl;

    // show the map contents
    for (auto pair : ad.get_all_values())
    {
        os << manips << "\tkey:" << "'" << pair.first << "'" << endl
           << manips << "\tvalue:" << pair.second << endl;
    }

    // indentation decrement
    --os.iword(DynamicTypeBuilderFactoryImpl::indentation_index);

    return os;
}
