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

#undef stdscr

int main(int argc, char* argv[]) {
  try {
    Config main_config = BuildVars::mainconfig_filename;
    KeyConfig key_config = KeyConfig(main_config.get("config_files.key_config"));

    setlocale(LC_ALL, "");

    crs::initscr();

    // FUCK MACROS!
    crs::WINDOW* initial_ncurses_window = crs::ncwrap_stdscr();
    
    crs::raw();
    crs::noecho();
    crs::start_color();
    crs::keypad(initial_ncurses_window, true);

    // Only 256 colors can be registered.
    // Blame ncurses...
    // Because of this we're going to forgo background colors all together.
    // They hurt my eyes anyway.
    // So for now this is hard coded, it can be config filed later if needed.
    // I really don't feel like config filing it now.
    for(unsigned int n = 0; n < 256; ++n) {
      crs::init_pair(n, n, 0);
    }

    Window main_menu = Window(initial_ncurses_window);
    Game the_game = Game(main_menu);
    
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
    std::cout << "A completely unknown type of exception was caught." << std::endl;
  }
}
