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
 * @file monitorservice_typesTypeObjectSupport.hpp
 * Header file containing the API required to register the TypeObject representation of the described types in the IDL file
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_STATISTICS_MONITORSERVICE_TYPES_TYPE_OBJECT_SUPPORT_HPP_
#define _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_STATISTICS_MONITORSERVICE_TYPES_TYPE_OBJECT_SUPPORT_HPP_

#include "typesTypeObjectSupport.hpp"

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

/**
 * @brief Register every TypeObject representation defined in the IDL file in Fast DDS TypeObjectRegistry.
 */
eProsima_user_DllExport void register_monitorservice_types_type_objects();

#ifndef DOXYGEN_SHOULD_SKIP_THIS_PUBLIC

namespace eprosima {
namespace fastdds {
namespace statistics {
/**
 * @brief Register eprosima_fastdds_statistics_Connection related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_eprosima_fastdds_statistics_Connection_type_identifier();

/**
 * @brief Register eprosima_fastdds_statistics_QosPolicyCount_s related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_eprosima_fastdds_statistics_QosPolicyCount_s_type_identifier();

/**
 * @brief Register eprosima_fastdds_statistics_BaseStatus_s related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_eprosima_fastdds_statistics_BaseStatus_s_type_identifier();


/**
 * @brief Register eprosima_fastdds_statistics_IncompatibleQoSStatus_s related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_eprosima_fastdds_statistics_IncompatibleQoSStatus_s_type_identifier();

/**
 * @brief Register eprosima_fastdds_statistics_LivelinessChangedStatus_s related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_eprosima_fastdds_statistics_LivelinessChangedStatus_s_type_identifier();

/**
 * @brief Register eprosima_fastdds_statistics_DeadlineMissedStatus_s related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_eprosima_fastdds_statistics_DeadlineMissedStatus_s_type_identifier();




namespace StatusKind {
} // namespace StatusKind

/**
 * @brief Register eprosima_fastdds_statistics_MonitorServiceData related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_eprosima_fastdds_statistics_MonitorServiceData_type_identifier();

/**
 * @brief Register eprosima_fastdds_statistics_MonitorServiceStatusData related TypeIdentifier.
 *        Fully-descriptive TypeIdentifiers are directly registered.
 *        Hash TypeIdentifiers require to fill the TypeObject information and hash it, consequently, the TypeObject is
 *        indirectly registered as well.
 */
eProsima_user_DllExport void register_eprosima_fastdds_statistics_MonitorServiceStatusData_type_identifier();

} // namespace statistics

} // namespace fastdds

} // namespace eprosima


#endif // DOXYGEN_SHOULD_SKIP_THIS_PUBLIC

#endif // _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_STATISTICS_MONITORSERVICE_TYPES_TYPE_OBJECT_SUPPORT_HPP_
