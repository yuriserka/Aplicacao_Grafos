#include "../include/grafo.h"
#include "../include/parser.h"

int main() {
    Parser* parser = new Parser("paraTestes.txt");
    Grafo grafo = Grafo();

    parser->inserirNoGrafo(grafo);

    // grafo.imprimeGrafo();

    grafo.betweenness();
    // grafo.betweenness(grafo.getVertices()[1]);

    // grafo.imprimeGrafo();
    // grafo.mostraComunidades();
    
    delete parser;
    return 0;
}