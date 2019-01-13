//
// Created by groku on 11/01/19.
//

#ifndef DIJKSTRA_HEAP_HPP
#define DIJKSTRA_HEAP_HPP

#include <vector>

template<class D, class V>
#define pair_dv std::pair<D,V>*

class Heap {
protected:
    std::vector<pair_dv> heap;
public:
    int right_child(int i);

    int left_child(int i);

    int parent(int i);

    virtual void insert(pair_dv el);

    virtual pair_dv get_root();

    virtual void heapify_down(int i);

    virtual void heapify_up(int i);
    void show();
    virtual ~Heap(){}
};


#endif //DIJKSTRA_HEAP_HPP

#include "Heap.tpp"