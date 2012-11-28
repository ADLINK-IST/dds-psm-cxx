#ifndef OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_
#define OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_

#include <dds/pub/TCoherentSet.hpp>
#include <foo/bar/pub/CoherentSet.hpp>

namespace dds {
  namespace pub {
    namespace detail {
      typedef dds::pub::TCoherentSet<foo::bar::pub::CoherentSet> CoherentSet;
    }
  }
}

#endif /*  OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_ */
