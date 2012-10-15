#ifndef OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_
#define OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_

#include <dds/sub/TGenerationCount.hpp>
#include <foo/bar/sub/GenerationCount.hpp>
namespace dds {
	namespace sub {
		namespace detail {
			typedef dds::sub::TGenerationCount< foo::bar::sub::GenerationCount> GenerationCount;
		}
	}
}

#endif /* OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_ */
