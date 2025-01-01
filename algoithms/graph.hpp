#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Graph {
    vector<vector<int>> uAdjList;
    vector<vector<pair<int,int>>> wAdjList;
    int len;
    
    bool weighted;
    bool directed; 
        //Constructor
    public:
        Graph(int numVertices, bool isDirected = false, bool isWeighted = false){
            directed = isDirected;
            weighted = isWeighted;
            
            if(weighted){
                //cout << wAdjList.size() << endl;
                wAdjList.resize(numVertices);
                //cout << wAdjList.size() << endl;
                len = numVertices;
            }
            else{
                uAdjList.resize(numVertices);
                len = numVertices;
            }

        };
    public:

        int size(){
            return len;
        }

        void addEdge(int u, int v){
            if(u >= len || v >= len){
                cout << "invalid vertex input" << endl;
            }
            else{
                uAdjList[u].push_back(v);
                if(!directed){
                    uAdjList[v].push_back(u);
                }
            }
        };

        void addEdge(int u, int v, int w){
            if(u >= len || v >= len){
                cout << "invalid vertex input" << endl;
                exit(0);
            }
            else{
                wAdjList[u].push_back(make_pair(v,w));
                if(!directed){
                    wAdjList[v].push_back(make_pair(u,w));
                }
            }

        };
        vector<int> getAdjListUnWeight(int u){
            cout<<"Called unweighted util"<<endl;
            return uAdjList[u];
        };

        vector<pair<int,int>> getAdjListWeight(int u){
            cout<<"Called weighted util"<<endl;
            return wAdjList[u];
        };


        void printList(){
            if(weighted){
                for (auto u = 0; u < wAdjList.size(); u++){
                    cout << u << ": ";
                    for(auto v: wAdjList[u]){
                        cout << "("<< v.first << ", " << v.second << "), ";
                    }
                    cout << endl;
                }
            }
            else{
                for(auto i =0; i < uAdjList.size();  i++){
                    cout << i << ": ";
                    for(auto j: uAdjList[i]){
                        cout << j <<", ";
                    }
                    cout << endl;
                }
            }
        };   
};

#endif