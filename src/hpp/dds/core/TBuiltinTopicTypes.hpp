#ifndef OMG_DDS_CORE_TBUILTIN_TOPIC_TYPES_HPP_
#define OMG_DDS_CORE_TBUILTIN_TOPIC_TYPES_HPP_


#if defined (OMG_DDS_X_TYPES_BUILTIN_TOPIC_TYPES_SUPPORT)
namespace dds {
  namespace core {

    template <typename DELEGATE>
    class TBytesTopicType;

    template <typename DELEGATE>
    class TStringTopicType;

    template <typename DELEGATE>
    class TKeyedBytesTopicType;

    template <typename DELEGATE>
    class TKeyedStringTopicType;
  }
}

template <typename DELEGATE>
class dds::core::TBytesTopicType {
public:
  TBytesTopicType();
  TBytesTopicType(const std::vector<uint32_t>& data);
public:
  operator std::vector<uint32_t>& ();
public:
  const std::vector<uint8_t>& data();
  void data(const std::vector<uint8_t>& bytes);
};

template <typename DELEGATE>
class dds::core::TStringTopicType {
public:
  TStringTopicType();
  TStringTopicType(const std::string& data);
public:
  operator std::string& ();
public:
  const std::string& data();
  void data(const std::string& bytes);
};


/**
 * This class represents a built-in topic type that can be used
 * to readily create Topics, DataReaders and DataWriters for this type.
 * No code generation is required when using this type.
 */
template <typename DELEGATE>
class dds::core::TKeyedStringTopicType<DELEGATE> {
public:
  TKeyedStringTopicType();
  TKeyedStringTopicType(const std::string& key, const std::string& value);

public:
  const std::string& key() const;
  void key(const std::string& value);

  const std::string& value() const;
  void value(const std::string& value);
};

/**
 * This class represents a built-in topic type that can be used
 * to readily create Topics, DataReaders and DataWriters for this type.
 * No code generation is required when using this type.
 */
template <typename DELEGATE>
class dds::core::TKeyedBytesTopicType<DELEGATE> {
public:
  TKeyedBytesTopicType();
  TKeyedBytesTopicType(const std::string& key, const std::vector<uint8_t>& bytes);

public:
  const std::string& key() const;
  void key(const std::string& value);

  const std::vector<uint8_t>& value() const;
  void value(const std::vector<uint8_t>& value);
};


#endif /* OMG_DDS_X_TYPES_BUILTIN_TOPIC_TYPES_SUPPORT */

#endif /* OMG_DDS_CORE_TBUILTIN_TOPIC_TYPES_HPP_ */
