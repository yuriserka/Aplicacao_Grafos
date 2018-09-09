#include "../include/graph.h"
#include "../include/parser.h"

int main() {
    Graph graph = Graph(34);
    Parser* parser = new Parser("arestas.txt");

    parser->insertOnGraph(graph);

    graph.bfs(1);
    graph.getCliques();

    delete parser;
    return 0;
}