std::map <std::string, uint32_t> read_original (std::ifstream& file)
{  
	std::map <std::string, uint32_t> dictionary;
	if (file.is_open()) {
		std::string curr_symbol = ""; 
		while(!file.eof()) {  
			char symbol = file.get();
			curr_symbol = symbol;   /*Check that it's correct*/
			++ dictionary[curr_symbol]; 
			curr_symbol = "";  /*Is it needed?*/  
			}
		}
	}
	else { 
		std::cout << "Can't open input file (Original)" << std::endl;
	}
	return dictionary;
}

std::vector<std::pair<int32_t, std::string>>& dict read_arch_table (std::ifstream& file)
{  
	std::vector<std::pair<int32_t, std::string>>& dict;
	std::pair<int32_t, std::string> temp;
	if (file.is_open()) {
		int table_size;
		file >> table_size;
		std::string curr_symbol = ""; 
		for (int i = 0; i < table_size; ++i) {  
			char symbol = file.get();
			temp.second = symbol; /*read symbol*/
			file >> temp.first; /*read frequency*/
			dict.push_back(temp);
		}
	dict.erase(dict.begin());	/*erase auto-created element*/
	}
	else { 
		std::cout << "Can't open input file (Archived)" << std::endl;
	}
	return dict;
}

std::vector<std::pair<int32_t, std::string>> map2vector (std::map <std::string, int32_t>& dictionary)
{
	std::vector<std::pair<int32_t, std::string>> dict;
	std::pair<int32_t, std::string> temp;
	for(auto it = dictionary.begin(); it != dictionary.end(); ++it) {
		temp.first = it->second;
		temp.second = it->first;
		dict.push_back(temp);
	}
	dict.erase(dict.begin());	/*erase auto-created element*/
	return dict;
}

