//
// Created by groku on 12/01/19.
//
#include <iostream>
#include <unordered_map>
#include "Heap.hpp"

#define base_h Heap<D,V>
#ifndef DIJKSTRA_HEAP_ID_HPP
#define DIJKSTRA_HEAP_ID_HPP

template<class D, class V>
class Heap_id :  public Heap<D, V> {

public:

    std::unordered_map<V, int> M;

    pair_dv get_root();

    void heapify_up(int i);

    void heapify_down(int i);

    void insert(pair_dv el);

    int getValue(V key);
    pair_dv getPair(int i){
        return Heap<D,V>::heap[i];
    }
    ~Heap_id() {}

};


#endif //DIJKSTRA_HEAP_ID_HPP

#include "Heap_id.tpp"