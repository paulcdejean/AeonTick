#include <stdexcept>
#include <string>
#include <iostream>

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

int Window::p(const char* c, int x, int y) {

  for(unsigned int x = 0; x < 255; x++) {
    crs::init_pair(x, x, COLOR_BLACK);
  }
  
  for(unsigned int x = 0; x < 255; x++) {
    crs::waddch(ncurses_window, 230);
    crs::waddch(ncurses_window, 156);
    crs::waddch(ncurses_window, 172 | x << 8);
  }

  //crs::attroff(1 << 8);
  /*
  for(unsigned int x = 0; x < 32; x++) {
    crs::move(x, 0);
    crs::waddch(ncurses_window, 230 | (1 << x));
    crs::waddch(ncurses_window, 156 | (1 << x));
    crs::waddch(ncurses_window, 172 | (1 << x));
    }*/
  return 0;
}
