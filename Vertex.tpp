//
// Created by groku on 10/01/19.
//



template < class W, class  T>
void Vertex<W,T>::setId(T _id){
     (*this).id=_id;
}
template < class W, class  T>
AdjacencyList< W,Vertex<W,T> *> * Vertex<W,T>::getList(){
     return (*this).adjList;
}