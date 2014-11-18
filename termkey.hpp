/* Dependencies:
namespace ltk {
#include "libtermkey-0.17/termkey.h"
}
*/

class TermKey {
 public:
  TermKey();
  ltk::TermKeyResult waitkey(ltk::TermKeyKey* tk_key);
  ltk::TermKey* get() const;
  ~TermKey();

 private:
  // Hopefully I don't have to touch this stuff too often.
  ltk::TermKey* tk;
};
