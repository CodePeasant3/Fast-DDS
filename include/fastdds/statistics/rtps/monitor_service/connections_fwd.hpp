// Copyright 2024 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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
 * @file connection_fwd.hpp
 *
 */

#ifndef _FASTDDS_STATISTICS_MONITOR_SERVICE_CONNECTION_FWD_HPP_
#define _FASTDDS_STATISTICS_MONITOR_SERVICE_CONNECTION_FWD_HPP_

namespace eprosima {
namespace fastdds {
namespace statistics {

class Connection;

namespace rtps {

using ConnectionList = std::vector<eprosima::fastdds::statistics::Connection>;

} // rtps
} // statistics
} // fastdds
} // eprosima

#endif // _FASTDDS_STATISTICS_MONITOR_SERVICE_CONNECTION_FWD_HPP_
