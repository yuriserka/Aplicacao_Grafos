#include "../include/graph.h"

void Graph::addProfessor(string nome, int habilitacoes, vector<string> escolas) {
    professores.emplace_back(nome, habilitacoes, escolas);
}

void Graph::addEscola(string nome, int habilitacoes, int vagas) {
    escolas.emplace_back(nome, habilitacoes, vagas);
}

void Graph::escreveProfs() {
    ofstream x;
    x.open("t.txt");

    x << "// lista de professores e preferencias\n// formato (codigo professor, habilitacoes): (Escolas em ordem decrescente de prioridade)\n\n";

    for (auto node : professores) {
        x << "(" << node.getNome() << ", " << node.getHabilitacoes() << "): (";
        for (std::size_t i = 0; i < node.getEscolas().size(); i++) {
            x << node.getEscolas()[i];
            if (i < node.getEscolas().size() - 1) {
                x << ", ";
            }
        }
        x << ")\n"; 
    }
}

void Graph::escreveEscs() {
    ofstream x;
    x.open("te.txt");

    x << "//escolas e preferencias em termos de habilitacoes\n// formato (codigo escola):(habilitacoes pretendidas):(vagas)\n";

    for (auto node : escolas) {
        x << "(" << node.getNome() << "):";
        if (node.getHabilidades() != 0) {
            x << "(" << node.getHabilidades() << "):";
        }
        x << "(" << node.getVagas() << ")\n"; 
    }
}