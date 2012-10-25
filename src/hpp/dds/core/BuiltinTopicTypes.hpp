/*
 * BuiltinTopicTypes.hpp
 *
 *  Created on: Oct 22, 2012
 *      Author: angelo
 */

#ifndef OMG_DDS_CORE_BUILTIN_TOPIC_TYPES_HPP_
#define OMG_DDS_CORE_BUILTIN_TOPIC_TYPES_HPP_

#include <dds/core/detail/conformance.hpp>
#include <dds/core/TBuiltinTopicTypes.hpp>
#include <dds/core/detail/BuiltinTopicTypes.hpp>

#if defined (OMG_DDS_X_TYPES_BUILTIN_TOPIC_TYPES_SUPPORT)
namespace dds {
  namespace core {
    typedef TBytesTopicType<detail::BytesTopicType> BytesTopicType;
    typedef TStringTopicType<detail::StringTopicType> StringTopicType;
    typedef TKeyedBytesTopicType<detail::KeyedBytesTopicType> KeyedBytesTopicType;
    typedef TKeyedStringTopicType<detail::KeyedStringTopicType> KeyedStringTopicType;
  }
}

#endif

#endif /* OMG_DDS_CORE_BUILTIN_TOPIC_TYPES_HPP_ */
