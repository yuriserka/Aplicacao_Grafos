#ifndef Parser_h_
#define Parser_h_

#include "graph.h"

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
         * @brief Construtor da classe Parser, onde a partir do nome do arquivo, o arquivo é aberto.
         * 
         * @param nomeDoArquivo 
         */
        Parser(string nomeDoArquivo) {
            this->setNomeDoArquivo(nomeDoArquivo);
        }

        /**
         * @brief Set the Nome Do Arquivo object
         * 
         * @param nomeDoArquivo 
         */
        void setNomeDoArquivo(string nomeDoArquivo) {
            if (file.is_open()) {
                this->file.close();
            }
            this->file.open(nomeDoArquivo);
            if (!file.is_open()) {
                cout << "O arquivo nao foi aberto\n";
                exit(-1);
            }
        }

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
        void lerProfessores(Graph& grafo);

        /**
         * @brief 
         * 
         * @param grafo 
         */
        void lerEscolas(Graph& grafo);
    private:
        fstream file;
};

#endif // Parser_h_