#include <iostream>
#include <string>
#include <cmath>
#include "Graph.hpp"
#include "Heap.hpp"

int main() {
    Graph<int,std::string> graph;

   // std::cout<<ds.second;

    Vertex <int,std::string> a("a") ;
    Vertex <int,std::string> b("b");
    Vertex <int,std::string> c("c") ;
    Vertex <int,std::string> d("d");
    Vertex <int,std::string> e("e");

    graph.addVertex(a);
    graph.addVertex(b);
    graph.addVertex(c);
    graph.addVertex(d);
    graph.addVertex(e);

    graph.addEdge(a,b,4);
    graph.addArc(a,c,6);
    graph.addEdge(a,d,9);
    graph.addEdge(d,e,1);
    graph.showGraph();

    Heap<int , std::string > h ;
    std::pair<int,std::string> p1(51,"lol");
    std::pair<int,std::string> p2(36,"aaa");
    std::pair<int,std::string> p3(14,"bbb");
    std::pair<int,std::string> p4(32,"cc");
    std::pair<int,std::string> p5(33,"cc");
    std::pair<int,std::string> p6(39,"cc");
    std::pair<int,std::string> pa(17,"cc");
    std::pair<int,std::string> pb(35,"cc");
    std::pair<int,std::string> pc(31,"cc");
    std::pair<int,std::string> pd(30,"cc");

    h.insert(&p1);
    h.insert(&p2);
    h.insert(&p3);
    h.insert(&p4);
    h.insert(&p5);
    h.insert(&p6);
    h.insert(&pa);
    h.insert(&pb);
    h.insert(&pc);
    h.insert(&pd);
    h.show();
    h.get_root();
    std::cout<<std::endl;
    h.show();
h.get_root();
    std::cout<<std::endl;
    h.show();
h.get_root();
    std::cout<<std::endl;
    h.show();
h.get_root();
    std::cout<<std::endl;
    h.show();


    //std::cout << a << std::endl;
    return 0;
}