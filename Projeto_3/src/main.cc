#include "../include/graph.h"
#include "../include/parser.h"

int main() {
    Graph* grafo = new Graph();

    Parser *parser = new Parser();
    parser->lerArquivos(grafo);

    grafo->escreveProfs();
    grafo->escreveEscs();
    
    grafo->Emparelhamentos();

    delete parser;
    delete grafo;
    return 0;
}