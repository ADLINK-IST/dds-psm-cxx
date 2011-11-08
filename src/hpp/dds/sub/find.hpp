#ifndef OMG_DDS_SUB_FIND_HPP_
#define OMG_DDS_SUB_FIND_HPP_

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

#include <string>
#include <vector>

#include <dds/core/macros.hpp>
#include <dds/core/ref_traits.hpp>
#include <dds/sub/detail/find.hpp>


namespace dds { namespace sub {


/**
 * This function retrieves a previously-created DataReader
 * belonging to the Subscriber that is attached to a Topic with a
 * matching topic_name. If no such DataReader exists, the operation
 * will return an empty container.  The use of this
 * operation on the built-in Subscriber allows access to the
 * built-in DataReader entities for the built-in topics
 *
 * @return the total number of elements found. Notice that
 * at most max_size will be copied using the provided iterator.
 *
 */
template <typename READER, typename FwdIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
		const std::string& topic_name,
		FwdIterator begin, uint32_t max_size) {
	return ::dds::sub::detail::find<READER, FwdIterator>(sub,
                                                         topic_name,
                                                         begin,
                                                         max_size);
}

/**
 * This function retrieves a previously-created DataReader
 * belonging to the Subscriber that is attached to a Topic with a
 * matching topic_name. If no such DataReader exists, the operation
 * will return an empty container.  The use of this
 * operation on the built-in Subscriber allows access to the
 * built-in DataReader entities for the built-in topics
 *
 * @return the total number of elements found and copied over.
 *
 */
template <typename READER, typename BinIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
		const std::string& topic_name,
		BinIterator begin) {
	return ::dds::sub::detail::find<READER, BinIterator>(sub,
                                                         topic_name,
                                                         begin);
}

/**
 * This function retrieves a previously-created DataReader
 * belonging to the Subscriber that is attached to a Topic with a
 * matching topic_name. If no such DataReader exists, the operation
 * will return an empty container.  The use of this
 * operation on the built-in Subscriber allows access to the
 * built-in DataReader entities for the built-in topics
 */
template <typename READER, typename T, typename FwdIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
		const dds::topic::TopicDescription<T>& topic_description,
		FwdIterator begin, uint32_t max_size) {

	OMG_DDS_STATIC_ASSERT((dds::core::is_same<T, typename READER::DataType>::value));
	return ::dds::sub::detail::find<READER, T, FwdIterator>(sub,
                                                            topic_description,
                                                            begin,
                                                            max_size);
}

template <typename READER, typename T, typename BinIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
		const dds::topic::TopicDescription<T>& topic_description,
		BinIterator begin) {

	OMG_DDS_STATIC_ASSERT((dds::core::is_same<T, typename READER::DataType>::value));
	return ::dds::sub::detail::find<READER, T, BinIterator>(sub,
                                                            topic_description,
                                                            begin);
}


template <typename READER, typename FwdIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
	const dds::sub::status::ReaderState& rs,
	FwdIterator begin, uint32_t max_size)
{
	return dds::sub::detail::find<READER, FwdIterator>(sub,
                                                       rs,
                                                       begin,
                                                       max_size);
}

template <typename READER, typename BinIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
	const dds::sub::status::ReaderState& rs,
	BinIterator begin)
{
	return dds::sub::detail::find<READER, BinIterator>(sub, rs, begin);
}


} }

#endif /* OMG_DDS_SUB_FIND_HPP_ */
