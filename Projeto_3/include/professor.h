#ifndef Professor_h_
#define Professor_h_

#include <string>
#include <vector>

struct Professor {
    std::string nome_;
    int habilidade_;
    std::vector<std::string> escolas_de_interesse_;

    Professor(const std::string &nome, const int &habilidade, 
              const std::vector<std::string> &escolas_de_interesse) {
        this->nome_ = nome;
        this->habilidade_ = habilidade;
        this->escolas_de_interesse_ = escolas_de_interesse;
    }
};

#endif