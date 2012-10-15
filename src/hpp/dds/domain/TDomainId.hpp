#ifndef OMG_DDS_DOMAIN_T_DOMAIN_ID_HPP_
#define OMG_DDS_DOMAIN_T_DOMAIN_ID_HPP_

#include <dds/core/Value.hpp>

namespace dds { namespace domain {
    template <typename DELEGATE>
    class TDomainId;
} }


template <typename DELEGATE>
class dds::domain::TDomainId : public dds::core::Value<DELEGATE> {
public:

    template <typename ARG0>
    TDomainId(ARG0 id) : dds::core::Value<DELEGATE>(id);
    
    template <typename ARG0, typename ARG1>
    TDomainId(ARG0 arg0, ARG1 arg1);
    
    operator uint32_t () const;
    
    uint32_t value() const;
    
    static const TDomainId default_domain();
};
    
#endif /* OMG_DDS_DOMAIN_T_DOMAIN_ID_HPP_ */
