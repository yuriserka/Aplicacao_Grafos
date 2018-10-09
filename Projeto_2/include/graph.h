#ifndef Graph_h_
#define Graph_h_

/**
 * @brief 
 * 
 * @file graph.h
 * @author Yuri Serka e Henrique Mendes
 * @date 2018-10-08
 */

#include "node.h"

/**
 * @brief Classe grafo.
 * 
 */
class Graph {
    public:
        /**
         * @brief Construct a new Graph object.
         * 
         */
        Graph() = default;

        /**
         * @brief addVertice cria um vértice com seu peso.
         * 
         * @param materia 
         * @param peso 
         */
        void addVertice(string materia, int dificuldade, int creditos);

        /**
         * @brief addAresta cria uma aresta entre os vértices.
         * 
         * @param origem 
         * @param destino 
         */
        void addAresta(string origem, string dest, int dificuldade, int creditos);

        /**
         * @brief Escreve em um arquivo txt os graus de entrada e sada de cada vértice, ou seja, 
         * quantos pré-requisitos a materia tem e quantas materias ela é pré-requisito.
         * 
         */
        void EscreveGrafo();

        /**
         * @brief Escreve em um arquivo txt todos os caminhos do grafo.
         * 
         */
        void EscreveTodosCaminhos();
        
        /**
         * @brief imprime todos os vertices e seus adjacentes do grafo.
         * 
         */
        void imprimeGrafo();

        /**
         * @brief Imprime a ordenação topologica.
         * 
         */
        void imprimeTopSort();

        /**
         * @brief Imprime o caminho crítico e seu peso total.
         * 
         */
        void imprimeCaminhoCritico();        
    private:
        void computaTodosCaminhos(string partida, map<string, bool>& visitados, map<string, int>& pesos);
        void computaCaminhoCritico();
        void TopSort();
        void dfs(Node v, map<string, bool>& visitados);
        map<string, int> grausDeEntrada;
        map<string, int> grausDeSaida;
        vector<Node> grafo;
        vector<string> listaTopSort;
        vector<string> caminho;
        list<pair<vector<string>, int>> todosCaminhos;  
};

#endif // Graph_h_