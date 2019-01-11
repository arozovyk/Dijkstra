//
// Created by groku on 10/01/19.
//

#ifndef DIJKSTRA_VERTEX_HPP
#define DIJKSTRA_VERTEX_HPP

#include "AdjacencyList.hpp"

template<class W, class T>
class Vertex {
private:
    T id;
    AdjacencyList<W, Vertex<W,T> > * adjList;
public:
    Vertex(); //ATTENTION
    Vertex(T _id);
    T getId();
    void setId(T _id);
    AdjacencyList< W,Vertex<W,T> > * getList();
    template <class SW, class ST>
    friend std::ostream & operator <<( std::ostream &os, const Vertex<SW,ST> & vertex );
};

template<class SW, class ST>
std::ostream & operator <<( std::ostream &os, const Vertex<SW,ST> & vertex ){
   os<<vertex.id;
   return os;
}

template <class W,class T>
Vertex<W,T>::Vertex(T _id) {
    id=_id;
    adjList=new AdjacencyList<W, Vertex<W,T> >();
}
template <class W,class T>
Vertex<W,T>::Vertex() {
    id=0;
    adjList=new AdjacencyList<W, Vertex<W,T> >();
}
#include "Vertex.tpp"


#endif //DIJKSTRA_VERTEX_HPP
