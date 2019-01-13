//
// Created by groku on 11/01/19.
//

#ifndef DIJKSTRA_GRAPH_HPP
#define DIJKSTRA_GRAPH_HPP

#include "Vertex.hpp"

template<class W, class T>
class Graph {
private:
    std::vector<Vertex<W, T> * >* verticies;
public:
    Graph();
    void addVertex(Vertex<W, T> *src);

    void addEdge(Vertex<W, T> * src, Vertex<W, T> *dst, W value);

    void addArc(Vertex<W, T> * src, Vertex<W, T> *dst, W value);

    void removeVertex(Vertex<W, T> * v_to_remove);

    std::vector<Vertex<W, T> * >* getVerticies();

    void removeEdge(Vertex<W, T> * src, Vertex<W, T> * dst);

    void removeArc(Vertex<W, T> * src, Vertex<W, T> * dst);

    void showGraph();
    ~Graph(){delete verticies;}
};


#endif //DIJKSTRA_GRAPH_HPP

#include "Graph.tpp"