#include "../include/grafo.h"
#include "../include/parser.h"

int main() {
    auto grafo = new Grafo();
    auto parser = new Parser();

    parser->lerArquivos(grafo);
    
    grafo->galeShapley();
    grafo->print();

    delete parser;
    delete grafo;

    return 0;
}