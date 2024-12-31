#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Graph {
    vector<int> v_List;
    vector<vector<int>> edge_List;
    pair<int,vector<int>> adj_List;
    vector<int, pair<int, vector<int>>> list_of_edges;

    public: 
        //Constructor
        Graph();

        //vertex_setter(Done)
        void set_vertices(vector<int> &vertex_list);

        //edge_setter(Done)
        void set_edges(vector<vector<int>> &edge_list);

        //vertex_getter(Done)
        vector<int> get_vertices();
        
        pair<int,vector<int>> get_edges();

        void add_vertex(int vertex);

        void add_edge(vector<int> edge);

        //reversing the list(Done)
        vector<int> rev_list();

        void remove_edge(vector<int> edge); 

        void remove_vertex(int vertex);

        //Destructor
        ~Graph();
};

#endif