#ifndef OMG_DDS_CORE_XTYPES_DYNAMICDATA_HPP_
#define OMG_DDS_CORE_XTYPES_DYNAMICDATA_HPP_

#include <dds/core/xtypes/DynamicData.hpp>
#include <dds/core/xtypes/detail/DynamicData.hpp>


namespace dds {
  namespace code {
    namespace xtypes {

      typedef TDynamicData<detail::DynamicData> DynamicData;

    }
  }
}


#endif /* OMG_DDS_CORE_XTYPES_DYNAMICDATA_HPP_ */
