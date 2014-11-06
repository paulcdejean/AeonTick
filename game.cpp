#include "game.h"

Game::Game(Window starting_window) {
  this->some_window = starting_window;
}

Window& Game::current_window() {
  return some_window;
}

void Game::run(Behavior action) {
  return;
}
