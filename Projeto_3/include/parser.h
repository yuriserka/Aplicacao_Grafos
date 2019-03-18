#ifndef Parser_h_
#define Parser_h_

#include <fstream>
#include <string>
#include <iostream>

#include "grafo.h"

/**
 * @brief esta classe é responsável por tratar o arquivo que irá conter o fluxo do curso, ou seja, fará a conversão do 
 * que está em texto e irá inserir no grafo para que possamos usar os dados.
 * 
 */
class Parser {
    public:
        /**
         * @brief Construtor default da classe Parser.
         * 
         */
        Parser() = default;

        /**
         * @brief Destrutor da classe Parser, no qual o arquivo é fechado antes do objeto ser destruído.
         * 
         */
        ~Parser() {
            file.close();
        }

        /**
         * @brief 
         * 
         * @param grafo 
         */
        void lerArquivos(Grafo* grafo);

    private:
        void setNomeDoArquivo(const std::string &nomeDoArquivo) {
            if (file.is_open()) {
                this->file.close();
            }
            this->file.open(nomeDoArquivo);
            if (!file.is_open()) {
                std::cout << "O arquivo " + nomeDoArquivo + " nao foi aberto\n";
                exit(-1);
            }
        }
        std::fstream file;
        const std::string nomeDoArquivoDosProfessores = "ListaDosProfessores.txt";
        const std::string nomeDosArquivoDasEscolas = "ListaDasEscolas.txt";
};

#endif // Parser_h_