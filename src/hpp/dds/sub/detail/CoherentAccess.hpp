#ifndef OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_
#define OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_

#include <foo/bar/sub/CoherentAccess.hpp>
#include <dds/sub/TCoherentAccess.hpp>

namespace dds { namespace sub { namespace detail {
	typedef ::dds::sub::TCoherentAccess<foo::bar::sub::CoherentAccess> CoherentAccess;
} } }

#endif /* OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_ */
