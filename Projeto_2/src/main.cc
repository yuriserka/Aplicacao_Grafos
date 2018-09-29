#include <bits/stdc++.h>
#include "../include/parser.h"

int main() {
    Graph grafo = Graph();
    Parser *parser = new Parser("fluxo.txt");
    parser->preencherGrafo(grafo);

    grafo.EscreveGrafo();
    grafo.EscreveTodosCaminhos();

    grafo.imprimeGrafo();
    grafo.imprimeTopSort();
    grafo.imprimeCaminhoCritico();

    delete parser;
    return 0;
}