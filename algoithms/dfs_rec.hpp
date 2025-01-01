#ifndef DFS_REC_H
#define DFS_REC_H

#include<iostream>
#include<vector>
#include "graph.hpp"

using namespace std;

class Dfs_rec
{
    vector<bool> visited;
    vector<int> prev;

    public: 

    Dfs_rec(Graph& graph, bool isDirected = false, bool isWeighted = false){
        int len = graph.size();
        visited.resize(len,false);
        prev.resize(len, -1);
    };

    //void previsit(v)
    //void postvisit(v)

    void dfsUtil(Graph& g, int v){
        visited[v] = true;
        for(auto vert: g.getAdjListUnWeight(v)){
            if(!visited[vert]){
                prev[vert] = v;
                //previsit(vert);
                dfsUtil(g, vert);
            }    
        }
        //postvisit(v);
    };

    void dfsRun(graph& g){
        for(int i = 0; i < g.size(); i++){
            if(!visited[i]){
                dfsUtil(g, i);
            }
        }
    };
};

#endif

