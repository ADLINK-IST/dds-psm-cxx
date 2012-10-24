#ifndef OMG_DDS_CORE_XTYPES_T_TYPE_PROVIDER_HPP_
#define OMG_DDS_CORE_XTYPES_T_TYPE_PROVIDER_HPP_

#include <dds/core/xtypes/DynamicType.hpp>

namespace dds {
  namespace core {
    namespace xtypes {

      template <typename DELEGATE>
      class TTypeProvider;

    }
  }
}

/**
 * TypeProvider that allows to create types from external representations.
 */
template <typename DELEGATE>
class dds::core::xtypes::TTypeProvider {
public:
  /**
   * Load a type from the specified URI. If multiple types are defined
   * only the first one is returned.
   */
  static DynamicType load_type(const std::string& uri);

  /**
   * Load a type from the specified URI. If multiple types are defined
   * only the first one is returned.
   */
  static std::vector<DynamicType> load_types(const std::string& uri);

  /**
   * Load a named type from the specified URI.
   */
  static DynamicType load_type(const std::string& uri, const std::string& name);
};


#endif /* OMG_DDS_CORE_XTYPES_T_TYPE_PROVIDER_HPP_ */
