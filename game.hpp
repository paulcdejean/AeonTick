class Game {
 public:
  Game(Window starting_window);
  void run(Behavior action);
  
 private:
  void draw_main_menu(Window& mm_window);
  Window main_menu;
};
