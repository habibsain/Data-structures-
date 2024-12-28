#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

using namespace std;

class Graph {
    vector<int> v_List;
    vector<vector<int>> adj_List;

    public: 
        //Constructor
        Graph();

        //vertex_setter
        void set_vertices(vector<int> &vertex_list);

        void set_edges(vector<vector<int>> &edge_list);

        //vertex_getter
        vector<int> get_vertices();
        
        vector<vector<int>> get_edges();

        void add_vertex(int vertex);

        void add_edge(vector<int> edge);

        //reversing the list
        vector<int> rev_list();

        void remove_edge(vector<int> edge); 

        void remove_vertex(int vertex);

        //Destructor
        ~Graph();
};

#endif