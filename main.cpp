#include <iostream>
#include <string>
#include <cmath>
#include "Dijkstra.hpp"


int main() {

    Vertex <int,std::string> a("a");
    Vertex <int,std::string> b("b");
    Vertex <int,std::string> c("c");
    Vertex <int,std::string> d("d");
    Vertex <int,std::string> e("e");
    Vertex <int,std::string> f("f");
    Vertex <int,std::string> g("g");

    Graph<int,std::string> graph;

    graph.addVertex(&a);
    graph.addVertex(&b);
    graph.addVertex(&c);
    graph.addVertex(&d);
    graph.addVertex(&f);
    //graph.removeVertex(&f);
    graph.addVertex(&g);
    graph.addVertex(&e);

    graph.addEdge(&a,&b,5);
    graph.addEdge(&b,&g,2);
    graph.addEdge(&g,&a,1);
    graph.addEdge(&g,&e,3);
    graph.addEdge(&g,&d,32);
    graph.addEdge(&c,&f,8);
    graph.addEdge(&c,&e,7);
    graph.addEdge(&d,&f,5);
    //graph.removeEdge(&a,&b);
    graph.showGraph();



     Dijkstra<int,std::string> dijkstra(&graph);
     std::set<std::pair<int,Vertex<int,std::string>*>*> *result= dijkstra.exec(b);

    for(auto it=result->begin();it!=result->end();++it){
        std::cout<<*(*it)->second << " - " << (*it)->first<<std::endl;
    }

    return 0;
}