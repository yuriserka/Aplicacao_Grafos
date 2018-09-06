#ifndef Graph_h_
#define Graph_h_

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        Node(int data) : data(data) {}
        Node() = default;
        void add(int data) {
            adjacents.push_back(data);
            sort(adjacents.begin(), adjacents.end());
        }
        int getData() const {
            return this->data;
        }
        vector<int> getList() {
            return this->adjacents;
        }
        void display() {
            for (auto el : adjacents) {
                cout << el << "-> ";
            }
        }
    private:
        int data;
        vector<int> adjacents;
};

class Graph {
    public:
        Graph() = default;
        Graph(int qtdNos) : graph(qtdNos) {}
        void addEdge(int src, int dest);
        void addVertice(int vertice);
        bool hasEdge(int src, int dest);
        void display();
    private:
        static bool comp(const Node& rhs, const Node& lhs);
        vector<Node> graph;
};

#endif // Graph_h_