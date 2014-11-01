#include <ncurses.h>

int main() {
  int ch;

  initscr();
  raw();    
  noecho();
  keypad(stdscr, TRUE);
  set_escdelay(-1);

  ch = getch();
  while(true) {
    if(ch == 3) {
      break;
    }
    printw("The pressed key is ");
    attron(A_BOLD);
    printw("%i %c \n", ch, ch);
    attroff(A_BOLD);
    refresh();
    ch = getch();
  }
  endwin();
  return 0;
}
