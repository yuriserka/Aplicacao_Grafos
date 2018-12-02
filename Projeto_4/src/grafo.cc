#include "../include/grafo.h"

void Grafo::addAresta(Vertice& origem, Vertice& destino) {
    if (find(this->grafo.begin(), this->grafo.end(), origem) == this->grafo.end()) {
        this->grafo.push_back(origem);
    }
    if (find(this->grafo.begin(), this->grafo.end(), destino) == this->grafo.end()) {
        this->grafo.push_back(destino);
    }

    grafo[find(this->grafo.begin(), this->grafo.end(), origem) - this->grafo.begin()].addAdjacente(destino);
}

void Grafo::imprimeGrafo() {
    sort(this->grafo.begin(), this->grafo.end());

    for (auto vertice : grafo) {
        cout << '[' << vertice.getId() << "]: ";
        for (auto adj : vertice.getAdjacentes()) {
            cout << adj.getId() << " ";
        }
        cout << '\n';
    }
}

void Grafo::mostraComunidades() {
    if (this->comunidades.empty()) {
        this->computaComunidades();
    }

    ofstream output;
    output.open("saida.json");

    if (!output.is_open()) {
        cout << "O arquivo \"saida.json\"nao foi aberto\n";
        exit(EXIT_FAILURE);
    }

    output << "{\n\t\"comunidades\": [\n";
    for (size_t k = 0; k < this->comunidades.size(); ++k) {
        auto comunidade = this->comunidades[k];
        output << "\t\t{\n";
        output << "\t\t\t\"tamanho\": " << comunidade.size() << ", \n";
        output << "\t\t\t\"elementos\": [\n";
        for (size_t i = 0; i < comunidade.size(); ++i) {
            output << "\t\t\t\t" << comunidade[i];
            if (i < (comunidade.size() - 1)) {
                output << ",";
            }
            output << "\n";
        }
        output << "\t\t\t]\n";
        output << "\t\t}";
        if (k < (this->comunidades.size() - 1)) {
            output << ",";
        }
        output << "\n";
    }
    output << "\t]\n";
    output << "}";

    cout << "As comunidades estao no Arquivo \"saida.json\"\n";
}

map<int, double> Grafo::betweenness() {
    map<int, double> Cb;

    for (auto s : this->grafo) {
        stack<int> S;
        map<int, int> d, sig;
        map<int, vector<int>> P;
        
        for (size_t i = 0; i < this->grafo.size(); ++i) {
            d[this->grafo[i].getId()] = -1.0;
            sig[this->grafo[i].getId()] = 0.0;
        }

        d[s.getId()] = 0;
        sig[s.getId()] = 1;

        for (size_t i = 0; i < this->grafo.size(); ++i) {
            cout << "[" << this->grafo[i].getId() << "]: d = " << d[this->grafo[i].getId()] << ", sig = "
                << sig[this->grafo[i].getId()] << "\n";
        }

        queue<Vertice> Q;

        Q.push(s);
        while (!Q.empty()) {
            auto v = Q.front();
            Q.pop();

            S.push(v.getId());
            for (auto w : v.getAdjacentes()) {
                if (d[w.getId()] < 0) {
                    Q.push(w);
                    d[w.getId()] += 1;
                }
                if (d[w.getId()] == d[v.getId()] + 1) {
                    sig[w.getId()] += sig[v.getId()];
                    P[w.getId()].push_back(v.getId());
                }
            }
        }

        map<Vertice, int> sigmao;
        for (size_t i = 0; i < this->grafo.size(); ++i) {
            sigmao[this->grafo[i]] = 0;
        }
        while (!S.empty()) {
            auto w = S.top();
            S.pop();
            for (auto v : P[w]) {
                sigmao[v] += (sig[v] / sig[w]) * (1 + sigmao[w]);
            }
            if (w != s.getId()) {
                Cb[w] += sigmao[w];
            }
        }
    }

    return Cb;
}

