
/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 6		-
-			-
-----------------------*/
#include <iostream>
#include <string>
#include <regex>

#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    try{
        if (argc != 2) throw invalid_argument("Usage: ./main <file name>");
        ifstream in(argv[1]);
        if (!in) throw invalid_argument("Invalid file name or unable to open file.");
        int vex;
        int edges;
        in >> vex;      //hold the number of veteces from stream
        in >> edges;    //hold number of edges from stream

        Graph g(vex,edges);
        g.buildGraph(in);   //send in the reference to the graph
        g.displayGraph();
        if(g.partitionGraph()){
            int in;
            int end;
            cout << "Please enter two vertices you would like to find the path two: " << endl;
            cin >> in;
            cin >> end;
            g.shortestPath(in,end);}

            cout << endl;
        return 0;
    }
    catch (exception& error){
        cerr << "Error: " << error.what() << endl;
    }
}

