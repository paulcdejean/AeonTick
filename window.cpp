#include "window.hpp"

Window::Window(crs::WINDOW* existing_window) : ncurses_window(existing_window) {}

Window::Window() {
  this->ncurses_window = crs::newwin(0, 0, 0, 0);
}

Window::~Window() {
  crs::delwin(this->ncurses_window);
}

void Window::refresh() {
  crs::wrefresh(this->ncurses_window);
}
