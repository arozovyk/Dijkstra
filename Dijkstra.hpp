//
// Created by groku on 12/01/19.
//

#ifndef DIJKSTRA_DIJKSTRA_HPP
#define DIJKSTRA_DIJKSTRA_HPP

#include <set>
#include "Graph.hpp"
#include "Heap_id.hpp"


template<class W, class T>
class Dijkstra {
private:
    Graph<W, T> *g;
    Heap_id<W, Vertex<W, T> *> *heap;
public:
    Dijkstra();
    Dijkstra(Graph<W, T> *);
    std::set<std::pair<W, Vertex<W, T> *> *> *exec(Vertex<W, T> &);
    ~Dijkstra(){delete heap; }
};

#include "Dijkstra.tpp"




#endif //DIJKSTRA_DIJKSTRA_HPP
