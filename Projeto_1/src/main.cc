#include "../include/graph.h"

int main() {
    Graph grafo = Graph();

    grafo.addEdge(1, 5);
    // grafo.addEdge(5, 8);
    // grafo.addEdge(1, 4);
    // grafo.addEdge(1, 3);
    // grafo.addEdge(8, 4);
    // grafo.addEdge(8, 3);
    // grafo.addEdge(4, 3);

    grafo.display();

    // cout << grafo.hasEdge(1, 5) << '\n';

    // grafo.display();
    // vector<int> v;
    // vector<Node> ve;

    // ve.emplace_back(10);
    // ve.emplace_back(5);
    // ve.push_back(1);
    // ve.push_back(3);
    // ve.push_back(2);

    // for (auto i : ve) {
    //     cout << i.getData() << "\n";
    // }

    // cout << "depois: \n";

    // for (auto i : ve) {
    //     cout << i.getData() << "\n";
    // }

    //  auto it = lower_bound(v.begin(), v.end(), 2, 
    //     [](const Node& rhs, const Node& lhs) -> bool {
    //         return (rhs.getData() < lhs.getData());
    //     });

    // v.push_back(1);
    // v.push_back(3);
    // v.push_back(2);

    // sort(v.begin(), v.end());

    // auto it = lower_bound(v.begin(), v.end(), 2, 
    //     [](const int& rhs, const int& lhs) -> bool {
    //         return (rhs < lhs);
    //     });

    
    // cout << *it << "\n";

    return 0;
}