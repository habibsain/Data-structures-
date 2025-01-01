#include <iostream>
#include <vector>
#include "graph.hpp"
#include <stack>

using namespace std;

void display_list(vector<int> list){

    for(auto item: list){
        cout << item << endl;
    }
}

int main(){
    vector<int>  vertices = {1, 2, 3, 4};

    cout << "Display an instance of Graph" << endl;
    Graph g;
    g.set_vertices(vertices);
    cout << "Display vertices of the graph" << endl;
    display_list(g.get_verices());
    cout << "List reversal" << endl;
    display_list(g.rev_list());
    return 0;
}