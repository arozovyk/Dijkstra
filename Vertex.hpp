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
    AdjacencyList<W, Vertex<W,T>* > * adjList;
public:
    Vertex(); //ATTENTION
    Vertex(T _id);
    T getId() const{
        return id;
    };

    void setId(T _id);
    AdjacencyList< W,Vertex<W,T>* > * getList();
    template <class SW, class ST>
    friend std::ostream & operator <<( std::ostream &os, const Vertex<SW,ST> & vertex );
    bool operator==(const Vertex& other) const
    {
        return ((*this).id==other.id);
    }

};


#include "Vertex.tpp"


#endif //DIJKSTRA_VERTEX_HPP
