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
 * @file Data1mb.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "Data1mb.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>


Data1mb::Data1mb()
{

}

Data1mb::~Data1mb()
{
}

Data1mb::Data1mb(
        const Data1mb& x)
{
    m_data = x.m_data;
}

Data1mb::Data1mb(
        Data1mb&& x) noexcept 
{
    m_data = std::move(x.m_data);
}

Data1mb& Data1mb::operator =(
        const Data1mb& x)
{

    m_data = x.m_data;

    return *this;
}

Data1mb& Data1mb::operator =(
        Data1mb&& x) noexcept
{

    m_data = std::move(x.m_data);

    return *this;
}

bool Data1mb::operator ==(
        const Data1mb& x) const
{

    return (m_data == x.m_data);
}

bool Data1mb::operator !=(
        const Data1mb& x) const
{
    return !(*this == x);
}

/*!
 * @brief This function copies the value in member data
 * @param _data New value to be copied in member data
 */
void Data1mb::data(
        const std::vector<uint8_t>& _data)
{
    m_data = _data;
}

/*!
 * @brief This function moves the value in member data
 * @param _data New value to be moved in member data
 */
void Data1mb::data(
        std::vector<uint8_t>&& _data)
{
    m_data = std::move(_data);
}

/*!
 * @brief This function returns a constant reference to member data
 * @return Constant reference to member data
 */
const std::vector<uint8_t>& Data1mb::data() const
{
    return m_data;
}

/*!
 * @brief This function returns a reference to member data
 * @return Reference to member data
 */
std::vector<uint8_t>& Data1mb::data()
{
    return m_data;
}

