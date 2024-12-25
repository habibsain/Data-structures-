#include<iostream>
#include<vector>
#include "graph.hpp"

void display_list(Graph &graph){

    for(auto item: graph.get_verices()){
        cout << item << endl;
    }
}

using namespace std;

int main(){
    vector<int>  vertices = {1, 2, 3, 4};

    cout<<"Display an instance of Graph"<<endl;
    Graph g;
    g.set_vertices(vertices);
    cout<<"Display vertices of the graph"<<endl;
    display_list(g);
    return 0;
}