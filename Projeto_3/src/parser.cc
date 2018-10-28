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

                    Professor p(nomeDoProfessor, habilitacoesDoProfessor);

                    while(file >> s && s != "interesse");
                    vector<Escola> es;
                    for (int i = 0; i < 5; i++) {
                        file >> s;
                        if (i < 4) {
                            s.erase(s.size() - 1);
                        }
                        es.push_back(this->lerEscola(s, "ListaDasEscolas.txt"));
                    }
                    p.setEscolasDeInteresse(es);
                    grafo.addProfessor(p);
                }
            }
        }
    }
}

Escola Parser::lerEscola(string escolaBuscada, string arquivoDasEscolas) {
    string s;
    fstream file;
    file.open(arquivoDasEscolas);
    if (!file.is_open()) {
        cout << "O arquivo " << arquivoDasEscolas << " nao foi aberto\n";
        exit(-1);
    }
    
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
                    file >> s;
                    if (s == escolaBuscada) {
                        nomeDaEscola = s;

                        while(file >> s && s != "habilidades_Requeridas");
                        file >> habilidadesRequeridas;

                        while(file >> s && s != "vagas");
                        file >> vagas;

                        file.close();

                        return Escola(nomeDaEscola, habilidadesRequeridas, vagas);
                    }
                }
            }
        }
    }
    file.close();
    return Escola();
}