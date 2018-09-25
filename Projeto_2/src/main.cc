#include <bits/stdc++.h>
#include "../include/parser.h"

int main() {
    Graph graph = Graph();
    Parser *parser = new Parser("fluxo.txt");
    parser->insertOnGraph(graph);

    // graph.writeGraph();
    // graph.showTopSort();

    // graph.addEdge("a", make_pair("b", 1));
    // graph.addEdge("b", make_pair("c", 7));
    // graph.addEdge("b", make_pair("d", 2));
    // graph.addEdge("c", make_pair("g", 8));
    // graph.addEdge("c", make_pair("h", 9));
    // graph.addEdge("d", make_pair("e", 4));
    // graph.addEdge("d", make_pair("f", 3));
    // graph.addEdge("e", make_pair("g", 6));
    // graph.addEdge("e", make_pair("h", 5));
    // graph.addEdge("f", make_pair("i", 10));
    // graph.addEdge("h", make_pair("i", 11));
    // graph.showTopSort();


    graph.computeCriticalPath();

    delete parser;
    return 0;
}