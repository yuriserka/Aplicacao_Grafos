#ifndef Node_h_
#define Node_h_

/**
 * @brief 
 * 
 * @file node.h
 * @author Yuri Serka e Henrique Mendes
 * @date 2018-10-08
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Está classe representará os nós que irão compor o grafo, o objetivo em fazer esta classe foi 
 * para reduzir a quantidade de estruturas de dados utilizadas para fazer um grafo. É bem conveninte 
 * fazer uma classe para a representação do nó, pois desse modo pode-se ter mais flexibilidade do que
 * usar um vector<int> por exemplo.
 * 
 */
class Node {
    public:
        /**
         * @brief usa o construtor padrão do C++ para criar um Nó.
         * 
         */
        Node() = default;

        /**
         * @brief Constrói um Nó com nome, creditos, dificuldade e o peso necessário para atingi-lo.
         * 
         * @param nome é o nome da matéria.
         * @param peso é calculado por (creditos * dificuldade)
         */
        Node(string nome, int dificuldade, int creditos) {
            this->setNome(nome);
            this->setDificuldade(dificuldade);
            this->setCreditos(creditos);
            this->setPeso(dificuldade * creditos);
        }

        /**
         * @brief Constrói um Nó com nome apenas.
         * 
         * @param nome é o nome da matéria.
         */
        Node(string nome) {
            this->setNome(nome);
        }

        /**
         * @brief Seta o atributo privado nome.
         * 
         * @param nome nome da matéria.
         */
        void setNome(string nome) {
            this->nome = nome;
        }

        /**
         * @brief Seta o atributo privado peso.
         * 
         * @param peso 
         */
        void setPeso(int peso) {
            this->peso = peso;
        }

        /**
         * @brief Seta o atributo privado dificuldade.
         * 
         * @param dificuldade escolha arbitraria baseado no que sabemos da matéria
         */
        void setDificuldade(int dificuldade) {
            this->dificuldade = dificuldade;
        }

        /**
         * @brief Seta o atributo privado creditos.
         * 
         * @param creditos quantidade de créditos que a máteria em questão vale.
         */
        void setCreditos(int creditos) {
            this->creditos = creditos;
        }

        /**
         * @brief Adciona um nó a lista de adjacentes dele.
         * 
         * @param adj é um Nó, ou seja, outra matéria.
         */
        void addAdjacente(Node& adj) {
            this->adjacentes.push_back(adj);
        }

        /**
         * @brief retorna o noma do nó
         * 
         * @return string 
         */
        string getNome() const {
            return this->nome;
        }

        /**
         * @brief retorna o peso do nó
         * 
         * @return int 
         */
        int getPeso() const {
            return this->peso;
        }

        /**
         * @brief retorna a dificuldade da matéria
         * 
         * @return int 
         */
        int getDificuldade() const {
            return this->dificuldade;
        }

        /**
         * @brief retorna a quantidade de créditos da matéria.
         * 
         * @return int 
         */
        int getCreditos() const {
            return this->creditos;
        }

        /**
         * @brief retorna a lista de adjacência do nó
         * 
         * @return vector<Node> 
         */
        vector<Node> getAdjacentes() const {
            return this->adjacentes;
        }
    private:
        string nome;
        int dificuldade;
        int creditos;
        int peso;
        vector<Node> adjacentes;
};

#endif //Node_h_