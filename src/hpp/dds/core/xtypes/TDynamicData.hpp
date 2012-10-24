#ifndef OMG_DDS_CORE_XTYPES_TDYNAMICDATA_HPP_
#define OMG_DDS_CORE_XTYPES_TDYNAMICDATA_HPP_

#include <dds/core/Reference.hpp>
#include <dds/core/xtypes/DynamicType.hpp>
#include <dds/core/xtypes/MemberType.hpp>

namespace dds {
  namespace code {
    namespace xtypes {
      template <typename DELEGATE>
      class TDynamicData;
    }
  }
}

/**
 * This class is used to read/write data for DynamicTypes. It allows to read/write
 * samples in a type-safe manner but w/o any compile-time knowledge of the type being
 * read/written.
 */
template <typename DELEGATE>
class dds::code::xtypes::TDynamicData : dds::core::Reference<DELEGATE> {
public:
  TDynamicData(const DynamicType& type);

public:
  template <typename T>
  void value(uint32_T mid, const T& v);
  template <typename T>
  T value(const std::string& mid, const T& v);

  template <typename T>
  T value(uint32_T mid) const;

  template <typename T>
  T value(const std::string& mid) const;

  DynamicType type();

  MemberType member_type(uint32_t id);
  MemberType member_type(const std::string& name);

  uint32_t member_id(const std::string& name);
};


#endif /* OMG_DDS_CORE_XTYPES_TDYNAMICDATA_HPP_ */
