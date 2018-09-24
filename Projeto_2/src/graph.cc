#include "../include/graph.h"

void Graph::addVertice(string subject, int weight) {
    vector<pair<string, int>> vazio;
    graph[subject] = vazio;
}

void Graph::writeGraph() {
    fstream out;
    out.open("output.txt");
    if(!out.is_open()) {
        cout << "Nao foi possivel abrir o arquivo de output\n";
        exit(-2);
    }
    out << "// G(e) é o grau de entrada de cada matéria, ou seja, quantos pré-requisitos ela tem.\n\n";
    for (auto node : graph) {
        out << "G(e)=[" << inputDegree[node.first] << "] | ";
        out << node.first << ": ";
        for (auto par : node.second) {
            out << par.first << ", " << par.second << "; ";
        }
        out << "\n";
    }
}

void Graph::addEdge(string src, pair<string, int> dest) {
    if (graph.find(dest.first) == graph.end()) {
        this->addVertice(dest.first, dest.second);
    }
    inputDegree[dest.first]++;
    graph[src].push_back(dest);
}

void Graph::showTopSort() {
    map<string, bool> visited;
    for (auto node : graph) {
        if (inputDegree[node.first] == 0) {
            dfs(node.first, visited);
        }
    }

    cout << "\tOrdenacao Topologica: \n";

    for (auto it = topologicSorted.rbegin(); it != topologicSorted.rend(); it++) {
        cout << *it << '\n';
    }
}

void Graph::dfs(string vertex, map<string, bool>& visited) {
    visited[vertex] = true;

    for (auto neighb : graph[vertex]) {
        if (!visited[neighb.first]) {
                dfs(neighb.first, visited);
        }
    }

    topologicSorted.push_back(vertex);
}