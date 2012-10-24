#ifndef OMG_DDS_CORE_XTYPES_COLLECTION_TYPES_HPP_
#define OMG_DDS_CORE_XTYPES_COLLECTION_TYPES_HPP_

#include <dds/core/xtypes/TCollectionTypes.hpp>
#include <dds/core/xtypes/detail/CollectionTypes.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      typedef TCollectionType<detail::CollectionType> CollectionType;

      typedef TMapType<detail::MapType> MapType;

      typedef TSequenceType<detail::SequenceType> SequenceType;

      template <typename CHAR_T, template <typename C> class DELEGATE = detail::StringType>
      class TStringType;
    }
  }
}

#endif /* OMG_DDS_CORE_XTYPES_COLLECTION_TYPES_HPP_ */
