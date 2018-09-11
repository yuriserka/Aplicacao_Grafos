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
    auto uni = [] (const vector<int>& x, const vector<int>& y) -> vector<int> {
        vector<int> dest;
        set_union(x.begin(), x.end(), y.begin(), y.end(), back_inserter(dest));
        return dest;
    };
    auto inter = [] (const vector<int>& x, const vector<int>& y) -> vector<int> {
        vector<int> dest;
        set_intersection(x.begin(), x.end(), y.begin(), y.end(), back_inserter(dest));
        return dest;
    };
    auto diff = [] (const vector<int>& x, const vector<int>& y) -> vector<int> {
        vector<int> dest;
        set_difference(x.begin(), x.end(), y.begin(), y.end(), back_inserter(dest));
        return dest;
    };

    if (uni(possible, excluded).empty()) {
        cliques.push_back(click);
    } else if (possible.empty() && !excluded.empty()) {
        return;
    }

    vector<int> aux = possible;

    for (auto v : inter(possible, aux)) {
        vector<int> newR, newP, newX;  

        newR = uni(click, {v});
        newP = inter(possible, this->getAdjNodes(v));
        newX = inter(excluded, this->getAdjNodes(v));   

        this->bronKerbosh(newR, newP, newX);

        possible = diff(possible, {v});
        if (possible.empty()) {
            return;
        }
        excluded = uni(excluded, {v});
    }
}

double Graph::getAglomeration(int vertex) {
    double coef;
    int qtdTriangulos = 0;
    if (getDegree(vertex) < 2) {
        coef = 0.0f;
    } else {
        double totalV = getDegree(vertex);
        coef = ( (double) (2.0f * qtdTriangulos)) / (totalV * (totalV - 1));
    }

    return coef;
}

void Graph::getAllAglomeration() {
    cout << "\n\nCoeficientes de Aglomeracao: \n";
    double media = 0;
    for (int i = 1; i < (int) graph.size(); i++) {
        double coef = this->getAglomeration(i);
        cout << "vertice " << i << ":    coeficiente: " << coef << "\n";
        media += coef;
    }

    media /= (double) graph.size();

    cout << "\nCoeficiente Medio de Aglomeracao do Grafo: " << media << "\n\n";

}