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
  //return behavior_map.at("QUIT_GAME");
  return QUIT_GAME;
}
