#include <iostream>
#include <vector>
#include <utility>
#include "graph.hpp"

typedef vector<pair<int,int>> wAdj;

int main(){
    Graph g(4, false, true);
    g.addEdge(2, 0, 5);
    g.addEdge(1, 3, 8);
    g.addEdge(0, 3, 10);
    g.addEdge(3, 2, 6);

    wAdj vec = g.getAdjListWeight(2);

    cout << vec.size() << endl;
    cout << g.getAdjListWeight(2)[0].second << endl;
    
    g.printList();
    return 0;
}