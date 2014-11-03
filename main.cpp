#include <ncurses.h>
#include <iostream>
#include "key.h" 

int main() {
  try {
    TermKey input_thingy = TermKey();
    Key test_key = input_thingy.get_key();
    std::cout << test_key.get_str() << std::endl;
    Key test_again = input_thingy.make_key("F1");
    std::cout << test_again.get_str() << std::endl;
    if(test_key == test_again) {
      std::cout << "The keys are the same" << std::endl;
    }
    return 0;
  }
  catch(std::string e) {
    std::cout << "Exception: " << e << std::endl;
  }
  catch(...) {
    std::cout << "Unknown exception occured." << std::endl;
  }
}
