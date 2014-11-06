#pragma once

#include <string>
#include "window.h"
#include "behavior.h"
#include "key.h"

class KeyConfig {
 public:
  KeyConfig(const std::string& confg_file_maybe);
  Behavior get_behavior(const Window& the_window, const Key& the_key);  
};
