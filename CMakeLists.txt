cmake_minimum_required(VERSION 3.5)
project(ProgrammingLibrary)



INCLUDE_DIRECTORIES(DP
        BinaryTree
        GreedyAlgo
        DataStructure/LinkedList
        STRING
        )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES main.cpp DP/Matrix2D.h
#        DP/MinimumCostPolygonTringulation.h
#        DP/MinimumInitialPointsToReachDestination.h DP/CountOfSumWhoseSumIsN.h
#        DP/CountNumberOfNonDecreasingDigits.h LinkedList/SwapNodes.h TEMPLATE.h Graph/OLD/GRAPH_OLD.h
#        Graph/GRAPH.h Graph/OLD/GraphTraversal.h Graph/GraphOperations.h Graph_Nirav_Template.h Graph/GraphChanged.h BinaryTree/BTree.h DP/DP_Problem_Library.h)

#add_executable(ProblemsImplementation ${SOURCE_FILES}
#        DP/Matrix2D.h
#        DP/MinimumCostPolygonTringulation.h
#        DP/MinimumInitialPointsToReachDestination.h DP/CountOfSumWhoseSumIsN.h
#        DP/CountNumberOfNonDecreasingDigits.h LinkedList/SwapNodes.h TEMPLATE.h Graph/OLD/GRAPH_OLD.h
#        Graph/GRAPH.h Graph/OLD/GraphTraversal.h Graph/GraphOperations.h Graph/Graph_Nirav_Template_backup.h Graph/GraphChanged.h BinaryTree/BTree.h DP/DP_Problem_Library.h)
add_library(GreedyAlgo GreedyAlgo/ActivitySelection.cpp)

set(SOURCE_FILES main.cpp
        DP/DP_Problem_Library.h
        Graph/Graph_Library.h
        Library/TEMPLATE.h
        Library/Utility.h
        )

add_executable(ProgrammingLibrary ${SOURCE_FILES}
        DP/DP_Problem_Library.h
        Graph/Graph_Library.h
        Library/TEMPLATE.h
        Library/Utility.h
        )

#TEMPLATE.h GRAPH.h