cmake_minimum_required(VERSION 3.12)
project(ExpressionParser)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExpressionParser src/main.cpp src/ExpressionParser.cpp)

target_include_directories(ExpressionParser PRIVATE include)

