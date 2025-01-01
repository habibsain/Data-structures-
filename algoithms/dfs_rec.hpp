#ifndef DFS_REC_H
#define DFS_REC_H

#include<iostream>
#include<vector>
#include "graph.hpp"

using namespace std;

class Dfs_rec{
    vector<bool> visited;
    vector<int> prev;

    public: 

    Dfs_rec(Graph& graph, bool isDirected = false, bool isWeighted = false){
        int len = graph.size();
        visited.resize(len,false);
        prev.resize(len, -1);
    };

    void dfsUtil(Graph& g, int v){
        visited[v] = true;
        for(auto vert: g.getAdjListUnWeight(v)){
            if(!visited[vert]){
                dfsUtil(g, vert);
            }
            }
        }
}

#endif

