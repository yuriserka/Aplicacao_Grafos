#ifndef Grafo_h_
#define Grafo_h_

#include <bits/stdc++.h>

using namespace std;

class Grafo {
    public:
        Grafo() = default;
        Grafo(int quantidadeDeNohs) : grafo(quantidadeDeNohs) {}

        void addAresta(int origem, int destino);
        void imprimeGrafo();
    private:
        vector<vector<int>> grafo;
};

#endif // Grafo_h_