#ifndef OMG_DDS_SUB_DETAIL_RANK_HPP
#define OMG_DDS_SUB_DETAIL_RANK_HPP

#include <dds/sub/TRank.hpp>
#include <foo/bar/sub/Rank.hpp>

namespace dds { namespace sub { namespace detail {
  typedef dds::sub::TRank< foo::bar::sub::Rank > Rank;
} } }

#endif /* OMG_DDS_SUB_DETAIL_RANK_HPP */
