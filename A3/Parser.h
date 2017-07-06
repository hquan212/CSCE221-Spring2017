/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 3		-
-			-
-----------------------*/


#ifndef PARSER_H
#define PARSER_H

#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "RuntimeException.h"
#include <vector>
#include <string>

class Parser {
private:
  /* declare constants */
  /* declare member variables;
   may include a string postfix queue and a integer operator stack */
   LinkedQueue<std::string> postFixQueue;	//Holds the postFix notation
   LinkedQueue<std::string> inFixQueue;		//Holds the infixnotation
   LinkedQueue<std::string> tokenize(std::string input);	//Tokenizes string
   LinkedQueue<std::string> toPostFix(LinkedQueue<std::string> in);
public:
  
  // tokenize s and save that to inFixQueue
  // convert inFixQueue to postfix and save to postFixQueue
  Parser(std::string s){tokenize(s);};	//constructor
  LinkedQueue<std::string> getPostFix();	//Return postFixQueue
  int inputPriority(string temp);	//Returns inputPriority associated number
  int stackPriority(string temp);	//Returns stackPriority associated number
  bool isBalanced();      //return true if parenthesis are balanced.
  // operations
  void printInfix();
  void printPostfix();
};

#endif
