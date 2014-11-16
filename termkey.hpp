#pragma once

#include "key.hpp"

class TermKey {
 public:
  TermKey();
  Key get_key();
  Key make_key(const std::string& key_str);
  ~TermKey();

 private:
  // Hopefully I don't have to touch this stuff too often.
  ltk::TermKey* tk;
  ltk::TermKeyKey tk_key;
};
