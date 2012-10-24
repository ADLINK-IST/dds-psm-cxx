#ifndef OMG_DDS_CORE_XTYPES_DETAIL_PRIMITIVE_TYPES_HPP_
#define OMG_DDS_CORE_XTYPES_DETAIL_PRIMITIVE_TYPES_HPP_

#include <dds/core/xtypes/TypeKind.hpp>

// This template specialization have the intent to provide guidelines
// implementors of this specification. Notice that this define only a subset
// of primitive types, thus more work for you to do...
namespace dds {
  namespace core {
    namespace xtypes {
      template<>
      struct dynamic_type_traits<uint8_t> {
        static const TypeKind TYPE_ID = UINT_8_TYPE;
        static const  std::string NAME; // "uint8_t"
      };

      template<>
      struct dynamic_type_traits<int16_t> {
        static const TypeKind TYPE_ID = INT_16_TYPE;
        static const  std::string NAME; // "uint16_t"
      };


      template<>
      struct dynamic_type_traits<uint16_t> {
        static const TypeKind TYPE_ID = UINT_16_TYPE;
        static const  std::string NAME; // "int16_t"
      };

      template<>
      struct dynamic_type_traits<int32_t> {
        static const TypeKind TYPE_ID = INT_32_TYPE;
        static const  std::string NAME; // "int16_t"
      };

      template<>
      struct dynamic_type_traits<uint32_t> {
        static const TypeKind TYPE_ID = UINT_32_TYPE;
        static const std::string NAME; // "uint32_t"
      };

    }
  }
}


#endif /* OMG_DDS_CORE_XTYPES_DETAIL_PRIMITIVE_TYPES_HPP_ */
