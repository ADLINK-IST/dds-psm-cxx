#ifndef OMG_DDS_SUB_TRANK_HPP_
#define OMG_DDS_SUB_TRANK_HPP_

#include <dds/core/Value.hpp>

namespace dds  { namespace sub {
  template <typename DELEGATE>
  class TRank;
} }


/**
 * This class encapsulate the concept of Rank for a sample.
 */
template <typename DELEGATE>
class dds::sub::TRank : public dds::core::Value<DELEGATE> {
public:
  TRank();

  TRank(int32_t s, int32_t a, int32_t ag);

  int32_t       absolute_generation() const;
  inline int32_t   generation() const;
  inline int32_t   sample() const;
};

#endif /* OMG_DDS_SUB_TRANK_HPP_ */
