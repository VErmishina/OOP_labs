project(Integrate)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB CPPS "*.cpp")

add_definitions(-Wall)

set(SOURCE_EXE main.cpp)

find_package(GTest REQUIRED)
add_executable(${PROJECT_NAME} ${SOURCE_EXE})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