double Grafo::betweenness(Vertice& vertice) {
    class MenorCaminho {
        public:
            MenorCaminho() = default;

            /**
             * @brief tentativa de implementar o somatorio duplo com o calculo dos sigmas
             * pra achar o betweenness
             * 
             * @param grafo 
             */
            void run(Grafo& grafo) {
                for (auto i : grafo.getVertices()) {
                    for (auto j : grafo.getVertices()) {
                        if (i == j) {
                            continue;
                        }
                        if (find(i.getAdjacentes().begin(), i.getAdjacentes().end(), j) 
                                != i.getAdjacentes().end()) {
                            menoresCaminhosEntreIeJ.push_back(1); // 1, pois é adjacente, portanto é o menor
                            qtdDeVezesQuePassaPeloVertice = 0;
                        } else {
                            queue<Vertice> fila;
                            map<int, bool> descobertos;

                            fila.push(i);
                            descobertos[i.getId()] = true;
                            menoresCaminhosEntreIeJ.push_back(menorCaminhoAteJ(j, fila, descobertos));
                        }
                    }
                }
            }

            /**
             * @brief uma BFS que nao testei direito pra verificar se passava pelo vertice
             * 
             * @param destino 
             * @param fila 
             * @param descobertos 
             * @return int 
             */
            int menorCaminhoAteJ(Vertice destino, 
                    queue<Vertice>& fila, map<int, bool>& descobertos) {
                if (fila.empty()) {
                    return 0;
                }

                auto verticeAtual = fila.front();
                fila.pop();

                bool chegouAoDestino = false;

                for (auto adj : verticeAtual.getAdjacentes()) {
                    if (!descobertos[adj.getId()]) {
                        descobertos[adj.getId()] = true;

                        if (adj == destino) {
                            chegouAoDestino = true;
                            break;
                        }
                        
                        fila.push(adj);
                    }
                }

                if (chegouAoDestino) {
                    return 1 + this->menorCaminhoAteJ(destino, fila, descobertos);
                } else {
                    this->menorCaminhoAteJ(destino, fila, descobertos);
                }
            }

            /**
             * @brief Dijkstra padão
             * 
             * @param grafo 
             * @param source 
             * @return map<int, int> 
             */
            map<int, int> dijkstra(Grafo& grafo, Vertice& source) {
                map<int, int> d;
                d[source.getId()] = 0;
                list<Vertice> q;

                for (auto v : grafo.getVertices()) {
                    if (v != source) {
                        d[v.getId()] = INT_MAX - 30000;
                    }
                    q.push_back(v);
                }

                while (!q.empty()) {
                    auto v = *min_element(q.begin(), q.end(), 
                        [&d] (const Vertice& a, const Vertice& b) {
                            return d[a.getId()] < d[b.getId()];
                    });
                    q.erase(find(begin(q), end(q), v));

                    for (auto adj : v.getAdjacentes()) {
                        auto alt = d[v.getId()] + 1;
                        if (alt < d[adj.getId()]) {
                            d[adj.getId()] = alt;
                        }
                    }
                }

                return d;
            }

        private:
            vector<int> menoresCaminhosEntreIeJ;
            int qtdDeVezesQuePassaPeloVertice;
            Vertice origem;
            Vertice destino;
    };

    MenorCaminho mc = MenorCaminho();
    map<int, int> x = mc.dijkstra(*this, vertice);

    for (auto a : x) {
        cout << "d(" << vertice.getId() << "," << a.first<< ")=" << a.second << "\n"; 
    }

    return 0.0;
}

void Grafo::computaComunidades() {
    // artigo "Finding and evaluating community structure in networks" -> 
        // https://arxiv.org/pdf/cond-mat/0308217.pdf, por M. E. J. Newman and M. Girvan

    /**
     * @brief the general form of our community structure finding algorithm is as follows:
     * 
     * 1. Calculate betweenness scores for all edges in the network.
     * 2. Find the edge with the highest score and remove it from the network.
     * 3. Recalculate betweenness for all remaining edges.
     * 4. Repeat from step 2.
     */

    return;
}