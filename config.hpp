class Config {
public:
  Config(const bfs::path& config_path);
  Config(const std::string& config_path);
  std::string get(const std::string& key) const;
protected:
  bpt::ptree vars;
private:
  bfs::path path;
};
