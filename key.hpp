class Key {
 public:
  Key(ltk::TermKeyKey data, ltk::TermKey* base);
  Key(const std::string& key_str, ltk::TermKey* base);

  const std::string str();
  const char* cstr();

 private:
  ltk::TermKeyKey data;
  ltk::TermKey* base;
  std::string key_str;
  static ltk::TermKeyFormat format;

  friend bool operator==(const Key& lhs, const Key& rhs);
};
