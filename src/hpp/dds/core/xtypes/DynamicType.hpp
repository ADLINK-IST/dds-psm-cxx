#ifndef OMG_DDS_CORE_XTYPES_DYNAMIC_TYPE_HPP_
#define OMG_DDS_CORE_XTYPES_DYNAMIC_TYPE_HPP_

#include <dds/core/xtypes/TDynamicType.hpp>
#include <dds/core/xtypes/detail/DynamicType.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      template <typename DELEGATE = detail::DynamicType>
      class TDynamicType;

      typedef TDynamicType<detail::DynamicType> DynamicType;
    }
  }
}

#endif /* OMG_DDS_CORE_XTYPES_DYNAMIC_TYPE_HPP_ */
