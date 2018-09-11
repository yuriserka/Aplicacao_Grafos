#include "../include/graph.h"
#include "../include/parser.h"

int main() {
    Graph graph = Graph(34);
    Parser* parser = new Parser("arestas.txt");

    parser->insertOnGraph(graph);

    graph.bfs(1);
    // graph.getCliques();

    graph.getAllAglomeration();
    // cout << graph.getAglomeration(1);
   
//    graph.addEdge(1,2);
//    graph.addEdge(1,3);
//    graph.addEdge(1,4);
//    graph.addEdge(2,3);
//    graph.addEdge(3,4);

//    graph.getCliques();

    delete parser;
    return 0;
}