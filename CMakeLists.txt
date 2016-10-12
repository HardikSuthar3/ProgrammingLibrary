cmake_minimum_required(VERSION 3.5)
project(ProgrammingLibrary)


#INCLUDE_DIRECTORIES(
#        Library
#        Library/DP
#        Library/GraphLibrary
#        DataStructure/BinaryTree
#        DataStructure/LinkedList
#        Greedy
#        STRING
#        DataStructure/Array
#)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES main.cpp STRING/StringPermutaitons.h)

add_executable(ProgrammingLibrary ${SOURCE_FILES})

