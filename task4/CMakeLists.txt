project(CSVParser)
cmake_minimum_required(VERSION 2.8)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_definitions(-Wall)


add_executable(${PROJECT_NAME} CSVParser.h main.cpp)
