#include "../include/grafo.h"
#include "../include/parser.h"

int main() {
    Parser* parser = new Parser("email-Eu-core.txt");
    Grafo grafo = Grafo(1005);

    parser->inserirNoGrafo(grafo);

    grafo.imprimeGrafo();
    
    delete parser;
    return 0;
}