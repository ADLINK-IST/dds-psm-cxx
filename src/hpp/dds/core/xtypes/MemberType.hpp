#ifndef OMG_DDS_CORE_XTYPES_MEMBER_TYPE_HPP
#define OMG_DDS_CORE_XTYPES_MEMBER_TYPE_HPP

#include <dds/core/xtypes/TMemberType.hpp>
#include <dds/core/xtypes/detail/MemberType.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      typedef  TMemberType<detail::MemberType> MemberType;
    }
  }
}

#endif /* OMG_DDS_CORE_XTYPES_MEMBER_TYPE_HPP */
