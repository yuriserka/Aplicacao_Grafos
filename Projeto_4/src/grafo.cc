#include "../include/grafo.h"

void Grafo::addAresta(int origem, int destino) {
    grafo[origem].push_back(destino);
}

void Grafo::imprimeGrafo() {
    for(size_t i = 0; i < grafo.size(); i++) {
        cout << "[" << i << "]: ";
        for(size_t j = 0; j < grafo[i].size(); j++) {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
}