//
// Created by groku on 10/01/19.
//

#ifndef DIJKSTRA_ADJACENCYLIST_HPP
#define DIJKSTRA_ADJACENCYLIST_HPP

#include <iostream>
#include <vector>
#include "Couple.hpp"

template<class W, class V>
class AdjacencyList {
private:
    std::vector<Couple<W, V > * >a_List;
public:
    void showList();
    void addAdjacency(Couple<W,V> * c );
};


template <class W, class V>
void AdjacencyList<W,V>::showList() {

    typename std::vector< Couple<W,V> *>::iterator it;
    for(it=a_List.begin();it!= a_List.end();++it){
        std::cout <<"("<< (*it)->getVertex()<<" - "<<(*it)->getWeight()<<")";
    }

}
template <class W, class V>
void AdjacencyList<W,V >::addAdjacency(Couple<W,V> *c) {

    a_List.push_back(c);
}

#include "AdjacencyList.tpp"

#endif //DIJKSTRA_ADJACENCYLIST_HPP
