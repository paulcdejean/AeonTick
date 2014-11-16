#pragma once

#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;

class BuildVars {
 public:
  static const bfs::path sysconfdir;
  static const bfs::path mainconfig_filename;
  static const bfs::path install_prefix;
  static const bfs::path keyconfig_filename;
};
