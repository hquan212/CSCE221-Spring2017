
/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 6		-
-			-
-----------------------*/
#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>

class Edge {
public:
    // start vertex's label
    int e_start;
    // end vertex's label
    int e_end;
    // the weight of this edge
    int e_weight;
    Edge(int start, int end, int weight=1) : e_start(start), e_end(end), e_weight(weight){}; //constructor
};

#endif /* Edge_hpp */
