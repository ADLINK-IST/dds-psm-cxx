#ifndef OMG_DDS_CORE_XTYPES_STRUCT_TYPE_HPP_
#define OMG_DDS_CORE_XTYPES_STRUCT_TYPE_HPP_

#include <dds/core/xtypes/TStructType.hpp>
#include <dds/core/xtypes/detail/StructType.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      typedef TStructType<detail::StructType> StructType;
    }
  }
}



#endif /* OMG_DDS_CORE_XTYPES_STRUCT_TYPE_HPP_ */
