cmake_minimum_required(VERSION 3.12)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Dijkstra
        AdjacencyList.hpp
        AdjacencyList.tpp
        Graph.hpp
        Graph.tpp
        main.cpp
        Vertex.hpp
        Vertex.tpp Heap.tpp Heap.hpp Dijkstra.cpp Dijkstra.hpp Heap_id.cpp Heap_id.hpp)
