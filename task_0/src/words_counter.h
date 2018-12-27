#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>

/*Check if symbol is separator*/
bool separate(char& symbol);

/*reading text from inpit file*/
std::map <std::string, int32_t> read_file (std::ifstream& file);

/*Convert map to vector and sort*/
void map2vector (std::map <std::string, int32_t>& dictionary, std::vector<std::pair<int32_t, std::string>>& dict,
				int& total_count, int& words_number);

/*writing to output*/
void write_to_output (std::ofstream& output, std::map<std::string, int32_t>& dictionary);