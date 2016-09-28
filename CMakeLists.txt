cmake_minimum_required(VERSION 3.5)
project(ProgrammingLibrary)


INCLUDE_DIRECTORIES(DP
        BinaryTree
        GreedyAlgo
        LinkedList
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

set(SOURCE_FILES main.cpp
        DP/BinaryStringWithoutConsicutiveOnes.h)

add_executable(ProgrammingLibrary ${SOURCE_FILES}
        DP/BinaryStringWithoutConsicutiveOnes.h)

#TEMPLATE.h GRAPH.h