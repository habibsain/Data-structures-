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
    int clock;

    public: 

    Dfs_rec(Graph& graph, bool isDirected = false, bool isWeighted = false){
        int len = graph.size();
        visited.resize(len,false);
        prev.resize(len, -1);
        cout<< "dfs initialised"<< endl;
    };

    //void previsit(v)
    //void postvisit(v)

    void dfsUtil(Graph& g, int v){
        visited[v] = true;
        cout << "discovered " << v << " at ";
        cout << clock << endl;
        clock += 1;
        //previsit(vert);
        for(auto vert: g.getAdjListUnWeight(v)){
            if(!visited[vert]){
                prev[vert] = v;
                dfsUtil(g, vert);
            }    
        }cout << "finished " << v << " at ";
        cout << clock << endl;
        clock += 1;
        //postvisit(v);
    };

    void dfsRun(Graph& g){
        clock = 0; 
        for(int i = 0; i < g.size(); i++){
            if(!visited[i]){
                dfsUtil(g, i);
            }
        }
    };
};

#endif

