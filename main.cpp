#include <iostream>
#include <string>
#include <cmath>
#include "Dijkstra.hpp"


int main() {

    std::cout<<std::endl<<"<int,string> graph"<<std::endl;
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
    //graph.removeArc(&g,&e);
    graph.addEdge(&g,&d,32);
    graph.addEdge(&c,&f,8.);
    graph.addEdge(&c,&e,7.12);
    graph.addEdge(&d,&f,5.33);
    //graph.removeEdge(&a,&b);
    graph.showGraph();



     Dijkstra<int,std::string> dijkstra(&graph);
     std::set<std::pair<int,Vertex<int,std::string>*>*> *result= dijkstra.exec(b);

    for(auto it=result->begin();it!=result->end();++it){
        std::cout<<*(*it)->second << " - " << (*it)->first<<std::endl;
    }


     std::cout<<std::endl;
     std::cout<<std::endl;
    std::cout<<"<float,char> graph"<<std::endl;

    Vertex <float,char> a1('a');
    Vertex <float,char> b1('b');
    Vertex <float,char> c1('c');
    Vertex <float,char> d1('d');
    Vertex <float,char> e1('e');
    Vertex <float,char> f1('f');
    Vertex <float,char> g1('g');

    Graph<float,char> graph1;

    graph1.addVertex(&a1);
    graph1.addVertex(&b1);
    graph1.addVertex(&c1);
    graph1.addVertex(&d1);
    graph1.addVertex(&f1);
    //graph.removeVertex(&f);
    graph1.addVertex(&g1);
    graph1.addVertex(&e1);

    graph1.addEdge(&a1,&b1,5.4);
    graph1.addEdge(&b1,&g1,2.2);
    graph1.addEdge(&g1,&a1,1.1);
    graph1.addEdge(&g1,&e1,3.3);
    graph1.addEdge(&g1,&d1,32.44);
    graph1.addEdge(&c1,&f1,8.413);
    graph1.addEdge(&c1,&e1,7.12);
    graph1.addEdge(&d1,&f1,5.33);
    //graph.removeEdge(&a,&b);
    graph1.showGraph();



    Dijkstra<float,char> dijkstra1(&graph1);
    std::set<std::pair<float,Vertex<float,char>*>*> *result1= dijkstra1.exec(b1);


    for(auto it=result1->begin();it!=result1->end();++it){
        std::cout<<*(*it)->second << " - " << (*it)->first<<std::endl;
    }

    return 0;
}