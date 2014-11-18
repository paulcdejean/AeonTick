class Config {
public:
  Config(const bfs::path& config_path);
  Config(const std::string& config_path);
  std::string get(const std::string& key) const;
private:
  bfs::path path;
  bpt::ptree vars;
};
