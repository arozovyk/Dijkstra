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

    std::set<std::pair<int, Vertex<W, T> *> *> exec(Vertex<W, T> &);
};

template<class W, class T>
std::set<std::pair<int, Vertex<W, T> *> *> Dijkstra<W, T>::exec(Vertex<W, T> &S) {

    std::set<std::pair<int, Vertex<W, T> *> *> *resultSet = new std::set<std::pair<int, Vertex<W, T> *> *>();
    AdjacencyList<W, Vertex<W, T> *> *adjList = S.getList();
    //adjList->showList();
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
            std::cout << "inserting" << (*(*it)) << std::endl;
            heap->insert(new std::pair<int, Vertex<W, T> *>(INT32_MAX, (*it)));
        }
    }
    for (auto it = vertices->begin(); it != vertices->end(); ++it) {
        std::cout << heap->getValue((*it)) << (*(*it)) << "cyka" << std::endl;
    }
    heap->show();
    int graph_v_size = g->getVerticies()->size(), res_set_size = resultSet->size();
    while (res_set_size != graph_v_size - 1) {
        //dijkstra
        std::pair<int, Vertex<W, T> *> *rootMin = heap->get_root();
        adjList = rootMin->second->getList();
        adjList->showList();
        for (int i = 0; i < adjList->getSize(); ++i) {
            std::pair<int,Vertex<W, T>*> *adj_pair_v_dist = adjList->getEl(i);
            if (!((*adj_pair_v_dist->second) == S)) {

                //not start
                //if(adj_pair_v_dist->first+rootMin->first<=(heap->getValue(adj_pair_v_dist->second)->first )){
                std::cout<<"mis a jour "<<adj_pair_v_dist->first<<std::endl;
                //}

            }
        }

        break;
        //std::cout<< heap->getValue(rootMin->second);
        //std::cout<<INT32_MAX<<std::endl;


    }


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
