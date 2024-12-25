#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

using namespace std;

class Graph {
    vector<int> v_List;

    public: 
        //Constructor
        Graph();

        //setter
        void set_vertices(vector<int> &vertex_list);

        //getter
        vector<int> get_verices();

        //reversing the list
        vector<int> rev_list();

        //Destructor
        ~Graph();
};

#endif