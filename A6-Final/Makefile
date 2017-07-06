OBJ = main.o Graph.o Vertex.o Edge.o
MAIN = main

$(MAIN): $(OBJ)
	c++ -std=c++14 -o $(MAIN) $(OBJ)

main.o: main.cpp
	c++ -std=c++14 -c main.cpp

Graph.o: Graph.cpp Graph.hpp
	c++ -std=c++14 -c Graph.cpp

Vertex.o: Vertex.cpp Vertex.hpp
	c++ -std=c++14 -c Vertex.cpp

Edge.o: Edge.cpp Edge.hpp
	c++ -std=c++14 -c Edge.cpp

clean: 
	rm -f $(OBJ) $(MAIN)
