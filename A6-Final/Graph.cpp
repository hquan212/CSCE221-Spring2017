
/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 6		-
-			-
-----------------------*/
#include "Graph.hpp"


Graph::Graph(int numVertex, int numEdge){
    cout << "Number of Cities: " << numVertex << "\t Number of Connections: " << numEdge << endl;
}

void Graph::buildGraph(ifstream &in){
    int index =0;   //Keep the index of the vertex for the adjancency list  
    while(in.eof()!=true){
        int end =0;       
        Vertex vert(index);
        while(end!=-1){
            in >> end; 
            if(end != -1){
                vert.connectTo(end);    //set the edgelist to connect the vertices
            }
        }
        vertices.push_back(vert);       //push back the vertex to our vector
        adj_list.push_back(vert.edgeList);      //lets push back all the edgelists
        index++;
    }
}

void Graph::displayGraph(){
    int c =0;       //number of vertex
    cout << "---------------------" << endl;
    for(int c=0; c<adj_list.size();c++){
        cout << c << "   " << "||" << "\t";
        list<Edge> edgeList = adj_list.at(c);
        for (list<Edge>::iterator i = edgeList.begin();i!=edgeList.end();++i) {
            cout << i->e_end << "   ";
        }
        cout  << endl;
    }
    cout << "---------------------" << endl;
}

bool Graph::partitionGraph(){

    deque<int> E1;

    E1.push_back(vertices[0].v_label);
    S1.insert(vertices[0].v_label);    //first group has 0
    while(!E1.empty()){
        int current_vertex = E1.front();
        E1.pop_front();
        for(list<Edge>::iterator j = vertices[current_vertex].edgeList.begin(); j != vertices[current_vertex].edgeList.end(); ++j){
            if(S1.find(j->e_end)==S1.end() &&S2.find(j->e_end) == S2.end()){
                E1.push_back(j->e_end);}
            if(S1.find(current_vertex) != S1.end()){
                S2.insert(j->e_end);}       //Add to second set
            else
                S1.insert(j->e_end);           //Add to first set
         }
    }

    cout << "Group 1 is: ";
    for(int i:S1){
        cout << i << " ";       // output our sets
    }
    cout << endl;

    cout << "Group 2 is: ";
     for(int i:S2){     //output the set
        cout << i << " ";
    }
    cout << endl;

    if(S1.size()+S2.size() == vertices.size()){
        cout << "We can partition the cities correctly!" << endl;  //true!
        return true;

    }
    else{
        cout << "Error, this graph cannot be bisected!" << endl;
        return false;       //fail
    }

}

void Graph::shortestPath(int start, int end){
 
        set <int> SR;       
        stack <int> Stack;
        deque<int> Q;
        int current;
        vector<int> V = vector<int>(vertices.size());   //Initialize a vector to hold the parent
        SR.insert(start);
        Q.push_back(start);

        while(!Q.empty()){
            current = Q.front();    //save first vertex
            Q.pop_front();
            if(current == end){     //found it!
                break;
            }
            for(auto it = adj_list[current].begin(); it!=adj_list[current].end();it++){ 
                if(SR.find(it->e_end)==SR.end()){   //Go throught the vertex list
                    SR.insert(it->e_end);           //Add to the set
                    V.at(it->e_end) = current;      //Push back the parent of the vertex
                    Q.push_back(it->e_end);         //Add the vertex number to our queue
                }
            }
        }
        
        int x = end;  
        int count=0;      
        if(current==end){       //Add these parent values to the Stack
            while(x!=start){
                Stack.push(x);
                x = V.at(x);
                count++;
            }
            cout << start;
            while(!Stack.empty()){      //Lets display the correct path
                int t = Stack.top();
                cout  << "->" << t;     
                Stack.pop();        //Reverse the display output!
            }
        cout << "\nThe Shortest path is: " << count<< " connection." << endl;
        }
}