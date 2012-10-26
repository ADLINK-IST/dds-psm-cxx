#ifndef OMG_DDS_CORE_XTYPES_TMEMBER_TYPE_HPP
#define OMG_DDS_CORE_XTYPES_TMEMBER_TYPE_HPP

namespace dds {
  namespace core {
    namespace xtypes {
      template <typename DELEGATE>
      class TMemberType;

      template <typename T>
      bool isOptional(const TMemberType<T>& m);

      template <typename T>
      bool isShared(const TMemberType<T>& m);

      template <typename T>
      bool isKey(const TMemberType<T>& m);

      template <typename T>
      bool isMustUnderstand(const TMemberType<T>& m);

      template <typename T>
      bool isBitset(const TMemberType<T>& m);

      template <typename T>
      bool hasBitbound(const TMemberType<T>& m);

      template <typename T>
      int32_t getBitbound(const TMemberType<T>& m);

      template <typename T>
      bool hasId(const TMemberType<T>& m);

      template <typename T>
      int32_t getId(const TMemberType<T>& m);
    }
  }
}

/**
 * This class represents a dynamic type member.
 */
template <typename DELEGATE>
class dds::core::xtypes::TMemberType : public dds::core::Reference<DELEGATE> {
public:
  OMG_DDS_REF_TYPE(TMemberType, dds::core::Reference, DELEGATE)

public:
  TMemberType(const std::string& name, const dds::core::xtypes::DynamicType& type);

  TMemberType(const std::string& name,
      const dds::core::xtypes::DynamicType& type,
      const Annotation& annotation
  );

  template <typename AnnotationIter>
  TMemberType(const std::string& name,
          const dds::core::xtypes::DynamicType& type,
          const AnnotationIter& begin,
          const AnnotationIter& end);


  TMemberType(const std::string& name,
        const dds::core::xtypes::DynamicType& type,
        const std::vector<Annotation>& annotations
    );

public:
  const std::string& name() const;
  const dds::core::xtypes::DynamicType& type() const;

public:
  TMemberType add_annotation(const Annotation& annotation);
  TMemberType remove_annotation(const Annotation& annotation);
};

#endif /* OMG_DDS_CORE_XTYPES_TMEMBER_TYPE_HPP */
