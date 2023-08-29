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
 * @file declarationsPubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

#include "declarationsPubSubTypes.h"

using SerializedPayload_t = eprosima::fastrtps::rtps::SerializedPayload_t;
using InstanceHandle_t = eprosima::fastrtps::rtps::InstanceHandle_t;

class ForwardStruct;

class ForwardUnion;





ForwardDeclarationsStructPubSubType::ForwardDeclarationsStructPubSubType()
{
    setName("ForwardDeclarationsStruct");
    auto type_size = ForwardDeclarationsStruct::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = ForwardDeclarationsStruct::isKeyDefined();
    size_t keyLength = ForwardDeclarationsStruct::getKeyMaxCdrSerializedSize() > 16 ?
            ForwardDeclarationsStruct::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

ForwardDeclarationsStructPubSubType::~ForwardDeclarationsStructPubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool ForwardDeclarationsStructPubSubType::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    ForwardDeclarationsStruct* p_type = static_cast<ForwardDeclarationsStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        // Serialize encapsulation
        ser.serialize_encapsulation();
        // Serialize the object.
        p_type->serialize(ser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    return true;
}

bool ForwardDeclarationsStructPubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    try
    {
        // Convert DATA to pointer of your type
        ForwardDeclarationsStruct* p_type = static_cast<ForwardDeclarationsStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        p_type->deserialize(deser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> ForwardDeclarationsStructPubSubType::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ForwardDeclarationsStruct*>(data))) +
                      4u /*encapsulation*/;
           };
}

void* ForwardDeclarationsStructPubSubType::createData()
{
    return reinterpret_cast<void*>(new ForwardDeclarationsStruct());
}

void ForwardDeclarationsStructPubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<ForwardDeclarationsStruct*>(data));
}

bool ForwardDeclarationsStructPubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    ForwardDeclarationsStruct* p_type = static_cast<ForwardDeclarationsStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            ForwardDeclarationsStruct::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || ForwardDeclarationsStruct::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

ForwardDeclarationsRecursiveStructPubSubType::ForwardDeclarationsRecursiveStructPubSubType()
{
    setName("ForwardDeclarationsRecursiveStruct");
    auto type_size = ForwardDeclarationsRecursiveStruct::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = ForwardDeclarationsRecursiveStruct::isKeyDefined();
    size_t keyLength = ForwardDeclarationsRecursiveStruct::getKeyMaxCdrSerializedSize() > 16 ?
            ForwardDeclarationsRecursiveStruct::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

ForwardDeclarationsRecursiveStructPubSubType::~ForwardDeclarationsRecursiveStructPubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool ForwardDeclarationsRecursiveStructPubSubType::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    ForwardDeclarationsRecursiveStruct* p_type = static_cast<ForwardDeclarationsRecursiveStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        // Serialize encapsulation
        ser.serialize_encapsulation();
        // Serialize the object.
        p_type->serialize(ser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    return true;
}

bool ForwardDeclarationsRecursiveStructPubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    try
    {
        // Convert DATA to pointer of your type
        ForwardDeclarationsRecursiveStruct* p_type = static_cast<ForwardDeclarationsRecursiveStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        p_type->deserialize(deser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> ForwardDeclarationsRecursiveStructPubSubType::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ForwardDeclarationsRecursiveStruct*>(data))) +
                      4u /*encapsulation*/;
           };
}

void* ForwardDeclarationsRecursiveStructPubSubType::createData()
{
    return reinterpret_cast<void*>(new ForwardDeclarationsRecursiveStruct());
}

void ForwardDeclarationsRecursiveStructPubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<ForwardDeclarationsRecursiveStruct*>(data));
}

bool ForwardDeclarationsRecursiveStructPubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    ForwardDeclarationsRecursiveStruct* p_type = static_cast<ForwardDeclarationsRecursiveStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            ForwardDeclarationsRecursiveStruct::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || ForwardDeclarationsRecursiveStruct::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}


