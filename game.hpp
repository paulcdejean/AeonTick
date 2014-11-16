#pragma once

#include "window.hpp"
#include "behavior.hpp"

class Game {
 public:
  Game(Window starting_window);
  Window& current_window();
  void run(Behavior action);
  
 private:
  Window some_window;
};
