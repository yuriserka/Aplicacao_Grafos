#ifndef Comunidade_h_
#define Comunidade_h_

#include "vertice.h"

class Comunidade {
    public:
        Comunidade() = default;

        Comunidade(string identificadorDaComunidade) {
            this->idLabel = identificadorDaComunidade;
        }

        void setId(string id) {
            this->idLabel = id;
        }

        double getQualidade() {
            double qualidade = 0.0f;
            this->computaSomatorioA();

            for (size_t i = 0; i < this->fracoes.size(); ++i) {
                qualidade += this->fracoes[i] - (somatorioA * somatorioA);
            }

            return qualidade;
        }

        vector<Vertice> getVertices() {
            return this->comunidade;
        }

        void addComunidadeAdjacente(Comunidade& adjacente) {
            this->comunidadesAdjacentes.push_back(adjacente);
        }

        void addNaComunidade(Vertice& v) {
            comunidade.push_back(v);
        }
    private:
        int computaQtdDeArestasInternas() {
            int qtdDeArestas = 0;

            return qtdDeArestas;
        }

        double computaSomatorioA() {
            double a = 0.0f;
            this->computaFracoes();
            for (size_t i = 0; i < this->fracoes.size(); ++i) {
                a += this->fracoes[i];
            }

            return a;
        }

        void computaFracoes() {
            vector<Vertice> adjacentesAComunidade;
            map<Vertice, bool> adjMarcado;
            vector<Vertice> foraDaComunidadeMasConectados;
            map<string, int> arestasParaOutraComunidade;
            map<string, bool> ComunidadeVisitada;
            int qtdDeComunidadesAdjacentes = 0;

            for (auto v : comunidade) {
                for (auto adj : v.getAdjacentes()) {
                    if (find(this->comunidade.begin(), this->comunidade.end(), adj)
                            == this->comunidade.end()) {
                        ++arestasParaOutraComunidade[adj.getComunidade()];
                        if (!ComunidadeVisitada[adj.getComunidade()]) {
                            ComunidadeVisitada[adj.getComunidade()] = true;
                            ++qtdDeComunidadesAdjacentes;
                        }
                    }
                }
            }

            for (auto ca : arestasParaOutraComunidade) {
                bool mudou = false;
                while (!mudou) {
                    
                }
            }

        }

        vector<Comunidade> comunidadesAdjacentes;
        vector<Vertice> comunidade;
        string idLabel;
        vector<double> fracoes;
        double somatorioA;
        double qualidade;
};

#endif // Comunidade_h_