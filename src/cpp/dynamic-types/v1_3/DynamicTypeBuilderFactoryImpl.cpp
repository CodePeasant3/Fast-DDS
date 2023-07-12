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

#include <fastrtps/types/TypeObject.h>
#include <fastrtps/types/TypeObjectFactory.h>
#include <fastrtps/types/TypeNamesGenerator.h>
#include <dynamic-types/v1_3/TypeState.hpp>
#include <dynamic-types/v1_3/DynamicTypeBuilderFactoryImpl.hpp>
#include <dynamic-types/v1_3/DynamicTypeBuilderImpl.hpp>
#include <dynamic-types/v1_3/DynamicTypeImpl.hpp>
#include <dynamic-types/v1_3/DynamicTypeMemberImpl.hpp>
#include <dynamic-types/v1_3/MemberDescriptorImpl.hpp>
#include <dynamic-types/v1_3/AnnotationDescriptorImpl.hpp>
#include <fastdds/dds/log/Log.hpp>

#include <fastdds/rtps/common/SerializedPayload.h>
#include <fastrtps/utils/md5.h>
#include <fastrtps/utils/string_convert.hpp>
#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

#include <ios>

using namespace eprosima::fastrtps::types::v1_3;

using eprosima::fastrtps::types::TypeObject;
using eprosima::fastrtps::types::TypeIdentifier;
using eprosima::fastrtps::types::AnnotationParameterValue;
using eprosima::fastrtps::types::AppliedAnnotationSeq;
using eprosima::fastrtps::types::ReturnCode_t;

// explicit instatiation of tracker methods for type_tracking::complete

template<>
void dynamic_tracker<type_tracking::complete>::reset() noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    builders_list_.clear();
    types_list_.clear();
    primitive_builders_list_.clear();
    primitive_types_list_.clear();
}

template<>
bool dynamic_tracker<type_tracking::complete>::is_empty() noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    return builders_list_.empty() && types_list_.empty();
}

template<>
void dynamic_tracker<type_tracking::complete>::add_primitive(
        const DynamicTypeBuilderImpl* pBuilder) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    primitive_builders_list_.insert(pBuilder);
}

template<>
void dynamic_tracker<type_tracking::complete>::add_primitive(
        const DynamicTypeImpl* pType) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    primitive_types_list_.insert(pType);
}

template<>
bool dynamic_tracker<type_tracking::complete>::add(
        const DynamicTypeBuilderImpl* pBuilder) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    if (!builders_list_.insert(pBuilder).second)
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "The given type builder has been inserted previously.");
        return false;
    }
    return true;
}

template<>
bool dynamic_tracker<type_tracking::complete>::remove(
        const DynamicTypeBuilderImpl* pBuilder) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    if (!builders_list_.erase(pBuilder)
            && primitive_builders_list_.find(pBuilder) != primitive_builders_list_.end())
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "The given type builder has been already removed.");
        return false;
    }
    return true;
}

template<>
bool dynamic_tracker<type_tracking::complete>::add(
        const DynamicTypeImpl* pType) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    if (!types_list_.insert(pType).second)
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "The given type has been inserted previously.");
        return false;
    }
    return true;
}

template<>
bool dynamic_tracker<type_tracking::complete>::remove(
        const DynamicTypeImpl* type) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    if (!types_list_.erase(type)
            && primitive_types_list_.find(type) != primitive_types_list_.end())
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "The given type has been already removed.");
        return false;
    }
    return true;
}

#ifndef NDEBUG
// force instantiation for error checking
template class eprosima::fastrtps::types::v1_3::dynamic_tracker<type_tracking::complete>;
#endif // ifndef NDEBUG

// explicit instatiation of tracker methods for type_tracking::partial

template<>
void dynamic_tracker<type_tracking::partial>::reset() noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    builders_list_.clear();
    types_list_.clear();
}

template<>
bool dynamic_tracker<type_tracking::partial>::is_empty() noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    return builders_list_.empty() && types_list_.empty();
}

template<>
void dynamic_tracker<type_tracking::partial>::add_primitive(
        const DynamicTypeBuilderImpl*) noexcept
{
}

template<>
void dynamic_tracker<type_tracking::partial>::add_primitive(
        const DynamicTypeImpl*) noexcept
{
}

template<>
bool dynamic_tracker<type_tracking::partial>::add(
        const DynamicTypeBuilderImpl* pBuilder) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    if (!builders_list_.insert(pBuilder).second)
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "The given type builder has been inserted previously.");
        return false;
    }
    return true;
}

template<>
bool dynamic_tracker<type_tracking::partial>::remove(
        const DynamicTypeBuilderImpl* pBuilder) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    if (!builders_list_.erase(pBuilder))
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "The given type builder has been already removed.");
        return false;
    }
    return true;
}

template<>
bool dynamic_tracker<type_tracking::partial>::add(
        const DynamicTypeImpl* pType) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    if (!types_list_.insert(pType).second)
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "The given type has been inserted previously.");
        return false;
    }
    return true;
}

template<>
bool dynamic_tracker<type_tracking::partial>::remove(
        const DynamicTypeImpl* type) noexcept
{
    std::lock_guard<std::mutex> _(mutex_);
    if (!types_list_.erase(type))
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "The given type has been already removed.");
        return false;
    }
    return true;
}

#ifndef NDEBUG
// force instantiation for error checking
template class eprosima::fastrtps::types::v1_3::dynamic_tracker<type_tracking::partial>;
#endif // ifndef NDEBUG

// explicit instatiation of tracker methods for type_tracking::none

template<>
void dynamic_tracker<type_tracking::none>::reset() noexcept
{
}

template<>
bool dynamic_tracker<type_tracking::none>::is_empty() noexcept
{
    return true;
}

template<>
void dynamic_tracker<type_tracking::none>::add_primitive(
        const DynamicTypeBuilderImpl*) noexcept
{
}

template<>
void dynamic_tracker<type_tracking::none>::add_primitive(
        const DynamicTypeImpl*) noexcept
{
}

template<>
bool dynamic_tracker<type_tracking::none>::add(
        const DynamicTypeBuilderImpl*) noexcept
{
    return true;
}

template<>
bool dynamic_tracker<type_tracking::none>::remove(
        const DynamicTypeBuilderImpl*) noexcept
{
    return true;
}

template<>
bool dynamic_tracker<type_tracking::none>::add(
        const DynamicTypeImpl*) noexcept
{
    return true;
}

template<>
bool dynamic_tracker<type_tracking::none>::remove(
        const DynamicTypeImpl*) noexcept
{
    return true;
}

#ifndef NDEBUG
// force instantiation for error checking
template class eprosima::fastrtps::types::v1_3::dynamic_tracker<type_tracking::none>;
#endif // ifndef NDEBUG

// DynamicTypeBuilderFactoryImpl ancillary

static std::string get_type_name(
        TypeKind kind)
{
    switch (kind)
    {
        // Primitive types, already defined (never will be asked, but ok)
        case TypeKind::TK_BOOLEAN: return TKNAME_BOOLEAN;
        case TypeKind::TK_INT16: return TKNAME_INT16;
        case TypeKind::TK_INT32: return TKNAME_INT32;
        case TypeKind::TK_UINT16: return TKNAME_UINT16;
        case TypeKind::TK_UINT32: return TKNAME_UINT32;
        case TypeKind::TK_FLOAT32: return TKNAME_FLOAT32;
        case TypeKind::TK_FLOAT64: return TKNAME_FLOAT64;
        case TypeKind::TK_CHAR8: return TKNAME_CHAR8;
        case TypeKind::TK_BYTE: return TKNAME_BYTE;
        case TypeKind::TK_INT64: return TKNAME_INT64;
        case TypeKind::TK_UINT64: return TKNAME_UINT64;
        case TypeKind::TK_FLOAT128: return TKNAME_FLOAT128;
        case TypeKind::TK_CHAR16: return TKNAME_CHAR16;
        /*
           case TypeKind::TK_STRING8: return TKNAME_STRING8;
           case TypeKind::TK_STRING16: return TKNAME_STRING16;
           case TypeKind::TK_ALIAS: return TKNAME_ALIAS;
           case TypeKind::TK_ENUM: return TKNAME_ENUM;
         */
        case TypeKind::TK_BITMASK: return TKNAME_BITMASK;
        /*
           case TypeKind::TK_ANNOTATION: return TKNAME_ANNOTATION;
           case TypeKind::TK_STRUCTURE: return TKNAME_STRUCTURE;
           case TypeKind::TK_UNION: return TKNAME_UNION;
         */
        case TypeKind::TK_BITSET: return TKNAME_BITSET;
        /*
           case TypeKind::TK_SEQUENCE: return TKNAME_SEQUENCE;
           case TypeKind::TK_ARRAY: return TKNAME_ARRAY;
           case TypeKind::TK_MAP: return TKNAME_MAP;
         */
        default:
            break;
    }
    return "UNDEF";
}

//static uint32_t s_typeNameCounter = 0;
static std::string GenerateTypeName(
        const std::string& kind)
{
    std::string tempKind = kind;
    std::replace(tempKind.begin(), tempKind.end(), ' ', '_');
    return tempKind;// + "_" + std::to_string(++s_typeNameCounter);
}

DynamicTypeBuilderFactoryImpl& DynamicTypeBuilderFactoryImpl::get_instance() noexcept
{
    // C++ standard requires preserve global construction order
    // make sure the dynamic tracker lifespan is larger than the factory one
    dynamic_tracker<selected_mode>::get_dynamic_tracker();

    // C++11 guarantees the construction to be atomic
    static DynamicTypeBuilderFactoryImpl instance;
    return instance;
}

ReturnCode_t DynamicTypeBuilderFactoryImpl::delete_instance() noexcept
{
    get_instance().reset();
    return ReturnCode_t::RETCODE_OK;
}

void DynamicTypeBuilderFactoryImpl::reset()
{
    dynamic_tracker<selected_mode>::get_dynamic_tracker().reset();
}

DynamicTypeBuilderFactoryImpl::~DynamicTypeBuilderFactoryImpl()
{
    assert(is_empty());
    reset();
}

void DynamicTypeBuilderFactoryImpl::after_construction(
        DynamicTypeBuilderImpl* pBuilder)
{
    dynamic_tracker<selected_mode>::get_dynamic_tracker().add(pBuilder);
}

