#include <ncurses.h>
#include <iostream>
#include "key.h" 

int main() {
  TermKey input_thingy = TermKey();
  Key test_key = input_thingy.get_key();
  std::cout << test_key.str() << std::endl;
  return 0;
}
