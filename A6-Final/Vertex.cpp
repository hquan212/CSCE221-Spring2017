
/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 6		-
-			-
-----------------------*/

#include "Vertex.hpp"
#include <iostream>

using namespace std;
    
// connect this vertex to a specific vertex (adding edge)
void Vertex::connectTo(int end){
    Edge ed(v_label,end);  
    edgeList.push_back(ed);
}

Vertex::Vertex(const Vertex& vec){        //copy constructer
    v_label = vec.v_label;      //Assign the Vertex 
    edgeList = vec.edgeList;    //Assign the edgeList
}