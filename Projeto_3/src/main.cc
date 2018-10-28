#include "../include/graph.h"
#include "../include/parser.h"

int main() {
    Graph *grafo = new Graph();

    Parser *parser = new Parser();
    parser->setNomeDoArquivo("ListaDosProfessores.txt");
    parser->lerProfessores(*grafo);

    parser->setNomeDoArquivo("ListaDasEscolas.txt");
    parser->lerEscolas(*grafo);

    grafo->escreveProfs();
    grafo->escreveEscs();

    grafo->printProfs();

    delete parser;
    delete grafo;
    return 0;
}