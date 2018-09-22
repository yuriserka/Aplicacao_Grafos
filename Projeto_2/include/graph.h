#ifndef Graph_h_
#define Graph_h_

#include <bits/stdc++.h>

using namespace std;

class Graph {
    public:
        Graph() = default;
        void addVertice(string materia, int weight);
        void showGraph();
        void addEdge(string src, pair<string, int> dest);
    private:
        map<string, vector<pair<string, int>>> graph;
};

#endif // Graph_h_