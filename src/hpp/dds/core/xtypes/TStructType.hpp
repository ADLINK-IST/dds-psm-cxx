#ifndef OMG_DDS_CORE_XTYPES_T_STRUCT_TYPE_HPP_
#define OMG_DDS_CORE_XTYPES_T_STRUCT_TYPE_HPP_

#include <dds/core/xtypes/DynamicType.hpp>
#include <dds/core/xtypes/MemberType.hpp>
#include <dds/core/xtypes/PrimitiveTypes.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      template <typename DELEGATE>
      class TStructType;

      template <typename T>
      bool isFinal(const TStructType<T>& s);

      template <typename T>
      bool isExtensible(const TStructType<T>& s);

      template <typename T>
      bool isMutable(const TStructType<T>& s);

      template <typename T>
      bool isNested(const TStructType<T>& s);
    }
  }
}

/**
 * Create a dynamic structure type. If the members don't have Id associated
 * explicitly, then their ID will be the same as the ordinal position on the
 * members vector.
 */
template <typename DELEGATE>
class dds::core::xtypes::TStructType : public dds::core::xtypes::DynamicType<DELEGATE> {
public:

  TStructType(const std::string& name);

  TStructType(
      const std::string& name,
      const TStructType& parent,
      const std::vector<MemberType>& members);

  template <typename MemberIter>
  TStructType(
        const std::string& name,
        const TStructType& parent,
        const MemberIter& begin,
        const MemberIter& end);

  TStructType(
          const std::string& name,
          const TStructType& parent,
          const std::vector<MemberType>& members,
          const Annotation& annotation);

  TStructType(
        const std::string& name,
        const TStructType& parent,
        const std::vector<MemberType>& members,
        const std::vector<Annotation>& annotations);

  template <typename AnnotationIter, typename MemberIter>
  TStructType(
        const std::string& name,
        const TStructType& parent,
        const MemberIter& begin,
        const MemberIter& end,
        const AnnotationIter& begin,
        const AnnotationIter& end);
public:
  TStructType parent() const;
  const std::vector<MemberType>& members() const;
  const MemberType& member(uint32_t id) const;
  const MemberType& member(const std::string& name) const;

  const std::vector<Annotation>& annotations() const;

  TStructType add_member(const MemberType& member) const ;
  TStructType remove_member(const MemberType& member) const;

  TStructType add_annotation(const Annotation& annotation) const;
  TStructType remove_annotation(const Annotation& annotation) const;
};


#endif /* OMG_DDS_CORE_XTYPES_T_STRUCT_TYPE_HPP_ */
