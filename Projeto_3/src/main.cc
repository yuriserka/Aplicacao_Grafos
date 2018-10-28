#include "../include/graph.h"
#include "../include/parser.h"

int main() {
    Graph grafo = Graph();

    Parser *parser = new Parser();
    parser->setNomeDoArquivo("ListaDosProfessores.txt");
    parser->lerProfessores(grafo);

    // grafo.escreveProfs();
    // grafo.escreveEscs();

    grafo.Emparelhamentos();

    delete parser;
    return 0;
}