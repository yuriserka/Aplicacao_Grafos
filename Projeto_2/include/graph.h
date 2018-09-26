#ifndef Graph_h_
#define Graph_h_

#include <bits/stdc++.h>

using namespace std;

class Graph {
    public:
        Graph() = default;
        void addVertice(string materia, int weight);
        void writeGraph();
        void showTopSort();
        void addEdge(string src, pair<string, int> dest);
        void showCriticalPath();
        void computeCriticalPath(string partida, map<string, bool>& visited, map<string, int>& pesos, map<string, int>& pesosAntigos);
    private:
        void TopSort();
        void dfs(string vertice, map<string, bool>& visited);
        map<string, int> inputDegree;
        map<string, int> outDegree;
        map<int, pair<vector<string>,int>> sla;
        map<string, vector<pair<string, int>>> graph;
        vector<string> topologicSorted;
        vector<string> criticalPath;
        vector<string> teste;
        int cont = 0;

};

#endif // Graph_h_