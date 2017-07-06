#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 6		-
-			-
-----------------------*/
#include "Edge.hpp"
#include "Vertex.hpp"
#include <unordered_set>
#include <deque>
#include <set>
#include <stack>

using namespace std;

class Graph {
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<list<Edge>> adj_list; // adjacency list
    vector<Vertex> vertices;  // all vertices
    unordered_set<int> S1;
    unordered_set<int> S2;
    Graph(int numVertex, int numEdge); // default constructor
    Graph(vector<list<Edge>> adjl); // constructor from adjl = adjacency list (optional)
    void buildGraph(ifstream &in);  // build a graph from the adjacency list
    void displayGraph();  // display the graph
    bool partitionGraph(); //checks whether we can partition the graph into two groups
    void shortestPath(int start, int end);  //Find the shortest path between two vertices
};

#endif /* Graph_hpp */
