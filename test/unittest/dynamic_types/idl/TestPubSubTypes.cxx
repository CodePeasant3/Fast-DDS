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
 * @file TestPubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>

#include "TestPubSubTypes.h"

using SerializedPayload_t = eprosima::fastrtps::rtps::SerializedPayload_t;
using InstanceHandle_t = eprosima::fastrtps::rtps::InstanceHandle_t;
using DataRepresentationId_t = eprosima::fastdds::dds::DataRepresentationId_t;





BasicStructPubSubType::BasicStructPubSubType()
{
    setName("BasicStruct");
    auto type_size = BasicStruct::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = BasicStruct::isKeyDefined();
    size_t keyLength = BasicStruct::getKeyMaxCdrSerializedSize() > 16 ?
            BasicStruct::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

BasicStructPubSubType::~BasicStructPubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool BasicStructPubSubType::serialize(
        void* data,
        SerializedPayload_t* payload,
        DataRepresentationId_t data_representation)
{
    BasicStruct* p_type = static_cast<BasicStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 : eprosima::fastcdr::CdrVersion::XCDRv2);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    ser.set_encoding_flag(
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
 :
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
);

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

bool BasicStructPubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data,
        DataRepresentationId_t data_representation)
{
    try
    {
        // Convert DATA to pointer of your type
        BasicStruct* p_type = static_cast<BasicStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
                data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);

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

std::function<uint32_t()> BasicStructPubSubType::getSerializedSizeProvider(
        void* data,
        DataRepresentationId_t data_representation)
{
    return [data, data_representation]() -> uint32_t
           {
               eprosima::fastcdr::CdrSizeCalculator calculator(
                       data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);
               return static_cast<uint32_t>(type::calculate_serialized_size(calculator,
                           *static_cast<BasicStruct*>(data))) +
                            4u /*encapsulation*/;
           };
}

void* BasicStructPubSubType::createData()
{
    return reinterpret_cast<void*>(new BasicStruct());
}

void BasicStructPubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<BasicStruct*>(data));
}

bool BasicStructPubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    BasicStruct* p_type = static_cast<BasicStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            BasicStruct::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || BasicStruct::getKeyMaxCdrSerializedSize() > 16)
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






ComplexStructPubSubType::ComplexStructPubSubType()
{
    setName("ComplexStruct");
    auto type_size = ComplexStruct::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = ComplexStruct::isKeyDefined();
    size_t keyLength = ComplexStruct::getKeyMaxCdrSerializedSize() > 16 ?
            ComplexStruct::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

ComplexStructPubSubType::~ComplexStructPubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool ComplexStructPubSubType::serialize(
        void* data,
        SerializedPayload_t* payload,
        DataRepresentationId_t data_representation)
{
    ComplexStruct* p_type = static_cast<ComplexStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 : eprosima::fastcdr::CdrVersion::XCDRv2);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    ser.set_encoding_flag(
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
 :
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
);

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

bool ComplexStructPubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data,
        DataRepresentationId_t data_representation)
{
    try
    {
        // Convert DATA to pointer of your type
        ComplexStruct* p_type = static_cast<ComplexStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
                data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);

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

std::function<uint32_t()> ComplexStructPubSubType::getSerializedSizeProvider(
        void* data,
        DataRepresentationId_t data_representation)
{
    return [data, data_representation]() -> uint32_t
           {
               eprosima::fastcdr::CdrSizeCalculator calculator(
                       data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);
               return static_cast<uint32_t>(type::calculate_serialized_size(calculator,
                           *static_cast<ComplexStruct*>(data))) +
                            4u /*encapsulation*/;
           };
}

void* ComplexStructPubSubType::createData()
{
    return reinterpret_cast<void*>(new ComplexStruct());
}

void ComplexStructPubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<ComplexStruct*>(data));
}

bool ComplexStructPubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    ComplexStruct* p_type = static_cast<ComplexStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            ComplexStruct::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || ComplexStruct::getKeyMaxCdrSerializedSize() > 16)
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



CompleteStructPubSubType::CompleteStructPubSubType()
{
    setName("CompleteStruct");
    auto type_size = CompleteStruct::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = CompleteStruct::isKeyDefined();
    size_t keyLength = CompleteStruct::getKeyMaxCdrSerializedSize() > 16 ?
            CompleteStruct::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

CompleteStructPubSubType::~CompleteStructPubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool CompleteStructPubSubType::serialize(
        void* data,
        SerializedPayload_t* payload,
        DataRepresentationId_t data_representation)
{
    CompleteStruct* p_type = static_cast<CompleteStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 : eprosima::fastcdr::CdrVersion::XCDRv2);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    ser.set_encoding_flag(
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
 :
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
);

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

bool CompleteStructPubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data,
        DataRepresentationId_t data_representation)
{
    try
    {
        // Convert DATA to pointer of your type
        CompleteStruct* p_type = static_cast<CompleteStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
                data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);

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

std::function<uint32_t()> CompleteStructPubSubType::getSerializedSizeProvider(
        void* data,
        DataRepresentationId_t data_representation)
{
    return [data, data_representation]() -> uint32_t
           {
               eprosima::fastcdr::CdrSizeCalculator calculator(
                       data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);
               return static_cast<uint32_t>(type::calculate_serialized_size(calculator,
                           *static_cast<CompleteStruct*>(data))) +
                            4u /*encapsulation*/;
           };
}

void* CompleteStructPubSubType::createData()
{
    return reinterpret_cast<void*>(new CompleteStruct());
}

void CompleteStructPubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<CompleteStruct*>(data));
}

bool CompleteStructPubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    CompleteStruct* p_type = static_cast<CompleteStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            CompleteStruct::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || CompleteStruct::getKeyMaxCdrSerializedSize() > 16)
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

KeyedStructPubSubType::KeyedStructPubSubType()
{
    setName("KeyedStruct");
    auto type_size = KeyedStruct::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = KeyedStruct::isKeyDefined();
    size_t keyLength = KeyedStruct::getKeyMaxCdrSerializedSize() > 16 ?
            KeyedStruct::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

KeyedStructPubSubType::~KeyedStructPubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool KeyedStructPubSubType::serialize(
        void* data,
        SerializedPayload_t* payload,
        DataRepresentationId_t data_representation)
{
    KeyedStruct* p_type = static_cast<KeyedStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 : eprosima::fastcdr::CdrVersion::XCDRv2);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    ser.set_encoding_flag(
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
 :
eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
);

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

bool KeyedStructPubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data,
        DataRepresentationId_t data_representation)
{
    try
    {
        // Convert DATA to pointer of your type
        KeyedStruct* p_type = static_cast<KeyedStruct*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
                data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);

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

std::function<uint32_t()> KeyedStructPubSubType::getSerializedSizeProvider(
        void* data,
        DataRepresentationId_t data_representation)
{
    return [data, data_representation]() -> uint32_t
           {
               eprosima::fastcdr::CdrSizeCalculator calculator(
                       data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ? eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);
               return static_cast<uint32_t>(type::calculate_serialized_size(calculator,
                           *static_cast<KeyedStruct*>(data))) +
                            4u /*encapsulation*/;
           };
}

void* KeyedStructPubSubType::createData()
{
    return reinterpret_cast<void*>(new KeyedStruct());
}

void KeyedStructPubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<KeyedStruct*>(data));
}

bool KeyedStructPubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    KeyedStruct* p_type = static_cast<KeyedStruct*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            KeyedStruct::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || KeyedStruct::getKeyMaxCdrSerializedSize() > 16)
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

