#include "../include/grafo.h"

void Grafo::addAresta(Vertice& origem, Vertice& destino) {
    if (find(this->grafo.begin(), this->grafo.end(), origem) == this->grafo.end()) {
        this->grafo.push_back(origem);
    }
    if (find(this->grafo.begin(), this->grafo.end(), destino) == this->grafo.end()) {
        this->grafo.push_back(destino);
    }

    grafo[find(this->grafo.begin(), this->grafo.end(), origem) - this->grafo.begin()].addAdjacente(destino);
}

void Grafo::imprimeGrafo() {
    sort(this->grafo.begin(), this->grafo.end());

    for (auto vertice : grafo) {
        cout << '[' << vertice.getId() << "]: ";
        for (auto adj : vertice.getAdjacentes()) {
            cout << adj.getId() << " ";
        }
        cout << '\n';
    }
}

void Grafo::mostraComunidades() {
    if (this->comunidades.empty()) {
        this->computaComunidades();
    }

    ofstream output;
    output.open("saida.json");

    if(!output.is_open()) {
        cout << "O arquivo \"saida.json\"nao foi aberto\n";
        exit(EXIT_FAILURE);
    }

    output << "{\n\t\"comunidades\": [\n";
    for (size_t k = 0; k < this->comunidades.size(); ++k) {
        auto comunidade = this->comunidades[k];
        output << "\t\t{\n";
        output << "\t\t\t\"tamanho\": " << comunidade.size() << ", \n";
        output << "\t\t\t\"elementos\": [\n";
        for (size_t i = 0; i < comunidade.size(); ++i) {
            output << "\t\t\t\t" << comunidade[i];
            if (i < (comunidade.size() - 1)) {
                output << ",";
            }
            output << "\n";
        }
        output << "\t\t\t]\n";
        output << "\t\t}";
        if (k < (this->comunidades.size() - 1)) {
            output << ",";
        }
        output << "\n";
    }
    output << "\t]\n";
    output << "}";

    cout << "As comunidades estao no Arquivo \"saida.json\"\n";
}

void Grafo::computaComunidades() {
    return;
}