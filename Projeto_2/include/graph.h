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
    private:
        void dfs(string vertice, map<string, bool>& visited);
        map<string, int> inputDegree;
        map<string, vector<pair<string, int>>> graph;
        vector<string> topologicSorted;
};

#endif // Graph_h_