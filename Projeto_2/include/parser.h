#ifndef Parser_h_
#define Parser_h_

#include "graph.h"

class Parser {
    public:
        Parser() = default;

        Parser(string fileName) {
            this->file.open(fileName);
            if (!file.is_open()) {
                cout << "O arquivo nao foi aberto\n";
                exit(-1);
            }
        }

        ~Parser() {
            file.close();
        }

        void insertOnGraph(Graph& graph);
    private:
        fstream file;
};

#endif // Parser_h_