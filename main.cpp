#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Hello world" << std::endl;
  return 0;
  /*
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
  */
}
