#include <bits/stdc++.h>

using namespace std;

class Graph{

public:
    vector<vector<int>> graph;

    vector<int> degree;

    vector<vector<int>> ans;

    int tam;

    void addEdge(int node1, int node2){
        if(node1 >= tam || node2 >= tam)
            return;

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);

        degree[node1]++;
        degree[node2]++;

        tam += 2;
    }

    void maximal_cliques(){
        vector<int> aux_P;
        vector<int> aux_X;
        vector<int> aux_R;

        if(aux_P.empty() && aux_X.empty()){
            ans.push_back(aux_R);
        } else {
            return;
        }


    }

    



    Graph() : degree(38, 0){
        tam = 0;
    }

}