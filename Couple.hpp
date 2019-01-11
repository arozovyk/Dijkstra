//
// Created by groku on 10/01/19.
//

#ifndef DIJKSTRA_COUPLE_HPP
#define DIJKSTRA_COUPLE_HPP

template <class W, class V>
class Couple {
private:
    V vertex;
    W weight;
public:
    Couple(V _vertex, W _weight);
    V getVertex();
    W getWeight();

};

template <class W,class V>
Couple<W,V>::Couple(V _vertex, W _weight) {
    vertex=_vertex;
    weight=_weight;
}

template <class W,class V>
V Couple<W,V>::getVertex() {
    return vertex;
}

template <class W,class V>
W Couple<W,V>::getWeight() {
    return weight;
}
#endif //DIJKSTRA_COUPLE_HPP
