#include <map>
#include <string>

namespace crs {
#include <ncurses.h>
}

#include "behavior.hpp"
#include "window.hpp"

#include "game.hpp"

Game::Game(Window starting_window) {
  some_window = starting_window;
}

const Window& Game::current_window() {
  return some_window;
}

void Game::run(Behavior action) {
  switch(action) {
    case QUIT_GAME: {
      crs::endwin();
      break;
    }
    default: {
      return;
    }
  }
}
