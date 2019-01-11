//
// Created by groku on 11/01/19.
//

#ifndef DIJKSTRA_GRAPH_HPP
#define DIJKSTRA_GRAPH_HPP

#include "Vertex.hpp"

template<class W, class T>
class Graph {
private:
    std::vector<Vertex<W, T> > verticies;
public:
    void addVertex(Vertex<W, T> src);

    void addEdge(Vertex<W, T> src, Vertex<W, T> dst, W value);

    void addArc(Vertex<W, T> src, Vertex<W, T> dst);

    void removeVertex(Vertex<W, T> v_to_remove);

    void removeEdge(Vertex<W, T> src, Vertex<W, T> dst);

    void removeArc(Vertex<W, T> src, Vertex<W, T> dst);

    void showGraph();
};

template<class W, class T>
void Graph<W, T>::addVertex(Vertex<W, T> to_add) {
    //if (! std::find(verticies.begin(), verticies.end(), to_add)) {
        verticies.push_back(to_add);
    //}
}

template<class W, class T>
void Graph<W, T>::addArc(Vertex<W, T> src, Vertex<W, T> dst) {

}

template<class W, class T>
void Graph<W, T>::addEdge(Vertex<W, T> src, Vertex<W, T> dst, W value) {
    src.getList()->addAdjacency( new Couple<W, Vertex<W,T>> (dst,value));
    dst.getList()->addAdjacency( new Couple<W, Vertex<W,T>> (src,value));
}


template<class W, class T>
void Graph<W, T>::removeEdge(Vertex<W, T> src, Vertex<W, T> dst) {

}

template<class W, class T>
void Graph<W, T>::removeVertex(Vertex<W, T> v_to_remove) {

}

template<class W, class T>
void Graph<W, T>::removeArc(Vertex<W, T> src, Vertex<W, T> dst) {

}

template<class W, class T>
void Graph<W, T>::showGraph() {
    typename std::vector <  Vertex<W,T> >::iterator it;
    for( it=verticies.begin();it!=verticies.end();++it){
        std::cout<< (*it).getId()<<":";
        (*it).getList()->showList();
        std::cout << std::endl;
    }
}

#endif //DIJKSTRA_GRAPH_HPP