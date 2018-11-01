#include "../include/graph.h"

void Graph::addProfessor(Professor& p) {
    grafo.push_back(p);
}

void Graph::escreveProfs() {
    ofstream x;
    x.open("ProfessoresGeradosPorMim.txt");
    if (!x.is_open()) {
        cout << "O arquivo ProfessoresGeradosPorMim nao foi aberto\n";
        exit(-1);
    }

    x << "// lista de professores e preferencias\n// formato (codigo professor, habilitacoes): (Escolas em ordem decrescente de prioridade)\n\n";

    for (auto node : grafo) {
        x << "(" << node.getNome() << ", " << node.getHabilitacoes() << "): (";
        int i = 0;
        for (auto e : node.getEscolasDeInteresse()) {
            x << e.getNome();
            if (i < (int) node.getEscolasDeInteresse().size() - 1) {
                x << ", ";
            }
            i++;
        }
        x << ")\n"; 
    }
}

void Graph::escreveEscs() {
    for (auto p : grafo) {
        for (auto e : p.getEscolasDeInteresse()) {
            if (find(escolas.begin(), escolas.end(), e) == escolas.end()) {
                escolas.push_back(e);
            }
        }
    }
    ofstream x;
    x.open("EscolasGeradasPorMim.txt");
    if (!x.is_open()) {
        cout << "O arquivo EscolasGeradasPorMim nao foi aberto\n";
        exit(-1);
    }

    x << "//escolas e preferencias em termos de habilitacoes\n// formato (codigo escola):(habilitacoes pretendidas)\n\n";

    sort(escolas.begin(), escolas.end());

    for (auto node : escolas) {
        x << "(" << node.getNome() << "):";
        for (size_t i = 0; i != node.getHabilidades().size(); i++) {
            x << "(" << node.getHabilidades()[i] << ")";
            if (i < node.getHabilidades().size() - 1) {
                x << ":";
            }
        }
        x << "\n";
    }
}

void Graph::Emparelhamentos() {
    if (escolas.empty()) {
        for (auto p : grafo) {
            for (auto e : p.getEscolasDeInteresse()) {
                if (find(escolas.begin(), escolas.end(), e) == escolas.end()) {
                    escolas.push_back(e);
                }
            }
        }
    }
    
    Escola e = Escola();

    for (auto& p : grafo) {
        p.setEscolaIdeal(&e);
    }

    Professor p = Professor();

    for (auto& e : escolas) {
        e.addProfessorIdeal(p);
    }

    this->galeShapley(e);

    ofstream x;
    x.open("Resultados.txt");
    if (!x.is_open()) {
        cout << "O arquivo Resultados nao foi aberto\n";
        exit(-1);
    }

    for (auto e : escolas) {
        x << e.getNome() << " possui " << e.getVagas() << " vagas e " << "quer hab = ";
        for (auto y : e.getHabilidades() ) { x << y << ","; } x << " e tem os profIdeais = {\n";
        for (auto p : e.getProfessoresIdeais()) {
            x << '\t' << p.getNome() << " com " << p.getHabilitacoes() << " hab\n";
        }
        x << "}\n";
    }
}

void Graph::galeShapley(Escola& e) {
    // pensar em como fazer com calma
    return;
}