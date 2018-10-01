#include "../include/graph.h"

void Graph::addEdge(int src, int dest) {
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

void Graph::bfs(int vertex) {
    vector<bool> visited(graph.size(), false);
    cout << "\n\tGrau dos vertices: \n";
    this->bfsAux(vertex, visited);
}

void Graph::bfsAux(int vertex, vector<bool>& visited) {
    queue<int> queue;
    queue.push(vertex);
    visited[vertex] = true;
    
    while (queue.size()) {
        int u = queue.front();
        cout << "vertice " << u << ":   grau: " << getDegree(u) << "\n";
        queue.pop();
        for (auto element : this->getAdjNodes(u)) {
            if (!visited[element]) {
                queue.push(element);
                visited[element] = true;
            }
        }
    }

    for (int i = 1; i < (int) visited.size(); i++) {
        if (visited[i] == false) {
            this->bfsAux(i, visited);
        }
    }
}

void Graph::getCliques() {
    this->sortCliques();
    cout << "\n\tCliques: \n";
    for (int i = 0; i < (int) cliques.size(); i++) {
        cout << '[';
        for (int j = 0; j < (int) cliques[i].size(); j++) {
            cout << cliques[i][j];
            if (j < (int) cliques[i].size() - 1) {
                cout << ' ';
            }
        }
        cout << "]\n";
    }
}

void Graph::sortCliques() {
    if (cliques.empty()) {
        vector<int> r, p, x;
        for (int i = 1; i < (int) graph.size(); i++) {
            p.push_back(i);
        }
        this->bronKerbosh(r, p, x);
    }

    sort(cliques.begin(), cliques.end(), 
        [](const vector<int>& x, const vector<int>& y) -> bool {
            return x.size() > y.size();
    });
}

void Graph::bronKerbosh(vector<int> click, vector<int>& possible, vector<int>& excluded) {
    auto inter = [] (const vector<int>& x, const vector<int>& y) -> vector<int> {
        vector<int> dest;
        for (int a : y) {
            if (find(x.begin(), x.end(), a) != x.end()) {
                dest.push_back(a);
            }
        }
        return dest;
    };

    if (possible.empty() && excluded.empty()) {
        sort(click.begin(), click.end());
        cliques.push_back(click);
        return;
    }

    for(int i = 0; possible.size() > 0; i++) {
        int v = possible[0];
        vector<int> newR = click, newP = possible, newX = excluded;  

        newR.push_back(v);
        newP = inter(possible, this->getAdjNodes(v));
        newX = inter(excluded, this->getAdjNodes(v));   

        bronKerbosh(newR, newP, newX);

        possible.erase(possible.begin() + 0);
        excluded.push_back(v);
    }
}

double Graph::getAglomeration(int vertex) {
    int qtdTriangulos = 0;

    auto adj = getAdjNodes(vertex);
    vector<int> nextAdj;

    for (int i = 0; i < (int) adj.size(); i++) {
        for (int j = i + 1; j < (int) adj.size(); j++) {
            nextAdj = getAdjNodes(adj[j]);
            for (auto adjVertex : nextAdj) {
                if (adj[i] == adjVertex) {
                    qtdTriangulos++;
                }
            }
        }
    }

    double coef;
    double totalV = getDegree(vertex);
    if (totalV < 2) {
        coef = 0.0f;
    } else {
        coef = ( (double) (2.0f * qtdTriangulos)) / (totalV * (totalV - 1));
    }

    return coef;
}

void Graph::getAllAglomeration() {
    cout << "\n\tCoeficientes de Aglomeracao: \n";
    double media = 0;
    for (int i = 1; i < (int) graph.size(); i++) {
        double coef = this->getAglomeration(i);
        cout << "vertice " << i << ":    coeficiente: " << coef << "\n";
        media += coef;
    }

    media /= (double) (graph.size() - 1);

    cout << "\nCoeficiente Medio de Aglomeracao do Grafo: " << media << "\n\n";

}
