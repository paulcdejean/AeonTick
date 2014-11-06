#pragma once

#include "window.h"
#include "behavior.h"

class Game {
 public:
  Game(Window starting_window);
  Window& current_window();
  void run(Behavior action);
  
 private:
  Window some_window;
};
