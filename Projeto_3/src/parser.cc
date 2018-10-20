#include "../include/parser.h"

void Parser::lerProfessores(Graph& grafo) {
    string s;
    while (file >> s) {
        if (s.find("//") != string::npos) {
            getline(file, s);
            continue;
        }

        if (s == "PROFESSORES") {
            string nomeDoProfessor;
            string interesses;
            vector<string> escolas;
            int habilitacoesDoProfessor;

            while (file >> s && s != "]fim") {
                if (s == "vertice") {
                    while(file >> s && s != "nome");
                    file >> nomeDoProfessor;

                    while(file >> s && s != "habilitacoes");
                    file >> habilitacoesDoProfessor;

                    while(file >> s && s != "interesse");
                    getline(file, interesses);
                    interesses.erase(interesses.begin());
                    interesses.erase(std::remove(interesses.begin(), interesses.end(), ','), interesses.end());

                    string escola;
                    for (std::size_t i = 0; i <= interesses.size(); i++) {
                        if (i == interesses.size()) {
                            escolas.push_back(escola);
                            escola.clear();
                        }
                        if (interesses[i] != ' ') {
                            escola += interesses[i];
                        } else {
                            escolas.push_back(escola);
                            escola.clear();
                        }
                    }
                    grafo.addProfessor(nomeDoProfessor, habilitacoesDoProfessor, escolas);
                    escolas.clear();
                }
            }
        }
    }
}

void Parser::lerEscolas(Graph& grafo) {
    string s;
    while (file >> s) {
        if (s.find("//") != string::npos) {
            getline(file, s);
            continue;
        }
        if (s == "ESCOLAS") {
            string nomeDaEscola;
            int habilidadesRequeridas;
            int vagas;

            while (file >> s && s != "]fim") {
                if (s == "vertice") {
                    while(file >> s && s != "nome");
                    file >> nomeDaEscola;

                    while(file >> s && s != "habilidades_Requeridas");
                    file >> habilidadesRequeridas;

                    while(file >> s && s != "vagas");
                    file >> vagas;

                    grafo.addEscola(nomeDaEscola, habilidadesRequeridas, vagas);
                }
            }
        }
    }
}