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
        for (auto& p : grafo) {
            for (auto& e : p.getEscolasDeInteresse()) {
                if (find(escolas.begin(), escolas.end(), e) == escolas.end()) {
                    escolas.push_back(e);
                }
            }
        }
    }

    sort(escolas.begin(), escolas.end());
    
    Escola e = Escola();

    for (auto& p : grafo) {
        p.setEscolaIdeal(&e);
    }

    Professor* p = new Professor();
    for (auto& escola : escolas) {
        escola.addProfessorIdeal(*p);
        p->setEscolaIdeal(&e);
    }

    this->galeShapley(e);

    ofstream y;
    y.open("Resultados.txt");
    if (!y.is_open()) {
        cout << "O arquivo Resultados nao foi aberto\n";
        exit(-1);
    }

    for (auto& p : this->grafo) {
        y << p.getNome() << " tem " << p.getHabilitacoes() << " habs e possui escola ideal = {\n\t" 
            << p.getEscolaIdeal()->getNome() << "\n}\n";
    }

    // for (auto& e : this->escolas) {
    //     y << e.getNome() << " possui " << e.getVagas() << " vagas e " << "quer hab = ";
    //     for (auto& h : e.getHabilidades() ) { 
    //         y << h << ","; 
    //     } 
    //     y << " e tem os profIdeais = {\n";
    //     for (auto& p : e.getProfessoresIdeais()) {
    //         auto pr = find(grafo.begin(), grafo.end(), p);
    //         y << '\t' << pr->getNome() << " com " << pr->getHabilitacoes() << " hab => ";
    //         y << "escola ideal do prof [ " << pr->getEscolaIdeal()->getNome() << " ]\n";
    //     }
    //     y << "}\n";
    // }
}


//// solução(não completa) pela visao das escolas:
////    dificuldade = quase nunca o professor vai estar na escola que ele realmente quer
// void Graph::galeShapley(Escola& e) {    
//     ofstream x;
//     x.open("passos.txt");
//     if (!x.is_open()) {
//         cout << "O arquivo passos nao foi aberto\n";
//         exit(-1);
//     }

//     for (auto& escola : this->escolas) {
//         x << "observando escola " << escola.getNome() << ":\n";   
//         for (auto& professor : this->grafo) {
//             for (auto interesse : professor.getEscolasDeInteresse()) {
//                 if (interesse.getNome() == escola.getNome()) {
//                     // cout << professor.getNome() << " possui interesse em " << escola.getNome() << "\n";
//                     // auto& esc = this->escolas[EhdeInteresse - professor.getEscolasDeInteresse().begin()];
//                     x << "o professor " << professor.getNome() << " tem interesse\n";
//                     if (!escola.getHabilidades().empty() 
//                             && professor.getHabilitacoes() >= escola.getHabilidades().front()) {
//                         // cout << "o professor " << professor.getNome() << " possui hab = " << professor.getHabilitacoes() << "\n";
//                         if (professor.getEscolaIdeal()->getNome() != "null") {
//                             break;
//                         }
//                         if(escola.getVagas() <= 0) {
//                             for (auto& profIdeal : escola.getProfessoresIdeais()) {
//                                 if (profIdeal.getHabilitacoes() < professor.getHabilitacoes()) {
//                                     escola.removeProfessorIdeal(profIdeal);
//                                     escola.aumentaVagas();
//                                     profIdeal.removeEscolaIdeal();
//                                     break;
//                                 }
//                             }
//                         }
//                         escola.removeProfessorIdeal(escola.getProfessoresIdeais().front());
//                         escola.addProfessorIdeal(professor);
//                         escola.diminuiVagas();
//                         professor.setEscolaIdeal(&escola);
                        
//                         escola.removeHabilidade(escola.getHabilidades().front());

//                         // escola.getHabilidades().erase(escola.getHabilidades().begin());

//                         x << "escola ideal do " << professor.getNome() << " = " << professor.getEscolaIdeal()->getNome() << "\n";
//                         break;
//                     }
//                 }
//             }

//             // cout << escolas[EhdeInteresse - professor.getEscolasDeInteresse().begin()].getNome() << "\n";

