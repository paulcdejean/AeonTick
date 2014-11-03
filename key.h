#include <string>
#include <memory>

namespace ltk {
#include "libtermkey-0.17/termkey.h"
}

class Key {
 private:
  ltk::TermKeyKey data;
  
 public:
  Key(ltk::TermKeyKey tkk);
  Key(std::string key_str);

  const std::string str();
};


// At first I made this a singleton.
// Then I changed it to a non singleton so I'm not tempted to grab keys in random places.
class TermKey {
 public:
  TermKey();
  Key get_key();
  ~TermKey();
  
 private:
  // Hopefully I don't have to touch this stuff too often.
  ltk::TermKey* tk;
  ltk::TermKeyKey tk_key;
};
