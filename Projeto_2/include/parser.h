#ifndef Parser_h_
#define Parser_h_

/**
 * @brief 
 * 
 * @file parser.h
 * @author Yuri Serka e Henrique Mendes
 * @date 2018-10-08
 */

#include "graph.h"

/**
 * @brief Classe Parser.
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
         * @brief preencherGrafo pega do arquivo todos os nós, pesos e arestas e constrói o grafo em memória primária.
         * 
         * @param recebe um grafo do tipo Graph
         */
        void preencherGrafo(Graph& grafo);
    private:
        fstream file;
};

#endif // Parser_h_