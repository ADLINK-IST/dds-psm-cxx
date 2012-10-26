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

      template <typename DDT, typename T>
      void value(DDT& dd, uint32_t mid, const T& v);

      template <typename DDT, typename T>
      T value(const DDT& dd, const std::string& mid, const T& v);

      template <typename DDT, typename T>
      T value(const DDT& dd, uint32_t mid);

      template <typename DDT, typename T>
      T value(const DDT& dd, const std::string& mid);


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
  OMG_DDS_REF_TYPE(TDynamicData, dds::core::Reference, DELEGATE)
public:
  TDynamicData(const DynamicType& type);

public:
  template <typename T>
  void value(uint32_T mid, const T& v) const;

  template <typename T>
  T value(const std::string& mid, const T& v) const;

  template <typename T>
  T value(uint32_T mid) const;

  template <typename T>
  T value(const std::string& mid) const;

  DynamicType type() const;

  MemberType member_type(uint32_t id) const;
  MemberType member_type(const std::string& name) const;

  uint32_t member_id(const std::string& name) const;
};


#endif /* OMG_DDS_CORE_XTYPES_TDYNAMICDATA_HPP_ */
