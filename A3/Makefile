all: run-main

run-main: Parser.o Evaluator.o Main.o
	c++ -o run-main Parser.o Evaluator.o Main.o

Main.o: Parser.h Evaluator.h RuntimeException.h
	c++ -c Main.cpp

Evaluator.o: Evaluator.h Parser.h LinkedStack.h LinkedQueue.h TemplatedDoublyLinkedList.h RuntimeException.h
	c++ -c Evaluator.cpp

Parser.o: Parser.h LinkedStack.h LinkedQueue.h TemplatedDoublyLinkedList.h RuntimeException.h
	c++ -c Parser.cpp

clean:
	rm *.o run-main
