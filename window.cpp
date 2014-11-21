#include <string>

namespace crs {
#include <ncurses.h>
}

#include "window.hpp"

Window::Window(crs::WINDOW* existing_window) : ncurses_window(existing_window) {}

Window::Window() {
  ncurses_window = crs::newwin(0, 0, 0, 0);
}

Window::~Window() {
  crs::delwin(ncurses_window);
}

int Window::refresh() {
  return crs::wrefresh(ncurses_window);
}

int Window::p(const char* c) {
  return crs::wprintw(ncurses_window, c);
}
