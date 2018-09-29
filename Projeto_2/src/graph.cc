#include "../include/graph.h"

void Graph::addVertice(string nomeDaMateria, int pesoDaMateria) {
    Node noh = Node(nomeDaMateria, pesoDaMateria);
    grafo.push_back(noh);
}

void Graph::addAresta(string origem, pair<string, int> dest) {
    Node destino = Node(dest.first, dest.second);

    auto i = find_if(grafo.begin(), grafo.end(), [&destino] (const Node& procurado) {
        return (procurado.getNome() == destino.getNome());
    });

    if (i == grafo.end()) {
        this->addVertice(dest.first, dest.second);
    }

    for (int i = 0; i < (int) grafo.size(); i++) {
        if (grafo[i].getNome() == origem) {
            grafo[i].addAdjacente(destino);
        }
    }

    grausDeEntrada[dest.first]++;
    grausDeSaida[origem]++;
}

void Graph::EscreveGrafo() {
    ofstream out;
    out.open("output.txt");
    if(!out.is_open()) {
        cout << "Nao foi possivel abrir o arquivo de output\n";
        exit(-2);
    }
    out << "// G(e) é o grau de entrada de cada matéria, ou seja, quantos pré-requisitos ela tem.\n";
    out << "// G(s) é o grau de saida de cada matéria, ou seja, de quantas materias ela é pré-requisito.\n\n";

    sort(grafo.begin(), grafo.end(), [] (const Node& x, const Node& y) {
        return (x.getNome() < y.getNome());
    });

    for (auto node : grafo) {
        out << "G(e) = " << grausDeEntrada[node.getNome()] << ", G(s) = " << grausDeSaida[node.getNome()] << " | ";
        out << node.getNome() << ": ";
        for (auto adj : node.getAdjacentes()) {
            out << adj.getNome() << ", " << adj.getPeso() << "; ";
        }
        out << '\n';
    }
}

void Graph::EscreveTodosCaminhos() {
    if (todosCaminhos.empty()) {
        this->computaCaminhoCritico();
    }
    ofstream out;
    out.open("caminhos.txt");
    if (!out.is_open()) {
        cout << "nao foi possivel abrir o arquivo dos caminhos.\n";
        exit(-2);
    }

    for (auto caminho: todosCaminhos) {
        for (auto materia : caminho.first) {
            out << materia << " -> ";
        }
        out << " | Peso Total = " << caminho.second << "\n";
    }
}

void Graph::imprimeGrafo() {
    cout << "\tGrafo: \n";

    sort(grafo.begin(), grafo.end(), [] (const Node& x, const Node& y) {
        return (x.getNome() < y.getNome());
    });

    for (auto node : grafo) {
        cout << node.getNome() << ", peso = " << node.getPeso() << ": ";
        for (auto adj : node.getAdjacentes()) {
            cout << adj.getNome() << ", peso = " << adj.getPeso() << "; ";
        }
        cout << "\n";
    }
}

void Graph::imprimeTopSort() {
    if (listaTopSort.empty()) {
        this->TopSort();
    }

    cout << "\tOrdenacao Topologica: \n";

    for (auto materia : listaTopSort) {
        cout << materia << "\n";
    }
}

void Graph::TopSort() {
    map<string, bool> visited;
    for (auto node : grafo) {
        if (grausDeEntrada[node.getNome()] == 0) {
            dfs(node, visited);
        }
    }

    reverse(listaTopSort.begin(), listaTopSort.end());
}

void Graph::dfs(Node v, map<string, bool>& visitados) {
    visitados[v.getNome()] = true;

    // O C++ n deixou eu usar o find normal pq tem que ter o opertator== na classe, mas assim tambem funciona
    auto index = find_if(grafo.begin(), grafo.end(), [&v] (const Node& procurado) {
        return (procurado.getNome() == v.getNome());
    });

    int pos = index - grafo.begin();

    for (auto adj : grafo[pos].getAdjacentes()) {
        if (!visitados[adj.getNome()]) {
            dfs(adj.getNome(), visitados);
        }
    }

    listaTopSort.push_back(v.getNome());
}

void Graph::imprimeCaminhoCritico() {
    if (todosCaminhos.empty()) {
        this->computaCaminhoCritico();
    }
    cout << "\tCaminho Critico: \n";
    
    vector<string> maior_caminho = todosCaminhos.back().first;
    int maiorPeso = todosCaminhos.back().second;

    for (auto materia : maior_caminho) {
        cout << materia << " -> ";
    }
    cout << "\n| Peso Total = " << maiorPeso << "\n";
}

void Graph::computaCaminhoCritico() {
    if (listaTopSort.empty()) {
        this->TopSort();
    }

    map<string, bool> visited;
    map<string,int> pesos;

    for (int i = 0; i < (int) grafo.size(); i++) {
        pesos[grafo[i].getNome()] = grafo[i].getPeso();
    }

    for (auto starter : listaTopSort) {
        if (grausDeEntrada[starter] != 0) {
            continue;
        }
        computaTodosCaminhos(starter, visited, pesos);
    }

    todosCaminhos.sort( 
        [] (const pair<vector<string>, int>& x, const pair<vector<string>, int>& y) {
            return (x.second < y.second);
        }
    );
}

void Graph::computaTodosCaminhos(string materiaDePartida, map<string, bool>& visitados, map<string, int>& pesos) {
    visitados[materiaDePartida] = true;
    caminho.push_back(materiaDePartida);

    auto index = find_if(grafo.begin(), grafo.end(), [&materiaDePartida] (const Node& procurado) {
        return (procurado.getNome() == materiaDePartida);
    });

    int pos = index - grafo.begin();

    for (auto adj : grafo[pos].getAdjacentes()) {
        pesos[adj.getNome()] = max(pesos[materiaDePartida], pesos[materiaDePartida] + adj.getPeso());
        if (!visitados[adj.getNome()]) {
            this->computaTodosCaminhos(adj.getNome(), visitados, pesos);
        }
    }

    if (grausDeSaida[materiaDePartida] == 0) {
        pair<vector<string>, int> toPush;
        toPush.first = caminho;
        toPush.second = pesos[materiaDePartida];
        todosCaminhos.push_back(toPush);
    }

    visitados.clear();    
    caminho.pop_back();
}