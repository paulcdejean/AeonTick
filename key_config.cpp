#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
namespace bpt = boost::property_tree;

#include <map>
#include <string>

namespace crs {
#include <ncurses.h>
}

namespace ltk {
#include "libtermkey-0.17/termkey.h"
}

#include "termkey.hpp"
#include "window.hpp"

#include "key.hpp"
#include "behavior.hpp"
#include "config.hpp"
#include "game.hpp"

#include "key_config.hpp"

KeyConfig::KeyConfig(const bfs::path& config_path)
  : Config(config_path) {
}

KeyConfig::KeyConfig(const std::string& config_path)
  : Config(config_path) {
}

const Behavior KeyConfig::get_behavior(const Game& the_game, const Key& the_key) const {
  // For now we are totally ignoring the game state and returning based on the key alone.
  // For the future the only part of the game state we're interested in might be the window.
  // No way to know for sure though, so we just pass the whole game state.
  
  bpt::ptree::path_type main_menu = "main_menu";
  std::string behavior_string = vars.get<std::string>(main_menu / the_key.cstr(), "DO_NOTHING");
  return behavior_map.at(behavior_string);
}
