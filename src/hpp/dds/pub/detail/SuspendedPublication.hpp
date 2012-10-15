#ifndef OMG_DDS_PUB_DETAIL_SUSPENDED_PUBLICATION_HPP_
#define OMG_DDS_PUB_DETAIL_SUSPENDED_PUBLICATION_HPP_

#include <dds/pub/TSuspendedPublication.hpp>
#include <foo/bar/pub/SuspendedPublication.hpp>

namespace dds { namespace pub { namespace detail {
    typedef dds::pub::TSuspendedPublication<foo::bar::pub::SuspendedPublicationImpl> SuspendedPublication;
} } }

#endif /*  OMG_DDS_PUB_DETAIL_SUSPENDED_PUBLICATION_HPP_ */
