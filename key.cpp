#include "key.h"

// Not the most readable format, but one in which keys are printed the same way they're parsed.
// I think the creators decided to test the default format but nothing else I swear to god...
ltk::TermKeyFormat Key::format = ltk::TermKeyFormat(0);

Key::Key(ltk::TermKeyKey data, ltk::TermKey* base) {
  this->data = data;
  this->base = base;
  return;
}

Key::Key(const std::string& key_str, ltk::TermKey* base) {
  this->base = base;
  const char* result;

  result = termkey_strpkey(this->base, key_str.data(), &this->data, this->format);
  if(! result) {
    throw std::string("Failed to prase key: ") + key_str;
  }
  return;
}

const std::string Key::str() {
  if(key_str.empty()) {
    char cstr_buffer[50];
    termkey_strfkey(this->base, cstr_buffer, sizeof cstr_buffer, &data, format);
    key_str = cstr_buffer;
  }
  return key_str;
}

const char* Key::cstr() {
  return this->str().c_str();
}

bool operator==(const Key& lhs, const Key& rhs) {
  if(lhs.base != rhs.base) {
    return false;
  }
  if(ltk::termkey_keycmp(lhs.base, &lhs.data, &rhs.data)  == 0) {
    return true;
  }
  else {
    return false;
  }
}
