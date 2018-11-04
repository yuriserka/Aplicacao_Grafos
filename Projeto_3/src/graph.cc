#include "../include/graph.h"

void Graph::addProfessor(Professor* p) {
    this->professores.push_back(p);
}

void Graph::addEscola(Escola* e) {
    this->escolas.push_back(e);
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
        x << "(" << node->getNome() << ", " << node->getHabilidade() << "): (";
        int i = 0;
        for (auto e : node->getCodigoDasEscolasDeInteresse()) {
            x << e;
            if (i < (int) node->getCodigoDasEscolasDeInteresse().size() - 1) {
                x << ", ";
            }
            i++;
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

    x << "//escolas e preferencias em termos de habilitacoes\n// formato (codigo escola):(habilitacoes pretendidas)\n\n";

    for (auto node : escolas) {
        x << "(" << node->getNome() << "):";
        for (size_t i = 0; i != node->getHabilidadesRequeridas().size(); i++) {
            x << "(" << node->getHabilidadesRequeridas()[i] << ")";
            if (i < node->getHabilidadesRequeridas().size() - 1) {
                x << ":";
            }
        }
        x << "\n";
    }
}

void Graph::addArestas() {
    for (auto professor : this->professores) {
        for (auto escolaDeInteresse : professor->getCodigoDasEscolasDeInteresse()) {
            for (auto e : this->escolas) {
                if (e->getNome() == escolaDeInteresse) {
                    professor->addEscolaDeInteresse(e);
                    break;
                }
            }
        }
    }
}

void Graph::Emparelhamentos() {
    this->addArestas();
    this->galeShapley();

    // printar resultados

}

// void Graph::galeShapley() {
    
//     while () {
//         for (auto e : escolas)
//     }


// }


//     if (escolas.empty()) {
//         this->addEscolas();
//     }

//     // sort(escolas.begin(), escolas.end());
//     escolas.sort();

//     Escola* e = new Escola();

//     for (auto& p : grafo) {
//         p->setEscolaIdeal(e);
//     }

//     Professor* p = new Professor();
//     for (auto& escola : escolas) {
//         escola->addProfessorIdeal(p);
//         p->setEscolaIdeal(e);
//     }

//     for (auto p : grafo) {
//         cout << p->getNome() << " -> ";
//         cout << p->getEscolaIdeal()->getNome() << "\n";
//     }

//     for (auto e : escolas) {
//         cout << e->getNome() << ": tem profs ideais = ";
//         for (auto p : e->getProfessoresIdeais()) {
//             cout << p->getNome() << ", ";
//         }
//         cout << "\n";
//     }

//     this->galeShapley();

//     ofstream y;
//     y.open("Resultados.txt");
//     if (!y.is_open()) {
//         cout << "O arquivo Resultados nao foi aberto\n";
//         exit(-1);
//     }

//     // for (auto& p : this->grafo) {
//     //     y << p.getNome() << " tem " << p.getHabilitacoes() << " habs e possui escola ideal = {\n\t" 
//     //         << p.getEscolaIdeal()->getNome() << "\n}\n";
//     // }

//     for (auto& e : this->escolas) {
//         y << e->getNome() << " possui " << e->getVagas() << " vagas e " << "quer hab = ";
//         for (auto& h : e->getHabilidades() ) { 
//             y << h << ","; 
//         } 
//         y << " e tem os profIdeais = {\n";
//         for (auto& pr : e->getProfessoresIdeais()) {
//             // auto pr = find(grafo.begin(), grafo.end(), p);
//             y << '\t' << pr->getNome() << " com " << pr->getHabilitacoes() << " hab => ";
//             y << "escola ideal do prof [ " << pr->getEscolaIdeal()->getNome() << " ]\n";
//         }
//         y << "}\n";
//     }
// }


// void Graph::galeShapley() {
//     ofstream x;
//     x.open("passos.txt");
//     if (!x.is_open()) {
//         cout << "O arquivo passos nao foi aberto\n";
//         exit(-1);
//     }
// }

// // solução(não completa) pela visao das escolas:
// //    dificuldade = quase nunca o professor vai estar na escola que ele realmente quer
// void Graph::galeShapley(Escola& e) {    
//     ofstream x;
//     x.open("passos.txt");
//     if (!x.is_open()) {
//         cout << "O arquivo passos nao foi aberto\n";
//         exit(-1);
//     }
//     // while (true) {
//         // bool naoPossuiMaisEscolaVazia = true;
//         for (auto& escola : this->escolas) {
//             x << "observando escola " << escola.getNome() << ":\n";   
//             for (auto& professor : this->grafo) {
//                 bool profAdicionado = false;
//                 for (auto escolaDeinteresse : professor.getEscolasDeInteresse()) {
//                     if (escolaDeinteresse.getNome() == escola.getNome()) {
//                         x << "o professor " << professor.getNome() << " tem interesse na escola " << escola.getNome() << "\n";
//                         for (auto hab : escola.getHabilidades()) {
//                             if (profAdicionado) {
//                                 break;
//                             }
//                             if (professor.getHabilitacoes() == hab) {
//                                 x << escola.getNome() << " pode recebe-lo, pois o professor tem hab = " 
//                                 << professor.getHabilitacoes() << " dentre as disponiveis: ";
//                                 for (auto a : escola.getHabilidades()) {
//                                     x << a << ",";
//                                 }
//                                 x << "\n";
//                                 if (escola.getVagas() <= 0) {
//                                     x << escola.getNome() << " nao possui mais vagas, portanto: \n";
//                                     for (auto& pi : escola.getProfessoresIdeais()) {
//                                         x << "\tolhando para o prof ideal " << pi.getNome() << ":\n";

//                                         int interesseDoProfessor;
//                                         int interesseDoPI;

//                                         for (size_t i = 0; i < pi.getEscolasDeInteresse().size(); i++) {
//                                             if (escola.getNome() == pi.getEscolasDeInteresse()[i].getNome()) {
//                                                 interesseDoPI = pi.getEscolasDeInteresse().size() - i;
//                                                 break;
//                                             }
//                                         }

//                                         for (size_t i = 0; i < professor.getEscolasDeInteresse().size(); i++) {
//                                             if (escola.getNome() == professor.getEscolasDeInteresse()[i].getNome()) {
//                                                 interesseDoProfessor = professor.getEscolasDeInteresse().size() - i;
//                                                 break;
//                                             }
//                                         }

//                                         x << "o prof " << professor.getNome() << " tem " << interesseDoProfessor << " de interesse na escola " << escola.getNome() << "\n";
//                                         x << "o prof ideal " << pi.getNome() << " tem " << interesseDoPI << " de interesse na escola " << escola.getNome() << "\n";
                                        
//                                         if (interesseDoProfessor > interesseDoPI) {
//                                             x << "o prof " << professor.getNome() << " tem mais interesse em " << escola.getNome() << " do que o " << pi.getNome() << "\n";
//                                             escola.removeProfessorIdeal(pi);
//                                             pi.setEscolaIdeal(new Escola());
//                                             escola.addProfessorIdeal(professor);
//                                             professor.setEscolaIdeal(&escola);
//                                             x << "setando escola ideal do " << professor.getNome() << " para " << professor.getEscolaIdeal()->getNome() << "\n";
//                                             x << "setando escola ideal do " << pi.getNome() << " para " << pi.getEscolaIdeal()->getNome() << "\n";
//                                             profAdicionado = true;
//                                             break;
//                                         }

//                                         // for (auto h : escola.getHabilidades()) {
//                                         //     if (professor.getHabilitacoes() == h && pi.getHabilitacoes() != h) {
//                                         //         escola.removeProfessorIdeal(pi);
//                                         //         pi.setEscolaIdeal(new Escola());
//                                         //         escola.addProfessorIdeal(professor);
//                                         //         professor.setEscolaIdeal(&escola);
//                                         //         x << "setando escola ideal do " << professor.getNome() << " para " << professor.getEscolaIdeal()->getNome() << "\n";
//                                         //         x << "setando escola ideal do " << pi.getNome() << " para " << pi.getEscolaIdeal()->getNome() << "\n";
//                                         //         profAdicionado = true;
//                                         //         break;
//                                         //     }
//                                         // }
//                                         if (profAdicionado) {
//                                             break;
//                                         }
//                                     }
//                                 } else {
//                                     escola.addProfessorIdeal(professor);
//                                     professor.setEscolaIdeal(&escola);
//                                     x << "setando escola ideal do " << professor.getNome() << " para " << professor.getEscolaIdeal()->getNome() << "\n";
//                                     profAdicionado = true;
//                                     break;
//                                 }
//                             } else {
//                                 x << "o professor " << professor.getNome() << " nao atende a hab = " << hab << "\n";
//                             }
//                             if (profAdicionado) {
//                                 break;
//                             }
//                         }
//                     }
//                 }
//                 if (escola.getVagas() == 0) {
//                     break;
//                 }
//                 // x << "lista dos professores ideais: ";
//                 // for (auto pi : escola.getProfessoresIdeais()) {
//                 //     x << pi.getNome() << "; ";
//                 // }
//                 x << "\n\n";
//             } 
//         // }

//         // for (auto& escola : this->escolas) {
//         //     if (escola.getProfessoresIdeais().empty()) {
//         //         naoPossuiMaisEscolaVazia = false;
//         //         break;
//         //     }
//         // }

//         // break;

//         // if (naoPossuiMaisEscolaVazia) {
//         //     break;
//         // }
//     }
// }

// void Graph::galeShapley(Escola& e) {
//     ofstream x;
//     x.open("passos.txt");
//     if (!x.is_open()) {
//         cout << "O arquivo passos nao foi aberto\n";
//         exit(-1);
//     }

//     ofstream y;
//     y.open("Resultados.txt");
//     if (!y.is_open()) {
//         cout << "O arquivo Resultados nao foi aberto\n";
//         exit(-1);
//     }
//     // bool continua = true;
//     // do {
//         for (auto it = this->grafo.begin(); it != this->grafo.end(); it++) {
//             Professor* professor = &*it;
//             bool professorAdicionado = false;
//             x << "Analisando professor " << professor->getNome() << ":\n";
            
//             for (auto& escolaInteressante : professor->getEscolasDeInteresse()) {
//             //     for (auto eIt = this->escolas.begin(); eIt != this->escolas.end(); eIt++) {
//             //         if (eIt->getNome() == escolaInteressante.getNome()) {
//             //             break;
//             //             escolaDeInteresse = &*eIt;
//             //         }
//             //     }
//                 // escolaDeInteresse = 
//                 auto escolaDeInteresse = &*find(this->escolas.begin(), 
//                         this->escolas.end(), escolaInteressante);

//                 for (int& habReq : escolaDeInteresse->getHabilidades()) {
//                     if (professor->getHabilitacoes() == habReq) {
//                         x << escolaDeInteresse->getNome() << " pode recebe-lo, pois o professor tem hab = " 
//                             << professor->getHabilitacoes() << " dentre as disponiveis: ";
//                             for (auto a : escolaDeInteresse->getHabilidades()) {
//                                 x << a << ",";
//                             }
//                             x << "\n";
//                         if (escolaDeInteresse->getProfessoresIdeais().front().getNome() == "null") {
//                             escolaDeInteresse->removeProfessorIdeal(escolaDeInteresse->getProfessoresIdeais().front());
//                         }
//                         if (escolaDeInteresse->getVagas() == 0) {
//                             x << escolaDeInteresse->getNome() << " nao possui mais vagas, logo: \n";
//                             for (auto& pr : escolaDeInteresse->getProfessoresIdeais()) {
                                
//                                 Professor* profIdealAtual = &*find(this->grafo.begin(), this->grafo.end(), pr);

//                                 if (professorAdicionado) {
//                                     break;
//                                 }

//                                 x << "\tolhando para os professor ideal: " << profIdealAtual->getNome() << "\n";
//                                 int posDaEscolaDeInteresse;
//                                 int posDaEscolaDeInteresseDoAtual;

//                                 for (size_t i = 0; i < profIdealAtual->getEscolasDeInteresse().size(); i++) {
//                                     if (escolaDeInteresse->getNome() == profIdealAtual->getEscolasDeInteresse()[i].getNome()) {
//                                         posDaEscolaDeInteresseDoAtual = profIdealAtual->getEscolasDeInteresse().size() - i;
//                                         break;
//                                     }
//                                 }

//                                 for (size_t i = 0; i < professor->getEscolasDeInteresse().size(); i++) {
//                                     if (escolaDeInteresse->getNome() == professor->getEscolasDeInteresse()[i].getNome()) {
//                                         posDaEscolaDeInteresse = professor->getEscolasDeInteresse().size() - i;
//                                         break;
//                                     }
//                                 }

//                                 if (professor->getHabilitacoes() >= profIdealAtual->getHabilitacoes()) {
//                                     x << posDaEscolaDeInteresse << " eh a prioridade da escola " << escolaDeInteresse->getNome() << " que ele quer entrar\n";
//                                     x << posDaEscolaDeInteresseDoAtual << " eh a prioridade da escola " << escolaDeInteresse->getNome() << " do prof " << profIdealAtual->getNome() << "\n";
//                                     x << professor->getNome() << " possui >= hab que o " << profIdealAtual->getNome() << "\n";

//                                     if (posDaEscolaDeInteresse > posDaEscolaDeInteresseDoAtual) {
//                                         x << "o prof tem mais preferencia pela escola " << escolaDeInteresse->getNome() << " do que o " << profIdealAtual->getNome() << "\n";
//                                         escolaDeInteresse->removeProfessorIdeal(*profIdealAtual);
//                                         // empregados--;
//                                         escolaDeInteresse->addProfessorIdeal(*professor);
//                                         // empregados++;
//                                         // escolaDeInteresse->removeHabilidade(habReq);
//                                         professor->setEscolaIdeal(escolaDeInteresse);
//                                         x << "setando escola ideal do " << professor->getNome() << " para " << professor->getEscolaIdeal()->getNome() << "\n";
//                                         profIdealAtual->setEscolaIdeal(&e);
//                                         x << "portanto agora o prof " << profIdealAtual->getNome() << " esta com a escola ideal = " << profIdealAtual->getEscolaIdeal()->getNome() << "\n";
//                                         professorAdicionado = true;
//                                         break;
//                                     }
//                                 } else {
//                                 //    if (posDaEscolaDeInteresse >= posDaEscolaDeInteresseDoAtual) {
//                                     //    for (auto hab : escolaDeInteresse->getHabilidades()) {
//                                         if (escolaDeInteresse->getHabilidades().front() == professor->getHabilitacoes()) {
//                                                 x << "a escola prefere mais " << professor->getNome() << " do que o " << profIdealAtual->getNome() << "\n";
//                                                 escolaDeInteresse->removeProfessorIdeal(*profIdealAtual);
//                                                 // empregados--;
//                                                 escolaDeInteresse->addProfessorIdeal(*professor);
//                                                 // empregados++;
//                                                 // escolaDeInteresse->removeHabilidade(habReq);
//                                                 professor->setEscolaIdeal(escolaDeInteresse);
//                                                 x << "setando escola ideal do " << professor->getNome() << " para " << professor->getEscolaIdeal()->getNome() << "\n";
//                                                 profIdealAtual->setEscolaIdeal(&e);
//                                                 x << "portanto agora o prof " << profIdealAtual->getNome() << " esta com a escola ideal = " << profIdealAtual->getEscolaIdeal()->getNome() << "\n";
//                                                 professorAdicionado = true;
//                                                 break;
//                                         }
//                                     //    }
//                                 //    } 
//                                 }
//                             }
//                         } else {
//                             // if (escolaDeInteresse->getHabilidadeMarcada(habReq)
//                             //         && !escolaDeInteresse->possuiHabilidadeMaisBaixa(professor->getHabilitacoes())) {
//                             //     x << "ja ha um professor com a hab " << habReq << " na escola " << escolaDeInteresse->getNome() << "\n";
//                             //     break; 
//                             // }
//                             escolaDeInteresse->addProfessorIdeal(*professor);
//                             professor->setEscolaIdeal(escolaDeInteresse);
//                             x << "setando escola ideal do " << professor->getNome() << " para " << professor->getEscolaIdeal()->getNome() << "\n";
//                             // escolaDeInteresse->removeHabilidade(habReq);
//                             // empregados++;
//                             professorAdicionado = true;
//                             break;
//                         }
//                     }
//                     if (professorAdicionado) {
//                         break;
//                     }
//                 }
//                 x << "profs ideias da escola: " << escolaDeInteresse->getNome() << " = ";
//                 for (auto a : escolaDeInteresse->getProfessoresIdeais()) {
//                     x << a.getNome() << ", ";
//                 }
//                 x << "\n";
//                 if (professorAdicionado) {
//                     // y << "foi adicionado o prof " << professor->getNome() << " na escola " << escolaDeInteresse->getNome() << "\n";
//                     // y << escolaDeInteresse->getNome() << " possui " << escolaDeInteresse->getVagas() << " vagas e " << "quer hab = ";
//                     // for (auto& h : escolaDeInteresse->getHabilidades() ) { 
//                     //     y << h << ","; 
//                     // } 
//                     // y << " e tem os profIdeais = {\n";
//                     // for (auto& p : escolaDeInteresse->getProfessoresIdeais()) {
//                     //     auto pr = find(grafo.begin(), grafo.end(), p);
//                     //     y << '\t' << pr->getNome() << " com " << pr->getHabilitacoes() << " hab => ";
//                     //     y << "escola ideal do prof [ " << pr->getEscolaIdeal()->getNome() << " ]\n";
//                     // }
//                     // y << "}\n\n";
//                     break;
//                 }
//             }
//             // int empregados = 0;
//             // for (auto& p : this->grafo) {
//             //     if (p.getEscolaIdeal()->getNome() != "null") {
//             //         empregados++;
//             //     }
//             // }
//             // cout << "professores empregados: " << empregados << "\n";
//             // if (empregados == 70) {
//             //     continua = false;
//                 break;
//             // }
//             x << "\n\n";
//         }
//     // } while (continua);
// }