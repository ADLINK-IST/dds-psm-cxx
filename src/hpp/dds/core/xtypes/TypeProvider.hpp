#ifndef OMG_DDS_CORE_XTYPES_TYPE_PROVIDER_HPP_
#define OMG_DDS_CORE_XTYPES_TYPE_PROVIDER_HPP_

#include <dds/core/xtypes/TTypeProvider.hpp>
#include <dds/core/xtypes/detail/TypeProvider.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      typedef TTypeProvider<detail::TypeProvider> TypeProvider;
    }
  }
}

#endif /* OMG_DDS_CORE_XTYPES_TYPE_PROVIDER_HPP_ */
