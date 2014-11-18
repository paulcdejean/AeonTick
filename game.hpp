class Game {
 public:
  Game(Window starting_window);
  const Window& current_window();
  void run(Behavior action);
  
 private:
  Window some_window;
};
