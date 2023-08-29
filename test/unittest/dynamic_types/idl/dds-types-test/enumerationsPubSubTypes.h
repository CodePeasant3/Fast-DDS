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
 * @file enumerationsPubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _FAST_DDS_GENERATED_ENUMERATIONS_PUBSUBTYPES_H_
#define _FAST_DDS_GENERATED_ENUMERATIONS_PUBSUBTYPES_H_

#include <fastdds/dds/topic/TopicDataType.hpp>
#include <fastrtps/utils/md5.h>

#include "enumerations.h"

#include "helpers/basic_inner_typesPubSubTypes.h"

#if !defined(GEN_API_VER) || (GEN_API_VER != 1)
#error \
    Generated enumerations is not compatible with current installed Fast DDS. Please, regenerate it with fastddsgen.
#endif  // GEN_API_VER

typedef int32_t InnerAliasHelper;
typedef eprosima::fastrtps::fixed_string<10> Inner_alias_bounded_string_helper;
typedef std::wstring Inner_alias_bounded_wstring_helper;
typedef std::array<int16_t, 2> Inner_alias_array_helper;
typedef std::vector<int16_t> Inner_alias_sequence_helper;
typedef std::map<int32_t, int32_t> Inner_alias_map_helper;

/*!
 * @brief This class represents the TopicDataType of the type EnumStructure defined by the user in the IDL file.
 * @ingroup enumerations
 */
class EnumStructurePubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef EnumStructure type;

    eProsima_user_DllExport EnumStructurePubSubType();

    eProsima_user_DllExport virtual ~EnumStructurePubSubType() override;

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data) override;

    eProsima_user_DllExport virtual bool getKey(
            void* data,
            eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
            bool force_md5 = false) override;

    eProsima_user_DllExport virtual void* createData() override;

    eProsima_user_DllExport virtual void deleteData(
            void* data) override;

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
    eProsima_user_DllExport inline bool is_bounded() const override
    {
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
    eProsima_user_DllExport inline bool is_plain() const override
    {
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

#ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
    eProsima_user_DllExport inline bool construct_sample(
            void* memory) const override
    {
        (void)memory;
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

    MD5 m_md5;
    unsigned char* m_keyBuffer;

};

#ifndef SWIG
namespace detail {

    template<typename Tag, typename Tag::type M>
    struct BitMaskStructure_rob
    {
        friend constexpr typename Tag::type get(
                Tag)
        {
            return M;
        }
    };

    struct BitMaskStructure_f
    {
        typedef InnerBitMaskHelper BitMaskStructure::* type;
        friend constexpr type get(
                BitMaskStructure_f);
    };

    template struct BitMaskStructure_rob<BitMaskStructure_f, &BitMaskStructure::m_var_InnerBitMaskHelper>;

    template <typename T, typename Tag>
    inline size_t constexpr BitMaskStructure_offset_of() {
        return ((::size_t) &reinterpret_cast<char const volatile&>((((T*)0)->*get(Tag()))));
    }
}
#endif

/*!
 * @brief This class represents the TopicDataType of the type BitMaskStructure defined by the user in the IDL file.
 * @ingroup enumerations
 */
class BitMaskStructurePubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef BitMaskStructure type;

    eProsima_user_DllExport BitMaskStructurePubSubType();

    eProsima_user_DllExport virtual ~BitMaskStructurePubSubType() override;

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data) override;

    eProsima_user_DllExport virtual bool getKey(
            void* data,
            eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
            bool force_md5 = false) override;

    eProsima_user_DllExport virtual void* createData() override;

    eProsima_user_DllExport virtual void deleteData(
            void* data) override;

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
    eProsima_user_DllExport inline bool is_bounded() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
    eProsima_user_DllExport inline bool is_plain() const override
    {
        return is_plain_impl();
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

#ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
    eProsima_user_DllExport inline bool construct_sample(
            void* memory) const override
    {
        new (memory) BitMaskStructure();
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

    MD5 m_md5;
    unsigned char* m_keyBuffer;

private:

    static constexpr bool is_plain_impl()
    {
        return 4ULL == (detail::BitMaskStructure_offset_of<BitMaskStructure, detail::BitMaskStructure_f>() + sizeof(InnerBitMaskHelper));

    }};

#endif // _FAST_DDS_GENERATED_ENUMERATIONS_PUBSUBTYPES_H_

