#ifndef Graph_h_
#define Graph_h_

/**
 * @brief 
 * 
 * @file graph.h
 * @author Yuri Serka e Henrique Mendes
 * @date 2018-09-08
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Classe que representa um grafo.
 * 
 */
class Graph {
public:

    Graph() = default;
    
    /**
     * @brief O construtor recebe a quantidade de vértices e passa para o vetor graph essa quantidade.
     * 
     * @param qtdNos 
     */
    Graph(int qtdOfNodes) : graph(qtdOfNodes + 1) {}

    /**
     * @brief getSize retorna o tamanho do vetor graph.
     * 
     * @return int 
     */
    int getSize() {
        return graph.size();
    }

    /**
     * @brief addEdge adiciona uma aresta ao grafo.
     * 
     * @param src 
     * @param dest 
     */
    void addEdge(int src, int dest);

    /**
     * @brief getAdjNodes retorna uma lista com os vértices adjacentes ao vértice passado como argumento.
     * 
     * @param vertex 
     * @return vector<int> 
     */
    vector<int> getAdjNodes(int vertex) {
        return graph[vertex];
    }

    /**
     * @brief bfs realiza um percorrimento em largura pelo grafo imprimindo o grau dos vértices.
     * 
     * @param vertex 
     */
    void bfs(int vertex);

    /**
     * @brief getDegree retorna o grau do vértice.
     * 
     * @param vertex 
     * @return int 
     */
    int getDegree(int vertex) {
        return graph[vertex].size();
    }

    /**
     * @brief getCliques imprime os cliques do vetor de cliques.
     */
    void getCliques();

    /**
     * @brief getAllAglomeration imprime todos os coeficientes de aglomeração dos vértices do grafo.
     */

    void getAllAglomeration();

    /**
     * @brief getMidAglomeration imprime o coeficiente de aglomeração do grafo.
     */

    void getMidAglomeration();

private:

    /**
     * @brief bsfAux realiza uma busca em largura no grafo imprimindo o grau dos vértices.
     * 
     * @param vertex
     * @param vector<bool>& visited
     */

    void bfsAux(int vertex, vector<bool>& visited);

    /**
     * @brief sortCliques preenche o vetor cliques com os cliques do grafo.
     */

    void sortCliques();

    void bronKerbosh(vector<int> click, vector<int>& possible, vector<int>& excluded);

    /**
     * @brief getAglomeration encontra o coeficiente de aglomeração do vértice.
     * @param vertex
     */

    void getAglomeration(int vertex);

    /**
     * @brief representação de um grafo utilizando vector de vectors.
     */

    vector<vector<int>> graph;

    /**
     * @brief vector que possui os cliques do grafo.
     */

    vector<vector<int>> cliques;

    /**
     * @brief vector que possui os cliques de tamanho 3 do grafo.
     */

    vector<vector<int>> triangulos;
};

#endif // Graph_h_