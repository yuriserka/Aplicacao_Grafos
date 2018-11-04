#ifndef Escola_h_
#define Escola_h_

#include <bits/stdc++.h>
using namespace std;

#include "professor.h"

class Escola {
    public:

        Escola() : nome("null"), vagas(-1) {}

        Escola(string nome, vector<int> habs, int vagas) {
            this->nome = nome;
            this->habilidadesRequeridas = habs;
            this->vagas = vagas;
        }

        void addProfessorIdeal(Professor* professor) {
            this->professoresIdeais.push_back(professor);
        }

        void removerProfessorIdeal(Professor* professor) {
            auto pos = this->professoresIdeais.begin();
            for (; pos != this->professoresIdeais.end(); pos++) {
                auto profAtual = *pos;
                if (profAtual->getNome() == professor->getNome()) {
                    break;
                }
            }
            this->professoresIdeais.erase(pos); 
        }

        int getVagas() const {
            return this->vagas;
        }

        string getNome() const {
            return this->nome;
        }

        vector<int> getHabilidadesRequeridas() const {
            return this->habilidadesRequeridas;
        }

        list<Professor*> getProfessoresIdeais() {
            return this->professoresIdeais;
        }

    private:
        list<Professor*> professoresIdeais;
        string nome;
        int vagas;
        vector<int> habilidadesRequeridas;
};

#endif // Escola_h_