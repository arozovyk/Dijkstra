//
// Created by groku on 12/01/19.
//

#ifndef DIJKSTRA_DIJKSTRA_HPP
#define DIJKSTRA_DIJKSTRA_HPP

#include <set>
#include "Graph.hpp"
#include "Heap_id.hpp"


template<class W, class T>
class Dijkstra {
private:
    Graph<W, T> *g;
    Heap_id<int, Vertex<W, T> *> *heap;
public:
    Dijkstra();

    Dijkstra(Graph<W, T> *);

    std::set<std::pair<int, Vertex<W, T> *> *> * exec(Vertex<W, T> &);
};

template<class W, class T>
std::set<std::pair<int, Vertex<W, T> *> *> * Dijkstra<W, T>::exec(Vertex<W, T> &S) {

    auto *resultSet = new std::set<std::pair<int, Vertex<W, T> *> *>();
    AdjacencyList<W, Vertex<W, T> *> *adjList = S.getList();
    int adjSize = adjList->getSize();
    for (int i = 0; i < adjSize; ++i) {
        std::pair<int, Vertex<W, T> *> *adjNode = adjList->getEl(i);
        if (resultSet->find(adjList->getEl(i)) == resultSet->end())
            heap->insert(adjNode);
    }

    //distances maxint for {V}\{S}U{adj(S)}
    //
    std::vector<Vertex<W, T> *> *vertices = g->getVerticies();
    for (auto it = vertices->begin(); it != vertices->end(); ++it) {
        //if not in ajd(S) and not S
        if (!adjList->containsVertex((*it)) && !((*(*it)) == S)) {
            heap->insert(new std::pair<int, Vertex<W, T> *>(INT32_MAX, (*it)));
        }
    }

    long graph_v_size = g->getVerticies()->size(), res_set_size = resultSet->size();

    while (res_set_size != graph_v_size - 1) {
        //dijkstra

        std::pair<int, Vertex<W, T> *> *rootMin = heap->get_root();
        adjList = rootMin->second->getList();

        for (int i = 0; i < adjList->getSize(); ++i) {
             std::pair<int,Vertex<W, T>*> *adj_pair_v_dist = adjList->getEl(i);

            bool pair_is_in_result= false;
            for(auto it=resultSet->begin();it!=resultSet->end();++it)
                if(*(*it)->second==*adj_pair_v_dist->second)
                    pair_is_in_result=true;

            if (!((*adj_pair_v_dist->second) == S) && !pair_is_in_result) {
                int index_heap=heap->getValue(adj_pair_v_dist->second);
                std::pair<int,Vertex<W, T>*> *heapPair=heap->getPair(index_heap);

                if(adj_pair_v_dist->first+rootMin->first<=heapPair->first){
                    heapPair->first=adj_pair_v_dist->first+rootMin->first;
                    heap->heapify_up(heap->getValue(heapPair->second));
                }
            }
        }
        resultSet->insert(rootMin);
        res_set_size++;


    }
    return resultSet;
}


template<class W, class T>
Dijkstra<W, T>::Dijkstra() {
    heap = new Heap_id<int, Vertex<W, T> *>();
}

template<class W, class T>
Dijkstra<W, T>::Dijkstra(Graph<W, T> *_g) {
    (*this).g = _g;
    heap = new Heap_id<int, Vertex<W, T> *>();
}


#endif //DIJKSTRA_DIJKSTRA_HPP
