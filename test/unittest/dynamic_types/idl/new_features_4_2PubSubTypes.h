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
 * @file new_features_4_2PubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _FAST_DDS_GENERATED_NEW_FEATURES_4_2_PUBSUBTYPES_H_
#define _FAST_DDS_GENERATED_NEW_FEATURES_4_2_PUBSUBTYPES_H_

#include <fastdds/dds/topic/TopicDataType.hpp>
#include <fastrtps/utils/md5.h>

#include "new_features_4_2.h"


#if !defined(GEN_API_VER) || (GEN_API_VER != 1)
#error \
    Generated new_features_4_2 is not compatible with current installed Fast DDS. Please, regenerate it with fastddsgen.
#endif  // GEN_API_VER


/*!
 * @brief This class represents the TopicDataType of the type NewAliases defined by the user in the IDL file.
 * @ingroup new_features_4_2
 */
class NewAliasesPubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef NewAliases type;

    eProsima_user_DllExport NewAliasesPubSubType();

    eProsima_user_DllExport virtual ~NewAliasesPubSubType() override;

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data,
            eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data,
            eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

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



namespace bitmodule
{




    #ifndef SWIG
    namespace detail {

        template<typename Tag, typename Tag::type M>
        struct BitsetBitmask_rob
        {
            friend constexpr typename Tag::type get(
                    Tag)
            {
                return M;
            }
        };

        struct BitsetBitmask_f
        {
            typedef bitmodule::MyBitMask BitsetBitmask::* type;
            friend constexpr type get(
                    BitsetBitmask_f);
        };

        template struct BitsetBitmask_rob<BitsetBitmask_f, &BitsetBitmask::m_mybitmask>;

        template <typename T, typename Tag>
        inline size_t constexpr BitsetBitmask_offset_of() {
            return ((::size_t) &reinterpret_cast<char const volatile&>((((T*)0)->*get(Tag()))));
        }
    }
    #endif

    /*!
     * @brief This class represents the TopicDataType of the type BitsetBitmask defined by the user in the IDL file.
     * @ingroup new_features_4_2
     */
    class BitsetBitmaskPubSubType : public eprosima::fastdds::dds::TopicDataType
    {
    public:

        typedef BitsetBitmask type;

        eProsima_user_DllExport BitsetBitmaskPubSubType();

        eProsima_user_DllExport virtual ~BitsetBitmaskPubSubType() override;

        eProsima_user_DllExport virtual bool serialize(
                void* data,
                eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

        eProsima_user_DllExport virtual bool deserialize(
                eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                void* data,
                eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

        eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
                void* data,
                eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

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
            new (memory) BitsetBitmask();
            return true;
        }

    #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

        MD5 m_md5;
        unsigned char* m_keyBuffer;

    private:

        static constexpr bool is_plain_impl()
        {
            return 21ULL == (detail::BitsetBitmask_offset_of<BitsetBitmask, detail::BitsetBitmask_f>() + sizeof(bitmodule::MyBitMask));

        }};

    #ifndef SWIG
    namespace detail {

        template<typename Tag, typename Tag::type M>
        struct BM2_rob
        {
            friend constexpr typename Tag::type get(
                    Tag)
            {
                return M;
            }
        };

        struct BM2_f
        {
            typedef int32_t BM2::* type;
            friend constexpr type get(
                    BM2_f);
        };

        template struct BM2_rob<BM2_f, &BM2::m_mylong>;

        template <typename T, typename Tag>
        inline size_t constexpr BM2_offset_of() {
            return ((::size_t) &reinterpret_cast<char const volatile&>((((T*)0)->*get(Tag()))));
        }
    }
    #endif

    /*!
     * @brief This class represents the TopicDataType of the type BM2 defined by the user in the IDL file.
     * @ingroup new_features_4_2
     */
    class BM2PubSubType : public eprosima::fastdds::dds::TopicDataType
    {
    public:

        typedef BM2 type;

        eProsima_user_DllExport BM2PubSubType();

        eProsima_user_DllExport virtual ~BM2PubSubType() override;

        eProsima_user_DllExport virtual bool serialize(
                void* data,
                eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

        eProsima_user_DllExport virtual bool deserialize(
                eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                void* data,
                eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

        eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
                void* data,
                eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

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
            new (memory) BM2();
            return true;
        }

    #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

        MD5 m_md5;
        unsigned char* m_keyBuffer;

    private:

        static constexpr bool is_plain_impl()
        {
            return 28ULL == (detail::BM2_offset_of<BM2, detail::BM2_f>() + sizeof(int32_t));

        }};
}

/*!
 * @brief This class represents the TopicDataType of the type StructTest defined by the user in the IDL file.
 * @ingroup new_features_4_2
 */
class StructTestPubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef StructTest type;

    eProsima_user_DllExport StructTestPubSubType();

    eProsima_user_DllExport virtual ~StructTestPubSubType() override;

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data,
            eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data,
            eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

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

#endif // _FAST_DDS_GENERATED_NEW_FEATURES_4_2_PUBSUBTYPES_H_