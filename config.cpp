#include "config.h"

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
  
  read_ini(path.string(), vars);
  return;
}

Config::Config(const std::string& config_path) : Config::Config(bfs::path(config_path)) {
}

std::string Config::get(const std::string& key) const {
  return vars.get<std::string>(key);
}
