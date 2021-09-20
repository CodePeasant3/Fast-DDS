// Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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
 * @file HelloWorldPublisher.h
 *
 */

#ifndef _EPROSIMA_FASTDDS_EXAMPLES_CPP_DDS_HELLOWORLDEXAMPLEDISCOVERYSERVER_HELLOWORLDPUBLISHER_H_
#define _EPROSIMA_FASTDDS_EXAMPLES_CPP_DDS_HELLOWORLDEXAMPLEDISCOVERYSERVER_HELLOWORLDPUBLISHER_H_

#include <atomic>
#include <condition_variable>
#include <mutex>

#include "HelloWorldPubSubTypes.h"
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>

class HelloWorldPublisher
{
public:

    HelloWorldPublisher();

    virtual ~HelloWorldPublisher();

    //!Initialize
    bool init(
            const std::string& topic_name,
            uint32_t num_wait_matched,
            eprosima::fastdds::rtps::Locator server_address);

    //!Publish a sample
    void publish();

    //!Run for number samples
    void run(
            uint32_t number,
            uint32_t sleep);

    static bool is_stopped();

    static void stop();

private:

    HelloWorld hello_;

    eprosima::fastdds::dds::DomainParticipant* participant_;

    eprosima::fastdds::dds::Publisher* publisher_;

    eprosima::fastdds::dds::Topic* topic_;

    eprosima::fastdds::dds::DataWriter* writer_;

    eprosima::fastdds::dds::TypeSupport type_;

    class PubListener : public eprosima::fastdds::dds::DataWriterListener
    {
    public:

        PubListener()
            : matched_(0)
            , num_wait_matched_(0)
        {
        }

        ~PubListener() override
        {
        }

        void on_publication_matched(
                eprosima::fastdds::dds::DataWriter* writer,
                const eprosima::fastdds::dds::PublicationMatchedStatus& info) override;

        void set_num_wait_matched(
                uint32_t num_wait_matched);

        bool enough_matched();

        void wait();

        static void awake();

    private:

        std::atomic<std::uint32_t> matched_;

        uint32_t num_wait_matched_;

        static std::mutex wait_matched_cv_mtx_;

        static std::condition_variable wait_matched_cv_;
    }
    listener_;

    void runThread(
            uint32_t number,
            uint32_t sleep);

    static std::atomic<bool> stop_;
};



#endif /* _EPROSIMA_FASTDDS_EXAMPLES_CPP_DDS_HELLOWORLDEXAMPLEDISCOVERYSERVER_HELLOWORLDPUBLISHER_H_ */
