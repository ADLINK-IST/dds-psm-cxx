#ifndef OMG_DDS_TOPIC_TOPIC_INSTANCE_HPP_
#define OMG_DDS_TOPIC_TOPIC_INSTANCE_HPP_

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <dds/core/Time.hpp>
#include <dds/core/InstanceHandle.hpp>

namespace dds { namespace topic {
    template <typename T>
    class TopicInstance;
} }

template <typename T>
class dds::topic::TopicInstance {
public:
    TopicInstance();
    TopicInstance(const ::dds::core::InstanceHandle& h);
    TopicInstance(const ::dds::core::InstanceHandle& h, const T& the_sample);

public:
    operator const ::dds::core::InstanceHandle() const;

    const ::dds::core::InstanceHandle handle() const;

    void handle(const ::dds::core::InstanceHandle& h);
    const T& sample() const;

    T& sample();

    void sample(const T& the_sample);

private:
    ::dds::core::InstanceHandle h_;
    T sample_;
};


#endif /* OMG_DDS_TOPIC_TOPIC_INSTANCE_HPP_ */
