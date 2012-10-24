/*
 * TUnionCase.hpp
 *
 *  Created on: Oct 24, 2012
 *      Author: angelo
 */

#ifndef  OMG_DDS_CORE_XTYPES_UNION_CASE_HPP_
#define  OMG_DDS_CORE_XTYPES_UNION_CASE_HPP_

#include <dds/core/Reference.hpp>
#include <dds/core/xtypes/MemberType.hpp>
#include <dds/core/xtypes/detail/UnionCase.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      template <typename T, template <typename Q> class DELEGATE = detail::UnionCase>
      class UnionCase;
    }
  }
}

template <typename T, template <typename Q> class DELEGATE>
class UnionCase : public dds::core::Reference<DELEGATE<T> > {
public:
  // Nil case
  UnionCase();
public:
  UnionCase(T discriminator, const MemberType& member);
public:
  T discriminator();
  const MemberType& member();
};

#endif /* OMG_DDS_CORE_XTYPES_T_UNION_CASE_HPP_ */
