#include "buildvars.h"

const bfs::path BuildVars::sysconfdir = "@SYSCONFDIR@";
const bfs::path BuildVars::mainconfig_filename = "@MAINCONFIG_FILENAME@";
const bfs::path BuildVars::install_prefix = "@CMAKE_INSTALL_PREFIX@";