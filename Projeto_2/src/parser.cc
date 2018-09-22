#include "../include/parser.h"

void Parser::insertOnGraph(Graph& graph) {
    string line, source, target;
    int dificulty, credits;

    while (file >> line) {
        if (line.find("//") != string::npos) {
            continue;
        }
        if (line == "edge") {

            while(file >> line && line != "creditos");
            file >> credits;

            while(file >> line && line != "dificuldade");
            file >> dificulty;

            while(file >> line && line != "target");
            getline(file, target);

            while (file >> line && line == "source") {
                getline(file, source);
                if (target == " null") {
                    graph.addVertice(source, dificulty * credits);
                } else {
                    graph.addEdge(source, make_pair(target, dificulty * credits));
                }
            }
        }
    }
}