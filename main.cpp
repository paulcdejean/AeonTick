#include <iostream>

namespace crs {
#include <ncurses.h>
}

#include "termkey.h"
#include "key.h"
#include "keyconfig.h"
#include "game.h"
#include "window.h"

int main() {
  try {
    TermKey input_thingy = TermKey();
    KeyConfig key_conf = KeyConfig("derp.ini");

    crs::initscr();
    crs::raw();
    crs::noecho();
    crs::keypad(crs::stdscr, true);

    Game the_game = Game(Window(crs::stdscr));
    
    while(not crs::isendwin()) {
      Key current_key = input_thingy.get_key();
      Window current_window = the_game.current_window();
      Behavior action = key_conf.get_behavior(current_window, current_key);
      
      the_game.run(action);
      
      if(current_key == input_thingy.make_key("C-c")) {
	crs::endwin();
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
