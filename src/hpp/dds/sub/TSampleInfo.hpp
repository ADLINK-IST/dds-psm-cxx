#ifndef OMG_DDS_SUB_TSAMPLE_INFO_HPP_
#define OMG_DDS_SUB_TSAMPLE_INFO_HPP_

#include <dds/core/Time.hpp>
#include <dds/core/Value.hpp>
#include <dds/sub/GenerationCount.hpp>
#include <dds/sub/Rank.hpp>

namespace dds {
  namespace sub {
    template <typename DELEGATE>
    class TSampleInfo;
  }
}

/**
 * This class implements the DDS <code>SampleInfo</code>.
 */
template <typename DELEGATE>
class dds::sub::TSampleInfo : dds::core::Value<DELEGATE> {

public:
  // Required for containers
  TSampleInfo();

public:
  const dds::core::Time         timestamp() const;
  const dds::sub::status::DataState   state() const;
  dds::sub::GenerationCount       generation_count() const;
  dds::sub::Rank             rank() const;
  bool                   valid() const;
  dds::core::InstanceHandle       instance_handle() const;
  dds::core::InstanceHandle       publication_handle() const;
};

#endif /* OMG_DDS_SUB_TSAMPLE_INFO_HPP_ */
