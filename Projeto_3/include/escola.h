#ifndef Escola_h_
#define Escola_h_

#include <string>
#include <vector>
#include <iostream>

struct Escola {
    std::string nome_;
    int quantidade_de_vagas_;
    std::vector<int> habilidades_requerida_;
    std::vector<std::string> professores_;

    Escola(const std::string &nome, const int &quantidade_de_vagas,
           const std::vector<int> &habilidades_requerida) {
        this->nome_ = nome;
        this->quantidade_de_vagas_ = quantidade_de_vagas;
        this->habilidades_requerida_ = habilidades_requerida;

        this->professores_.resize(quantidade_de_vagas);
    }

    void addProfessorOfPreference(const std::string &professor,
                                  const int &pref_pos) {
        this->professores_[pref_pos] = professor;
    }
};

#endif