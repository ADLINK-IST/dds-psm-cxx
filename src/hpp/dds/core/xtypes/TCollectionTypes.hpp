#ifndef OMG_DDS_CORE_XTYPES_T_COLLECTION_TYPES_HPP_
#define OMG_DDS_CORE_XTYPES_T_COLLECTION_TYPES_HPP_

#include <dds/core/xtypes/DynamicType.hpp>

namespace dds {
  namespace core {
    namespace xtypes {

      template <typename DELEGATE>
      class TCollectionType;

      template <typename DELEGATE>
      class TMapType;

      template <typename DELEGATE>
      class TSequenceType;

      template <typename CHAR_T, template <typename C> class DELEGATE>
      class TStringType;
    }
  }
}

template <typename DELEGATE>
class dds::core::xtypes::TCollectionType : public dds::core::xtypes::TDynamicType<DELEGATE> {
public:
    const uint32_t UNBOUNDED = 0xFFFFFFFF;

protected:
  TCollectionType(const std::string& name, TypeKind kind);
public:
  uint32_t bounds() const;
};


template <typename DELEGATE>
class dds::core::xtypes::TMapType : public dds::core::xtypes::TCollectionType<DELEGATE> {
public:
  /**
   * Create an unbounded Map with the given key/value type.
   */
  TMapType(const DyanmicType& key_type, const DynamicType& value_type);
  /**
   * Create an bounded Map with the given key/value type.
   */
  TMapType(const DyanmicType& key_type, const DynamicType& value_type, uint32_t bounds);
public:
  const DyanmicType& key_type();
  const DynamicType& value_type();
};

template <typename DELEGATE>
class dds::core::xtypes::TSequenceType : public dds::core::xtypes::TCollectionType<DELEGATE> {
public:
  /**
   * Create an unbounded sequence for the given type.
   */
  TSequenceType(const DynamicType& type);

  /**
   * Create a bounded sequence for the given type.
   */
  TSequenceType(const DynamicType& type, uint32_t bounds);
public:
  const DyanmicType& key_type() const;
};

template <typename CHAR_T, template <typename C> class DELEGATE>
class dds::core::xtypes::TStringType : public dds::core::xtypes::TCollectionType<DELEGATE> {
public:
  TStringType(uint32_t bounds);
};


#endif /* OMG_DDS_CORE_XTYPES_T_COLLECTION_TYPES_HPP_ */
