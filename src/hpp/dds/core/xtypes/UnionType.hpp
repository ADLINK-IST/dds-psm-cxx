#ifndef OMG_DDS_CORE_XTYPES_T_UNION_TYPE_HPP_
#define OMG_DDS_CORE_XTYPES_T_UNION_TYPE_HPP_

#include <dds/core/xtypes/DynamicType.hpp>
#include <dds/core/xtypes/UnionCase.hpp>
#include <dds/core/xtypes/PrimitiveTypes.hpp>
#include <dds/core/xtypes/detail/UnionType.hpp>
#include <vector>

namespace dds {
  namespace core {
    namespace xtypes {
      template <typename T, template <typename Q> class DELEGATE = detail::UnionType >
      class UnionType;
    }
  }
}

template <typename T, typename DELEGATE>
class dds::core::xtypes::TUnionType  : public dds::core::xtypes::DynamicType<DELEGATE<T> > {
public:

  TUnionType(
      const std::string& name,
      const TPrimitiveType<T>& discriminator_type,
      const std::vector<UnionCase<T> >& cases);

  TUnionType(
      const std::string& name,
      const TPrimitiveType<T>& discriminator_type,
      const std::vector<UnionCase<T> >& cases,
      const Annotation& annotation);

  TUnionType(
      const std::string& name,
      const TPrimitiveType<T>& discriminator_type,
      const std::vector<UnionCase<T> >& cases,
      const std::vector<Annotation>& annotations);

 public:

   const std::vector<UnionCase<T> >& members();
   const MemberType& member(uint32_t id);
   const MemberType& member(const std::string& name);

   const std::vector<Annotation>& annotations();

   TUnionType operator +(const UnionCase<T>& member);
   TUnionType operator -(const UnionCase<T>& member);

   TUnionType operator +(const Annotation& annotation);
   TUnionType operator -(const Annotation& annotation);

};

#endif /* OMG_DDS_CORE_XTYPES_T_STRUCT_TYPE_HPP_ */
