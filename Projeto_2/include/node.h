#ifndef Node_h_
#define Node_h_

/**
 * @brief 
 * 
 * @file node.h
 * @author Yuri Serka e Henrique Mendes
 * @date 2018-09-29
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * 
 */
class Node {
    public:
        /**
         * @brief Construct a new Node object
         * 
         */
        Node() = default;

        /**
         * @brief Construct a new Node object
         * 
         * @param nome 
         * @param peso 
         */
        Node(string nome, int peso) {
            this->setNome(nome);
            this->setPeso(peso);
        }

        /**
         * @brief Construct a new Node object
         * 
         * @param nome 
         */
        Node(string nome) {
            this->setNome(nome);
        }

        /**
         * @brief Set the Nome object
         * 
         * @param nome 
         */
        void setNome(string nome) {
            this->nome = nome;
        }

        /**
         * @brief Set the Peso object
         * 
         * @param peso 
         */
        void setPeso(int peso) {
            this->peso = peso;
        }

        /**
         * @brief 
         * 
         * @param adj 
         */
        void addAdjacente(Node& adj) {
            this->adjacentes.push_back(adj);
        }

        /**
         * @brief Get the Nome object
         * 
         * @return string 
         */
        string getNome() const {
            return this->nome;
        }

        /**
         * @brief Get the Peso object
         * 
         * @return int 
         */
        int getPeso() const {
            return this->peso;
        }

        /**
         * @brief Get the Adjacents object
         * 
         * @return vector<Node> 
         */
        vector<Node> getAdjacentes() const {
            return this->adjacentes;
        }
    private:
        string nome;
        int peso;
        vector<Node> adjacentes;
};

#endif //Node_h_