#include<iostream>
#include<vector>
#include "graph.hpp"

void display_list(vector<int> list){

    for(auto item: list){
        cout << item << endl;
    }
}

using namespace std;

int main(){
    vector<int>  vertices = {1, 2, 3, 4};
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}};

    cout << "Display an instance of Graph" << endl;
    Graph g;
    //g.set_vertices(vertices);
    ///cout << "Display vertices of the graph" << endl;
    //display_list(g.get_vertices());
    //cout << "List reversal" << endl;
    //display_list(g.rev_list());
    g.set_edges(edges);

    pair<int, vector<int>> edge_list = g.get_edges();
    for(auto edge: edge_list){
        cout<< edge.first << display_list(edge);
    }
    return 0;
}