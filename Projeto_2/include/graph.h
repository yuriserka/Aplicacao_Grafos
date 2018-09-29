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
         * @param weight 
         */
        void addVertice(string materia, int weight);

        /**
         * @brief 
         * 
         * @param src 
         * @param dest 
         */
        void addEdge(string src, pair<string, int> dest);

        /**
         * @brief 
         * 
         */
        void writeGraph();

        /**
         * @brief 
         * 
         */
        void writeAllPaths();

        /**
         * @brief 
         * 
         */
        void showTopSort();

        /**
         * @brief 
         * 
         */
        void showCriticalPath();        
    private:
        void computeAllPaths(string partida, map<string, bool>& visited, map<string, int>& pesos);
        void computeCriticalPath();
        void TopSort();
        void dfs(Node v, map<string, bool>& visited);
        map<string, int> inputDegree;
        map<string, int> outDegree;
        //map<string, vector<pair<string, int>>> graph;
        vector<string> topologicSorted;
        vector<string> criticalPath;
        list<pair<vector<string>, int>> allPaths;



        ///////////////////////TETSTES F=ZODE
        vector<Node> graph;
        
};

#endif // Graph_h_