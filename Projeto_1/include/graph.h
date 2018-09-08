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
    Graph(int qtdNos) : graph(qtdNos + 1) {}
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
     * @param vertice 
     * @return vector<int> 
     */
    vector<int> getAdjNodes(int vertice) {
        return graph[vertice];
    }
    /**
     * @brief 
     * 
     * @param vertice 
     */
    void bfs(int vertice);
    /**
     * @brief Get the Degree object
     * 
     * @param vertice 
     * @return int 
     */
    int getDegree(int vertice) {
        return graph[vertice].size();
    }
private:
    void bfsAux(int vertice, vector<bool> visited);
    vector<vector<int>> graph;
};

#endif // Graph_h_