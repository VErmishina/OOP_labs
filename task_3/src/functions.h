std::map <std::string, uint32_t> read_original (std::ifstream& file);

std::vector<std::pair<int32_t, std::string>>& dict read_arch_table (std::ifstream& file);

std::vector<std::pair<int32_t, std::string>> map2vector (std::map <std::string, int32_t>& dictionary);