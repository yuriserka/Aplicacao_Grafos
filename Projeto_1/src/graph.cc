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

void Graph::getAglomeration(int vertex) {
    if (this->cliques.empty()) {
        this->sortCliques();
    }

    for (auto clique : this->cliques) {
        if (clique.size() == 3) {
            triangulos.push_back(clique);   
        }
    }

    int qtdTriangulos = 0;

    // cout << "\n\nTRIANGULOS: \n";
    // for (int i = 0; i < (int) triangulos.size(); i++) {
    //     cout << '[';
    //     for (int j = 0; j < (int) triangulos[i].size(); j++) {
    //         cout << triangulos[i][j];
    //         if (j < (int) triangulos[i].size() - 1) {
    //             cout << ' ';
    //         }
    //     }
    //     cout << "]\n";
    // }

    for (auto tri : triangulos) {
        for (int i = 1; i < (int) tri.size(); i++) {
            if (tri[i] == vertex) {
                qtdTriangulos++;
            }
        }
    }

    // cout << "QTD TRi: " << qtdTriangulos / 3.0f << "\n";

    double totalV = getDegree(vertex);

    double coef = ( (double) (4.0f * qtdTriangulos) / (totalV * (totalV - 1)));

    cout << "\n\nCoeficientes de Aglomeracao: \n";

    cout << "vertice: " << vertex << ":    coeficiente: " << coef << "\n";
}

void Graph::getAllAglomeration() {
    for (int i = 1; i < (int) triangulos.size(); i++) {
        this->getAglomeration(i);
    }
}