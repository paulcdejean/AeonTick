#include <stdexcept>

namespace ltk {
#include "libtermkey-0.17/termkey.h"
}

#include "termkey.hpp"

TermKey::TermKey() {
  tk = ltk::termkey_new(0, ltk::TERMKEY_FLAG_SPACESYMBOL | ltk::TERMKEY_FLAG_CTRLC);
  if(! tk) {
    throw std::runtime_error("Cannot allocate termkey instance");
  }
}

TermKey::~TermKey() {
  ltk::termkey_destroy(this->tk);
}

ltk::TermKeyResult TermKey::waitkey(ltk::TermKeyKey* tk_key) {
  return ltk::termkey_waitkey(tk, tk_key);
}

ltk::TermKey* TermKey::get() const {
  return tk;
}
