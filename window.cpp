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

void Window::p(const char* c, int color, bool bold, bool underline, bool reverse) {
  // 0xxxxxxx = 1 byte
  // 110xxxxx = 2 bytes
  // 1110xxxx = 3 bytes
  // 11110xxx = 4 bytes
  int utf8_char_size;
  if(c[0] == '\0') {
    utf8_char_size = 0;
  }
  else if((c[0] & 240) == 240) {
    utf8_char_size = 4;
  }
  else if((c[0] & 224) == 224) {
    utf8_char_size = 3;
  }
  else if((c[0] & 192) == 192) {
    utf8_char_size = 2;
  }
  else {
    utf8_char_size = 1;
  }

  for(int i = 0; i < utf8_char_size; ++i) {
    crs::waddch(ncurses_window,
		static_cast<int>(static_cast<unsigned char>(c[i]))
		| (color << 8)
		| (bold << 21)
		| (underline << 17)
		| (reverse << 18));
  }
}
