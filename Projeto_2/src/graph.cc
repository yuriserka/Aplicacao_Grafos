#include "../include/graph.h"

void Graph::addVertice(string subject, int weight) {
    vector<pair<string, int>> vazio;
    graph[subject] = vazio;
}

void Graph::addEdge(string src, pair<string, int> dest) {
    if (graph.find(dest.first) == graph.end()) {
        this->addVertice(dest.first, dest.second);
    }
    inputDegree[dest.first]++;
    outDegree[src]++;
    graph[src].push_back(dest);
}

void Graph::writeGraph() {
    ofstream out;
    out.open("output.txt");
    if(!out.is_open()) {
        cout << "Nao foi possivel abrir o arquivo de output\n";
        exit(-2);
    }
    out << "// G(e) é o grau de entrada de cada matéria, ou seja, quantos pré-requisitos ela tem.\n";
    out << "// G(o) é o grau de saida de cada matéria, ou seja, de quantas materias ela é pré-requisito.\n\n";
    for (auto node : graph) {
        out << "G(e)=[" << inputDegree[node.first] << "], ";
        out << "G(o)=[" << outDegree[node.first] << "] | ";
        out << node.first << ": ";
        for (auto par : node.second) {
            out << par.first << ", " << par.second << "; ";
        }
        out << "\n";
    }
}

void Graph::writeAllPaths() {
    if (allPaths.empty()) {
        this->computeCriticalPath();
    }
    ofstream out;
    out.open("caminhos.txt");
    if (!out.is_open()) {
        cout << "nao foi possivel abrir o arquivo dos caminhos.\n";
        exit(-2);
    }

    for (auto caminho: allPaths) {
        for (auto x : caminho.first) {
            out << x << " -> ";
        }
        out << " | Peso Total = " << caminho.second << "\n";
    }
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

void Graph::showCriticalPath() {
    if (allPaths.empty()) {
        this->computeCriticalPath();
    }
    cout << "\tCaminho Critico: \n";
    
    vector<string> maior_caminho = allPaths.back().first;
    int maiorPeso = allPaths.back().second;

    for (auto x : maior_caminho) {
        cout << x << " -> ";
    }
    cout << "\n| Peso Total = " << maiorPeso << "\n";
}

void Graph::computeCriticalPath() {
    if (topologicSorted.empty()) {
        this->TopSort();
    }

    map<string, bool> visited;
    map<string,int> pesos;

    for (auto starter : topologicSorted) {
        if (inputDegree[starter] != 0) {
            continue;
        }
        computeAllPaths(starter, visited, pesos);
    }

    allPaths.sort( 
        [] (const pair<vector<string>, int>& x, const pair<vector<string>, int>& y) {
            return (x.second < y.second);
        }
    );

}

void Graph::computeAllPaths(string materiaDePartida, map<string, bool>& visited, map<string, int>& pesos) {
    visited[materiaDePartida] = true;
    criticalPath.push_back(materiaDePartida);

    for (auto adj : graph[materiaDePartida]) {
        pesos[adj.first] = max(pesos[materiaDePartida], pesos[materiaDePartida] + adj.second);
        if (!visited[adj.first]) {
            this->computeAllPaths(adj.first, visited, pesos);
        }
    }

    if (outDegree[materiaDePartida] == 0) {
        pair<vector<string>, int> toPush;
        toPush.first = criticalPath;
        toPush.second = pesos[materiaDePartida];
        allPaths.push_back(toPush);
    }
    visited.clear();    
    criticalPath.pop_back();
}