void DynamicTypeBuilderFactoryImpl::before_destruction(
        DynamicTypeBuilderImpl* builder)
{
    dynamic_tracker<selected_mode>::get_dynamic_tracker().remove(builder);
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_type(
        const TypeState& td) noexcept
{
    try
    {
        if (td.is_consistent())
        {
            std::shared_ptr<DynamicTypeBuilderImpl> sp;
            auto & al = DynamicTypeBuilderFactoryImpl::get_instance().get_allocator();

#if _MSC_VER >= 1921
            // MSVC v142 can allocate on a single block
            sp = std::allocate_shared<DynamicTypeBuilderImpl>(
                al,
                DynamicTypeBuilderImpl::use_the_create_method{},
                td);
#else
            using traits = std::allocator_traits<builder_allocator>;
            auto new_instance = al.allocate(sizeof(DynamicTypeBuilderImpl));
            traits::construct(
                al,
                new_instance,
                DynamicTypeBuilder::use_the_create_method{},
                td);

            sp.reset(new_instance);
#endif
            // Keep alive on external references
            sp->add_ref();
            return sp;
        }
        else
        {
            EPROSIMA_LOG_ERROR(DYN_TYPES, "Error building type builder. The current descriptor isn't consistent.");
        }
    }
    catch(const std::bad_alloc& e)
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "Error building type builder. Allocation failed: " << e.what());
    }

    return {};
}

const DynamicTypeImpl& DynamicTypeBuilderFactoryImpl::create_copy(
        const DynamicTypeImpl& type) noexcept
{
    return DynamicTypeBuilderImpl::create_copy(type);
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_type_copy(
        const DynamicTypeImpl& type) noexcept
{
    assert(type.is_consistent());
    return create_type(type);
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_alias_type(
        const DynamicTypeImpl& base_type,
        const std::string& sName)
{
    TypeState state;
    state.set_kind(TypeKind::TK_ALIAS);
    state.set_base_type(base_type.shared_from_this());
    state.set_name(sName);

    return create_type(state);
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_array_type(
        const DynamicTypeImpl& type,
        const std::vector<uint32_t>& bounds) noexcept
{
    TypeState state;
    state.set_kind(TypeKind::TK_ARRAY);
    state.set_name(TypeNamesGenerator::get_array_type_name(type.get_name(), bounds, false));
    state.element_type_ = type.shared_from_this();
    state.bound_ = bounds;

    for (uint32_t i = 0; i < state.bound_.size(); ++i)
    {
        if (state.bound_[i] == 0)
        {
            state.bound_[i] = MAX_ELEMENTS_COUNT;
        }
    }

    return create_type(state);
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_bitmask_type(
        uint32_t bound) noexcept
{
    if (bound <= MAX_BITMASK_LENGTH)
    {
        TypeState state;
        state.set_kind(TypeKind::TK_BITMASK);
        // TODO review on implementation for IDL
        state.set_name(GenerateTypeName(get_type_name(TypeKind::TK_BITMASK)));
        state.element_type_ = get_bool_type();
        state.bound_.push_back(bound);

        return create_type(state);
    }
    else
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES,
                "Error creating bitmask, length exceeds the maximum value '" << MAX_BITMASK_LENGTH << "'");
    }
    return {};
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_bitset_type(
        uint32_t bound) noexcept
{
    if (bound <= MAX_BITMASK_LENGTH)
    {
        TypeState state;
        state.set_kind(TypeKind::TK_BITSET);
        // TODO Review on implementation for IDL
        state.set_name(GenerateTypeName(get_type_name(TypeKind::TK_BITSET)));
        state.bound_.push_back(bound);
        return create_type(state);
    }
    else
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES,
                "Error creating bitmask, length exceeds the maximum value '" << MAX_BITMASK_LENGTH << "'");
    }

    return {};
}

// Beware! this method doesn't return a static object but creates it
std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::new_primitive_builder(
        TypeKind kind) noexcept
{
    try
    {
        // create on heap
        std::shared_ptr<DynamicTypeBuilderImpl> builder;
        TypeState td{GenerateTypeName(get_type_name(kind)), kind};

#if _MSC_VER >= 1921
        builder = std::make_shared<DynamicTypeBuilderImpl>(
            DynamicTypeBuilderImpl::use_the_create_method{},
            td,
            true);         // will be a static object
#else
        builder.reset(new DynamicTypeBuilderImpl(
            DynamicTypeBuilderImpl::use_the_create_method{},
            td,
            true);         // will be a static object
#endif // _MSC_VER

        // notify the tracker
        dynamic_tracker<selected_mode>::get_dynamic_tracker().add_primitive(builder.get());
        return builder;
    }
    catch(const std::bad_alloc& e)
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES,
                "Error building primitive type builder. Allocation failed: " << e.what());
    }

    return {};
}

