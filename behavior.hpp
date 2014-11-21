enum Behavior {
  DO_NOTHING,
  QUIT_GAME,
  MENU_UP,
  MENU_DOWN,
  MENU_SELECT
};

const static std::map<const std::string, const Behavior> behavior_map = {
  {"DO_NOTHING", DO_NOTHING},
  {"QUIT_GAME", QUIT_GAME},
  {"MENU_UP", MENU_UP},
  {"MENU_DOWN", MENU_DOWN},
  {"MENU_SELECT", MENU_SELECT},
};

/*
  {"MOVE_UP", MOVE_UP},
  {"MOVE_DOWN", MOVE_DOWN},
  {"MOVE_LEFT", MOVE_LEFT},
  {"MOVE_RIGHT", MOVE_RIGHT},
  {"MOVE_UPLEFT", MOVE_UPLEFT},
  {"MOVE_DOWNLEFT", MOVE_DOWNLEFT},
  {"MOVE_UPRIGHT", MOVE_UPRIGHT},
  {"MOVE_DOWNRIGHT", MOVE_DOWNRIGHT},
*/
