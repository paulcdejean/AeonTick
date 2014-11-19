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

#include "termkey.hpp"

#include "key.hpp"
#include "behavior.hpp"
#include "config.hpp"
#include "window.hpp"
#include "game.hpp"
#include "key_config.hpp"
#include "buildvars.hpp"

int main(int argc, char* argv[]) {
  try {
    Config main_config = BuildVars::mainconfig_filename;
    KeyConfig key_config = KeyConfig(main_config.get("config_files.key_config"));

    crs::initscr();
    crs::raw();
    crs::noecho();
    crs::keypad(crs::stdscr, true);

    Game the_game = Game(Window(crs::stdscr));

    while(not crs::isendwin()) {
      Behavior action = key_config.get_behavior(the_game, Key::waitkey());

      the_game.run(action);
    }
  }
  catch(std::runtime_error e) {
    // We gotta drop out of curses mode before we panic exit.
    // If we don't bad things happen. Very bad things!
    crs::endwin();
    std::cout << e.what() << std::endl;
  }
  catch(...) {
    // I don't know what other types of exceptions might be caught, but just in case...
    crs::endwin();
  }
}
