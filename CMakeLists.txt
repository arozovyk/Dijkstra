cmake_minimum_required(VERSION 3.13)
project(lala11)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lala11
        AdjacencyList.hpp
        Dijkstra.tpp
        Dijkstra.hpp
        Graph.hpp
        Heap.hpp
        Heap_id.tpp
        Heap_id.hpp
        main.cpp
        Vertex.hpp)
