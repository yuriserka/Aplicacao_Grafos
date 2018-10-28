#ifndef Node_h_
#define Node_h_

#include <bits/stdc++.h>

using namespace std;

class Escola;
class Professor;

class Professor {
    public:
        Professor() = default;

        Professor(string nome, int habilitacoes) {
            this->setNome(nome);
            this->setHabilitacoes(habilitacoes);
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        void setEscolasDeInteresse(vector<Escola> escolas) {
            this->escolas = escolas;
        }

        void setHabilitacoes(int habilitacoes) {
            this->habilitacoes = habilitacoes;
        }

        void setEscolaIdeal(Escola *escolaIdeal) {
            this->escolaIdeal = escolaIdeal;
        }

        string getNome() const {
            return this->nome;
        }

        int getHabilitacoes() const {
            return this->habilitacoes;
        }

        vector<Escola> getEscolasDeInteresse() {
            return this->escolas;
        }

        Escola* getEscolaIdeal() const {
            return this->escolaIdeal;
        }

        bool operator==(const Professor& lhs) const {
            return this->nome == lhs.getNome();
        }
    private:
        string nome;
        int habilitacoes;
        vector<Escola> escolas;
        Escola* escolaIdeal;
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

        void addProfessorIdeal(Professor& professorIdeal) {
            this->professoresIdeais.push_back(professorIdeal);
        }

        void removeProfessorIdeal(Professor& professorRemovido) {
            this->professoresIdeais.erase(find(this->professoresIdeais.begin(), this->professoresIdeais.end(), professorRemovido));
        }
        
        void diminuiVagas() {
            this->vagas -= 1;
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

        list<Professor> getProfessoresIdeais() {
            return this->professoresIdeais;
        }

        bool operator==(const Escola& lhs) const {
            return this->nome == lhs.getNome();
        }

        bool operator<(const Escola& lhs) const {
            return lexicographical_compare(this->nome.begin(), this->nome.end(), lhs.getNome().begin(), lhs.getNome().end());
        }
    private:
        string nome;
        int vagas;
        int habilidadeRequeridas;
        list<Professor> professoresIdeais;
};

#endif //Node_h_