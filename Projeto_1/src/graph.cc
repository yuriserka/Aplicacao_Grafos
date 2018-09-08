#include "../include/graph.h"

void Graph::addEdge(int src, int dest) {
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

void Graph::bfs(int vertice) {
    vector<bool> visited(graph.size(), false);
    bfsAux(vertice, visited);
}

void Graph::bfsAux(int vertice, vector<bool>& visited) {
    queue<int> queue;
    queue.push(vertice);
    visited[vertice] = true;
    
    while (queue.size()) {
        int u = queue.front();
        cout << "Grau do vertice " << u << " = " << getDegree(u) << "\n";
        queue.pop();
        for (auto element : graph[u]) {
            if (!visited[element]) {
                queue.push(element);
                visited[element] = true;
            }
        }
    }

    for (int i = 1; i < (int) visited.size(); i++) {
        if (visited[i] == false) {
            bfsAux(i, visited);
        }
    }
}