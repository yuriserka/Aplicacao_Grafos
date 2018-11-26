#include "../include/parser.h"

void Parser::inserirNoGrafo(Grafo& grafo) {
    string line;
    while (file >> line) {
        if (line.find("//") != string::npos) {
            continue;
        }
        int src, dest;
        file >> src;
        file >> dest;
        grafo.addAresta(src, dest);
    }
}