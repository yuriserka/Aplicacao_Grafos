#ifndef Grafo_h_
#define Grafo_h_

#include "vertice.h"

class Grafo {
    public:
        Grafo() = default;

        void addAresta(Vertice& origem, Vertice& destino);
        void imprimeGrafo();
        void mostraComunidades();
    private:
        void computaComunidades();
        vector<Vertice> grafo;
        vector<vector<int>> comunidades;
        map<Vertice, double> intermediacoes;
};

#endif // Grafo_h_