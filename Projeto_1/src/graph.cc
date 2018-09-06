#include "../include/graph.h"

bool Graph::comp(const Node& rhs, const Node& lhs)  {
    return (rhs.getData() < lhs.getData());
}

void Graph::addVertice(int vertice) {
    graph.emplace_back(vertice);
    sort(graph.begin(), graph.end(), this->comp);
}

void Graph::addEdge(int src, int dest) {
    if (!binary_search(graph.begin(), graph.end(), src, this->comp)) {
        this->addVertice(src);
    }
    if (!binary_search(graph.begin(), graph.end(), dest, this->comp)) {
        this->addVertice(dest);
    }
    if (hasEdge(src, dest)) {
        cout << "aresta (" << src << ", " << dest << ") ja existente\n";
        return;
    }

    graph[lower_bound(graph.begin(), graph.end(), src, this->comp) - graph.begin()].add(dest);
    graph[lower_bound(graph.begin(), graph.end(), dest, this->comp) - graph.begin()].add(src);

    cout << "adicionada aresta (" << src << ", " << dest << ")\n";
    this->display();
    cout << '\n';
}

bool Graph::hasEdge(int src, int dest) {
    if (graph.empty()) {
        cout << "Grafo vazio.\n";
        exit(2);
    }
    int posNode = lower_bound(graph.begin(), graph.end(), src, this->comp) - graph.begin();
    if (graph[posNode].getData() != src) {
        return false;
    }
    int posVal = lower_bound(graph[posNode].getList().begin(), graph[posNode].getList().end(), dest) - graph[posNode].getList().begin();
    if (graph[posNode].getList().at(posVal) != dest) {
        return false;
    }
    return false;
}

void Graph::display() {
    for (auto node : graph) {
        cout << node.getData() << ": ";
        node.display();
        cout << "\n";
    }
}