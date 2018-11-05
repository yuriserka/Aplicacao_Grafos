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
        void lerArquivos(Graph* grafo);

    private:
        void setNomeDoArquivo(string nomeDoArquivo) {
            if (file.is_open()) {
                this->file.close();
            }
            this->file.open(nomeDoArquivo);
            if (!file.is_open()) {
                cout << "O arquivo " << nomeDoArquivo << " nao foi aberto\n";
                exit(-1);
            }
        }
        fstream file;
        string nomeDoArquivoDosProfessores = "ListaDosProfessores.txt";
        string nomeDosArquivoDasEscolas = "ListaDasEscolas.txt";
};

#endif // Parser_h_