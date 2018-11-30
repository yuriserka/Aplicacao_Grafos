#include "../include/grafo.h"
#include "../include/parser.h"

int main() {
    Parser* parser = new Parser("email-Eu-core.txt");
    Grafo grafo = Grafo();

    parser->inserirNoGrafo(grafo);

    // grafo.imprimeGrafo();
    grafo.mostraComunidades();
    
    delete parser;
    return 0;
}