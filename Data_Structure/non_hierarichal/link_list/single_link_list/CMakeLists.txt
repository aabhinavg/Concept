cmake_minimum_required(VERSION 3.12)
project(SingleLinkList)

set(CMAKE_CXX_STANDARD 14)

add_executable(SingleLinkList main.cpp SingleLinkList.cpp)  # Create the first executable from main.cpp

# If you want to include headers, you should specify them in the target_include_directories:
target_include_directories(SingleLinkList PRIVATE ${CMAKE_SOURCE_DIR})

