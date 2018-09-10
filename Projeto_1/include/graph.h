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
     * @brief Construct a new Graph object
     * 
     * @param qtdNos 
     */
    Graph(int qtdOfNodes) : graph(qtdOfNodes + 1) {}

    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    int getSize() {
        return graph.size();
    }

    /**
     * @brief 
     * 
     * @param src 
     * @param dest 
     */
    void addEdge(int src, int dest);

    /**
     * @brief Get the Adj Nodes object
     * 
     * @param vertex 
     * @return vector<int> 
     */
    vector<int> getAdjNodes(int vertex) {
        return graph[vertex];
    }

    /**
     * @brief 
     * 
     * @param vertex 
     */
    void bfs(int vertex);

    /**
     * @brief Get the Degree object
     * 
     * @param vertex 
     * @return int 
     */
    int getDegree(int vertex) {
        return graph[vertex].size();
    }

    /**
     * @brief Get the Cliques object
     * 
     * @param vertex 
     */
    void getCliques();

    void getAllAglomeration();

    void getMidAglomeration();
private:
    void bfsAux(int vertex, vector<bool>& visited);
    void sortCliques();
    void bronKerbosh(vector<int> click, vector<int>& possible, vector<int>& excluded);
    void getAglomeration(int vertex);
    vector<vector<int>> graph;
    vector<vector<int>> cliques;
    vector<vector<int>> triangulos;
};

#endif // Graph_h_