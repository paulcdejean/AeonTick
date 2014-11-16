#pragma once

#include <string>

#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
namespace bpt = boost::property_tree;

#include "buildvars.h"

class Config {
 public:
  Config(const bfs::path& config_path);
  Config(const std::string& config_path);
  std::string get(const std::string& key) const;
 private:
  bfs::path path;
  bpt::ptree vars;
};
