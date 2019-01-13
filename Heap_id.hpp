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
class Heap_id : public Heap<D, V> {

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

};

template<class D, class V>
void Heap_id<D, V>::heapify_up(int i) {

    if (i >= 0 && base_h::parent(i) >= 0 && base_h::heap[base_h::parent(i)]->first > base_h::heap[i]->first) {
        M[base_h::heap[base_h::parent(i)]->second] = i;
        M[base_h::heap[i]->second] = base_h::parent(i);
        pair_dv tmp = base_h::heap[i];
        base_h::heap[i] = base_h::heap[base_h::parent(i)];
        base_h::heap[base_h::parent(i)] = tmp;
        heapify_up(base_h::parent(i));
    }

}

template<class D, class V>
void Heap_id<D, V>::heapify_down(int i) {
    int l_child = base_h::left_child(i);
    int r_child = base_h::right_child(i);

    if (l_child >= 0 && r_child >= 0 && base_h::heap[l_child]->first > base_h::heap[r_child]->first)
        l_child = r_child;

    if (l_child > 0 && base_h::heap[i]->first > base_h::heap[l_child]->first) {

        M[base_h::heap[i]->second] = l_child;
        M[base_h::heap[l_child]->second] = i;
        pair_dv tmp = base_h::heap[i];
        base_h::heap[i] = base_h::heap[l_child];
        base_h::heap[l_child] = tmp;
        heapify_down(l_child);


    }
}

template<class D, class V>
void Heap_id<D, V>::insert(std::pair<D, V> *el) {
    Heap<D, V>::heap.push_back(el);
    M[el->second] = Heap<D, V>::heap.size() - 1;
    heapify_up(Heap<D, V>::heap.size() - 1);
}

template<class D, class V>
std::pair<D, V> *Heap_id<D, V>::get_root() {
    if (base_h::heap.empty())
        return nullptr;
    M[base_h::heap[0]->second] = -1;
    M[base_h::heap[base_h::heap.size() - 1]->second] = 0;
    pair_dv p = base_h::heap.front();
    base_h::heap[0] = base_h::heap.at(base_h::heap.size() - 1);
    base_h::heap.pop_back();
    heapify_down(0);
    return p;
}

template<class D, class V>
int Heap_id<D, V>::getValue(V key) {
        return M[key];
}


#endif //DIJKSTRA_HEAP_ID_HPP
