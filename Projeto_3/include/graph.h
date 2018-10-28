#ifndef Graph_h_
#define Graph_h_

#include "node.h"

class Graph {
    public:
        Graph() = default;

        void addAresta(Professor& p, Escola& e);

        void addProfessor(Professor& p);

        // void addEscola(string nome, int habilitacoes, int vagas);

        void escreveProfs();
        
        void escreveEscs();

        void Emparelhamentos();       
    private:
        list<Professor> grafo;
        vector<Escola> escolas;
        void galeShapley();
        // list<Professor> professores;
        // list<Escola> escolas;
};

#endif // Graph_h_