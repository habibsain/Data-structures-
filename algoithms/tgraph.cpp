
/*

#include <iostream>
//#include <vector>


#include "graph.hpp"

using namespace std;

Graph::Graph(){
    //Constructor
    //this->v_List = verticex_list;
    cout << "Class is instantiated" << endl;

}

void Graph::set_vertices(vector<int> &vertex_list){
    //cout << "Setting vertices" << endl;
    this->v_List = vertex_list;
}

void Graph::set_edges(vector<vector<int>> &edge_list){
    cout << "Setting edges" << endl;
    for (auto edge: edge_list){
        cout << edge[0] << " " << edge[1] << endl;
        this->adj_List.first = edge[0];
        this->adj_List.second.push_back(edge[1]);
        cout << "Done" << endl;
    }
    for (auto edge: edge_list){
    }
}

vector<int> Graph::get_vertices(){
    cout << "Getting vertices" << endl;
    return this->v_List;
}

pair<int,vector<int>> Graph::get_edges(){
    cout << "Getting edges" << endl;
    return this->adj_List;
}

vector<int> Graph::rev_list(){
    vector<int> reversed_list;
    
    for(auto item = this->v_List.rbegin(); item != this->v_List.rend(); item++){
        //cout << *item << endl;
        reversed_list.push_back(*item);
    }
    
   for (int i = this->v_List.size() - 1; i >= 0; i--){
       reversed_list.push_back(this->v_List[i]);
    }
    
    return reversed_list;
}

Graph::~Graph(){
    cout << "Class is destroyed" << endl;
}
*/