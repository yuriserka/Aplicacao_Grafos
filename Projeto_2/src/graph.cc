#include "../include/graph.h"

void Graph::addVertice(string subject, int weight) {
    graph[subject].push_back(make_pair(subject, weight));
}

void Graph::showGraph() {
    fstream out;
    out.open("output.txt");
    if(!out.is_open()) {
        cout << "!errc";
        exit(-2);
    }
    for (auto node : graph) {
        for (auto par : node.second) {
            // cout << "Materia: " << par.first << ", ";
            // cout << "Peso: " << par.second << " => ";
            out << par.first << ", " << par.second << " => ";
        }
        out << "\n";
        // cout << '\n';
    }
}

void Graph::addEdge(string src, pair<string, int> dest) {
    if (graph.find(dest.first) == graph.end()) {
        this->addVertice(dest.first, dest.second);
    }
    graph[src].push_back(dest);
}