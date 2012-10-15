#ifndef OMG_DDS_SUB_TLOANED_SAMPLES_HPP_
#define OMG_DDS_SUB_TLOANED_SAMPLES_HPP_

#include <dds/core/ref_traits.hpp>
#include <dds/sub/Sample.hpp>

#include <dds/sub/detail/LoanedSamples.hpp>

namespace dds {
	namespace sub {
		template <typename T,
				  template <typename Q> class DELEGATE = detail::LoanedSamples>
		class LoanedSamples;
  } 
}

/**
 * This class encapsulate and automates the management of loaned samples.
 */
template <typename T,
	  template <typename Q> class DELEGATE>
class dds::sub::LoanedSamples
{
public:
  typedef T                     DataType;
  typedef typename DELEGATE<T>::iterator              iterator;
  typedef typename DELEGATE<T>::const_iterator        const_iterator;

  typedef typename dds::core::smart_ptr_traits< DELEGATE<T> >::ref_type DELEGATE_REF_T;

public:
  LoanedSamples();
  
  /**
   * Implicitly return the loan.
   */
  ~LoanedSamples();
  

public:
  const_iterator begin() const;

  const_iterator  end() const;

  const DELEGATE_REF_T& delegate() const;

  DELEGATE_REF_T& delegate();

  uint32_t length() const;
  
private:
  DELEGATE_REF_T delegate_;
};

#endif /* OMG_DDS_SUB_TLOANED_SAMPLES_HPP_ */
