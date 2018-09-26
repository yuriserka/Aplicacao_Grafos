#include <bits/stdc++.h>
#include "../include/parser.h"

int main() {
    Graph graph = Graph();
    Parser *parser = new Parser("fluxo.txt");
    parser->insertOnGraph(graph);

    
    // graph.addEdge("a", make_pair("b", 2));
    // graph.addEdge("b", make_pair("c", 6));
    // graph.addEdge("b", make_pair("d", 4));
    // graph.addEdge("c", make_pair("e", 10));
    // graph.addEdge("c", make_pair("h", 12));
    // graph.addEdge("d", make_pair("c", 8));
    // graph.addEdge("f", make_pair("c", 5));
    // graph.addEdge("f", make_pair("g", 7));
    // graph.addEdge("g", make_pair("c", 9));

    graph.writeGraph();

    graph.showTopSort();
    graph.showCriticalPath();

    delete parser;
    return 0;
}