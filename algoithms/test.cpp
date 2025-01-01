#include <iostream>
#include <vector>
#include <utility>
#include "graph.hpp"
//#include "dfs_itr.hpp"
#include "dfs_rec.hpp"

typedef vector<pair<int,int>> wAdj;
typedef vector<vector<int>> uAdj;

int main(){

    //DFS recursive
    //UnWeighted
    //UnDirected
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    Dfs_rec dfs(g);
    dfs.dfsRun(g);






    /*
    weighted
    
    Graph g(4, false, true);
    g.addEdge(2, 0, 5);
    g.addEdge(1, 3, 8);
    g.addEdge(0, 3, 10);
    g.addEdge(3, 2, 6);
    
    wAdj vec = g.getAdjListWeight(2);

    cout << vec.size() << endl;
    cout << g.getAdjListWeight(2)[0].second << endl;
    
    g.printList();
    */


   /*
   unweighted
   

    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 0);
    g.addEdge(1, 0);

    g.printList();

    */
    return 0;
}