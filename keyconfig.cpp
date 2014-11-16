#include "keyconfig.h"

KeyConfig::KeyConfig() {
  return;
}

Behavior KeyConfig::get_behavior(const Window& the_window, const Key& the_key) {
 return MOVE_UP;
}
