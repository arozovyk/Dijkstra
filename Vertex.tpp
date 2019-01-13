//
// Created by groku on 10/01/19.
//


namespace std {
        template <class W,class T>
        struct hash<Vertex<W,T>*>
        {
            std::size_t operator()(const Vertex<W,T>* k) const
            {
                using std::hash;
                return hash<T>()(k->getId());
            }
        };
}

template < class W, class  T>
void Vertex<W,T>::setId(T _id){
     (*this).id=_id;
}
template < class W, class  T>
AdjacencyList< W,Vertex<W,T> *> * Vertex<W,T>::getList(){
     return (*this).adjList;
}




template<class SW, class ST>
std::ostream & operator <<( std::ostream &os, const Vertex<SW,ST> & vertex ){
   os<<vertex.getId();
   return os;
}

template <class W,class T>
Vertex<W,T>::Vertex(T _id) {
    id=_id;
    adjList=new AdjacencyList<W, Vertex<W,T> *>();
}
template <class W,class T>
Vertex<W,T>::Vertex() {
    adjList=new AdjacencyList<W, Vertex<W,T>* >();
}