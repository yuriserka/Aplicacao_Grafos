#ifndef Grafo_h_
#define Grafo_h_

#include "vertice.h"

class Grafo {
    public:
        Grafo() = default;

        vector<Vertice> getVertices() {
            return this->grafo;
        }

        void addAresta(Vertice& origem, Vertice& destino);
        void imprimeGrafo();
        void mostraComunidades();

        /**
         * @brief Betweeness Centrality (Centralidade de Intermediação) - Para
         * essa medida encontraremos nós que tem alta influência na comunicação
         * entre regiões distantes do Grafo. É normal ocorrer que um nó tenha
         * alta centralidade de intermediação e cujas outras medidas de 
         * centralidade sejam baixas, portanto cada medida de Centralidade
         * possui um significado bem diferente de outro. Nós com alta
         * centralidade de intermediação formam verdadeiras "pontes" entre
         * partes do gráfico, o que significa que sem a presença deles a comunicação
         * entre grupos distantes fica dificultada. Eles tornam a travessia do
         * grafo mais fácil. Eles também fazem comunicação de Clusters.
         * 
         * 
         * Esse algoritmo é baseado do pseudo-código
         * deste pdf: http://wiki.icmc.usp.br/images/9/90/GrafoT4.pdf
         * 
         * @return map<Vertice, int> 
         */
        map<int, double> betweenness();

        /**
         * @brief esse daqui eu meio que to tentando traduzir 
         * esse video: https://www.youtube.com/watch?v=ptqt2zr9ZRE, mas
         * ainda n ta funcionando 100% pq tem a parte de verificar se passa pelo vertice
         * 
         * @param vertice 
         * @return double 
         */
        double betweenness(Vertice& vertice);

        /**
         * @brief talvez valha a pena tentar entender esse daqui tambem...
         * 
         */
        void algoritmoDeBrandes();
    private:
        /**
         * @brief aqui ta o link do artigo que descreve o algoritmo para achar comunidades.
         * 
         */
        void computaComunidades();
        vector<Vertice> grafo;
        vector<vector<int>> comunidades;
        map<Vertice, double> intermediacoes;
};

#endif // Grafo_h_