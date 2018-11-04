#ifndef Graph_h_
#define Graph_h_

#include "escola.h"
#include "professor.h"

class Graph {
    public:
        Graph() = default;

        void addProfessor(Professor* p);
        void addEscola(Escola *e);

        void escreveProfs();
        void escreveEscs();

        void Emparelhamentos();       
    private:
        void addArestas();
        list<Professor*> professores;
        list<Escola*> escolas;
        void galeShapley();
};

#endif // Graph_h_