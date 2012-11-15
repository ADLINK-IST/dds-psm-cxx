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

    // Used by C++11 compilers to allow for using LoanedSamples
    // and SharedSamples in a range based for-loop.
    template <typename T> typename T::iterator begin(T& t);
    template <typename T> typename T::iterator end(T& t);

    template <typename T> typename T::const_iterator cbegin(const T& t);
    template <typename T> typename T::const_iterator cend(const T& t);
  }

}

/**
 * This class encapsulate and automates the management of loaned samples.
 * Notice that this class should be <b>exception safe</b> and implement
 * the move idiom as explained at:
 * http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Move_Constructor
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

namespace dds {
  namespace sub {
    template <typename T, template <typename Q> class D>
    LoanedSamples<T, D<T> >
    move(LoanedSamples<T, D<T> >& a);
  }
}
#endif /* OMG_DDS_SUB_TLOANED_SAMPLES_HPP_ */
