#include "../include/graph.h"

void Graph::addVertice(string subject, int weight) {
    Node noh = Node(subject, weight);
    graph.push_back(noh);
}

void Graph::addEdge(string src, pair<string, int> dest) {
    Node destino = Node(dest.first, dest.second);

    auto i = find_if(graph.begin(), graph.end(), [&destino] (const Node& procurado) {
        return (procurado.getNome() == destino.getNome());
    });

    if (i == graph.end()) {
        this->addVertice(dest.first, dest.second);
    }

    for (int i = 0; i < (int) graph.size(); i++) {
        if (graph[i].getNome() == src) {
            graph[i].addAdjacent(destino);
        }
    }

    inputDegree[dest.first]++;
    outDegree[src]++;
}

void Graph::writeGraph() {
    ofstream out;
    out.open("output.txt");
    if(!out.is_open()) {
        cout << "Nao foi possivel abrir o arquivo de output\n";
        exit(-2);
    }
    out << "// G(e) é o grau de entrada de cada matéria, ou seja, quantos pré-requisitos ela tem.\n";
    out << "// G(s) é o grau de saida de cada matéria, ou seja, de quantas materias ela é pré-requisito.\n\n";

    sort(graph.begin(), graph.end(), [] (const Node& x, const Node& y) {
        return (x.getNome() < y.getNome());
    });

    for (auto node : graph) {
        cout << node.getNome() << ": ";
        out << "G(e) = " << inputDegree[node.getNome()] << ", G(s) = " << outDegree[node.getNome()] << " | ";
        out << node.getNome() << ": ";
        for (auto adj : node.getAdjacents()) {
            cout << adj.getNome() << ", peso = " << adj.getPeso() << "; ";
            out << adj.getNome() << ", " << adj.getPeso() << "; ";
        }
        cout << "\n";
        out << '\n';
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
        if (inputDegree[node.getNome()] == 0) {
            dfs(node, visited);
        }
    }

    reverse(topologicSorted.begin(), topologicSorted.end());
}

void Graph::dfs(Node v, map<string, bool>& visited) {
    visited[v.getNome()] = true;

    // O C++ n deixou eu usar o find normal pq tem que ter o opertator== na classe, mas assim tambem funciona
    auto index = find_if(graph.begin(), graph.end(), [&v] (const Node& procurado) {
        return (procurado.getNome() == v.getNome());
    });

    int pos = index - graph.begin();

    for (auto adj : graph[pos].getAdjacents()) {
        if (!visited[adj.getNome()]) {
            dfs(adj.getNome(), visited);
        }
    }

    topologicSorted.push_back(v.getNome());
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

    for (int i = 0; i < (int) graph.size(); i++) {
        pesos[graph[i].getNome()] = graph[i].getPeso();
    }

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

    auto index = find_if(graph.begin(), graph.end(), [&materiaDePartida] (const Node& procurado) {
        return (procurado.getNome() == materiaDePartida);
    });

    int pos = index - graph.begin();

    for (auto adj : graph[pos].getAdjacents()) {
        pesos[adj.getNome()] = max(pesos[materiaDePartida], pesos[materiaDePartida] + adj.getPeso());
        if (!visited[adj.getNome()]) {
            this->computeAllPaths(adj.getNome(), visited, pesos);
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