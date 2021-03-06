#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
namespace bpt = boost::property_tree;

#include "buildvars.hpp"

#include "config.hpp"

Config::Config(const bfs::path& config_path) {
  if(config_path.is_absolute()) {
    path = config_path;
  }
  else if(BuildVars::sysconfdir.is_absolute()) {
    path = BuildVars::sysconfdir / config_path;
  }
  else {
    path = BuildVars::install_prefix / BuildVars::sysconfdir / config_path;
  }
  
  bpt::read_ini(path.string(), vars);
  return;
}

Config::Config(const std::string& config_path) : Config::Config(bfs::path(config_path)) {
}

std::string Config::get(const std::string& key) const {
  return vars.get<std::string>(key);
}
