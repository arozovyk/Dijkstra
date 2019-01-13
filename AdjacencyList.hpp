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
    std::vector< std::pair<W, V> * > *a_List;
public:
    AdjacencyList();
    void showList();
    std::pair<W, V> * getEl(int i);
    void addAdjacency(std::pair<W, V> * );
    int getSize(){
        return a_List->size();
    }
    bool containsVertex(V vert);
    void remove(V vert);
};


template <class W, class V>
void AdjacencyList<W,V>::showList() {

    typename std::vector< std::pair<W,V>*>::iterator it;
    for(it=a_List->begin();it!= a_List->end();++it){
        std::cout <<"("<< *(*it)->second <<" - "<<(*it)->first<<")";
    }
}

template <class W, class V>
void AdjacencyList<W,V >::addAdjacency(std::pair<W, V> * p) {
    a_List->push_back(p);
}

template<class W, class V>
std::pair<W, V> *AdjacencyList<W, V>::getEl(int i) {
    return (*a_List)[i];
}

template<class W, class V>
bool AdjacencyList<W, V>::containsVertex(V vert) {
    for(auto it=a_List->begin();it!=a_List->end();++it){
        if((*it)->second==vert)//PEUT ETRE FAUX
            return true;

    }
    return false;
}

template<class W, class V>
void AdjacencyList<W, V>::remove(V  vert) {
    int i=0;
    for(auto it=a_List->begin();it!=a_List->end();++it)
        if((*((*it)->second))==*vert)break;
        else
            i++;
    a_List->erase(a_List->begin()+i);

}

template<class W, class V>
AdjacencyList<W, V>::AdjacencyList() {
    a_List=new std::vector< std::pair<W, V> * >();

}

#include "AdjacencyList.tpp"
#endif //DIJKSTRA_ADJACENCYLIST_HPP
