#pragma once

#include <string>

#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
namespace bpt = boost::property_tree;

class Config {
 public:
  Config(const bfs::path& config_path);
  bpt::ptree vars;
};
