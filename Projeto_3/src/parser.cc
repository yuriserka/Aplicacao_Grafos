#include "../include/parser.h"

void Parser::lerArquivos(Graph& grafo) {

    this->setNomeDoArquivo(this->nomeDoArquivoDosProfessores);

    string s;
    while (this->file >> s) {
        if (s.find("//") != string::npos) {
            getline(file, s);
            continue;
        }

        if (s == "PROFESSORES") {
            string nomeDoProfessor;
            string interesses;
            vector<string> escolas;
            int habilitacoesDoProfessor;

            while (this->file >> s && s != "]fim") {
                if (s == "vertice") {
                    while(this->file >> s && s != "nome");
                    file >> nomeDoProfessor;

                    while(this->file >> s && s != "habilitacoes");
                    file >> habilitacoesDoProfessor;

                    while(this->file >> s && s != "interesse");
                    vector<string> es;
                    for (int i = 0; i < 5; i++) {
                        file >> s;
                        if (i < 4) {
                            s.erase(s.size() - 1);
                        }

                        es.push_back(s);
                    }
                    Professor* p = new Professor(nomeDoProfessor, habilitacoesDoProfessor, es);
                    grafo.addProfessor(p);
                }
            }
        }
    }

    this->setNomeDoArquivo(this->nomeDosArquivoDasEscolas);

    while (this->file >> s) {
        if (s.find("//") != string::npos) {
            getline(this->file, s);
            continue;
        }
        if (s == "ESCOLAS") {
            while (this->file >> s && s != "]fim") {
                if (s == "vertice") {
                    string nomeDaEscola;
                    while(this->file >> s && s != "nome");
                    this->file >> nomeDaEscola;

                    int vagas;
                    while(this->file >> s && s != "vagas");
                    this->file >> vagas;

                    while(this->file >> s && s != "habilidades_Requeridas");
                    vector<int> habilidades;
                    int habilidadesRequeridas;
                    for (int i = 0; i < vagas; i++) {
                        this->file >> s;
                        if (i < vagas - 1) {
                            s.erase(s.size() - 1);
                        }
                        habilidadesRequeridas = stoi(s);
                        habilidades.push_back(habilidadesRequeridas);
                    }
                    Escola* escola = new Escola(nomeDaEscola, habilidades, vagas);
                    grafo.addEscola(escola);
                }
            }
        }
    }
}