ForwardStructPubSubType::ForwardStructPubSubType()
{
    setName("ForwardStruct");
    auto type_size = ForwardStruct::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = ForwardStruct::isKeyDefined();
    size_t keyLength = ForwardStruct::getKeyMaxCdrSerializedSize() > 16 ?
            ForwardStruct::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

ForwardStructPubSubType::~ForwardStructPubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool ForwardStructPubSubType::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    ForwardStruct* p_type = static_cast<ForwardStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        // Serialize encapsulation
        ser.serialize_encapsulation();
        // Serialize the object.
        p_type->serialize(ser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    return true;
}

bool ForwardStructPubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    try
    {
        // Convert DATA to pointer of your type
        ForwardStruct* p_type = static_cast<ForwardStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        p_type->deserialize(deser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> ForwardStructPubSubType::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ForwardStruct*>(data))) +
                      4u /*encapsulation*/;
           };
}

void* ForwardStructPubSubType::createData()
{
    return reinterpret_cast<void*>(new ForwardStruct());
}

void ForwardStructPubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<ForwardStruct*>(data));
}

bool ForwardStructPubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    ForwardStruct* p_type = static_cast<ForwardStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            ForwardStruct::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || ForwardStruct::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

namespace declarations_module {
    class ModuledForwardStruct;

    class ModuledForwardUnion;






} //End of namespace declarations_module

ModuledForwardDeclarationsStructPubSubType::ModuledForwardDeclarationsStructPubSubType()
{
    setName("ModuledForwardDeclarationsStruct");
    auto type_size = ModuledForwardDeclarationsStruct::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = ModuledForwardDeclarationsStruct::isKeyDefined();
    size_t keyLength = ModuledForwardDeclarationsStruct::getKeyMaxCdrSerializedSize() > 16 ?
            ModuledForwardDeclarationsStruct::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

ModuledForwardDeclarationsStructPubSubType::~ModuledForwardDeclarationsStructPubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool ModuledForwardDeclarationsStructPubSubType::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    ModuledForwardDeclarationsStruct* p_type = static_cast<ModuledForwardDeclarationsStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        // Serialize encapsulation
        ser.serialize_encapsulation();
        // Serialize the object.
        p_type->serialize(ser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    return true;
}

bool ModuledForwardDeclarationsStructPubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    try
    {
        // Convert DATA to pointer of your type
        ModuledForwardDeclarationsStruct* p_type = static_cast<ModuledForwardDeclarationsStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        p_type->deserialize(deser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> ModuledForwardDeclarationsStructPubSubType::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ModuledForwardDeclarationsStruct*>(data))) +
                      4u /*encapsulation*/;
           };
}

void* ModuledForwardDeclarationsStructPubSubType::createData()
{
    return reinterpret_cast<void*>(new ModuledForwardDeclarationsStruct());
}

void ModuledForwardDeclarationsStructPubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<ModuledForwardDeclarationsStruct*>(data));
}

bool ModuledForwardDeclarationsStructPubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    ModuledForwardDeclarationsStruct* p_type = static_cast<ModuledForwardDeclarationsStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            ModuledForwardDeclarationsStruct::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || ModuledForwardDeclarationsStruct::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

ModuledForwardDeclarationsRecursiveStructPubSubType::ModuledForwardDeclarationsRecursiveStructPubSubType()
{
    setName("ModuledForwardDeclarationsRecursiveStruct");
    auto type_size = ModuledForwardDeclarationsRecursiveStruct::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = ModuledForwardDeclarationsRecursiveStruct::isKeyDefined();
    size_t keyLength = ModuledForwardDeclarationsRecursiveStruct::getKeyMaxCdrSerializedSize() > 16 ?
            ModuledForwardDeclarationsRecursiveStruct::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

ModuledForwardDeclarationsRecursiveStructPubSubType::~ModuledForwardDeclarationsRecursiveStructPubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool ModuledForwardDeclarationsRecursiveStructPubSubType::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    ModuledForwardDeclarationsRecursiveStruct* p_type = static_cast<ModuledForwardDeclarationsRecursiveStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        // Serialize encapsulation
        ser.serialize_encapsulation();
        // Serialize the object.
        p_type->serialize(ser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    return true;
}

bool ModuledForwardDeclarationsRecursiveStructPubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    try
    {
        // Convert DATA to pointer of your type
        ModuledForwardDeclarationsRecursiveStruct* p_type = static_cast<ModuledForwardDeclarationsRecursiveStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        p_type->deserialize(deser);
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> ModuledForwardDeclarationsRecursiveStructPubSubType::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ModuledForwardDeclarationsRecursiveStruct*>(data))) +
                      4u /*encapsulation*/;
           };
}

