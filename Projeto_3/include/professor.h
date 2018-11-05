#ifndef Professor_h_
#define Professor_h_

// class Professor;
#include "escola.h"

class Professor {
    public:

        Professor() {
            this->nome = "null";
            this->habilidade = -1;
        }

        Professor(string nome, int habilidade, vector<string> escolas) {
            this->nome = nome;
            this->habilidade = habilidade;
            this->codigosDasEscolas = escolas;
        }

        void addEscolaDeInteresse(Escola* escola) {
            this->escolasDeInteresse.push_back(escola);
        }

        void setEscolaIdeal(string escolaIdeal) {
            this->escolaIdeal = escolaIdeal;
        }

        void removeEscolaIdeal() {
            this->escolaIdeal = nullptr;
        }

        string getEscolaIdeal() {
            return this->escolaIdeal;
        }

        vector<string> getCodigoDasEscolasDeInteresse() {
            return this->codigosDasEscolas;
        }

        list<Escola*> getEscolasDeInteresse() {
            return this->escolasDeInteresse;
        }

        string getNome() {
            return this->nome;
        }

        int getHabilidade() {
            return this->habilidade;
        }

    private:
        string nome;
        vector<string> codigosDasEscolas;
        int habilidade;
        list<Escola*> escolasDeInteresse;
        string escolaIdeal;
};

#endif // Professor_h_