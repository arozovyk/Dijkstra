cmake_minimum_required(VERSION 3.12)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Dijkstra
        AdjacencyList.hpp
        AdjacencyList.tpp
        Couple.hpp
        Couple.tpp
        Graph.hpp
        Graph.tpp
        main.cpp
        Vertex.hpp
        Vertex.tpp)
