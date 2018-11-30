#include "../include/parser.h"

void Parser::inserirNoGrafo(Grafo& grafo) {
    string line;
    while (getline(this->file, line)) {
        if (line.find("//") != string::npos) {
            continue;
        } else {
            int src, dest;
            stringstream formated(line);
            formated >> src >> dest;
            Vertice origem = Vertice(src);
            Vertice destino = Vertice(dest);
            grafo.addAresta(origem, destino);
        }
    }
}