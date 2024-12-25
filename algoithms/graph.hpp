#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

using namespace std;

class Graph {
    vector<int> v_List;

    public: 
        Graph(){
        //Constructor
        //this->v_List = verticex_list;
            cout << "Class is instantiated" << endl;

        }

        void set_vertices(vector<int> &vertex_list){
            v_List = vertex_list;
        }

        vector<int> get_verices(){
            return v_List;
        }
};

#endif