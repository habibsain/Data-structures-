#include <iostream>
#include <vector>
#include "graph.hpp"
#include <stack>

using namespace std;

class Dfs_itr{
    vector<bool> visited;
    Graph g;
    int size;
    vector<int> prev;

    Dfs_itr(Graph& graph){
        
        
    }

    void setGraph(Graph& graph){
        size = graph.size();
        g.resize(size);
        if(graph.isWeighted()){
            for(int i=0; i<size; i++){
                g graph.getAdjListWeight(i);
                //trying to set a new graph
            }
        }
    }

    void printGraph(){
        cout << g.size() << endl;
    }

};