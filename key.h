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


// Singletons are bad but I'm using one anyway. Sue me.
class TermKey {
 public:
  static TermKey& instance();
  Key get_key();
  ~TermKey();
  
 private:
  TermKey();
  TermKey(TermKey const&){};
  TermKey& operator=(TermKey const&){};
  // Static points always initialize to null pointers.
  static std::unique_ptr<TermKey> instance_p;

  // Hopefully I don't have to touch this stuff too often.
  ltk::TermKey* tk;
  ltk::TermKeyKey tk_key;
};
