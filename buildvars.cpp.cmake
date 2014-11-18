#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;

#include "buildvars.hpp"

const bfs::path BuildVars::sysconfdir = "@SYSCONFDIR@";
const bfs::path BuildVars::mainconfig_filename = "@MAINCONFIG_FILENAME@";
const bfs::path BuildVars::install_prefix = "@CMAKE_INSTALL_PREFIX@";
const bfs::path BuildVars::keyconfig_filename = "@KEYCONFIG_FILENAME@";
