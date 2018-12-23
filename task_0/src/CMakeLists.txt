project(word_count)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB CPPS "*.cpp")

add_definitions(-Wall)

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB words_counter.cpp)
add_library(count_lib STATIC ${SOURCE_LIB})

add_executable(${PROJECT_NAME} ${SOURCE_EXE})
target_link_libraries(${PROJECT_NAME} count_lib )