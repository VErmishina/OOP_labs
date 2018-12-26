#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
#include <stdlib>

int byte_size;

std::map <std::string, uint32_t> read_original (std::ifstream& file);

std::vector<std::pair<int32_t, std::string>>& dict read_arch_table (std::ifstream& file);

std::vector<std::pair<int32_t, std::string>> map2vector (std::map <std::string, int32_t>& dictionary);

std::vector<Data> symbols2table (std::vector<std::pair<int32_t, std::string>>& dict);

void write2arch (std::ofstream& output, std::vector<Data> table);

void write_restore (std::ofstream& output, std::vector<Data> table);

std::vector<bool> code_by_symbol(std::string symbol, std::vector<Data> table);

int bool2int (std::vector<bool> byte);

void write2arch (std::ifstream& in_file, std::ofstream& out_file, std::vector<Data>& table);

std::vector<bool> code_by_char (char my_char);