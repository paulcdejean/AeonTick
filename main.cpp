#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
namespace bpt = boost::property_tree;

#include <map>
#include <string>
#include <iostream>

namespace crs {
#include <ncurses.h>
}

namespace ltk {
#include "libtermkey-0.17/termkey.h"
}

#include "key.hpp"
#include "termkey.hpp"
#include "behavior.hpp"
#include "config.hpp"
#include "window.hpp"
#include "key_config.hpp"
#include "game.hpp"
#include "buildvars.hpp"

int main(int argc, char* argv[]) {
  try {
    Config main_config = BuildVars::mainconfig_filename;
    KeyConfig key_config = KeyConfig(main_config.get("config_files.key_config"));

    TermKey input_thingy = TermKey();
    
    crs::initscr();
    crs::raw();
    crs::noecho();
    crs::keypad(crs::stdscr, true);

    Game the_game = Game(Window(crs::stdscr));

    while(not crs::isendwin()) {
      Key current_key = input_thingy.get_key();
      Behavior action = key_config.get_behavior(the_game.current_window(), current_key);

      the_game.run(action);

      if(current_key == input_thingy.make_key("C-c")) {
	the_game.run(QUIT_GAME);
      }
    }
  }
  catch(std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }
}