void* ModuledForwardDeclarationsRecursiveStructPubSubType::createData()
{
    return reinterpret_cast<void*>(new ModuledForwardDeclarationsRecursiveStruct());
}

void ModuledForwardDeclarationsRecursiveStructPubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<ModuledForwardDeclarationsRecursiveStruct*>(data));
}

bool ModuledForwardDeclarationsRecursiveStructPubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    ModuledForwardDeclarationsRecursiveStruct* p_type = static_cast<ModuledForwardDeclarationsRecursiveStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            ModuledForwardDeclarationsRecursiveStruct::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || ModuledForwardDeclarationsRecursiveStruct::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

namespace declarations_module {
    ModuledForwardStructPubSubType::ModuledForwardStructPubSubType()
    {
        setName("declarations_module::ModuledForwardStruct");
        auto type_size = ModuledForwardStruct::getMaxCdrSerializedSize();
        type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
        m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
        m_isGetKeyDefined = ModuledForwardStruct::isKeyDefined();
        size_t keyLength = ModuledForwardStruct::getKeyMaxCdrSerializedSize() > 16 ?
                ModuledForwardStruct::getKeyMaxCdrSerializedSize() : 16;
        m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
        memset(m_keyBuffer, 0, keyLength);
    }

    ModuledForwardStructPubSubType::~ModuledForwardStructPubSubType()
    {
        if (m_keyBuffer != nullptr)
        {
            free(m_keyBuffer);
        }
    }

    bool ModuledForwardStructPubSubType::serialize(
            void* data,
            SerializedPayload_t* payload)
    {
        ModuledForwardStruct* p_type = static_cast<ModuledForwardStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
        // Object that serializes the data.
        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
        payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        try
        {
            // Serialize encapsulation
            ser.serialize_encapsulation();
            // Serialize the object.
            p_type->serialize(ser);
        }
        catch (eprosima::fastcdr::exception::Exception& /*exception*/)
        {
            return false;
        }

        // Get the serialized length
        payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
        return true;
    }

    bool ModuledForwardStructPubSubType::deserialize(
            SerializedPayload_t* payload,
            void* data)
    {
        try
        {
            // Convert DATA to pointer of your type
            ModuledForwardStruct* p_type = static_cast<ModuledForwardStruct*>(data);

            // Object that manages the raw buffer.
            eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

            // Object that deserializes the data.
            eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

            // Deserialize encapsulation.
            deser.read_encapsulation();
            payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

            // Deserialize the object.
            p_type->deserialize(deser);
        }
        catch (eprosima::fastcdr::exception::Exception& /*exception*/)
        {
            return false;
        }

        return true;
    }

    std::function<uint32_t()> ModuledForwardStructPubSubType::getSerializedSizeProvider(
            void* data)
    {
        return [data]() -> uint32_t
               {
                   return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ModuledForwardStruct*>(data))) +
                          4u /*encapsulation*/;
               };
    }

    void* ModuledForwardStructPubSubType::createData()
    {
        return reinterpret_cast<void*>(new ModuledForwardStruct());
    }

    void ModuledForwardStructPubSubType::deleteData(
            void* data)
    {
        delete(reinterpret_cast<ModuledForwardStruct*>(data));
    }

    bool ModuledForwardStructPubSubType::getKey(
            void* data,
            InstanceHandle_t* handle,
            bool force_md5)
    {
        if (!m_isGetKeyDefined)
        {
            return false;
        }

        ModuledForwardStruct* p_type = static_cast<ModuledForwardStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                ModuledForwardStruct::getKeyMaxCdrSerializedSize());

        // Object that serializes the data.
        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
        p_type->serializeKey(ser);
        if (force_md5 || ModuledForwardStruct::getKeyMaxCdrSerializedSize() > 16)
        {
            m_md5.init();
            m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
            m_md5.finalize();
            for (uint8_t i = 0; i < 16; ++i)
            {
                handle->value[i] = m_md5.digest[i];
            }
        }
        else
        {
            for (uint8_t i = 0; i < 16; ++i)
            {
                handle->value[i] = m_keyBuffer[i];
            }
        }
        return true;
    }



} //End of namespace declarations_module