// Beware! this method doesn't return a static object but creates it
std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::new_unlimited_string_builder(
        bool large) noexcept
{
    TypeState td;
    td.set_kind(large ? TypeKind::TK_STRING16 : TypeKind::TK_STRING8);
    td.set_name(TypeNamesGenerator::get_string_type_name(MAX_STRING_LENGTH, large, true));
    td.element_type_ = large ? get_char16_type() : get_char8_type();
    td.bound_.push_back(MAX_STRING_LENGTH);

    try
    {
        // create on heap
        std::shared_ptr<DynamicTypeBuilderImpl> builder;

#if _MSC_VER >= 1921
        builder = std::make_shared<DynamicTypeBuilderImpl>(
            DynamicTypeBuilderImpl::use_the_create_method{},
            td,
            true);         // will be a static object
#else
        builder.reset(new DynamicTypeBuilderImpl(
            DynamicTypeBuilderImpl::use_the_create_method{},
            td,
            true);         // will be a static object
#endif // _MSC_VER

        // notify the tracker
        dynamic_tracker<selected_mode>::get_dynamic_tracker().add_primitive(builder.get());
        return builder;

    }
    catch(const std::bad_alloc& e)
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES,
                "Error building primitive string builder. Allocation failed: " << e.what());
    }

    return {};
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_bool_type() noexcept
{
    return create_primitive_type<TypeKind::TK_BOOLEAN>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_byte_type() noexcept
{
    return create_primitive_type<TypeKind::TK_BYTE>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_char8_type() noexcept
{
    return create_primitive_type<TypeKind::TK_CHAR8>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_char16_type() noexcept
{
    return create_primitive_type<TypeKind::TK_CHAR16>();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::create_annotation_primitive(
        const std::string& name)
{
    TypeState state;
    state.set_kind(TypeKind::TK_ANNOTATION);
    state.set_name(name);
    return create_type(state)->build();
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_enum_type()
{
    TypeState state;
    state.set_kind(TypeKind::TK_ENUM);
    // Enum currently is an alias for uint32_t
    state.set_name(GenerateTypeName(get_type_name(TypeKind::TK_UINT32)));
    return create_type(state);
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_float32_type() noexcept
{
    return create_primitive_type<TypeKind::TK_FLOAT32>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_float64_type() noexcept
{
    return create_primitive_type<TypeKind::TK_FLOAT64>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_float128_type() noexcept
{
    return create_primitive_type<TypeKind::TK_FLOAT128>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_int16_type() noexcept
{
    return create_primitive_type<TypeKind::TK_INT16>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_int32_type() noexcept
{
    return create_primitive_type<TypeKind::TK_INT32>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_int64_type() noexcept
{
    return create_primitive_type<TypeKind::TK_INT64>();
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_map_type(
        const DynamicTypeImpl& key_type,
        const DynamicTypeImpl& value_type,
        uint32_t bound /* = LENGTH_UNLIMITED */) noexcept
{
    if (bound == LENGTH_UNLIMITED)
    {
        bound = MAX_ELEMENTS_COUNT;
    }

    TypeState state;
    state.set_kind(TypeKind::TK_MAP);
    state.bound_.push_back(bound);
    state.key_element_type_ = key_type.shared_from_this();
    state.element_type_ = value_type.shared_from_this();
    state.set_name(
        TypeNamesGenerator::get_map_type_name(
            key_type.get_name(),
            value_type.get_name(),
            bound, false));
    return create_type(state);
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_sequence_type(
        const DynamicTypeImpl& type,
        uint32_t bound /* = LENGTH_UNLIMITED */) noexcept
{
    if (bound == LENGTH_UNLIMITED)
    {
        bound = MAX_ELEMENTS_COUNT;
    }

    TypeState state;
    state.set_kind(TypeKind::TK_SEQUENCE);
    state.set_name(TypeNamesGenerator::get_sequence_type_name(type.get_name(), bound, false));
    state.bound_.push_back(bound);
    state.element_type_ = type.shared_from_this();

    return create_type(state);
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_string_type(
        uint32_t bound /* = LENGTH_UNLIMITED */) noexcept
{
    // C++11 compiler uses double-checked locking pattern to avoid concurrency issues
    static std::shared_ptr<const DynamicTypeBuilderImpl> unlimited_builder = { new_unlimited_string_builder(false) };

    if (!unlimited_builder)
    {
        return {};
    }

    if ( 0 == bound )
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "Error creating bounded string with bound: " << bound);
        return {};
    }
    else if ( LENGTH_UNLIMITED == bound )
    {
        // TODO:Barro refactor unbounded to be unbounded and not 256
        unlimited_builder->add_ref();
        return unlimited_builder;
    }

    // otherwise allocate one on the heap
    TypeState state(*unlimited_builder);
    state.set_name(TypeNamesGenerator::get_string_type_name(bound, false, true));
    state.bound_[0] = bound;
    return create_type(state);
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_wstring_type(
        uint32_t bound /* = LENGTH_UNLIMITED */) noexcept
{
    // C++11 compiler uses double-checked locking pattern to avoid concurrency issues
    static std::shared_ptr<const DynamicTypeBuilderImpl> unlimited_builder = { new_unlimited_string_builder(true) };

    if (!unlimited_builder)
    {
        return {};
    }

    if ( 0 == bound )
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "Error creating bounded wstring with bound: " << bound);
        return {};
    }
    else if ( LENGTH_UNLIMITED == bound )
    {
        // TODO:Barro refactor unbounded to be unbounded and not 256
        unlimited_builder->add_ref();
        return unlimited_builder;
    }

    // otherwise allocate one on the heap
    TypeState state(*unlimited_builder);
    state.set_name(TypeNamesGenerator::get_string_type_name(bound, true, true));
    state.bound_[0] = bound;
    return create_type(state);
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_child_struct_type(
        const DynamicTypeImpl& parent_type)
{
    auto kind = parent_type.get_kind();

    if (kind == TypeKind::TK_STRUCTURE || kind == TypeKind::TK_BITSET)
    {
        TypeState state;
        state.set_kind(kind);
        state.set_name(GenerateTypeName(get_type_name(kind)));
        state.base_type_ = parent_type.shared_from_this();

        return create_type(state);
    }
    else if (kind == TypeKind::TK_ALIAS)
    {
        // Resolve aliases
        auto p = parent_type.shared_from_this();

        do
        {
            p = p->base_type_;
        }
        while ( p->kind_ == TypeKind::TK_ALIAS );

        return create_child_struct_type(*p);
    }
    else
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "Error creating child struct, invalid input type.");
        return {};
    }
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_struct_type() noexcept
{
    TypeState state;
    state.set_kind(TypeKind::TK_STRUCTURE);
    state.set_name(GenerateTypeName(get_type_name(TypeKind::TK_STRUCTURE)));

    return create_type(state);
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_uint16_type() noexcept
{
    return create_primitive_type<TypeKind::TK_UINT16>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_uint32_type() noexcept
{
    return create_primitive_type<TypeKind::TK_UINT32>();
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_uint64_type() noexcept
{
    return create_primitive_type<TypeKind::TK_UINT64>();
}

std::shared_ptr<DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_union_type(
        const DynamicTypeImpl& discriminator_type)
{
    if (discriminator_type.is_discriminator_type())
    {
        TypeState state;
        state.set_kind(TypeKind::TK_UNION);
        state.set_name(GenerateTypeName(get_type_name(TypeKind::TK_UNION)));
        state.discriminator_type_ = discriminator_type.shared_from_this();

        return create_type(state);
    }

    EPROSIMA_LOG_ERROR(DYN_TYPES, "Error building Union, invalid discriminator type");
    return {};
}

ReturnCode_t DynamicTypeBuilderFactoryImpl::delete_type(
        const DynamicTypeImpl& type) noexcept
{
    return DynamicTypeBuilderImpl::delete_type(type);
}

ReturnCode_t DynamicTypeBuilderFactoryImpl::delete_type(
        const DynamicTypeBuilderImpl& builder) noexcept
{
    builder.release();
    return ReturnCode_t::RETCODE_OK;
}

std::shared_ptr<const DynamicTypeBuilderImpl> DynamicTypeBuilderFactoryImpl::create_primitive_type(
        TypeKind kind) noexcept
{
    switch (kind)
    {
        case TypeKind::TK_BOOLEAN:
            return create_bool_type();
        case TypeKind::TK_BYTE:
            return create_byte_type();
        case TypeKind::TK_INT16:
            return create_int16_type();
        case TypeKind::TK_INT32:
            return create_int32_type();
        case TypeKind::TK_INT64:
            return create_int64_type();
        case TypeKind::TK_UINT16:
            return create_uint16_type();
        case TypeKind::TK_UINT32:
            return create_uint32_type();
        case TypeKind::TK_UINT64:
            return create_uint64_type();
        case TypeKind::TK_FLOAT32:
            return create_float32_type();
        case TypeKind::TK_FLOAT64:
            return create_float64_type();
        case TypeKind::TK_FLOAT128:
            return create_float128_type();
        case TypeKind::TK_CHAR8:
            return create_char8_type();
        case TypeKind::TK_CHAR16:
            return create_char16_type();
        default:
            EPROSIMA_LOG_ERROR(DYN_TYPES, "The type provided " << int(kind) << " is not primitive");
            return {};
    }
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_primitive_type(
        TypeKind kind) noexcept
{
    std::shared_ptr<const DynamicTypeBuilderImpl> builder{create_primitive_type(kind)};
    if (builder)
    {
        return builder->build();
    }
    return {};
}

bool DynamicTypeBuilderFactoryImpl::is_empty() const
{
    return dynamic_tracker<selected_mode>::get_dynamic_tracker().is_empty();
}

void DynamicTypeBuilderFactoryImpl::build_type_identifier(
        const TypeState& descriptor,
        TypeIdentifier& identifier,
        bool complete) const
{
    const TypeIdentifier* id2 = (complete)
        ? TypeObjectFactory::get_instance()->get_type_identifier_trying_complete(descriptor.get_name())
        : TypeObjectFactory::get_instance()->get_type_identifier(descriptor.get_name());
    if (id2 != nullptr)
    {
        identifier = *id2;
    }
    else
    {
        switch (descriptor.kind_)
        {
            // Basic types
            case TypeKind::TK_NONE:
            case TypeKind::TK_BOOLEAN:
            case TypeKind::TK_BYTE:
            case TypeKind::TK_INT16:
            case TypeKind::TK_INT32:
            case TypeKind::TK_INT64:
            case TypeKind::TK_UINT16:
            case TypeKind::TK_UINT32:
            case TypeKind::TK_UINT64:
            case TypeKind::TK_FLOAT32:
            case TypeKind::TK_FLOAT64:
            case TypeKind::TK_FLOAT128:
            case TypeKind::TK_CHAR8:
            case TypeKind::TK_CHAR16:
            {
                identifier._d(descriptor.kind_);
            }
            break;
            // String TKs
            case TypeKind::TK_STRING8:
            {
                if (descriptor.bound_[0] < 256)
                {
                    identifier._d(TypeKind::TI_STRING8_SMALL);
                    identifier.string_sdefn().bound(static_cast<SBound>(descriptor.bound_[0]));
                }
                else
                {
                    identifier._d(TypeKind::TI_STRING8_LARGE);
                    identifier.string_ldefn().bound(descriptor.bound_[0]);
                }
            }
            break;
            case TypeKind::TK_STRING16:
            {
                if (descriptor.bound_[0] < 256)
                {
                    identifier._d(TypeKind::TI_STRING16_SMALL);
                    identifier.string_sdefn().bound(static_cast<SBound>(descriptor.bound_[0]));
                }
                else
                {
                    identifier._d(TypeKind::TI_STRING16_LARGE);
                    identifier.string_ldefn().bound(descriptor.bound_[0]);
                }
            }
            break;
            // Collection TKs
            case TypeKind::TK_SEQUENCE:
            {
                if (descriptor.bound_[0] < 256)
                {
                    identifier._d(TypeKind::TI_PLAIN_SEQUENCE_SMALL);
                    identifier.seq_sdefn().bound(static_cast<SBound>(descriptor.bound_[0]));
                    TypeIdentifier elem_id;
                    build_type_identifier(*descriptor.get_element_type(), elem_id, complete);
                    identifier.seq_sdefn().element_identifier(&elem_id);
                }
                else
                {
                    identifier._d(TypeKind::TI_PLAIN_SEQUENCE_LARGE);
                    identifier.seq_ldefn().bound(descriptor.bound_[0]);
                    TypeIdentifier elem_id;
                    build_type_identifier(*descriptor.get_element_type(), elem_id, complete);
                    identifier.seq_ldefn().element_identifier(&elem_id);
                }
            }
            break;
            case TypeKind::TK_ARRAY:
            {
                uint32_t size = 0;
                for (uint32_t s : descriptor.bound_)
                {
                    size += s;
                }

                if (size < 256)
                {
                    identifier._d(TypeKind::TI_PLAIN_ARRAY_SMALL);
                    for (uint32_t b : descriptor.bound_)
                    {
                        identifier.array_sdefn().array_bound_seq().emplace_back(static_cast<SBound>(b));
                    }
                    TypeIdentifier elem_id;
                    build_type_identifier(*descriptor.get_element_type(), elem_id, complete);
                    identifier.array_sdefn().element_identifier(&elem_id);
                }
                else
                {
                    identifier._d(TypeKind::TI_PLAIN_ARRAY_LARGE);
                    identifier.array_ldefn().array_bound_seq(descriptor.bound_);
                    TypeIdentifier elem_id;
                    build_type_identifier(*descriptor.get_element_type(), elem_id, complete);
                    identifier.array_ldefn().element_identifier(&elem_id);
                }
            }
            break;
            case TypeKind::TK_MAP:
            {
                if (descriptor.bound_[0] < 256)
                {
                    identifier._d(TypeKind::TI_PLAIN_MAP_SMALL);
                    identifier.map_sdefn().bound(static_cast<SBound>(descriptor.bound_[0]));
                    TypeIdentifier elem_id;
                    build_type_identifier(*descriptor.get_element_type(), elem_id, complete);
                    identifier.map_sdefn().element_identifier(&elem_id);
                    TypeIdentifier key_id;
                    build_type_identifier(*descriptor.get_key_element_type(), key_id, complete);
                    identifier.map_sdefn().key_identifier(&key_id);
                }
                else
                {
                    identifier._d(TypeKind::TI_PLAIN_MAP_LARGE);
                    identifier.map_ldefn().bound(static_cast<SBound>(descriptor.bound_[0]));
                    TypeIdentifier elem_id;
                    build_type_identifier(*descriptor.get_element_type(), elem_id, complete);
                    identifier.map_ldefn().element_identifier(&elem_id);
                    TypeIdentifier key_id;
                    build_type_identifier(*descriptor.get_key_element_type(), key_id, complete);
                    identifier.map_ldefn().key_identifier(&key_id);
                }
            }
            break;
            // Constructed/Named types
            case TypeKind::TK_ALIAS:
            // Enumerated TKs
            case TypeKind::TK_ENUM:
            case TypeKind::TK_BITMASK:
            // Structured TKs
            case TypeKind::TK_ANNOTATION:
            case TypeKind::TK_STRUCTURE:
            case TypeKind::TK_UNION:
            case TypeKind::TK_BITSET:
            {
                // Need to be registered as TypeObject first
                // and return them as EK_MINIMAL or TypeKind::EK_COMPLETE
                EPROSIMA_LOG_INFO(DYN_TYPE_FACTORY, "Complex types must be built from CompleteTypeObjects.");
            }
            break;
            // TODO:BARRO handle this specific cases
            case TypeKind::TI_STRING8_SMALL:
            case TypeKind::TI_STRING8_LARGE:
            case TypeKind::TI_STRING16_SMALL:
            case TypeKind::TI_STRING16_LARGE:
            case TypeKind::TI_PLAIN_SEQUENCE_LARGE:
            case TypeKind::TI_PLAIN_SEQUENCE_SMALL:
            case TypeKind::TI_PLAIN_ARRAY_SMALL:
            case TypeKind::TI_PLAIN_ARRAY_LARGE:
            case TypeKind::TI_PLAIN_MAP_SMALL:
            case TypeKind::TI_PLAIN_MAP_LARGE:
            case TypeKind::TI_STRONGLY_CONNECTED_COMPONENT:
            case TypeKind::EK_MINIMAL:
            case TypeKind::EK_COMPLETE:
            case TypeKind::EK_BOTH:
                assert(0);
        }

        TypeObjectFactory::get_instance()->add_type_identifier(descriptor.get_name(), &identifier);
    }
}

void DynamicTypeBuilderFactoryImpl::build_type_object(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete,
        bool force) const
{
    const TypeObject* obj2 = (force)
        ? nullptr
        : TypeObjectFactory::get_instance()->get_type_object(descriptor.get_name(), complete);

    if (obj2 != nullptr)
    {
        object = *obj2;
        return;
    }

    // Create the TypeObject
    switch (descriptor.kind_)
    {
        // Basic types
        case TypeKind::TK_NONE:
        case TypeKind::TK_BOOLEAN:
        case TypeKind::TK_BYTE:
        case TypeKind::TK_INT16:
        case TypeKind::TK_INT32:
        case TypeKind::TK_INT64:
        case TypeKind::TK_UINT16:
        case TypeKind::TK_UINT32:
        case TypeKind::TK_UINT64:
        case TypeKind::TK_FLOAT32:
        case TypeKind::TK_FLOAT64:
        case TypeKind::TK_FLOAT128:
        case TypeKind::TK_CHAR8:
        case TypeKind::TK_CHAR16:
        {
            break;
        }
        // String TKs
        case TypeKind::TK_STRING8:
        {
            build_string8_type_code(descriptor);
            break;
        }
        case TypeKind::TK_STRING16:
        {
            build_string16_type_code(descriptor);
            break;
        }
        // Collection TKs
        case TypeKind::TK_SEQUENCE:
        {
            build_sequence_type_code(descriptor, object, complete);
            break;
        }
        case TypeKind::TK_ARRAY:
        {
            build_array_type_code(descriptor, object, complete);
            break;
        }
        case TypeKind::TK_MAP:
        {
            build_map_type_code(descriptor, object, complete);
            break;
        }

        // Constructed/Named types
        case TypeKind::TK_ALIAS:
        {
            build_alias_type_code(descriptor, object, complete);
        }
        break;
        // Enumerated TKs
        case TypeKind::TK_ENUM:
        {
            build_enum_type_code(descriptor, object, complete);
        }
        break;
        case TypeKind::TK_BITMASK:
        {
            build_bitmask_type_code(descriptor, object, complete);
        }
        break;
        // Structured TKs
        case TypeKind::TK_ANNOTATION:
        {
            build_annotation_type_code(descriptor, object, complete);
        }
        break;
        case TypeKind::TK_STRUCTURE:
        {
            build_struct_type_code(descriptor, object, complete);
        }
        break;
        case TypeKind::TK_UNION:
        {
            build_union_type_code(descriptor, object, complete);
        }
        break;
        case TypeKind::TK_BITSET:
        {
            build_bitset_type_code(descriptor, object, complete);
        }
        break;
        // TODO:BARRO handle this specific cases
        case TypeKind::TI_STRING8_SMALL:
        case TypeKind::TI_STRING8_LARGE:
        case TypeKind::TI_STRING16_SMALL:
        case TypeKind::TI_STRING16_LARGE:
        case TypeKind::TI_PLAIN_SEQUENCE_LARGE:
        case TypeKind::TI_PLAIN_SEQUENCE_SMALL:
        case TypeKind::TI_PLAIN_ARRAY_LARGE:
        case TypeKind::TI_PLAIN_ARRAY_SMALL:
        case TypeKind::TI_PLAIN_MAP_SMALL:
        case TypeKind::TI_PLAIN_MAP_LARGE:
        case TypeKind::TI_STRONGLY_CONNECTED_COMPONENT:
        case TypeKind::EK_MINIMAL:
        case TypeKind::EK_COMPLETE:
        case TypeKind::EK_BOTH:
            assert(0);
    }
}

void DynamicTypeBuilderFactoryImpl::build_string8_type_code(
        const TypeState& descriptor) const
{
    const TypeIdentifier* identifier =
            TypeObjectFactory::get_instance()->get_string_identifier(
        descriptor.get_bounds(),
        false);

    TypeObjectFactory::get_instance()->add_type_identifier(descriptor.get_name(), identifier);
}

void DynamicTypeBuilderFactoryImpl::build_string16_type_code(
        const TypeState& descriptor) const
{
    const TypeIdentifier* identifier =
            TypeObjectFactory::get_instance()->get_string_identifier(
        descriptor.get_bounds(),
        true);

    TypeObjectFactory::get_instance()->add_type_identifier(descriptor.get_name(), identifier);
}

void DynamicTypeBuilderFactoryImpl::build_sequence_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_SEQUENCE);
        object.complete().sequence_type().collection_flag().IS_FINAL(false);
        object.complete().sequence_type().collection_flag().IS_APPENDABLE(false);
        object.complete().sequence_type().collection_flag().IS_MUTABLE(false);
        object.complete().sequence_type().collection_flag().IS_NESTED(false);
        object.complete().sequence_type().collection_flag().IS_AUTOID_HASH(false);

        // Apply annotations
        apply_type_annotations(object.complete().sequence_type().header().detail().ann_custom(), descriptor);

        object.complete().sequence_type().header().detail().type_name(descriptor.get_name());
        object.complete().sequence_type().header().common().bound(descriptor.get_bounds());
        object.complete().sequence_type().element().common().element_flags().TRY_CONSTRUCT1(false);
        object.complete().sequence_type().element().common().element_flags().TRY_CONSTRUCT2(false);
        object.complete().sequence_type().element().common().element_flags().IS_EXTERNAL(false);
        object.complete().sequence_type().element().common().element_flags().IS_OPTIONAL(false);
        object.complete().sequence_type().element().common().element_flags().IS_MUST_UNDERSTAND(false);
        object.complete().sequence_type().element().common().element_flags().IS_KEY(false);
        object.complete().sequence_type().element().common().element_flags().IS_DEFAULT(false);

        //TypeIdentifier ident;
        //build_type_identifier(*descriptor.get_base_type(), ident);
        TypeObject obj;
        build_type_object(*descriptor.get_element_type(), obj, complete);
        TypeIdentifier ident = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_element_type()->get_name());

        object.complete().sequence_type().element().common().type(ident);

        const TypeIdentifier* identifier =
                TypeObjectFactory::get_instance()->get_sequence_identifier(
            descriptor.get_element_type()->get_name(),
            descriptor.get_bounds(),
            true);

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_MINIMAL);
        object.minimal()._d(TypeKind::TK_SEQUENCE);
        object.minimal().sequence_type().collection_flag().IS_FINAL(false);
        object.minimal().sequence_type().collection_flag().IS_APPENDABLE(false);
        object.minimal().sequence_type().collection_flag().IS_MUTABLE(false);
        object.minimal().sequence_type().collection_flag().IS_NESTED(false);
        object.minimal().sequence_type().collection_flag().IS_AUTOID_HASH(false);

        // Apply annotations
        object.minimal().sequence_type().header().common().bound(descriptor.get_bounds());
        object.minimal().sequence_type().element().common().element_flags().TRY_CONSTRUCT1(false);
        object.minimal().sequence_type().element().common().element_flags().TRY_CONSTRUCT2(false);
        object.minimal().sequence_type().element().common().element_flags().IS_EXTERNAL(false);
        object.minimal().sequence_type().element().common().element_flags().IS_OPTIONAL(false);
        object.minimal().sequence_type().element().common().element_flags().IS_MUST_UNDERSTAND(false);
        object.minimal().sequence_type().element().common().element_flags().IS_KEY(false);
        object.minimal().sequence_type().element().common().element_flags().IS_DEFAULT(false);

        //TypeIdentifier ident;
        //build_type_identifier(*descriptor.get_base_type(), ident);
        TypeObject obj;
        build_type_object(*descriptor.get_element_type(), obj);
        TypeIdentifier ident = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_element_type()->get_name());

        object.minimal().sequence_type().element().common().type(ident);

        const TypeIdentifier* identifier =
                TypeObjectFactory::get_instance()->get_sequence_identifier(
            descriptor.get_element_type()->get_name(),
            descriptor.get_bounds(),
            false);

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::build_array_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_ARRAY);
        object.complete().array_type().collection_flag().IS_FINAL(false);
        object.complete().array_type().collection_flag().IS_APPENDABLE(false);
        object.complete().array_type().collection_flag().IS_MUTABLE(false);
        object.complete().array_type().collection_flag().IS_NESTED(false);
        object.complete().array_type().collection_flag().IS_AUTOID_HASH(false);

        // Apply annotations
        apply_type_annotations(object.complete().array_type().header().detail().ann_custom(), descriptor);

        object.complete().array_type().header().detail().type_name(descriptor.get_name());
        for (uint32_t i = 0; i < descriptor.get_bounds_size(); ++i)
        {
            object.complete().array_type().header().common().bound_seq().push_back(descriptor.get_bounds(i));
        }
        object.complete().array_type().element().common().element_flags().TRY_CONSTRUCT1(false);
        object.complete().array_type().element().common().element_flags().TRY_CONSTRUCT2(false);
        object.complete().array_type().element().common().element_flags().IS_EXTERNAL(false);
        object.complete().array_type().element().common().element_flags().IS_OPTIONAL(false);
        object.complete().array_type().element().common().element_flags().IS_MUST_UNDERSTAND(false);
        object.complete().array_type().element().common().element_flags().IS_KEY(false);
        object.complete().array_type().element().common().element_flags().IS_DEFAULT(false);

        //TypeIdentifier ident;
        //build_type_identifier(*descriptor.get_base_type(), ident);
        TypeObject obj;
        build_type_object(*descriptor.get_element_type(), obj, complete);
        TypeIdentifier ident = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_element_type()->get_name());

        object.complete().array_type().element().common().type(ident);

        const TypeIdentifier* identifier =
                TypeObjectFactory::get_instance()->get_array_identifier(
            descriptor.get_element_type()->get_name(),
            object.complete().array_type().header().common().bound_seq(),
            true);

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_MINIMAL);
        object.minimal()._d(TypeKind::TK_ARRAY);
        object.minimal().array_type().collection_flag().IS_FINAL(false);
        object.minimal().array_type().collection_flag().IS_APPENDABLE(false);
        object.minimal().array_type().collection_flag().IS_MUTABLE(false);
        object.minimal().array_type().collection_flag().IS_NESTED(false);
        object.minimal().array_type().collection_flag().IS_AUTOID_HASH(false);

        // Apply annotations
        for (uint32_t i = 0; i < descriptor.get_bounds_size(); ++i)
        {
            object.minimal().array_type().header().common().bound_seq().push_back(descriptor.get_bounds(i));
        }
        object.minimal().array_type().element().common().element_flags().TRY_CONSTRUCT1(false);
        object.minimal().array_type().element().common().element_flags().TRY_CONSTRUCT2(false);
        object.minimal().array_type().element().common().element_flags().IS_EXTERNAL(false);
        object.minimal().array_type().element().common().element_flags().IS_OPTIONAL(false);
        object.minimal().array_type().element().common().element_flags().IS_MUST_UNDERSTAND(false);
        object.minimal().array_type().element().common().element_flags().IS_KEY(false);
        object.minimal().array_type().element().common().element_flags().IS_DEFAULT(false);

        //TypeIdentifier ident;
        //build_type_identifier(*descriptor.get_base_type(), ident);
        TypeObject obj;
        build_type_object(*descriptor.get_element_type(), obj);
        TypeIdentifier ident = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_element_type()->get_name());

        object.minimal().array_type().element().common().type(ident);

        const TypeIdentifier* identifier =
                TypeObjectFactory::get_instance()->get_array_identifier(
            descriptor.get_element_type()->get_name(),
            object.minimal().array_type().header().common().bound_seq(),
            false);

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::build_map_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_MAP);
        object.complete().map_type().collection_flag().IS_FINAL(false);
        object.complete().map_type().collection_flag().IS_APPENDABLE(false);
        object.complete().map_type().collection_flag().IS_MUTABLE(false);
        object.complete().map_type().collection_flag().IS_NESTED(false);
        object.complete().map_type().collection_flag().IS_AUTOID_HASH(false);

        // Apply annotations
        apply_type_annotations(object.complete().map_type().header().detail().ann_custom(), descriptor);

        object.complete().map_type().header().detail().type_name(descriptor.get_name());
        object.complete().map_type().header().common().bound(descriptor.get_bounds());
        object.complete().map_type().element().common().element_flags().TRY_CONSTRUCT1(false);
        object.complete().map_type().element().common().element_flags().TRY_CONSTRUCT2(false);
        object.complete().map_type().element().common().element_flags().IS_EXTERNAL(false);
        object.complete().map_type().element().common().element_flags().IS_OPTIONAL(false);
        object.complete().map_type().element().common().element_flags().IS_MUST_UNDERSTAND(false);
        object.complete().map_type().element().common().element_flags().IS_KEY(false);
        object.complete().map_type().element().common().element_flags().IS_DEFAULT(false);
        object.complete().map_type().key().common().element_flags().TRY_CONSTRUCT1(false);
        object.complete().map_type().key().common().element_flags().TRY_CONSTRUCT2(false);
        object.complete().map_type().key().common().element_flags().IS_EXTERNAL(false);
        object.complete().map_type().key().common().element_flags().IS_OPTIONAL(false);
        object.complete().map_type().key().common().element_flags().IS_MUST_UNDERSTAND(false);
        object.complete().map_type().key().common().element_flags().IS_KEY(false);
        object.complete().map_type().key().common().element_flags().IS_DEFAULT(false);

        //TypeIdentifier ident;
        //build_type_identifier(*descriptor.get_base_type(), ident);
        TypeObject obj;
        build_type_object(*descriptor.get_element_type(), obj, complete);
        TypeIdentifier ident = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_element_type()->get_name());

        build_type_object(*descriptor.get_key_element_type(), obj, complete);
        TypeIdentifier ident_key = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_key_element_type()->get_name());

        object.complete().map_type().element().common().type(ident);
        object.complete().map_type().key().common().type(ident_key);

        const TypeIdentifier* identifier =
                TypeObjectFactory::get_instance()->get_map_identifier(
            descriptor.get_key_element_type()->get_name(),
            descriptor.get_element_type()->get_name(),
            descriptor.get_bounds(),
            true);

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_MINIMAL);
        object.minimal()._d(TypeKind::TK_MAP);
        object.minimal().map_type().collection_flag().IS_FINAL(false);
        object.minimal().map_type().collection_flag().IS_APPENDABLE(false);
        object.minimal().map_type().collection_flag().IS_MUTABLE(false);
        object.minimal().map_type().collection_flag().IS_NESTED(false);
        object.minimal().map_type().collection_flag().IS_AUTOID_HASH(false);

        // Apply annotations
        object.minimal().map_type().header().common().bound(descriptor.get_bounds());
        object.minimal().map_type().element().common().element_flags().TRY_CONSTRUCT1(false);
        object.minimal().map_type().element().common().element_flags().TRY_CONSTRUCT2(false);
        object.minimal().map_type().element().common().element_flags().IS_EXTERNAL(false);
        object.minimal().map_type().element().common().element_flags().IS_OPTIONAL(false);
        object.minimal().map_type().element().common().element_flags().IS_MUST_UNDERSTAND(false);
        object.minimal().map_type().element().common().element_flags().IS_KEY(false);
        object.minimal().map_type().element().common().element_flags().IS_DEFAULT(false);

        //TypeIdentifier ident;
        //build_type_identifier(*descriptor.get_base_type(), ident);
        TypeObject obj;
        build_type_object(*descriptor.get_element_type(), obj);
        TypeIdentifier ident = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_element_type()->get_name());

        build_type_object(*descriptor.get_key_element_type(), obj, complete);
        TypeIdentifier ident_key = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_key_element_type()->get_name());

        object.minimal().map_type().element().common().type(ident);
        object.minimal().map_type().key().common().type(ident_key);

        const TypeIdentifier* identifier =
                TypeObjectFactory::get_instance()->get_map_identifier(
            descriptor.get_key_element_type()->get_name(),
            descriptor.get_element_type()->get_name(),
            descriptor.get_bounds(),
            false);

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::build_alias_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_ALIAS);
        object.complete().alias_type().alias_flags().IS_FINAL(false);
        object.complete().alias_type().alias_flags().IS_APPENDABLE(false);
        object.complete().alias_type().alias_flags().IS_MUTABLE(false);
        object.complete().alias_type().alias_flags().IS_NESTED(false);
        object.complete().alias_type().alias_flags().IS_AUTOID_HASH(false);

        // Apply annotations
        apply_type_annotations(object.complete().alias_type().header().detail().ann_custom(), descriptor);

        object.complete().alias_type().header().detail().type_name(descriptor.get_name());
        object.complete().alias_type().body().common().related_flags().TRY_CONSTRUCT1(false);
        object.complete().alias_type().body().common().related_flags().TRY_CONSTRUCT2(false);
        object.complete().alias_type().body().common().related_flags().IS_EXTERNAL(false);
        object.complete().alias_type().body().common().related_flags().IS_OPTIONAL(false);
        object.complete().alias_type().body().common().related_flags().IS_MUST_UNDERSTAND(false);
        object.complete().alias_type().body().common().related_flags().IS_KEY(false);
        object.complete().alias_type().body().common().related_flags().IS_DEFAULT(false);

        //TypeIdentifier ident;
        //build_type_identifier(*descriptor.get_base_type(), ident);
        TypeObject obj;
        build_type_object(*descriptor.get_base_type(), obj, complete);
        TypeIdentifier ident = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_base_type()->get_name());

        object.complete().alias_type().body().common().related_type(ident);

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_COMPLETE);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    CompleteAliasType::getCdrSerializedSize(object.complete().alias_type()) + 4));
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
        // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
        eprosima::fastcdr::Cdr ser(
            fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;

        object.serialize(ser);
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        // Add our alias
        TypeObjectFactory::get_instance()->add_alias(descriptor.get_name(), descriptor.get_base_type()->get_name());

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_MINIMAL);
        object.minimal()._d(TypeKind::TK_ALIAS);
        object.minimal().alias_type().alias_flags().IS_FINAL(false);
        object.minimal().alias_type().alias_flags().IS_APPENDABLE(false);
        object.minimal().alias_type().alias_flags().IS_MUTABLE(false);
        object.minimal().alias_type().alias_flags().IS_NESTED(false);
        object.minimal().alias_type().alias_flags().IS_AUTOID_HASH(false);

        object.minimal().alias_type().body().common().related_flags().TRY_CONSTRUCT1(false);
        object.minimal().alias_type().body().common().related_flags().TRY_CONSTRUCT2(false);
        object.minimal().alias_type().body().common().related_flags().IS_EXTERNAL(false);
        object.minimal().alias_type().body().common().related_flags().IS_OPTIONAL(false);
        object.minimal().alias_type().body().common().related_flags().IS_MUST_UNDERSTAND(false);
        object.minimal().alias_type().body().common().related_flags().IS_KEY(false);
        object.minimal().alias_type().body().common().related_flags().IS_DEFAULT(false);

        //TypeIdentifier ident;
        //build_type_identifier(*descriptor.get_base_type(), ident);
        TypeObject obj;
        build_type_object(*descriptor.get_base_type(), obj);
        TypeIdentifier ident = *TypeObjectFactory::get_instance()->get_type_identifier(
            descriptor.get_base_type()->get_name());

        object.minimal().alias_type().body().common().related_type(ident);

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_MINIMAL);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    MinimalAliasType::getCdrSerializedSize(object.minimal().alias_type()) + 4));
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
        // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
        eprosima::fastcdr::Cdr ser(
            fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;

        object.serialize(ser);
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        // Add our alias
        TypeObjectFactory::get_instance()->add_alias(descriptor.get_name(), descriptor.get_base_type()->get_name());

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::build_enum_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_ENUM);
        object.complete().enumerated_type().header().common().bit_bound(descriptor.annotation_get_bit_bound());
        object.complete().enumerated_type().header().detail().type_name(descriptor.get_name());

        // Apply annotations
        apply_type_annotations(object.complete().enumerated_type().header().detail().ann_custom(), descriptor);

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;
            CompleteEnumeratedLiteral mel;
            mel.common().flags().IS_DEFAULT(member.annotation_is_default_literal());
            mel.common().value(member.get_index());
            mel.detail().name(member.get_name());

            // Apply member annotations
            apply_type_annotations(mel.detail().ann_custom(), *member.get_type());

            object.complete().enumerated_type().literal_seq().emplace_back(mel);
        }

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_COMPLETE);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    CompleteEnumeratedType::getCdrSerializedSize(object.complete().enumerated_type()) + 4));
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
        // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
        eprosima::fastcdr::Cdr ser(
            fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;

        object.serialize(ser);
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_MINIMAL);
        object.minimal()._d(TypeKind::TK_ENUM);
        object.minimal().enumerated_type().header().common().bit_bound(32); // TODO fixed by IDL, isn't?

        for (const DynamicTypeMemberImpl* pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;
            MinimalEnumeratedLiteral mel;
            mel.common().flags().IS_DEFAULT(member.annotation_is_default_literal());
            mel.common().value(member.get_index());
            MD5 hash(member.get_name());
            for (int i = 0; i < 4; ++i)
            {
                mel.detail().name_hash()[i] = hash.digest[i];
            }
            object.minimal().enumerated_type().literal_seq().emplace_back(mel);
        }

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_MINIMAL);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    MinimalEnumeratedType::getCdrSerializedSize(object.minimal().enumerated_type()) + 4));
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
        // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
        eprosima::fastcdr::Cdr ser(
            fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;

        object.serialize(ser);
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::build_struct_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_STRUCTURE);

        object.complete().struct_type().struct_flags().IS_FINAL(descriptor.annotation_is_final());
        object.complete().struct_type().struct_flags().IS_APPENDABLE(descriptor.annotation_is_appendable());
        object.complete().struct_type().struct_flags().IS_MUTABLE(descriptor.annotation_is_mutable());
        object.complete().struct_type().struct_flags().IS_NESTED(descriptor.annotation_is_nested());
        object.complete().struct_type().struct_flags().IS_AUTOID_HASH(false);

        // Apply annotations
        apply_type_annotations(object.complete().struct_type().header().detail().ann_custom(), descriptor);

        auto members = descriptor.get_all_members();
        auto it = members.begin();

        // Populate base type
        auto base_type = descriptor.get_base_type();
        if (base_type)
        {
            TypeIdentifier parent;
            build_type_identifier(*base_type, parent);
            object.complete().struct_type().header().base_type(parent);

            // TypeObject only references a types own members
            std::advance(it, base_type->get_member_count());
        }

        for (; it != members.end(); ++it)
        {
            assert(nullptr != *it);
            const DynamicTypeMemberImpl& member = **it;

            CompleteStructMember msm;
            msm.common().member_id(MemberId(member.get_index()));
            msm.common().member_flags().TRY_CONSTRUCT1(false);
            msm.common().member_flags().TRY_CONSTRUCT2(false);
            msm.common().member_flags().IS_EXTERNAL(false);
            msm.common().member_flags().IS_OPTIONAL(member.annotation_is_optional());
            msm.common().member_flags().IS_MUST_UNDERSTAND(member.annotation_is_must_understand());
            msm.common().member_flags().IS_KEY(member.annotation_is_key());
            msm.common().member_flags().IS_DEFAULT(false);

            // Apply member annotations
            auto member_type = member.get_type();
            apply_type_annotations(msm.detail().ann_custom(), *member_type);

            TypeObject memObj;
            build_type_object(*member_type, memObj);
            const TypeIdentifier* typeId =
                    TypeObjectFactory::get_instance()->get_type_identifier_trying_complete(member_type->get_name());
            if (typeId == nullptr)
            {
                EPROSIMA_LOG_ERROR(DYN_TYPES, "Member " << member.get_name() << " of struct "
                                                        << descriptor.get_name() << " failed.");
            }
            else
            {
                TypeIdentifier memIdent = *typeId;
                msm.common().member_type_id(memIdent);
            }

            msm.detail().name(member.get_name());
            object.complete().struct_type().member_seq().emplace_back(msm);
        }

        object.complete().struct_type().header().detail().type_name(descriptor.get_name());
        //object.complete().struct_type().header().detail().ann_builtin()...
        //object.complete().struct_type().header().detail().ann_custom()...
        //object.complete().struct_type().header().base_type().equivalence_hash()[0..13];

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_COMPLETE);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    CompleteStructType::getCdrSerializedSize(object.complete().struct_type()) + 4));
        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);

        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;
        // Serialize encapsulation

        for (CompleteStructMember& st : object.complete().struct_type().member_seq())
        {
            ser << st;
        }
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_MINIMAL);
        object.minimal()._d(TypeKind::TK_STRUCTURE);

        object.minimal().struct_type().struct_flags().IS_FINAL(descriptor.annotation_is_final());
        object.minimal().struct_type().struct_flags().IS_APPENDABLE(descriptor.annotation_is_appendable());
        object.minimal().struct_type().struct_flags().IS_MUTABLE(descriptor.annotation_is_mutable());
        object.minimal().struct_type().struct_flags().IS_NESTED(descriptor.annotation_is_nested());
        object.minimal().struct_type().struct_flags().IS_AUTOID_HASH(false);

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;

            MinimalStructMember msm;
            msm.common().member_id(MemberId(member.get_index()));
            msm.common().member_flags().TRY_CONSTRUCT1(false);
            msm.common().member_flags().TRY_CONSTRUCT2(false);
            msm.common().member_flags().IS_EXTERNAL(false);
            msm.common().member_flags().IS_OPTIONAL(member.annotation_is_optional());
            msm.common().member_flags().IS_MUST_UNDERSTAND(member.annotation_is_must_understand());
            msm.common().member_flags().IS_KEY(member.annotation_is_key());
            msm.common().member_flags().IS_DEFAULT(false);
            //TypeIdentifier memIdent;
            //build_type_identifier(*member.get_type(), memIdent);

            TypeObject memObj;
            build_type_object(*member.get_type(), memObj, false);
            const TypeIdentifier* typeId =
                    TypeObjectFactory::get_instance()->get_type_identifier(member.get_type()->get_name());
            if (typeId == nullptr)
            {
                EPROSIMA_LOG_ERROR(DYN_TYPES, "Member " << member.get_name()
                                                        << " of struct " << descriptor.get_name() << " failed.");
            }
            else
            {
                TypeIdentifier memIdent = *typeId;
                msm.common().member_type_id(memIdent);
            }

            MD5 hash(member.get_name());
            for (int i = 0; i < 4; ++i)
            {
                msm.detail().name_hash()[i] = hash.digest[i];
            }
            object.minimal().struct_type().member_seq().emplace_back(msm);
        }

        if (descriptor.get_base_type().get() != nullptr)
        {
            TypeIdentifier parent;
            build_type_identifier(*descriptor.get_base_type(), parent, false);
            object.minimal().struct_type().header().base_type(parent);
        }

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_MINIMAL);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    MinimalStructType::getCdrSerializedSize(object.minimal().struct_type()) + 4));
        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);

        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;
        // Serialize encapsulation

        for (MinimalStructMember& st : object.minimal().struct_type().member_seq())
        {
            ser << st;
        }
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::build_union_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_UNION);

        object.complete().union_type().union_flags().IS_FINAL(descriptor.annotation_is_final());
        object.complete().union_type().union_flags().IS_APPENDABLE(descriptor.annotation_is_appendable());
        object.complete().union_type().union_flags().IS_MUTABLE(descriptor.annotation_is_mutable());
        object.complete().union_type().union_flags().IS_NESTED(descriptor.annotation_is_nested());
        object.complete().union_type().union_flags().IS_AUTOID_HASH(false);

        object.complete().union_type().discriminator().common().member_flags().TRY_CONSTRUCT1(false);
        object.complete().union_type().discriminator().common().member_flags().TRY_CONSTRUCT2(false);
        object.complete().union_type().discriminator().common().member_flags().IS_EXTERNAL(false);
        object.complete().union_type().discriminator().common().member_flags().IS_OPTIONAL(false);
        object.complete().union_type().discriminator().common().member_flags().IS_MUST_UNDERSTAND(false);
        object.complete().union_type().discriminator().common().member_flags().IS_KEY(
            descriptor.discriminator_type_->annotation_is_key());
        object.complete().union_type().discriminator().common().member_flags().IS_DEFAULT(false);

        // Apply annotations
        apply_type_annotations(object.complete().struct_type().header().detail().ann_custom(), descriptor);

        TypeObject discObj;
        build_type_object(*descriptor.discriminator_type_, discObj);
        TypeIdentifier discIdent =
                *TypeObjectFactory::get_instance()->get_type_identifier(descriptor.discriminator_type_->get_name());
        object.complete().union_type().discriminator().common().type_id(discIdent);

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;

            CompleteUnionMember mum;
            mum.common().member_id(MemberId(member.get_index()));
            mum.common().member_flags().TRY_CONSTRUCT1(false);
            mum.common().member_flags().TRY_CONSTRUCT2(false);
            mum.common().member_flags().IS_EXTERNAL(false);
            mum.common().member_flags().IS_OPTIONAL(false);
            mum.common().member_flags().IS_MUST_UNDERSTAND(false);
            mum.common().member_flags().IS_KEY(false);
            mum.common().member_flags().IS_DEFAULT(member.is_default_union_value());

            // Apply member annotations
            const auto& state = *member.get_type();
            apply_type_annotations(mum.detail().ann_custom(), state);

            TypeObject memObj;
            build_type_object(state, memObj);
            const TypeIdentifier* typeId =
                    TypeObjectFactory::get_instance()->get_type_identifier_trying_complete(member.get_type()->get_name());
            if (typeId == nullptr)
            {
                EPROSIMA_LOG_ERROR(DYN_TYPES, "Member " << member.get_name()
                                                        << " of union " << descriptor.get_name() << " failed.");
            }
            else
            {
                TypeIdentifier memIdent = *typeId;
                mum.common().type_id(memIdent);
            }

            for (uint64_t lab : member.get_union_labels())
            {
                mum.common().label_seq().emplace_back(static_cast<uint32_t>(lab));
            }
            mum.detail().name(member.get_name());
            object.complete().union_type().member_seq().emplace_back(mum);
        }

        object.complete().union_type().header().detail().type_name(descriptor.get_name());

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_MINIMAL);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    CompleteUnionType::getCdrSerializedSize(object.complete().union_type()) + 4));
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
        // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
        eprosima::fastcdr::Cdr ser(
            fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;

        object.serialize(ser);
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_MINIMAL);
        object.minimal()._d(TypeKind::TK_UNION);

        object.minimal().union_type().union_flags().IS_FINAL(descriptor.annotation_is_final());
        object.minimal().union_type().union_flags().IS_APPENDABLE(descriptor.annotation_is_appendable());
        object.minimal().union_type().union_flags().IS_MUTABLE(descriptor.annotation_is_mutable());
        object.minimal().union_type().union_flags().IS_NESTED(descriptor.annotation_is_nested());
        object.minimal().union_type().union_flags().IS_AUTOID_HASH(false);

        object.minimal().union_type().discriminator().common().member_flags().TRY_CONSTRUCT1(false);
        object.minimal().union_type().discriminator().common().member_flags().TRY_CONSTRUCT2(false);
        object.minimal().union_type().discriminator().common().member_flags().IS_EXTERNAL(false);
        object.minimal().union_type().discriminator().common().member_flags().IS_OPTIONAL(false);
        object.minimal().union_type().discriminator().common().member_flags().IS_MUST_UNDERSTAND(false);
        object.minimal().union_type().discriminator().common().member_flags().IS_KEY(
            descriptor.discriminator_type_->annotation_is_key());
        object.minimal().union_type().discriminator().common().member_flags().IS_DEFAULT(false);

        TypeObject discObj;
        build_type_object(*descriptor.discriminator_type_, discObj);
        TypeIdentifier discIdent =
                *TypeObjectFactory::get_instance()->get_type_identifier(descriptor.discriminator_type_->get_name());
        object.minimal().union_type().discriminator().common().type_id(discIdent);
        //*TypeObjectFactory::get_instance().get_type_identifier(descriptor.discriminator_type_->get_name()));

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;

            MinimalUnionMember mum;
            mum.common().member_id(MemberId(member.get_index()));
            mum.common().member_flags().TRY_CONSTRUCT1(false);
            mum.common().member_flags().TRY_CONSTRUCT2(false);
            mum.common().member_flags().IS_EXTERNAL(false);
            mum.common().member_flags().IS_OPTIONAL(false);
            mum.common().member_flags().IS_MUST_UNDERSTAND(false);
            mum.common().member_flags().IS_KEY(false);
            mum.common().member_flags().IS_DEFAULT(member.is_default_union_value());

            //TypeIdentifier memIdent;
            //build_type_identifier(*member.get_type(), memIdent);

            TypeObject memObj;
            build_type_object(*member.get_type(), memObj);
            const TypeIdentifier* typeId =
                    TypeObjectFactory::get_instance()->get_type_identifier(member.get_type()->get_name());
            if (typeId == nullptr)
            {
                EPROSIMA_LOG_ERROR(DYN_TYPES, "Member " << member.get_name()
                                                        << " of union " << descriptor.get_name() << " failed.");
            }
            else
            {
                TypeIdentifier memIdent = *typeId;
                mum.common().type_id(memIdent);
            }

            for (uint64_t lab : member.get_union_labels())
            {
                mum.common().label_seq().emplace_back(static_cast<uint32_t>(lab));
            }
            MD5 hash(member.get_name());
            for (int i = 0; i < 4; ++i)
            {
                mum.detail().name_hash()[i] = hash.digest[i];
            }
            object.minimal().union_type().member_seq().emplace_back(mum);
        }

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_MINIMAL);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    MinimalUnionType::getCdrSerializedSize(object.minimal().union_type()) + 4));
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
        // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
        eprosima::fastcdr::Cdr ser(
            fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;

        object.serialize(ser);
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::build_bitset_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_BITSET);

        object.complete().bitset_type().bitset_flags().IS_FINAL(false);
        object.complete().bitset_type().bitset_flags().IS_APPENDABLE(false);
        object.complete().bitset_type().bitset_flags().IS_MUTABLE(false);
        object.complete().bitset_type().bitset_flags().IS_NESTED(false);
        object.complete().bitset_type().bitset_flags().IS_AUTOID_HASH(false);

        // Apply annotations
        apply_type_annotations(object.complete().bitset_type().header().detail().ann_custom(), descriptor);

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;

            CompleteBitfield msm;
            msm.common().position(member.annotation_get_position()); // Position stored as annotation
            // Bitcount stored as bit_bound annotation
            msm.common().bitcount(static_cast<octet>(member.annotation_get_bit_bound()));
            msm.common().holder_type(member.get_type()->get_kind());
            msm.detail().name(member.get_name());

            // Apply member annotations
            apply_type_annotations(msm.detail().ann_custom(), *member.get_type());

            object.complete().bitset_type().field_seq().emplace_back(msm);
        }

        object.complete().bitset_type().header().detail().type_name(descriptor.get_name());
        //object.complete().bitset_type().header().detail().ann_builtin()...
        //object.complete().bitset_type().header().detail().ann_custom()...

        if (descriptor.get_base_type().get() != nullptr)
        {
            TypeIdentifier parent;
            build_type_identifier(*descriptor.get_base_type(), parent);
            object.complete().bitset_type().header().base_type(parent);
        }
        //object.complete().bitset_type().header().base_type().equivalence_hash()[0..13];

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_COMPLETE);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    CompleteBitsetType::getCdrSerializedSize(object.complete().bitset_type()) + 4));
        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);

        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;
        // Serialize encapsulation

        for (CompleteBitfield& st : object.complete().bitset_type().field_seq())
        {
            ser << st;
        }
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_COMPLETE);
        object.minimal()._d(TypeKind::TK_BITSET);

        object.minimal().bitset_type().bitset_flags().IS_FINAL(false);
        object.minimal().bitset_type().bitset_flags().IS_APPENDABLE(false);
        object.minimal().bitset_type().bitset_flags().IS_MUTABLE(false);
        object.minimal().bitset_type().bitset_flags().IS_NESTED(false);
        object.minimal().bitset_type().bitset_flags().IS_AUTOID_HASH(false);

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;

            MinimalBitfield msm;
            msm.common().position(member.annotation_get_position()); // Position stored as annotation
            // Bitcount stored as bit_bound annotation
            msm.common().bitcount(static_cast<octet>(member.annotation_get_bit_bound()));
            msm.common().holder_type(member.get_type()->get_kind());
            MD5 parent_bitfield_hash(member.get_name());
            for (int i = 0; i < 4; ++i)
            {
                msm.name_hash()[i] = parent_bitfield_hash.digest[i];
            }
            object.minimal().bitset_type().field_seq().emplace_back(msm);
        }

        //object.minimal().bitset_type().header().detail().ann_builtin()...
        //object.minimal().bitset_type().header().detail().ann_custom()...

        if (descriptor.get_base_type().get() != nullptr)
        {
            TypeIdentifier parent;
            build_type_identifier(*descriptor.get_base_type(), parent);
            object.minimal().bitset_type().header().base_type(parent);
        }
        //object.minimal().bitset_type().header().base_type().equivalence_hash()[0..13];

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_COMPLETE);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    MinimalBitsetType::getCdrSerializedSize(object.minimal().bitset_type()) + 4));
        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);

        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;
        // Serialize encapsulation

        for (MinimalBitfield& st : object.minimal().bitset_type().field_seq())
        {
            ser << st;
        }
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::build_bitmask_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_BITMASK);

        object.complete().bitmask_type().bitmask_flags().IS_FINAL(false);
        object.complete().bitmask_type().bitmask_flags().IS_APPENDABLE(false);
        object.complete().bitmask_type().bitmask_flags().IS_MUTABLE(false);
        object.complete().bitmask_type().bitmask_flags().IS_NESTED(false);
        object.complete().bitmask_type().bitmask_flags().IS_AUTOID_HASH(false);

        // Apply annotations
        apply_type_annotations(object.complete().bitmask_type().header().detail().ann_custom(), descriptor);

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;

            CompleteBitflag msm;
            msm.common().position(member.annotation_get_position()); // Position stored as annotation
            msm.detail().name(member.get_name());

            // Apply member annotations
            apply_type_annotations(msm.detail().ann_custom(), *member.get_type());

            object.complete().bitmask_type().flag_seq().emplace_back(msm);
        }

        object.complete().bitmask_type().header().detail().type_name(descriptor.get_name());

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_COMPLETE);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    CompleteBitmaskType::getCdrSerializedSize(object.complete().bitmask_type()) + 4));
        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);

        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;
        // Serialize encapsulation

        for (CompleteBitflag& st : object.complete().bitmask_type().flag_seq())
        {
            ser << st;
        }
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_COMPLETE);
        object.minimal()._d(TypeKind::TK_BITMASK);

        object.minimal().bitmask_type().bitmask_flags().IS_FINAL(false);
        object.minimal().bitmask_type().bitmask_flags().IS_APPENDABLE(false);
        object.minimal().bitmask_type().bitmask_flags().IS_MUTABLE(false);
        object.minimal().bitmask_type().bitmask_flags().IS_NESTED(false);
        object.minimal().bitmask_type().bitmask_flags().IS_AUTOID_HASH(false);

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;

            MinimalBitflag msm;
            msm.common().position(member.annotation_get_position()); // Position stored as annotation
            MD5 parent_bitfield_hash(member.get_name());
            for (int i = 0; i < 4; ++i)
            {
                msm.detail().name_hash()[i] = parent_bitfield_hash.digest[i];
            }
            object.minimal().bitmask_type().flag_seq().emplace_back(msm);
        }

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_COMPLETE);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    MinimalBitmaskType::getCdrSerializedSize(object.minimal().bitmask_type()) + 4));
        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);

        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;
        // Serialize encapsulation

        for (MinimalBitflag& st : object.minimal().bitmask_type().flag_seq())
        {
            ser << st;
        }
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::build_annotation_type_code(
        const TypeState& descriptor,
        TypeObject& object,
        bool complete) const
{
    if (complete)
    {
        object._d(TypeKind::EK_COMPLETE);
        object.complete()._d(TypeKind::TK_ANNOTATION);

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;

            CompleteAnnotationParameter msm;
            msm.name(member.get_name());

            if (!member.get_default_value().empty())
            {
                AnnotationParameterValue apv;
                set_annotation_default_value(apv, member);
                msm.default_value(apv);
            }

            TypeObject memObj;
            build_type_object(*member.get_type(), memObj);
            const TypeIdentifier* typeId =
                    TypeObjectFactory::get_instance()->get_type_identifier(member.get_type()->get_name());
            if (typeId == nullptr)
            {
                EPROSIMA_LOG_ERROR(DYN_TYPES, "Member " << member.get_name()
                                                        << " of annotation " << descriptor.get_name() << " failed.");
            }
            else
            {
                TypeIdentifier memIdent = *typeId;
                msm.common().member_type_id(memIdent);
            }

            object.complete().annotation_type().member_seq().emplace_back(msm);
        }

        object.complete().annotation_type().header().annotation_name(descriptor.get_name());

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_COMPLETE);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    CompleteAnnotationType::getCdrSerializedSize(object.complete().annotation_type()) + 4));
        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);

        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;
        // Serialize encapsulation

        for (CompleteAnnotationParameter& st : object.complete().annotation_type().member_seq())
        {
            ser << st;
        }
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
    else
    {
        object._d(TypeKind::EK_COMPLETE);
        object.minimal()._d(TypeKind::TK_ANNOTATION);

        for (auto pm : descriptor.get_all_members())
        {
            assert(pm);
            const DynamicTypeMemberImpl& member = *pm;

            MinimalAnnotationParameter msm;
            msm.name(member.get_name());

            if (!member.get_default_value().empty())
            {
                AnnotationParameterValue apv;
                set_annotation_default_value(apv, member);
                msm.default_value(apv);
            }

            TypeObject memObj;
            build_type_object(*member.get_type(), memObj);
            const TypeIdentifier* typeId =
                    TypeObjectFactory::get_instance()->get_type_identifier(member.get_type()->get_name());
            if (typeId == nullptr)
            {
                EPROSIMA_LOG_ERROR(DYN_TYPES, "Member " << member.get_name()
                                                        << " of annotation " << descriptor.get_name() << " failed.");
            }
            else
            {
                TypeIdentifier memIdent = *typeId;
                msm.common().member_type_id(memIdent);
            }

            object.minimal().annotation_type().member_seq().emplace_back(msm);
        }

        TypeIdentifier identifier;
        identifier._d(TypeKind::EK_COMPLETE);

        eprosima::fastrtps::rtps::SerializedPayload_t payload(static_cast<uint32_t>(
                    MinimalAnnotationType::getCdrSerializedSize(object.minimal().annotation_type()) + 4));
        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);

        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
        payload.encapsulation = CDR_LE;
        // Serialize encapsulation

        for (MinimalAnnotationParameter& st : object.minimal().annotation_type().member_seq())
        {
            ser << st;
        }
        payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        MD5 objectHash;
        objectHash.update((char*)payload.data, payload.length);
        objectHash.finalize();
        for (int i = 0; i < 14; ++i)
        {
            identifier.equivalence_hash()[i] = objectHash.digest[i];
        }

        TypeObjectFactory::get_instance()->add_type_object(descriptor.get_name(), &identifier, &object);
    }
}

