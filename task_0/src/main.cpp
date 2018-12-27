#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cstdint>
#include "words_counter.h"

int main(int argc, char** argv)
{

	if (argc != 3){
		std::cout << "Please, enter all arguments" << std::endl;
		return 1;
	}

	std::ifstream input (argv[1], std::ios::in);
	std::ofstream output (argv[2], std::ios::out);

	auto my_dictionary = read_file(input);
	write_to_output (output, my_dictionary);


	
	return 0;
}