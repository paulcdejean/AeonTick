#include "filepaths.h"

FilePaths::FilePaths() : main_config() {
}

bfs::path FilePaths::get_main_config() {
  if(not this->main_config.empty()) {
    return main_config;
  }
  else {
    if(bfs::path(BuildVars::mainconfig_filename).is_absolute()) {
      main_config = BuildVars::mainconfig_filename;
      return main_config;
    }
    else if(bfs::path(BuildVars::sysconfdir).is_absolute()) {
      this->main_config = BuildVars::sysconfdir / BuildVars::mainconfig_filename;
      return main_config;
    }
    else {
      this->main_config = BuildVars::install_prefix / BuildVars::sysconfdir / BuildVars::mainconfig_filename;
      return main_config;
    }
  }
}
