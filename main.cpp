#include <iostream>

#include <ncurses.h>

#include "termkey.h"
#include "key.h" 

int main() {
  try {
    TermKey input_thingy = TermKey();

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    
    while(not isendwin()) {
      Key current_key = input_thingy.get_key();
      refresh();

      if(current_key == input_thingy.make_key("C-c")) {
	endwin();
      }
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
