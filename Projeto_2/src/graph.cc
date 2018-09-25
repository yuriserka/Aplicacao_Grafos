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
    if (topologicSorted.empty()) {
        this->TopSort();
    }

    cout << "\tOrdenacao Topologica: \n";

    for (auto el : topologicSorted) {
        cout << el << "\n";
    }
}

void Graph::TopSort() {
    map<string, bool> visited;
    for (auto node : graph) {
        if (inputDegree[node.first] == 0) {
            dfs(node.first, visited);
        }
    }
    reverse(topologicSorted.begin(), topologicSorted.end());
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

// void Graph::showCriticalPath() {
//     if (criticalPath.empty()) {
//         this->computeCriticalPath();
//     }

//     cout << "\tCaminho Critico: \n";

//     for (auto subject : criticalPath) {
//         cout << subject << " -> ";
//     }
// }

void Graph::computeCriticalPath() {
    if (topologicSorted.empty()) {
        this->TopSort();
    }

    map<string, int> pesoAcumulado;
    vector<pair<pair<string, string>, int>> paresDeMaterias;

    for (auto v : topologicSorted) {
        for (auto adj : graph[v]) {
            pesoAcumulado[adj.first] = max(pesoAcumulado[v], pesoAcumulado[v] + adj.second);
            paresDeMaterias.push_back(make_pair(make_pair(v, adj.first), pesoAcumulado[adj.first]));
        }
    }

    for (auto par : paresDeMaterias) {
        cout << par.first.first << " -> " << par.first.second << ": " << par.second;
        cout << '\n';
    }
}