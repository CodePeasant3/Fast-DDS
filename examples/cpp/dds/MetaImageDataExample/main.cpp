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

/**
 * @file main.cpp
 *
 */

#include <cstdlib>
#include <cstring>

#include <iostream>

#include <fastrtps/Domain.h>
#include <fastrtps/log/Log.h>

#include "ImageDataPublisher.h"
#include "ImageDataSubscriber.h"

using namespace eprosima;
using namespace fastrtps;
using namespace rtps;

int main(
        int argc,
        char** argv)
{
    std::cout << "Starting " << std::endl;
    int type = 1;
    uint16_t pub_frequency = 10;
    if (argc > 1)
    {
        uint8_t argc_idx = 1;
        if (strcmp(argv[argc_idx], "publisher") == 0)
        {
            type = 1;
            argc_idx++;
            if (argc > 2)
            {
                pub_frequency = static_cast<uint16_t>(atoi(argv[argc_idx]));
            }
        }
        else if (strcmp(argv[argc_idx], "subscriber") == 0)
        {
            type = 2;
        }

    }
    else
    {
        std::cout << "publisher OR subscriber argument needed" << std::endl;
        Log::Reset();
        return 0;
    }

    switch (type)
    {
        case 1:
        {
            ImageDataPublisher mypub;
            if (mypub.init())
            {
                mypub.run(pub_frequency);
            }
            break;
        }
        case 2:
        {
            ImageDataSubscriber mysub;
            if (mysub.init())
            {
                mysub.run();
            }
            break;
        }
    }
    Log::Reset();
    return 0;
}