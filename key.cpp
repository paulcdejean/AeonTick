#include <stdexcept>
#include <string>

namespace ltk {
#include "libtermkey-0.17/termkey.h"
}

#include "termkey.hpp"
#include "key.hpp"

// Not the most readable format, but one in which keys are printed the same way they're parsed.
// I think the creators decided to test the default format but nothing else I swear to god...
ltk::TermKeyFormat Key::format = ltk::TermKeyFormat(0);
TermKey Key::base = TermKey();

Key::Key(ltk::TermKeyKey tkk_input) {
  data = tkk_input;
}

Key::Key(char const* string_input) {
  const char* result;

  result = termkey_strpkey(base.get(), string_input, &data, format);
  if(! result) {
    throw std::runtime_error(std::string("Failed to prase key: ") + key_str);
  }
  return;
}

Key Key::waitkey() {
  ltk::TermKeyKey tkk;
  base.waitkey(&tkk);
  return Key(tkk);
}

const std::string Key::str() {
  if(key_str.empty()) {
    char cstr_buffer[50];
    termkey_strfkey(base.get(), cstr_buffer, sizeof cstr_buffer, &data, format);
    key_str = cstr_buffer;
  }
  return key_str;
}

const char* Key::cstr() {
  return str().c_str();
}

bool operator==(const Key& lhs, const Key& rhs) {
  if(ltk::termkey_keycmp(Key::base.get(), &lhs.data, &rhs.data) == 0) {
    return true;
  }
  else {
    return false;
  }
}
