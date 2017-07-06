
/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 6		-
-			-
-----------------------*/
#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include <list>
#include <string>
#include <vector>

#include "Edge.hpp"
using namespace std;

class Vertex {
public:
    // the label of this vertex
    int v_label;
    // Checks wether the vertex has been visited
    bool is_visited;
    // Remembers the node that was visited by the parent
    int parent_node;    
    // using a linked-list to manage its edges which offers O(c) insertion
    list<Edge> edgeList;
    
    // init your vertex here
    Vertex(){}
    Vertex(int label): v_label(label), is_visited(false), parent_node(-1) {}  //constructor
    Vertex(const Vertex& vec); //copy constructor
    
    // connect this vertex to a specific vertex (adding edge)
    void connectTo(int end);
};

#endif /* Vertex_hpp */
