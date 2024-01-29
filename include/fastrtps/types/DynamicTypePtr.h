// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#ifndef TYPES_DYNAMIC_TYPE_PTR_H
#define TYPES_DYNAMIC_TYPE_PTR_H

#include <memory>

#include <fastdds/dds/core/ReturnCode.hpp>
#include <fastdds/fastdds_dll.hpp>

namespace eprosima {
namespace fastrtps {
namespace types {

class DynamicType;

class DynamicType_ptr : public std::shared_ptr<DynamicType>
{
public:

    typedef std::shared_ptr<DynamicType> Base;

    using Base::operator ->;
    using Base::operator *;
    using Base::operator bool;

    DynamicType_ptr()
    {
    }

    FASTDDS_EXPORTED_API explicit DynamicType_ptr(
            DynamicType* pType);

    FASTDDS_EXPORTED_API DynamicType_ptr(
            const DynamicType_ptr& other) = default;

    FASTDDS_EXPORTED_API DynamicType_ptr(
            DynamicType_ptr&& other) = default;

    FASTDDS_EXPORTED_API DynamicType_ptr& operator =(
            const DynamicType_ptr&) = default;

    FASTDDS_EXPORTED_API DynamicType_ptr& operator =(
            DynamicType_ptr&&) = default;

    FASTDDS_EXPORTED_API DynamicType_ptr& operator =(
            DynamicType*);

    FASTDDS_EXPORTED_API bool operator !=(
            std::nullptr_t) const
    {
        return bool(*this);
    }

    FASTDDS_EXPORTED_API bool operator ==(
            std::nullptr_t) const
    {
        return !*this;
    }

};

} // namespace types
} // namespace fastrtps
} // namespace eprosima

#endif // TYPES_DYNAMIC_TYPE_PTR_H
