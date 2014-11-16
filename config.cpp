#include "config.h"

Config::Config(const bfs::path& config_path) {
  read_ini(config_path.string(), this->vars);
  return;
}
