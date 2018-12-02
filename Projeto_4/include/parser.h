#ifndef Parser_h_
#define Parser_h_

/**
 * @brief 
 * 
 * @file parser.h
 * @author Yuri Serka e Henrique Mendes
 * @date 2018-09-08
 */

#include "../include/grafo.h"

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
                cout << "O arquivo \"" + fileName + "\" nao foi aberto\n";
                exit(EXIT_FAILURE);
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
        void inserirNoGrafo(Grafo& grafo);
    private:
        /**
         * @brief Variavel para manipular o arquivo
         * 
         */
        fstream file;
};

#endif // Parser_h_