#include "key.h"

ltk::TermKeyFormat Key::format = static_cast<ltk::TermKeyFormat>(ltk::TERMKEY_FORMAT_LONGMOD | ltk::TERMKEY_FORMAT_WRAPBRACKET);

TermKey::TermKey() {
  this->tk = ltk::termkey_new(0, ltk::TERMKEY_FLAG_SPACESYMBOL | ltk::TERMKEY_FLAG_CTRLC);
  if(! this->tk) {
    throw "Cannot allocate termkey instance";
  }
}

TermKey::~TermKey() {
  ltk::termkey_destroy(this->tk);
}

Key TermKey::get_key() {
  ltk::termkey_waitkey(this->tk, &this->tk_key);
  return Key(this->tk_key, this->tk);
}

Key TermKey::make_key(const std::string& key_str) {
  return Key(key_str, this->tk);
}

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

const std::string Key::get_str() {
  if(this->str.empty()) {
    char cstr_buffer[50];
    termkey_strfkey(this->base, cstr_buffer, sizeof cstr_buffer, &this->data, this->format);
    this->str = cstr_buffer;
  }
  return this->str;
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
