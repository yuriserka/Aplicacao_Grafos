#ifndef Graph_h_
#define Graph_h_

/**
 * @brief 
 * 
 * @file graph.h
 * @author Yuri Serka e Henrique Mendes
 * @date 2018-09-26
 */

#include "node.h"

/**
 * @brief 
 * 
 */
class Graph {
    public:
        /**
         * @brief Construct a new Graph object
         * 
         */
        Graph() = default;

        /**
         * @brief 
         * 
         * @param materia 
         * @param peso 
         */
        void addVertice(string materia, int peso);

        /**
         * @brief 
         * 
         * @param origem 
         * @param destino 
         */
        void addAresta(string origem, pair<string, int> destino);

        /**
         * @brief 
         * 
         */
        void EscreveGrafo();

        /**
         * @brief 
         * 
         */
        void EscreveTodosCaminhos();
        
        /**
         * @brief 
         * 
         */
        void imprimeGrafo();

        /**
         * @brief 
         * 
         */
        void imprimeTopSort();

        /**
         * @brief 
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