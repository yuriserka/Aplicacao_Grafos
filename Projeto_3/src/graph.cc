#include "../include/graph.h"

void Graph::addProfessor(string nome, int habilitacoes, vector<string> escolas) {
    professores.emplace_back(nome, habilitacoes, escolas);
}

void Graph::addEscola(string nome, int habilitacoes, int vagas) {
    escolas.emplace_back(nome, habilitacoes, vagas);
}

void Graph::escreveProfs() {
    ofstream x;
    x.open("ProfessoresGeradosPorMim.txt");
    if (!x.is_open()) {
        cout << "O arquivo ProfessoresGeradosPorMim nao foi aberto\n";
        exit(-1);
    }

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
    x.open("EscolasGeradasPorMim.txt");
    if (!x.is_open()) {
        cout << "O arquivo EscolasGeradasPorMim nao foi aberto\n";
        exit(-1);
    }

    x << "//escolas e preferencias em termos de habilitacoes\n// formato (codigo escola):(habilitacoes pretendidas):(vagas)\n";

    for (auto node : escolas) {
        x << "(" << node.getNome() << "):";
        x << "(" << node.getHabilidades() << "):";
        x << "(" << node.getVagas() << ")\n"; 
    }
}

void Graph::printEscs(){
    for(auto e : escolas){
        cout << endl << "Escola: " << e.getNome() << " Habilitacoes: " << e.getHabilidades() << " Vagas: " << e.getVagas();
    }
}

void Graph::printProfs(){
    for(auto p : professores){
        cout << endl << "Professor: " << p.getNome() << " Habilidade: " << p.getHabilitacoes() << " Escolas: (";
        for(auto v : p.getEscolas()){
            cout << " " << v << " ";
        }
        cout << ")";
    }
}