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
 * @brief 
 * 
 */
class Parser {
    public:
        /**
         * @brief Construct a new Parser object
         * 
         */
        Parser() = default;

        /**
         * @brief Construct a new Parser object
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
         * @brief Destroy the Parser object
         * 
         */
        ~Parser() {
            file.close();
        }

        /**
         * @brief 
         * 
         */
        void insertOnGraph(Graph& graph);
    private:
        fstream file;
};

#endif // Parser_h_