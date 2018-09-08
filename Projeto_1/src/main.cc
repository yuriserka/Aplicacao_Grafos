#include "../include/graph.h"

int main() {
    Graph graph = Graph(8);
    cout << "tamanho: " << graph.getSize() << "\n";
    graph.addEdge(0, 5);
    graph.addEdge(0, 2);
    graph.addEdge(0, 1);
    graph.addEdge(0, 6);
    graph.addEdge(3, 5);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(6, 4);
    graph.addEdge(7, 8);

    graph.bfs(0);
    return 0;
}