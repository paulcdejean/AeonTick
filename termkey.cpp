#include <string>

namespace ltk {
  #include "libtermkey-0.17/termkey.h"
}


#include "key.hpp"

#include "termkey.hpp"

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
