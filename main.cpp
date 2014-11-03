#include <ncurses.h>
#include <iostream>
#include "key.h" 

int main() {
  Key test_key = TermKey::instance().get_key();
  std::cout << test_key.str() << std::endl;
  return 0;
}
