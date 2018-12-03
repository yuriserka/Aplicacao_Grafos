#include "../include/grafo.h"
// #include "../include/parser.h"

int main() {
    // Parser* parser = new Parser("paraTeste.txt");
    Grafo grafo = Grafo();

    Comunidade c = Comunidade();
    Vertice v1 = Vertice(1), v2 = Vertice(156), v3 = Vertice(10), v4 = Vertice(4);
    c.addNaComunidade(v1);
    c.addNaComunidade(v2);
    c.addNaComunidade(v3);
    c.addNaComunidade(v4);

    grafo.addComunidade(c);
    grafo.mostraComunidades();

    // parser->inserirNoGrafo(grafo);

    // grafo.imprimeGrafo();

    // grafo.betweenness();
    // grafo.betweenness(grafo.getVertices()[1]);

    // grafo.imprimeGrafo();
    // grafo.mostraComunidades();
    
    // delete parser;
    return 0;
}