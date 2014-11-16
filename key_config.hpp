#pragma once

#include "config.hpp"
#include "window.hpp"
#include "key.hpp"
#include "behavior.hpp"

class KeyConfig : public Config {
  Behavior get_behavior(const Window& the_window, const Key& the_key) const;
};
