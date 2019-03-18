#include "../include/grafo.h"

#include <iostream>
#include <algorithm>

void Grafo::addProfessor(Professor &professor) {
    this->professores_.emplace_back(professor);
}

void Grafo::addEscola(Escola &escola) {
    this->escolas_.emplace_back(escola);
}

void Grafo::print() {
    std::cout << "Lista dos professores => {\n";
    for (auto &professor : this->professores_) {
        std::string res = "\tnome: " + professor.nome_ + "; habilidade: "
            + std::to_string(professor.habilidade_)
            + "; escolas de interesse: ";
        for (auto &escola_de_interesse : professor.escolas_de_interesse_) {
            res += escola_de_interesse + ", ";
        }
        res.erase(res.find_last_of(','));

        std::cout << res << "\n";
    }
    std::cout << "}\n";

    std::cout << "Lista das escolas => {\n";
    for (auto &escola : this->escolas_) {
        std::string res = "\tnome: " + escola.nome_ + "; quantidade de vagas: "
            + std::to_string(escola.quantidade_de_vagas_)
            + "; habilidades requeridas: ";
        for (auto &habilidade : escola.habilidades_requerida_) {
            res += std::to_string(habilidade) + ", ";
        }
        res.erase(res.find_last_of(','));

        res += "; professores: ";
        for (auto &prof : escola.professores_) {
            res += prof + ", ";
        }
        res.erase(res.find_last_of(','));

        std::cout << res << "\n";
    }
    std::cout << "}\n";
}

void Grafo::galeShapley() {
    std::cout << "\tjust for teste\n\n";
    for (auto &escola : this->escolas_) {
        for (auto &professor : this->professores_) {
            escola.addProfessorOfPreference(professor.nome_, 0);
        }
    }
}