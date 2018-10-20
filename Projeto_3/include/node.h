#ifndef Node_h_
#define Node_h_

#include <bits/stdc++.h>

using namespace std;

class Professor {
    public:
        Professor() = default;

        Professor(string nome, int habilitacoes, vector<string> escolas) {
            this->setNome(nome);
            this->setHabilitacoes(habilitacoes);
            this->setEscolasDeInteresse(escolas);
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        void setEscolasDeInteresse(vector<string> escolas) {
            this->escolas = escolas;
        }

        void setHabilitacoes(int habilitacoes) {
            this->habilitacoes = habilitacoes;
        }

        string getNome() const {
            return this->nome;
        }

        int getHabilitacoes() const {
            return this->habilitacoes;
        }

        vector<string> getEscolas() const {
            return this->escolas;
        }
    private:
        string nome;
        int habilitacoes;
        vector<string> escolas;
};

class Escola {
    public:
        Escola() = default;

        Escola(string nome, int habilidadesPedidas, int vagas) {
            this->setNome(nome);
            this->setHabilidades(habilidadesPedidas);
            this->setVagas(vagas);
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        void setVagas(int vagas) {
            this->vagas = vagas;
        }

        void setHabilidades(int habilidadeRequeridas) {
            this->habilidadeRequeridas = habilidadeRequeridas;
        }

        string getNome() const {
            return this->nome;
        }

        int getHabilidades() const {
            return this->habilidadeRequeridas;
        }

        int getVagas() const {
            return this->vagas;
        }
    private:
        string nome;
        int vagas;
        int habilidadeRequeridas;
};

#endif //Node_h_