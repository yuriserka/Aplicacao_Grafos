#ifndef Graph_h_
#define Graph_h_

#include "node.h"

class Graph {
    public:
        Graph() = default;

        void addProfessor(string nome, int habilitacoes, vector<string> escolas);

        void addEscola(string nome, int habilitacoes, int vagas);

        void escreveProfs();
        
        void escreveEscs();       
    private:
        list<Professor> professores;
        list<Escola> escolas;
};

#endif // Graph_h_