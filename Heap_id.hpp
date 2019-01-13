//
// Created by groku on 12/01/19.
//
#include <iostream>
#include <tr1/unordered_map>
#include "Heap.hpp"
#ifndef DIJKSTRA_HEAP_ID_HPP
#define DIJKSTRA_HEAP_ID_HPP

template <class D,class V>
class Heap_id : public Heap<D,V>{

public:

    std::tr1::unordered_map<V,int> M;
    void heapify_up(int i);

    void heapify_down(int i);
    void insert(pair_dv el);

};

template<class D, class V>
void Heap_id<D, V>::heapify_up(int i) {

}

template<class D, class V>
void Heap_id<D, V>::heapify_down(int i) {

}

template<class D, class V>
void Heap_id<D, V>::insert(std::pair<D, V> *el) {
}


#endif //DIJKSTRA_HEAP_ID_HPP
