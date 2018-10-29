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

    Escola e = Escola();
    e.setNome("null");
    e.setHabilidades(-1);

    for (auto& p : grafo) {
        p.setEscolaIdeal(&e);
    }

    Professor p;
    p.setNome("null");

    for (auto& e : escolas) {
        e.addProfessorIdeal(p);
    }

    this->galeShapley(e);

    ofstream x;
    x.open("Resultados.txt");
    if (!x.is_open()) {
        cout << "O arquivo EscolasGeradasPorMim nao foi aberto\n";
        exit(-1);
    }

    for (auto e : escolas) {
        x << e.getNome() << " possui " << e.getVagas() << " vagas e " << "quer hab = " << e.getHabilidades() << " e tem os profIdeais = {\n";
        for (auto p : e.getProfessoresIdeais()) {
            x << '\t' << p.getNome() << " com " << p.getHabilitacoes() << " hab\n";
        }
        x << "}\n";
    }
}

void Graph::galeShapley(Escola& e) {
    ofstream x;
    x.open("jesus.txt");
    if (!x.is_open()) {
        cout << "O arquivo EscolasGeradasPorMim nao foi aberto\n";
        exit(-1);
    }

    auto getPos = [](vector<Escola> v, Escola buscada) -> int {
        return (find(v.begin(), v.end(), buscada) - v.begin());
    };

    int empregados = 0;
    while (empregados < 67) {
        for (auto k = grafo.begin(); k != grafo.end(); k++) {
            auto& p = *k;
            // if (p.getEscolaIdeal()->getNome() != "null") {
            //     continue;
            // }
            x << "Avaliando possibilidades para o prof " << p.getNome() << ": \n";
            for (int i = 0; i < 5; i++) {

                Escola& escolaAtual = escolas[getPos(escolas, p.getEscolasDeInteresse()[i])];

                x << "profs ideais (antes do if) da " << escolaAtual.getNome() << " = ";
                for (auto& pi : escolaAtual.getProfessoresIdeais()) {
                    x << pi.getNome() << ", ";
                }
                x << "\n";
                x << "vagas (antes do if) da " << escolaAtual.getNome() << " = " << escolaAtual.getVagas() << "\n";

                if (escolaAtual.getProfessoresIdeais().front().getNome() == "null" && p.getHabilitacoes() == escolaAtual.getHabilidades()) {
                    escolaAtual.removeProfessorIdeal(escolaAtual.getProfessoresIdeais().front());
                    escolaAtual.addProfessorIdeal(p);
                    p.setEscolaIdeal(&escolaAtual);
                    escolaAtual.diminuiVagas();
                    x << "profs ideal (null && p.H == e.H) da " << escolaAtual.getNome() << " = ";
                    for (auto& pi : escolaAtual.getProfessoresIdeais()) {
                        x << pi.getNome() << ", ";
                    }
                    x << "\n";
                    empregados++;
                    break;
                } else {
                    if (escolaAtual.getVagas() > 0 && escolaAtual.getProfessoresIdeais().front().getNome() != "null") {
                        if (p.getHabilitacoes() >= escolaAtual.getHabilidades()) {
                            escolaAtual.addProfessorIdeal(p);
                            p.setEscolaIdeal(&escolaAtual);
                            escolaAtual.diminuiVagas();
                            x << "profs ideal (!null && e.V > 0 && p.H >= e.H) da " << escolaAtual.getNome() << " = ";
                            for (auto& pi : escolaAtual.getProfessoresIdeais()) {
                                x << pi.getNome() << ", ";
                            }
                            x << "\n";
                            empregados++;
                            break;
                        }
                    } else {
                        bool mudou = false;
                        for (auto& pi : escolaAtual.getProfessoresIdeais()) {
                            if (p.getHabilitacoes() > pi.getHabilitacoes() && p.getHabilitacoes() == escolaAtual.getHabilidades()) {
                                escolaAtual.removeProfessorIdeal(pi);
                                escolaAtual.addProfessorIdeal(p);
                                p.setEscolaIdeal(&escolaAtual);
                                
                                find(grafo.begin(), grafo.end(), pi)->setEscolaIdeal(&e);
                                // cout << "nani : " << find(grafo.begin(), grafo.end(), pi)->getEscolaIdeal()->getHabilidades() << " a\n";

                                x << "Agora o prof " << pi.getNome() << " tem escolas ideal = " << find(grafo.begin(), grafo.end(), pi)->getEscolaIdeal()->getNome() << "\n";


                                x << "profs ideal (!null && e.V <= 0 && p.H > e.P[x].H && p.H == e.H) da " << escolaAtual.getNome() << " = ";
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

        // tentativa de deixar pelo menos todas as escolas com 1 professor, deu certo, mas o problema ta la encima ainda.
        for (auto& x : escolas) {
            if (x.getProfessoresIdeais().front().getNome() == "null") {
                auto pos = find_if(escolas.begin(), escolas.end(), [&x] (Escola& y) -> bool {
                        return (
                            y.getProfessoresIdeais().front().getNome() != "null" && x.getNome() != y.getNome() 
                            && x.getHabilidades() == y.getHabilidades() && y.getProfessoresIdeais().size() > 1
                        );
                });

                if (pos != escolas.end()) {
                    Escola& escolaQpossuiHabIgual_e_MaisDeUmProf = escolas[pos - escolas.begin()];
                    // nao faço ideia se funciona
                    for (auto& prof : escolaQpossuiHabIgual_e_MaisDeUmProf.getProfessoresIdeais()) {
                        auto& procuraEscolaIdealQueTemVaga = find_if(prof.getEscolasDeInteresse().begin(), prof.getEscolasDeInteresse().end(), [&x] (Escola& e) {
                            return (x.getNome() == e.getNome());
                        });
                        if (procuraEscolaIdealQueTemVaga != prof.getEscolasDeInteresse().end()) {
                            x.removeProfessorIdeal(x.getProfessoresIdeais().front());
                            x.addProfessorIdeal(prof);
                            // procuraEscolaIdealQueTemVaga->addProfessorIdeal(prof);        
                            pos->getProfessoresIdeais().front().setEscolaIdeal(&x);
                            escolaQpossuiHabIgual_e_MaisDeUmProf.removeProfessorIdeal(prof);
                            // escolaQpossuiHabIgual_e_MaisDeUmProf.removeProfessorIdeal(pos->getProfessoresIdeais().front());
                        }
                    }
                }
            }
        }

        int k = 0;
        for (auto x : escolas) {
            if (x.getProfessoresIdeais().front().getNome() == "null") {
                cout << "escola " << x.getNome() << " esta sem professor pois deseja " << x.getHabilidades() << " habs\n";
                ++k;
            }
        }

        cout << "sao " << k << " escolas sem prof\n";
        
        cout << "temos " << empregados << " professores empregados\n";
    }
}