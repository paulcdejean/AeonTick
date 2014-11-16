#pragma once

#include <string>

#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;

#include "buildvars.h"

class FilePaths {
 public:
  FilePaths();
  bfs::path get_main_config();
 private:
  bfs::path main_config;
};
