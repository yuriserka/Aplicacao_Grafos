#ifndef Vertice_h_
#define Vertice_h_

#include <bits/stdc++.h>

using namespace std;

class Vertice {
    public:
        Vertice() = default;

        Vertice(int id) {
            this->id = id;
        }

        void addAdjacente(Vertice& adjacente) {
            this->adjacentes.push_back(adjacente);
        }

        vector<Vertice> getAdjacentes() {
            return this->adjacentes;
        }

        void setComunidade(string IdDaComunidade) {
            this->comunidade = IdDaComunidade;
        }

        string getComunidade() {
            return this->comunidade;
        }

        int getId() const {
            return this->id;
        }

        bool operator==(const Vertice& rhs) const {
            return this->id == rhs.getId();
        }
        bool operator!=(const Vertice& rhs) const {
            return this->id != rhs.getId();
        }
        bool operator>(const Vertice& rhs) const {
            return this->id > rhs.getId();
        }
        bool operator<(const Vertice& rhs) const {
            return this->id < rhs.getId();
        }
    private:
        int id;
        vector<Vertice> adjacentes;
        string comunidade = "null";
};

#endif // Vertice_h_