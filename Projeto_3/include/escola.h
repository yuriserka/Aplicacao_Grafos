#ifndef Escola_h_
#define Escola_h_

#include <bits/stdc++.h>
using namespace std;

// #include "professor.h"

class Escola {
    public:

        Escola() {
            this->nome = "null";
            this->vagas = -1;
        }

        Escola(string nome, vector<int> habs, int vagas) {
            this->nome = nome;
            this->habilidadesRequeridas = habs;
            this->vagas = vagas;
        }

        void addProfessorIdeal(string professorIdeal) {
            this->professoresIdeais.push_back(professorIdeal);
            this->vagas--;
            
            // if (this->habilidadesRequeridas.size() > 1) {
            //     if (this->habilidadesRequeridas[0] == this->habilidadesRequeridas[1]) {
            //         if (this->habilidadesRequeridas[0] == false) {
            //             this->marcador[0].second = true;
            //             this->marcador[0].first = professor->getHabilidade();
            //         } else {
            //             this->marcador[1].second = true;
            //             this->marcador[1].first = professor->getHabilidade();
            //         }
            //     } else {
            //         for (size_t i = 0; i < this->habilidadesRequeridas.size(); i++) {
            //             if (professor->getHabilidade() >= this->habilidadesRequeridas[i]) {
            //                 this->marcador[i].first = professor->getHabilidade();
            //                 this->marcador[i].second = true;
            //             }
            //         }
            //     }
            // } else {
            //     this->marcador.front().second = true;
            //     this->marcador.front().first = professor->getHabilidade();
            // }
        }

        void removerProfessorIdeal(string professorRemovido) {
            this->professoresIdeais.erase(find(this->professoresIdeais.begin(),
                this->professoresIdeais.end(), professorRemovido));
            this->vagas++;

            // if (this->habilidadesRequeridas.size() > 1) {
            //     if (this->habilidadesRequeridas[0] == this->habilidadesRequeridas[1]) {
            //         if (this->habilidadesRequeridas[0] == true) {
            //             this->marcador[0].second = false;
            //         } else {
            //             this->marcador[1].second = false;
            //         }
            //     } else {
            //         for (size_t i = 0; i < this->habilidadesRequeridas.size(); i++) {
            //             if (professor->getHabilidade() == this->habilidadesRequeridas[i]) {
            //                 this->marcador[i].second = true;
            //             }
            //         }
            //     }
            // } else {
            //     this->marcador.front().second = false;
            //     this->marcador.front().first = 0;
            // }
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

        vector<string> getProfessoresIdeais() {
            return this->professoresIdeais;
        }

    private:
        vector<string> professoresIdeais;
        string nome;
        int vagas;
        vector<int> habilidadesRequeridas;
        // vector<pair<int, bool>> marcador;
};

#endif // Escola_h_