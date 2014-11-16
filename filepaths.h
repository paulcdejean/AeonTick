#pragma once

#include <string>

#include <boost/filesystem.hpp>

namespace bfs = boost::filesystem;

class FilePaths {
 public:
  bfs::path get_main_config();
};
