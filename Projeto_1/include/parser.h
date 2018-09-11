#ifndef Parser_h_
#define Parser_h_

/**
 * @brief 
 * 
 * @file parser.h
 * @author Yuri Serka e Henrique Mendes
 * @date 2018-09-08
 */

#include "../include/graph.h"

/**
 * @brief Classe que tem a responsabilidade de ler o arquivo
 * 
 */
class Parser {
    public:
        /**
         * @brief Construtor padrao do parser
         * 
         */
        Parser() = default;

        /**
         * @brief constroi o parser passando o nome do arquivo que contem as arestas
         * 
         * @param fileName 
         */
        Parser(string fileName) {
            this->file.open(fileName);
            if (!file.is_open()) {
                cout << "O arquivo nao foi aberto\n";
                exit(-1);
            }
        }

        /**
         * @brief Destrutor da classe que fecha o arquivo.
         * 
         */
        ~Parser() {
            file.close();
        }

        /**
         * @brief Le do arquivo e insere os dados no grafo passado.
         * 
         */
        void insertOnGraph(Graph& graph);
    private:
    
        /**
         * @brief Variavel para manipular o arquivo
         * 
         */
        fstream file;
};

#endif // Parser_h_