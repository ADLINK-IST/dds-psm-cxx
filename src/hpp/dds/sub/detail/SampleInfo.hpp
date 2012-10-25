#ifndef OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_
#define OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_

#include <foo/bar/sub/SampleInfo.hpp>
#include <dds/sub/TSampleInfo.hpp>

namespace dds { namespace sub { namespace detail {
  typedef dds::sub::TSampleInfo<foo::bar::sub::SampleInfo> SampleInfo;
} } }

#endif /* OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_ */

