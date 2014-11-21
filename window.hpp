// WARNING!
// Using macros with a namespace wrapped C header is broken.
// It's pretty obvious why that might be.

class Window {
public:
  Window(crs::WINDOW* existing_window);
  Window();
  ~Window();

  int refresh();
  void p(const char* c, int color=0, bool bold=false, bool underline=false, bool reverse=false);
private:
  crs::WINDOW* ncurses_window;
};
