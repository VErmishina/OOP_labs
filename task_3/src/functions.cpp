int byte_size = 8;

std::map <std::string, uint32_t> read_original (std::ifstream& in_file)
{  
	std::map <std::string, uint32_t> dictionary;
	if (in_file.is_open()) {
		std::string curr_symbol = ""; 
		while(!in_file.eof()) {  
			char symbol = in_file.get();
			curr_symbol = symbol;   
			++ dictionary[curr_symbol]; 
			curr_symbol = "";  
		}
	}
	else { 
		std::cout << "Can't open input file (Original)" << std::endl;
	}
	return dictionary;
}

std::vector<std::pair<int32_t, std::string>>& dict read_arch_table (std::ifstream& in_file)
{  
	std::vector<std::pair<int32_t, std::string>>& dict;
	std::pair<int32_t, std::string> temp;
	if (in_file.is_open()) {
		int table_size;
		in_file >> table_size;
		std::string curr_symbol = ""; 
		for (int i = 0; i < table_size; ++i) {  
			char symbol = in_file.get();
			temp.second = symbol; /*read symbol*/
			in_file >> temp.first; /*read its frequency*/
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
	std::sort(dict.begin(),dict.end()); /*sort from */
	return dict;
}

std::vector<Data> symbols2table (std::vector<std::pair<int32_t,
					  std::string>>& dict)
{
	std::vector<Data> table;
	Data() temp;
	for(auto it = dict.begin(); it != dict.end(); ++it){
		temp.set_s(it.second);
		temp.set_f(it.first);
		table.push_back(temp);
	}
	table.erase(table.begin());
}

std::vector<bool> code_by_symbol(std::string symbol, std::vector<Data> table)
{
	std::vector<bool>  temp;
	for(uint32_t i = 0; i < table.size; ++i){
		if (table[i].symbol_ == symbol){
			temp = table[i].code_;
			i = table.size;
		}
	}
	return temp;
}

int bool2int (std::vector<bool> byte)
{
	int result = 0;
	for (int i = byte.size - 1; i = 0; --i){
		if (byte[i]){
			result += pow(2,i);
		}
	}
	return result;
}

void write2arch (std::ifstream& in_file, std::ofstream& out_file, std::vector<Data>& table)
{
	in_file.clear(); in_file.seekg(0);
	out_file << table.size << " ";
	for (uint32_t i = 0; i < table.size; ++i){
		out_file << table[i].symbol_ << " " <<
			   table[i].frequency_ << " ";
	}
	std::string curr_symbol = "";
	std::vector<bool> buffer;
	std::vector<bool> byte_code;
	int32_t
	while(!in_file.eof()) {
		char symbol = in_file.get();
		if (symbol != EOF){
			curr_symbol = symbol;
			auto curr_code = code_by_symbol(curr_symbol);
			buffer.insert(buffer.end(), curr_code.begin(), curr_code.end());
			if (buffer.size >= byte_size){
				std::vector<bool> byte_code;
				byte_code.insert(buffer.begin(), buffer.begin()+byte_size); 
				buffer.erase(buffer.begin(), buffer.begin()+byte_size);
				char out = itoa(bool2int(byte_code));
				out_file << out;
			}
		} else {
			in_file.eof() = true;
			int extra = (byte_size - buffer.size) % byte_size;
			if (extra >0){
				buffer.insert(buffer.end(), extra, 0);
			}
			char out = itoa(bool2int(buffer));
			out_file << out << " " << extra;
		}	
	}
}


std::vector<bool> code_by_char (char my_char)
{
	int int_code = atoi(my_char);
	std::vector<bool> new_code;
	for (int k = 0; k < byte_size; ++k){
		new_code[byte_size - k -1] = int_code % 2;
		int_code = int_code / 2;
	}
	return new_code;
}


void unarch (std::ifstream& in_file, std::ofstream& out_file, std::vector<Data>& table)
{
	//in_file.clear(); in_file.seekg(0);
	
	auto arch_pairs = read_arch_table (std::ifstream& in_file);
	auto table =  symbols2table (arch_pairs);
	auto my_tree = Create_Tree(arch_pairs);
	while
	char symbol = in_file.get();


}