cmake_minimum_required(VERSION 3.8)
project(AdjacencyList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AdjMGraph.cpp AdjMGraph.h)
add_executable(AdjacencyList ${SOURCE_FILES} AdjMGraph.cpp AdjMGraph.h)