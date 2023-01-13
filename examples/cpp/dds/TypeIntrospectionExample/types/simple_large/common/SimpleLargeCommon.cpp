// Copyright 2022 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/**
 * @file ComplexCode.h
 *
 */

#include <fastrtps/types/DynamicDataPtr.h>
#include <fastrtps/types/DynamicDataFactory.h>
#include <fastrtps/types/DynamicTypeBuilderFactory.h>
#include <fastrtps/types/DynamicTypeBuilderPtr.h>

#include "../../types.hpp"

using namespace eprosima::fastrtps;

template <>
eprosima::fastrtps::types::DynamicData_ptr get_data_by_type<DataTypeKind::SIMPLELARGE>(
        const unsigned int& index,
        eprosima::fastrtps::types::DynamicType_ptr dyn_type)
{
    // Create and initialize new data
    eprosima::fastrtps::types::DynamicData_ptr new_data;
    new_data = eprosima::fastrtps::types::DynamicDataFactory::get_instance()->create_data(dyn_type);

    // Set index
    new_data->set_uint32_value(index, 0);
    // Set message
    new_data->set_string_value("Hello World", 1);
    // Set second_message
    new_data->set_string_value(std::to_string(index), 3);
    // Set is_it_not_true_that_true_is_not_true
    new_data->set_bool_value((index % 2 == 0), 5);

    // Set points (it requires to loan the simple)
    eprosima::fastrtps::types::DynamicData* simple = new_data->loan_value(2);

    simple->set_int32_value(index + 1, 0);
    simple->set_int32_value(index * 0.5, 1);
    simple->set_int32_value(index * -1, 2);

    new_data->return_loaned_value(simple);

    // Set points (it requires to loan the Sequence)
    eprosima::fastrtps::types::DynamicData* sequence = new_data->loan_value(4);

    eprosima::fastrtps::types::MemberId id0, id1, id2;
    sequence->insert_int16_value(index + 1, id0);
    sequence->insert_int16_value(index * 0.5, id1);
    sequence->insert_int16_value(index * -1, id2);

    new_data->return_loaned_value(sequence);

    // Return data
    return new_data;
}
