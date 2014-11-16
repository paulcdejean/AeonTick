#pragma once

#include <boost/program_options.hpp> 
namespace bpo = boost::program_options;

#include <string>

#include "window.h"
#include "behavior.h"
#include "key.h"
#include "buildvars.h"

class KeyConfig {
 public:
  KeyConfig();
  Behavior get_behavior(const Window& the_window, const Key& the_key);
 private:
  bpo::variables_map vars;
};