//             // if (EhdeInteresse != professor.getEscolasDeInteresse().end()) {
//             //     
//             // }
//         }
//         x << "lista dos professores ideais: ";
//         for (auto pi : escola.getProfessoresIdeais()) {
//             x << pi.getNome() << "; ";
//         }
//         x << "\n\n\n";
//     }
//     return;
// }

void Graph::galeShapley(Escola& e) {
    ofstream x;
    x.open("passos.txt");
    if (!x.is_open()) {
        cout << "O arquivo passos nao foi aberto\n";
        exit(-1);
    }

    ofstream y;
    y.open("Resultados.txt");
    if (!y.is_open()) {
        cout << "O arquivo Resultados nao foi aberto\n";
        exit(-1);
    }
    // bool continua = true;
    // do {
        for (auto it = this->grafo.begin(); it != this->grafo.end(); it++) {
            Professor* professor = &*it;
            bool professorAdicionado = false;
            x << "Analisando professor " << professor->getNome() << ":\n";
            for (auto& escolaInteressante : professor->getEscolasDeInteresse()) {
                Escola* escolaDeInteresse = &this->escolas[find(this->escolas.begin(), 
                        this->escolas.end(), escolaInteressante) - this->escolas.begin()];
                
                for (auto habReq : escolaDeInteresse->getHabilidades()) {
                    if (professor->getHabilitacoes() == habReq) {
                        x << escolaDeInteresse->getNome() << " pode recebe-lo, pois o professor tem hab = " 
                            << professor->getHabilitacoes() << " dentre as disponiveis: ";
                            for (auto a : escolaDeInteresse->getHabilidades()) {
                                x << a << ",";
                            }
                            x << "\n";
                        if (escolaDeInteresse->getProfessoresIdeais().front().getNome() == "null") {
                            escolaDeInteresse->removeProfessorIdeal(escolaDeInteresse->getProfessoresIdeais().front());
                        }
                        if (escolaDeInteresse->getVagas() == 0) {
                            x << escolaDeInteresse->getNome() << " nao possui mais vagas, logo: \n";
                            for (auto& pr : escolaDeInteresse->getProfessoresIdeais()) {
                                
                                Professor* profIdealAtual = &*find(this->grafo.begin(), this->grafo.end(), pr);

                                if (professorAdicionado) {
                                    break;
                                }

                                x << "\tolhando para os professor ideal: " << profIdealAtual->getNome() << "\n";
                                int posDaEscolaDeInteresse;
                                int posDaEscolaDeInteresseDoAtual;

                                for (size_t i = 0; i < profIdealAtual->getEscolasDeInteresse().size(); i++) {
                                    if (escolaDeInteresse->getNome() == profIdealAtual->getEscolasDeInteresse()[i].getNome()) {
                                        posDaEscolaDeInteresseDoAtual = profIdealAtual->getEscolasDeInteresse().size() - i;
                                        break;
                                    }
                                }

                                for (size_t i = 0; i < professor->getEscolasDeInteresse().size(); i++) {
                                    if (escolaDeInteresse->getNome() == professor->getEscolasDeInteresse()[i].getNome()) {
                                        posDaEscolaDeInteresse = professor->getEscolasDeInteresse().size() - i;
                                        break;
                                    }
                                }

                                if (professor->getHabilitacoes() >= profIdealAtual->getHabilitacoes()) {
                                    x << posDaEscolaDeInteresse << " eh a prioridade da escola " << escolaDeInteresse->getNome() << " que ele quer entrar\n";
                                    x << posDaEscolaDeInteresseDoAtual << " eh a prioridade da escola " << escolaDeInteresse->getNome() << " do prof " << profIdealAtual->getNome() << "\n";
                                    x << professor->getNome() << " possui >= hab que o " << profIdealAtual->getNome() << "\n";

                                    if (posDaEscolaDeInteresse > posDaEscolaDeInteresseDoAtual) {
                                        x << "o prof tem mais preferencia pela escola " << escolaDeInteresse->getNome() << " do que o " << profIdealAtual->getNome() << "\n";
                                        escolaDeInteresse->removeProfessorIdeal(*profIdealAtual);
                                        // empregados--;
                                        escolaDeInteresse->addProfessorIdeal(*professor);
                                        // empregados++;
                                        // escolaDeInteresse->removeHabilidade(habReq);
                                        professor->setEscolaIdeal(escolaDeInteresse);
                                        x << "setando escola ideal do " << professor->getNome() << " para " << professor->getEscolaIdeal()->getNome() << "\n";
                                        profIdealAtual->setEscolaIdeal(&e);
                                        x << "portanto agora o prof " << profIdealAtual->getNome() << " esta com a escola ideal = " << profIdealAtual->getEscolaIdeal()->getNome() << "\n";
                                        professorAdicionado = true;
                                        break;
                                    }
                                } else {
                                //    if (posDaEscolaDeInteresse >= posDaEscolaDeInteresseDoAtual) {
                                    //    for (auto hab : escolaDeInteresse->getHabilidades()) {
                                        if (escolaDeInteresse->getHabilidades().front() == professor->getHabilitacoes()) {
                                                x << "a escola prefere mais " << professor->getNome() << " do que o " << profIdealAtual->getNome() << "\n";
                                                escolaDeInteresse->removeProfessorIdeal(*profIdealAtual);
                                                // empregados--;
                                                escolaDeInteresse->addProfessorIdeal(*professor);
                                                // empregados++;
                                                // escolaDeInteresse->removeHabilidade(habReq);
                                                professor->setEscolaIdeal(escolaDeInteresse);
                                                x << "setando escola ideal do " << professor->getNome() << " para " << professor->getEscolaIdeal()->getNome() << "\n";
                                                profIdealAtual->setEscolaIdeal(&e);
                                                x << "portanto agora o prof " << profIdealAtual->getNome() << " esta com a escola ideal = " << profIdealAtual->getEscolaIdeal()->getNome() << "\n";
                                                professorAdicionado = true;
                                                break;
                                        }
                                    //    }
                                //    } 
                                }
                            }
                        } else {
                            escolaDeInteresse->addProfessorIdeal(*professor);
                            professor->setEscolaIdeal(escolaDeInteresse);
                            x << "setando escola ideal do " << professor->getNome() << " para " << professor->getEscolaIdeal()->getNome() << "\n";
                            // escolaDeInteresse->removeHabilidade(habReq);
                            // empregados++;
                            professorAdicionado = true;
                            break;
                        }
                    }
                    if (professorAdicionado) {
                        break;
                    }
                }
                x << "profs ideias da escola: " << escolaDeInteresse->getNome() << " = ";
                for (auto a : escolaDeInteresse->getProfessoresIdeais()) {
                    x << a.getNome() << ", ";
                }
                x << "\n";
                if (professorAdicionado) {
                    // y << "foi adicionado o prof " << professor->getNome() << " na escola " << escolaDeInteresse->getNome() << "\n";
                    // y << escolaDeInteresse->getNome() << " possui " << escolaDeInteresse->getVagas() << " vagas e " << "quer hab = ";
                    // for (auto& h : escolaDeInteresse->getHabilidades() ) { 
                    //     y << h << ","; 
                    // } 
                    // y << " e tem os profIdeais = {\n";
                    // for (auto& p : escolaDeInteresse->getProfessoresIdeais()) {
                    //     auto pr = find(grafo.begin(), grafo.end(), p);
                    //     y << '\t' << pr->getNome() << " com " << pr->getHabilitacoes() << " hab => ";
                    //     y << "escola ideal do prof [ " << pr->getEscolaIdeal()->getNome() << " ]\n";
                    // }
                    // y << "}\n\n";
                    break;
                }
            }
            // int empregados = 0;
            // for (auto& p : this->grafo) {
            //     if (p.getEscolaIdeal()->getNome() != "null") {
            //         empregados++;
            //     }
            // }
            // cout << "professores empregados: " << empregados << "\n";
            // if (empregados == 70) {
            //     continua = false;
            //     break;
            // }
            x << "\n\n";
        }
    // } while (continua);
}