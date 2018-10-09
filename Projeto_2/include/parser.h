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
         * @brief Construct a new Parser object.
         * 
         */
        Parser() = default;

        /**
         * @brief Construct a new Parser object.
         * 
         * @param fileName 
         */
        Parser(string nomeDoArquivo) {
            this->file.open(nomeDoArquivo);
            if (!file.is_open()) {
                cout << "O arquivo nao foi aberto\n";
                exit(-1);
            }
        }

        /**
         * @brief Destroy the Parser object.
         * 
         */
        ~Parser() {
            file.close();
        }

        /**
         * @brief preencherGrafo pega do arquivo todos os nós, pesos e arestas e constrói o grafo em memória primária.
         * 
         * @param graph 
         */
        void preencherGrafo(Graph& grafo);
    private:
        fstream file;
};

#endif // Parser_h_