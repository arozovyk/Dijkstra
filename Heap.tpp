//
// Created by groku on 11/01/19.
//


template<class D, class V>
pair_dv Heap<D, V>::get_root() {
    pair_dv p = heap.front();
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapify_down(0);
    return p;
}


template<class D, class V>
void Heap<D, V>::insert(pair_dv el) {
    heap.push_back(el);
    heapify_up(heap.size() - 1);
}


template<class D, class V>
int Heap<D, V>::right_child(int i) {
    if (2 * i + 1 < heap.size()) {
        return 2 * i + 2;
    }
    return -1;
}

template<class D, class V>
int Heap<D, V>::left_child(int i) {
    if (2 * i + 1 < heap.size()) {
        return 2 * i + 1;
    }
    return -1;
}

template<class D, class V>
int Heap<D, V>::parent(int i) {
    return (!i)?-1:(i - 1) / 2;

}

template<class D, class V>
void Heap<D, V>::heapify_down(int i){

    int l_child=left_child(i);
    int r_child=right_child(i);

    if(l_child>=0 && r_child >=0 && heap[l_child]->first>heap[r_child]->first)
        l_child=r_child;

    if(l_child >  0 && heap[i]->first >heap[l_child]->first){
        pair_dv tmp = heap[i];
        heap[i]=heap[l_child];
        heap[l_child]=tmp;
        heapify_down(l_child);
    }

}

template<class D, class V>
void Heap<D, V>::heapify_up(int i) {
    if(i>=0 && parent(i)>=0 && heap[parent(i)]->first > heap[i]->first)
    {
        pair_dv tmp=heap[i];
        heap[i]=heap[parent(i)];
        heap[parent(i)]=tmp;
        heapify_up(parent(i));
    }

}

template<class D, class V>
void Heap<D, V>::show() {
    int i=0;
    for (auto it=heap.begin();it!=heap.end();++it){
        std::cout << i <<" : " << (*it)->first << " - "<<*(*it)->second ;
        std::cout << std::endl ;
        i++;
    }

}
