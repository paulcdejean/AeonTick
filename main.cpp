#include <iostream>

#include <boost/filesystem.hpp>

//namespace crs {
//#include <ncurses.h>
//}

//#include "termkey.h"
//#include "key.h"
//#include "game.h"
//#include "window.h"
//#include "keyconfig.h"
#include "filepaths.h"

int main(int argc, char* argv[]) {
  FilePaths the_paths = FilePaths();
  std::cout << the_paths.get_main_config() << std::endl;
  
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
