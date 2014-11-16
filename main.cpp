#include <iostream>

//#include "termkey.h"
//#include "key.h"
//#include "game.h"
//#include "window.h"
#include "buildvars.hpp"
#include "config.hpp"

// This is so wrong but it feels so right.
// I don't fully understand why, but this type of thing needs to be delcared after everything.
namespace crs {
#include <ncurses.h>
}

int main(int argc, char* argv[]) {
  try {
    Config main_config = BuildVars::mainconfig_filename;
    Config key_config = main_config.get("config_files.key_config");
    std::cout << key_config.get("main_menu.a") << std::endl;
  }
  catch(std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }
  
  //std::cout << ConfigPath::bin_path << ConfigPath::conf_path << std::endl;
  /*  try {
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
    }*/
}
