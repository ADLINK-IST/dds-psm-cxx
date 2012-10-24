#ifndef OMG_DDS_CORE_SAFEENUMERATION_HPP_
#define OMG_DDS_CORE_SAFEENUMERATION_HPP_

namespace dds {
  namespace core {
    template<typename def, typename inner = typename def::type>
    class safe_enum : public def
    {
      typedef typename def::type type;
      inner val;

    public:

      safe_enum(type v) : val(v) {}
      inner underlying() const { return val; }

      bool operator == (const safe_enum & s) const { return this->val == s.val; }
      bool operator != (const safe_enum & s) const { return this->val != s.val; }
      bool operator <  (const safe_enum & s) const { return this->val <  s.val; }
      bool operator <= (const safe_enum & s) const { return this->val <= s.val; }
      bool operator >  (const safe_enum & s) const { return this->val >  s.val; }
      bool operator >= (const safe_enum & s) const { return this->val >= s.val; }
    };


  }
}



#endif /* OMG_DDS_CORE_SAFEENUMERATION_HPP_ */
