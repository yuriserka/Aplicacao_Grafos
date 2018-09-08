#include "../include/parser.h"

void Parser::insertOnGraph(Graph& graph) {
    string line;
    while (getline(this->file, line)) {
        if (line.find("//") != string::npos) {
            continue;
        } else {
            int src, dest;
            stringstream formated(line);
            formated >> src >> dest;
            graph.addEdge(src, dest);
        }
    }
}