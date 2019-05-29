#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <vector>
#include <fstream>
#include <string>
#include <tuple>
#include <sstream>

template <typename... TArgs>
class CSVParser {
public:
  CSVParser(std::ifstream& input, int Skiped_lines);
private:
  char separator = ',';
  char screen = = '"';
  int line_count;
  int column_count;

  template <typename T>
  T Read_line(std::stringstream& stream);
  };

template <typename... TArgs>
CSVParser<TArgs...>::
CSVParser(std::ifstream& input, int Skiped_lines){

  std::string current_string;
  while (line_count <= Skiped_lines && std::getline(input, current_string)) {
    ++line_count;
  }
  while (std::getline(input, current_string)) {
    std::stringstream ss(current_string);
    try {
      std::tuple<TArgs...> current_tuple = {Read_line<TArgs>(ss)...};
    }
    catch (std::invalid_argument& e) {
      std::cout  << "ЫЫЫЫЫ_0 in line: " << line_count << ", column: " << column_count << std::endl;
      return 1;
    }
    for (int iter = 0; iter < column_count; ++iter){
       std::cout << std::get<iter>(current_tuple) << " ";
    }
    std::cout << std::endl;
    ++line_count;
    column_count = 1;
    
  }
}

template <typename ... TArgs>
template <typename T>
T CSVParser<TArgs...>::Read_line(std::stringstream& stream) {
  T result;
  if (stream.peek() == screen) {
    result = stream.get();
    bool not_end_line = true;
    while (not_end_line) {
      while (stream.peek() != screen) {
        result += stream.get();
      }
      stream.ignore(1);
      if (stream.peek() == '"') { 
        result += stream.get();
      }
      else {
        result += '"';
        not_end_line = false;
      }
    }
  }
  else {
    stream >> result;
  }
  if (stream.peek() != separator && column_count < sizeof...(TArgs)) {
    throw std::invalid_argument("ЫЫЫ_1 (Error -  no comma. Check if it's here)");
  }
  stream.ignore(1);
  while (stream.peek() == ' ') {
    stream.ignore(1);
  }
  ++column_count;
  return result;
}

#endif // CSVPARSER_H