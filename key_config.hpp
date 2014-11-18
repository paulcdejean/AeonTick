class KeyConfig : public Config {
public:
  KeyConfig(const bfs::path& config_path);
  KeyConfig(const std::string& config_path);
  const Behavior get_behavior(const Game& the_game, const Key& the_key) const;
};
