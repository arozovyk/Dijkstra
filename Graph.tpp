//
// Created by groku on 11/01/19.
//


template<class W, class T>
void Graph<W, T>::addVertex(Vertex<W, T> *to_add) {
    //if (! std::find(verticies.begin(), verticies.end(), to_add)) {
    verticies->push_back(to_add);
    //}
}

template<class W, class T>
void Graph<W, T>::addArc(Vertex<W, T> *src, Vertex<W, T> * dst, W value) {
    src->getList()->addAdjacency(new std::pair<W, Vertex<W, T> *>(value, dst));
}

template<class W, class T>
void Graph<W, T>::addEdge(Vertex<W, T> * src, Vertex<W, T> *dst, W value) {
    src->getList()->addAdjacency(new std::pair<W, Vertex<W, T> *>(value, dst));
    dst->getList()->addAdjacency(new std::pair<W, Vertex<W, T> *>(value, src));
}


template<class W, class T>
void Graph<W, T>::removeEdge(Vertex<W, T> * src, Vertex<W, T> * dst) {
    src->getList()->remove(dst);
    dst->getList()->remove(src);
}

template<class W, class T>
void Graph<W, T>::removeVertex(Vertex<W, T> * v_to_remove) {
    int i=0;
    for(auto it=verticies->begin();it!=verticies->end();++it)
        if((*(*it))==*v_to_remove)break;
        else
            i++;
    verticies->erase(verticies->begin()+i);
}

template<class W, class T>
void Graph<W, T>::removeArc(Vertex<W, T> * src, Vertex<W, T> * dst) {
    src->getList()->remove(dst);

}

template<class W, class T>
void Graph<W, T>::showGraph() {
    typename std::vector<Vertex<W, T> * >::iterator it;
    for (it = verticies->begin(); it != verticies->end(); ++it) {
        std::cout << (*it)->getId() << ":";
        (*it)->getList()->showList();
        std::cout << std::endl;
    }
}

template<class W, class T>
std::vector<Vertex<W, T> *>* Graph<W, T>::getVerticies() {
    return verticies;
}

template<class W, class T>
Graph<W, T>::Graph() {
    verticies=new std::vector<Vertex<W, T> * >();

}