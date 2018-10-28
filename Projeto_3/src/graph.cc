#include "../include/graph.h"

void Graph::addProfessor(Professor& p) {
    grafo.push_back(p);
}

// void Graph::addEscola(string nome, int habilitacoes, int vagas) {
//     escolas.emplace_back(nome, habilitacoes, vagas);
// }

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

    x << "//escolas e preferencias em termos de habilitacoes\n// formato (codigo escola):(habilitacoes pretendidas):(vagas)\n\n";

    for (auto node : escolas) {
        x << "(" << node.getNome() << "):";
        x << "(" << node.getHabilidades() << "):";
        x << "(" << node.getVagas() << ")\n"; 
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
    

    sort(escolas.begin(), escolas.end());

    // escolas.sort([] (const Escola& x, const Escola& y) {
    //     return x.getNome() < y.getNome();
    // });

    Escola *e = new Escola();
    e->setNome("null");
    
    for (auto& p : grafo) {
        p.setEscolaIdeal(e);
    }

    delete e;

    Professor p;
    p.setNome("null");

    for (auto& e : escolas) {    
        e.addProfessorIdeal(p);
    }

    galeShapley();
}

void Graph::galeShapley() {
    ofstream x;
    x.open("jesus.txt");
    if (!x.is_open()) {
        cout << "O arquivo EscolasGeradasPorMim nao foi aberto\n";
        exit(-1);
    }

    auto getPos = [](vector<Escola> v, Escola buscada) -> int {
        return (find(v.begin(), v.end(), buscada) - v.begin());
    };

    Escola *e = new Escola();
    e->setNome("null");

    int j = 0;
    while (j < 1) {
        for (auto k = grafo.begin(); k != grafo.end(); k++) {
            auto& p = *k;
            x << "Avaliando possibilidades para o prof " << p.getNome() << ": \n";
            for (int i = 0; i < 5; i++) {
                Escola& escolaAtual = escolas[getPos(escolas, p.getEscolasDeInteresse()[i])]; 
                x << "profs ideal (antes do if) da " << escolaAtual.getNome() << " = ";
                for (auto& pi : escolaAtual.getProfessoresIdeais()) {
                    x << pi.getNome() << ", ";
                }
                x << "\n";
                x << "vagas (antes do if) da " << escolaAtual.getNome() << " = " << escolaAtual.getVagas() << "\n";
                if (escolaAtual.getProfessoresIdeais().front().getNome() == "null" && p.getHabilitacoes() >= escolaAtual.getHabilidades()) {
                    escolaAtual.removeProfessorIdeal(escolaAtual.getProfessoresIdeais().front());
                    escolaAtual.addProfessorIdeal(p);
                    p.setEscolaIdeal(&escolaAtual);
                    escolaAtual.diminuiVagas();
                    x << "profs ideal (null && p.H >= e.H) da " << escolaAtual.getNome() << " = ";// << escolaAtual.getProfessoresIdeais().getNome() << "\n";
                    for (auto& pi : escolaAtual.getProfessoresIdeais()) {
                        x << pi.getNome() << ", ";
                    }
                    x << "\n";
                    break;
                } else {
                    if (escolaAtual.getVagas() > 0) {
                        if (p.getHabilitacoes() >= escolaAtual.getHabilidades()) {
                            escolaAtual.addProfessorIdeal(p);
                            p.setEscolaIdeal(&escolaAtual);
                            escolaAtual.diminuiVagas();
                            x << "profs ideal (!null && e.V > 0 && p.H >= e.H) da " << escolaAtual.getNome() << " = ";// << escolaAtual.getProfessorIdeal().getNome() << "\n";
                            for (auto& pi : escolaAtual.getProfessoresIdeais()) {
                                x << pi.getNome() << ", ";
                            }
                            x << "\n";
                            break;
                        }
                    } else {
                        bool mudou = false;
                        for (auto& pi : escolaAtual.getProfessoresIdeais()) {
                            if (p.getHabilitacoes() > pi.getHabilitacoes()) {
                                escolaAtual.removeProfessorIdeal(pi);
                                escolaAtual.addProfessorIdeal(p);
                                p.setEscolaIdeal(&escolaAtual);
                                
                                
                                find(grafo.begin(), grafo.end(), pi)->setEscolaIdeal(e);

                                x << "Agora o prof " << pi.getNome() << " tem escolas ideal = " << find(grafo.begin(), grafo.end(), pi)->getEscolaIdeal()->getNome() << "\n";

                                x << "profs ideal (!null && e.V <= 0 && p.H > e.P[x].H) da " << escolaAtual.getNome() << " = ";// << escolaAtual.getProfessorIdeal().getNome() << "\n";
                                for (auto& pi : escolaAtual.getProfessoresIdeais()) {
                                    x << pi.getNome() << ", ";
                                }
                                mudou = true;
                                x << "\n";
                                break;
                            }
                        }
                        if (mudou) {
                                break;
                        }
                    }
                }
                x << "vagas (depois do if) da " << escolaAtual.getNome() << " = " << escolaAtual.getVagas() << "\n";
            }
            x << "escola ideal para " <<  p.getNome() << " = " << p.getEscolaIdeal()->getNome() << "\n\n\n";
        }
        j++;
    }
    delete e;
}