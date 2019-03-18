#ifndef Grafo_h_
#define Grafo_h_

#include <vector>
#include "escola.h"
#include "professor.h"

class Grafo {
  private:
    std::vector<Escola> escolas_;
    std::vector<Professor> professores_;
  public:
    Grafo() = default;

    void print();

    void galeShapley();

    void addProfessor(Professor &professor);
    void addEscola(Escola &escola);
};

#endif