#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
#include "words_counter.h"


bool separate(char& symbol) {  
    return (!(std::isalpha(symbol) || std::isdigit(symbol)));
}

std::map <std::string, int32_t> read_file (std::ifstream& file){  
	std::map <std::string, int32_t> dictionary;
	if (file.is_open()) {
		std::string curr_word = ""; 
		while(!file.eof()) {  
			char symbol = file.get();
			if (separate(symbol)) {
				++ dictionary[curr_word]; 
				curr_word = "";   
			}
			else {
				curr_word = curr_word+symbol;				
			}
		}

	dictionary.erase(""); /*delete empty words from map*/ 
	}
	else { 
		std::cout << "Can't open input file" << std::endl;
	}
	return dictionary;
}
/*rewrite map to vector of pairs*/
void map2vector(std::map <std::string, int32_t>& dictionary, 
		std::vector<std::pair<int32_t, std::string>>& dict,
		int& total_count, int& words_number){
	std::pair<int32_t, std::string> temp;
	for(auto it = dictionary.begin(); it != dictionary.end(); ++it) {
		temp.first = it->second;
		temp.second = it->first;
		dict.push_back(temp);
		words_number ++;
		total_count = total_count + temp.first;
	}
	std::sort(dict.begin(),dict.end());
}

void write_to_output (std::ofstream& output, std::map<std::string, int32_t>& dictionary){
	std::vector<std::pair<int32_t, std::string>> dict;
	int total_count = 0;
	int words_number = 0;

	map2vector(dictionary, dict, total_count, words_number);
	
	for (int i = 1; i <= words_number; ++i) { 
		
		output << (dict[words_number - i]).second << ", " << 
			(dict[words_number - i]).first << ", " << 
			(double)dict[words_number - i].first * 100 / total_count <<
			"%" << std::endl;
	}
}


