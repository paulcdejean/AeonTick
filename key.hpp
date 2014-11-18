class Key {
 public:
  Key(ltk::TermKeyKey tkk_input);
  Key(char const* string_input);

  static Key waitkey();

  const std::string str();
  const char* cstr();

private:
  static ltk::TermKeyFormat format;
  static TermKey base;
  ltk::TermKeyKey data;
  std::string key_str;

  friend bool operator==(const Key& lhs, const Key& rhs);
};
