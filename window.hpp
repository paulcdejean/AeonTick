// WARNING!
// Using macros with a namespace wrapped C header is broken.
// It's pretty obvious why that might be.
#undef addch
#undef addchnstr
#undef addchstr
#undef addnstr
#undef addstr
#undef attroff
#undef attron
#undef attrset
#undef attr_get
#undef attr_off
#undef attr_on
#undef attr_set
#undef bkgd
#undef bkgdset
#undef chgat
#undef clear
#undef clrtobot
#undef clrtoeol
#undef color_set
#undef delch
#undef deleteln
#undef echochar
#undef erase
#undef getch
#undef getstr
#undef inch
#undef inchnstr
#undef inchstr
#undef innstr
#undef insch
#undef insdelln
#undef insertln
#undef insnstr
#undef insstr
#undef instr
#undef move
#undef refresh
#undef scrl
#undef setscrreg
#undef standend
#undef standout
#undef timeout
#undef wdeleteln
#undef winsertln

class Window {
 public:
  Window(crs::WINDOW* existing_window);
  Window();
  ~Window();

  int refresh();
  int p(const char* c);
  
 private:
  crs::WINDOW* ncurses_window;
};
