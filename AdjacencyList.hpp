//
// Created by groku on 10/01/19.
//

#ifndef DIJKSTRA_ADJACENCYLIST_HPP
#define DIJKSTRA_ADJACENCYLIST_HPP

#include <iostream>
#include <vector>

template<class W, class V>
class AdjacencyList {
private:
    std::vector< std::pair<W, V> * >a_List;
public:
    void showList();
    void addAdjacency(std::pair<W, V> * );
};


template <class W, class V>
void AdjacencyList<W,V>::showList() {

    typename std::vector< std::pair<W,V>*>::iterator it;
    for(it=a_List.begin();it!= a_List.end();++it){
        std::cout <<"("<< (*it)->second<<" - "<<(*it)->first<<")";
    }
}

template <class W, class V>
void AdjacencyList<W,V >::addAdjacency(std::pair<W, V> * p) {
    a_List.push_back(p);
}

#include "AdjacencyList.tpp"
#endif //DIJKSTRA_ADJACENCYLIST_HPP
