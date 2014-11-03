#include "key.h"

std::unique_ptr<TermKey> TermKey::instance_p;

TermKey::TermKey() {
  this->tk = ltk::termkey_new(0, ltk::TERMKEY_FLAG_SPACESYMBOL | ltk::TERMKEY_FLAG_CTRLC);
  if(! this->tk) {
    throw "Cannot allocate termkey instance";
  }
}

TermKey::~TermKey() {
  ltk::termkey_destroy(this->tk);
}

TermKey& TermKey::instance() {
  static TermKey the_instance{};
  return the_instance;
}

Key TermKey::get_key() {
  ltk::termkey_waitkey(this->tk, &this->tk_key);
  return Key(this->tk_key);
}

Key::Key(ltk::TermKeyKey tkk) {
  this->data = tkk;
  return;
}

Key::Key(std::string key_str) {
  return;
}

const std::string Key::str() {
  return "I'm a key!";
}
