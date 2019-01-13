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


namespace std {
        template <class W,class T>
        struct hash<Vertex<W,T>*>
        {
            std::size_t operator()(const Vertex<W,T>* k) const
            {
                using std::hash;
                return hash<T>()(k->getId());
            }
        };
}


template<class SW, class ST>
std::ostream & operator <<( std::ostream &os, const Vertex<SW,ST> & vertex ){
   os<<vertex.getId();
   return os;
}

template <class W,class T>
Vertex<W,T>::Vertex(T _id) {
    id=_id;
    adjList=new AdjacencyList<W, Vertex<W,T> *>();
}
template <class W,class T>
Vertex<W,T>::Vertex() {
    adjList=new AdjacencyList<W, Vertex<W,T>* >();
}
#include "Vertex.tpp"


#endif //DIJKSTRA_VERTEX_HPP