void DynamicTypeBuilderFactoryImpl::set_annotation_default_value(
        AnnotationParameterValue& apv,
        const MemberDescriptorImpl& member) const
{
    switch (member.get_kind())
    {
        case TypeKind::TK_BOOLEAN:
        {
            std::string value = member.get_default_value();
            std::transform(value.begin(), value.end(), value.begin(),
                    [](unsigned char c)
                    {
                        return static_cast<char>(std::tolower(c));
                    });
            apv.boolean_value(value.compare("0") != 0 || value.compare(CONST_TRUE) == 0);
        }
        break;
        case TypeKind::TK_BYTE:
        {
            apv.byte_value(static_cast<uint8_t>(std::stoul(member.get_default_value())));
        }
        break;
        case TypeKind::TK_INT16:
        {
            apv.int16_value(static_cast<int16_t>(std::stoi(member.get_default_value())));
        }
        break;
        case TypeKind::TK_INT32:
        {
            apv.int32_value(static_cast<int32_t>(std::stoi(member.get_default_value())));
        }
        break;
        case TypeKind::TK_INT64:
        {
            apv.int64_value(static_cast<int64_t>(std::stoll(member.get_default_value())));
        }
        break;
        case TypeKind::TK_UINT16:
        {
            apv.uint_16_value(static_cast<uint16_t>(std::stoul(member.get_default_value())));
        }
        break;
        case TypeKind::TK_UINT32:
        {
            apv.uint32_value(static_cast<uint32_t>(std::stoul(member.get_default_value())));
        }
        break;
        case TypeKind::TK_UINT64:
        {
            apv.uint64_value(static_cast<uint64_t>(std::stoull(member.get_default_value())));
        }
        break;
        case TypeKind::TK_FLOAT32:
        {
            apv.float32_value(std::stof(member.get_default_value()));
        }
        break;
        case TypeKind::TK_FLOAT64:
        {
            apv.float64_value(std::stod(member.get_default_value()));
        }
        break;
        case TypeKind::TK_FLOAT128:
        {
            apv.float128_value(std::stold(member.get_default_value()));
        }
        break;
        case TypeKind::TK_CHAR8:
        {
            apv.char_value(member.get_default_value().c_str()[0]);
        }
        break;
        case TypeKind::TK_CHAR16:
        {
            apv.wchar_value(wstring_from_bytes(member.get_default_value()).c_str()[0]);
        }
        break;
        case TypeKind::TK_STRING8:
        {
            apv.string8_value(member.get_default_value());
        }
        break;
        case TypeKind::TK_STRING16:
        {
            apv.string16_value(wstring_from_bytes(member.get_default_value()));
        }
        break;
        case TypeKind::TK_ENUM:
        {
            // TODO Translate from enum value name to integer value
            apv.enumerated_value(static_cast<int32_t>(std::stoul(member.get_default_value())));
        }
        break;
        default:
            break;
    }
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_alias_type(
        const DynamicTypeImpl& base_type,
        const std::string& sName)
{
    auto builder  = create_alias_type(base_type, sName);
    std::shared_ptr<const DynamicTypeImpl> ret;

    if (builder)
    {
        ret = builder->build();
    }

    return ret;
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_int32_type()
{
    return create_int32_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_uint32_type()
{
    return create_uint32_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_int16_type()
{
    return create_int16_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_uint16_type()
{
    return create_uint16_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_int64_type()
{
    return create_int64_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_uint64_type()
{
    return create_uint64_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_float32_type()
{
    return create_float32_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_float64_type()
{
    return create_float64_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_float128_type()
{
    return create_float128_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_char8_type()
{
    return create_char8_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_char16_type()
{
    return create_char16_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_bool_type()
{
    return create_bool_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_byte_type()
{
    return create_byte_type()->build();
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_string_type(
        uint32_t bound /* = LENGTH_UNLIMITED */) noexcept
{
    std::shared_ptr<const DynamicTypeImpl> ret;
    auto builder = bound == LENGTH_UNLIMITED ?
                   create_string_type() : create_string_type(bound);

    if (builder)
    {
        ret = builder->build();
    }

    return ret;
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_wstring_type(
        uint32_t bound /* = LENGTH_UNLIMITED */) noexcept
{
    std::shared_ptr<const DynamicTypeImpl> ret;
    auto builder = bound == LENGTH_UNLIMITED ?
                   create_wstring_type() : create_wstring_type(bound);

    if (builder)
    {
        ret = builder->build();
    }

    return ret;
}

std::shared_ptr<const DynamicTypeImpl> DynamicTypeBuilderFactoryImpl::get_bitset_type(
        uint32_t bound)
{
    std::shared_ptr<const DynamicTypeImpl> ret;
    auto builder = create_bitset_type(bound);

    if (builder)
    {
        ret = builder->build();
    }

    return ret;
}

void DynamicTypeBuilderFactoryImpl::apply_type_annotations(
        AppliedAnnotationSeq& annotations,
        const TypeState& descriptor) const
{
    for (const AnnotationDescriptorImpl& annotation : descriptor.get_all_annotations())
    {
        AppliedAnnotation ann;
        ann.annotation_typeid(
            *TypeObjectFactory::get_instance()->get_type_identifier_trying_complete(annotation.type()->get_name()));
        std::map<std::string, std::string> values;
        annotation.get_all_value(values);
        for (auto it : values)
        {
            AppliedAnnotationParameter ann_param;
            MD5 message_hash(it.first);
            for (int i = 0; i < 4; ++i)
            {
                ann_param.paramname_hash()[i] = message_hash.digest[i];
            }
            AnnotationParameterValue param_value;
            param_value._d(annotation.type()->get_kind());
            param_value.from_string(it.second);
            ann_param.value(param_value);
            ann.param_seq().push_back(ann_param);
        }
        annotations.push_back(ann);
    }
}

const int DynamicTypeBuilderFactoryImpl::indentation_index = std::ios_base::xalloc();
const int DynamicTypeBuilderFactoryImpl::object_index = std::ios_base::xalloc();

using namespace eprosima::fastrtps::types::typekind_detail;

#define XTYPENAME(type)                                                                            \
    const char* TypeKindName<TypeKind::type, char, std::char_traits<char>>::name = #type;              \
    const wchar_t* TypeKindName<TypeKind::type, wchar_t, std::char_traits<wchar_t>>::name = L"" #type; \

XTYPENAME(TK_BOOLEAN)
XTYPENAME(TK_BYTE)
XTYPENAME(TK_INT16)
XTYPENAME(TK_INT32)
XTYPENAME(TK_INT64)
XTYPENAME(TK_UINT16)
XTYPENAME(TK_UINT32)
XTYPENAME(TK_UINT64)
XTYPENAME(TK_FLOAT32)
XTYPENAME(TK_FLOAT64)
XTYPENAME(TK_FLOAT128)
XTYPENAME(TK_CHAR8)
XTYPENAME(TK_CHAR16)
XTYPENAME(TK_STRING8)
XTYPENAME(TK_STRING16)
XTYPENAME(TK_ALIAS)
XTYPENAME(TK_ENUM)
XTYPENAME(TK_BITMASK)
XTYPENAME(TK_ANNOTATION)
XTYPENAME(TK_STRUCTURE)
XTYPENAME(TK_UNION)
XTYPENAME(TK_BITSET)
XTYPENAME(TK_SEQUENCE)
XTYPENAME(TK_ARRAY)
XTYPENAME(TK_MAP)
XTYPENAME(TI_STRING8_SMALL)
XTYPENAME(TI_STRING8_LARGE)
XTYPENAME(TI_STRING16_SMALL)
XTYPENAME(TI_STRING16_LARGE)
XTYPENAME(TI_PLAIN_SEQUENCE_SMALL)
XTYPENAME(TI_PLAIN_SEQUENCE_LARGE)
XTYPENAME(TI_PLAIN_ARRAY_SMALL)
XTYPENAME(TI_PLAIN_ARRAY_LARGE)
XTYPENAME(TI_PLAIN_MAP_SMALL)
XTYPENAME(TI_PLAIN_MAP_LARGE)
XTYPENAME(TI_STRONGLY_CONNECTED_COMPONENT)

#undef XTYPENAME