project(game_of_life)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB CPPS "*.cpp")

add_definitions(-Wall)

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB cell.cpp)
add_library(cell_lib STATIC ${SOURCE_LIB})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED graphics window system)
add_executable(${PROJECT_NAME} ${SOURCE_EXE})
target_link_libraries(${PROJECT_NAME} cell_lib ${SFML_LIBRARIES})
