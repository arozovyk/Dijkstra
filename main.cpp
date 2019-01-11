#include <iostream>
#include <string>
#include "Graph.hpp"

int main() {
    Graph<std::string,int> graph;



    Vertex <std::string,int> a(0) ;
    Vertex <std::string,int> b(1);
    Vertex <std::string,int> c(2) ;
    Vertex <std::string,int> d(3);

    graph.addVertex(a);
    graph.addVertex(b);
    graph.addVertex(c);
    graph.addVertex(d);

    graph.addEdge(a,b,"8");
    graph.addEdge(a,c,"9");
    graph.addEdge(a,d,"7");
    graph.showGraph();

    std::cout << a << std::endl;
    return 0;
}