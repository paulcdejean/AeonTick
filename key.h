#include <string>
#include <memory>

namespace ltk {
#include "libtermkey-0.17/termkey.h"
}

class Key {
 private:
  ltk::TermKeyKey data;
  ltk::TermKey* base;
  std::string str;
  static ltk::TermKeyFormat format;

  friend bool operator==(const Key& lhs, const Key& rhs);
  
 public:
  Key(ltk::TermKeyKey data, ltk::TermKey* base);
  Key(const std::string& key_str, ltk::TermKey* base);

  const std::string get_str();
};

// At first I made this a singleton.
// Then I changed it to a non singleton so I'm not tempted to grab keys in random places.
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
