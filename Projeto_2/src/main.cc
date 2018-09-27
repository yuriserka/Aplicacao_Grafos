#include <bits/stdc++.h>
#include "../include/parser.h"

int main() {
    Graph graph = Graph();
    Parser *parser = new Parser("fluxo.txt");
    parser->insertOnGraph(graph);

    graph.writeGraph();
    graph.writeAllPaths();

    graph.showTopSort();
    graph.showCriticalPath();

    delete parser;
    return 0;
}