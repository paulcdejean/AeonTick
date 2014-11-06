#pragma once

namespace crs {
#include <ncurses.h>
}

class Window {
 public:
  Window(crs::WINDOW* existing_window);
  Window();
  ~Window();

  void refresh();
  
 private:
  crs::WINDOW* ncurses_window;
};
