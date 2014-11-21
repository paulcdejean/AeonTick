#include <map>
#include <string>

namespace crs {
#include <ncurses.h>
}

#include "behavior.hpp"
#include "window.hpp"

#include "game.hpp"

void Game::draw_main_menu(Window& mm_window) {
  mm_window.p("ＡＢＣＤＥＦＧＨＩＪ", 0, 0);
}

Game::Game(Window starting_window) {
  // Ok this one is going to be a dozy.
  // This constructor is going to initalize ALL THE THINGS.
  // There's no way around that.
  // It could potentially take a noticable amount of time to initialize all the things.
  // However we are still going to have the initalization block the rest of the program.
  // Opening the ansync thread of worms is NOT worth it.
  // The only advantage would be that the user could screw around on the menu before the game is loaded.
  // There's nothing of substance you can do before the game is loaded anyway.
  // So accepting keyboard input before the game is loaded really is no big deal.
  // What we can do, is have multiple refreshes take place during this call.
  // Using this we can have a loading bar type thing down the line potentially.
  // Other operations (worldgen etc) could also potentially take a noticable amount of time to run.
  // Those operations will be refered here, which is where the approach behind non instant stuff is detailed.

  main_menu = starting_window;
  draw_main_menu(main_menu);

  // Calls to refresh are done explicitly outside of drawing functions.
  // Having refreshes inside of drawing functions would make drawing animations and similar possible.
  // However animations of that sort would block input, which would make the game feel a lot less responsive.
  // Calling refresh inside of a drawing function could lead to a situation like this:
  // Crawl's auto explore by default will animate every frame.
  // This sounds nice and you see an animation of your character exploring.
  // In practice though, it slows down gameplay a lot, and I disable it every time.
  // Code to disable it could be hard though if we have refresh calls all over the place.
  main_menu.refresh();
}

void Game::run(Behavior action) {
  switch(action) {
    case QUIT_GAME: {
      crs::endwin();
      break;
    }
    case DO_NOTHING: {
      break;
    }
    default: {
      throw std::runtime_error("Behavior not implemented.");
      return;
    }
  }
}
