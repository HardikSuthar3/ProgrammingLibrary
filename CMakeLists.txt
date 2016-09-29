cmake_minimum_required(VERSION 3.5)
project(ProgrammingLibrary)



INCLUDE_DIRECTORIES(
        Library
        Library/DP
        Library/GraphLibrary
        DataStructure/BinaryTree
        DataStructure/LinkedList
        Greedy
        STRING
        )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES main.cpp
        Library/DP_Problem_Library.h
        Library/Graph_Library.h
        Library/TEMPLATE.h
        Library/Utility.h
        Library/Graph_Structure.h
        Library/GraphLibrary/Graph_Structure.h Library/GraphLibrary/DFS.h Library/GraphLibrary/BFS.h Library/GraphLibrary/Shortest_Path_Using_BFS.h Library/GraphLibrary/Topological_Ordering.h Library/GraphLibrary/DetectCycle_Using_Union_Find.h Library/GraphLibrary/M_Coloring_Problem.h Library/GraphLibrary/Minimum_Spanning_Tree.h Library/GraphLibrary/Shortest_Path_Algorithms.h Library/GraphLibrary/Strongly_Connected_Components.h "Library/GraphLibrary/Detect_Eular_Path.h" Library/GraphLibrary/Maximim_Flow.h STRING/String_Split.h DataStructure/BinaryTree/BinaryTreeStructure.h)

add_executable(ProgrammingLibrary ${SOURCE_FILES}
        Library/DP_Problem_Library.h
        Library/Graph_Library.h
        Library/TEMPLATE.h
        Library/Utility.h
        Library/Graph_Structure.h
        Library/GraphLibrary/Graph_Structure.h Library/GraphLibrary/DFS.h Library/GraphLibrary/BFS.h Library/GraphLibrary/Shortest_Path_Using_BFS.h Library/GraphLibrary/Topological_Ordering.h Library/GraphLibrary/DetectCycle_Using_Union_Find.h Library/GraphLibrary/M_Coloring_Problem.h Library/GraphLibrary/Minimum_Spanning_Tree.h Library/GraphLibrary/Shortest_Path_Algorithms.h Library/GraphLibrary/Strongly_Connected_Components.h "Library/GraphLibrary/Detect_Eular_Path.h" Library/GraphLibrary/Maximim_Flow.h STRING/String_Split.h DataStructure/BinaryTree/BinaryTreeStructure.h)

