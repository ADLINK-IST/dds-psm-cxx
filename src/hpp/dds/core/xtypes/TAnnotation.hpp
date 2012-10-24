#ifndef OMG_DDS_CORE_XTYPES_TANNOTATIONS_HPP_
#define OMG_DDS_CORE_XTYPES_TANNOTATIONS_HPP_

namespace dds {
  namespace core {
    namespace xtypes {

      enum AnnotationKind {
        ID_ANNOTATION_TYPE,
        OPTIONAL_ANNOTATION_TYPE,
        KEY_ANNOTATION_TYPE,
        SHARED_ANNOTATION_TYPE,
        NESTED_ANNOTATION_TYPE,
        EXTENSIBILITY_ANNOTATION_TYPE,
        MUST_UNDERSTAND_ANNOTATION_TYPE,
        VERBATIM_ANNOTATION_TYPE,
        BITSET_ANNOTATION_TYPE
      };

      template <typename DELEGATE>
      class TAnnotation;

      template <typename DELEGATE>
      class TIdAnnotation;

      template <typename DELEGATE>
      class TKeyAnnotation;

      template <typename DELEGATE>
      class TSharedAnnotation;

      template <typename DELEGATE>
      class TNestedAnnotation;

      template <typename DELEGATE>
      class TExtensibilityAnnotation;

      template <typename DELEGATE>
      class TMustUnderstandAnnotation;

      template <typename DELEGATE>
      class TVerbatimAnnotation;

      template <typename DELEGATE>
      class TBitsetAnnotation;

      template <typename DELEGATE>
      class TBitBoundAnnotation;

    }
  }
}
template <typename DELEGATE>
class dds::core::xtypes::TAnnotation {
public:
  TAnnotation();
protected:
  TAnnotation(const TypeKind& kind);
public:
  TypeKind kind() const;
};
template <typename DELEGATE>
class dds::core::xtypes::TIdAnnotation : public dds::core::xtypes::TAnnotation<DELEGATE> {
public:
  TIdAnnotation(uint32_t id);
public:
  uint32_t id() const;
};
template <typename DELEGATE>
class dds::core::xtypes::TKeyAnnotation : public dds::core::xtypes::TAnnotation<DELEGATE> {
public:
  TKeyAnnotation();
};
template <typename DELEGATE>
class dds::core::xtypes::TSharedAnnotation : public dds::core::xtypes::TAnnotation<DELEGATE> {
public:
  TSharedAnnotation();
};
template <typename DELEGATE>
class dds::core::xtypes::TNestedAnnotation : public dds::core::xtypes::TAnnotation<DELEGATE> {
public:
  TNestedAnnotation();
};

template <typename DELEGATE>
class dds::core::xtypes::TExtensibilityAnnotation : public dds::core::xtypes::TAnnotation<DELEGATE> {
public:
  typedef enum {
    FINAL,
    EXTENSIBLE,
    MUTABLE
  } ExtensibilityKind;

public:
  TExtensibilityAnnotation(ExtensibilityKind xkind);

public:
  ExtensibilityKind extensibility_kind() const;
};

template <typename DELEGATE>
class dds::core::xtypes::TMustUnderstandAnnotation : public dds::core::xtypes::TAnnotation<DELEGATE> {
public:
  TMustUnderstandAnnotation();
};

template <typename DELEGATE>
class dds::core::xtypes::TVerbatimAnnotation : public dds::core::xtypes::TAnnotation<DELEGATE> {
public:
  TVerbatimAnnotation(const std::string& text);
public:
  const std::string& verbatim_text() const;
};

template <typename DELEGATE>
class dds::core::xtypes::TBitsetAnnotation : public dds::core::xtypes::TAnnotation<DELEGATE> {
public:
  TBitsetAnnotation();

};

template <typename DELEGATE>
class  dds::core::xtypes::TBitBoundAnnotation : public dds::core::xtypes::TAnnotation<DELEGATE> {
public:
  TBitBoundAnnotation(uint32_t bound);
};


#endif /* OMG_DDS_CORE_XTYPES_TANNOTATIONS_HPP_ */
