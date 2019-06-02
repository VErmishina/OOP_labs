#include <iostream>
#include <fstream>
#include <string>
#include <tuple>

#include "CSVParser.h"

int main(int argc, char** argv) {
  if (argc != 2){
		std::cout << "Please, enter all arguments" << std::endl;
		return 1;
	}

  std::ifstream csv(argv[1]);
  CSVParser<int, std::string> parse(csv, 0);

  return 0;
}