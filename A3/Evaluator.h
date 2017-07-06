/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 3		-
-			-
-----------------------*/


#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Parser.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "RuntimeException.h"
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>
#include <sstream>
#include <cmath>



class Evaluator {   
private:
  /* declare member variables; 
    may include a string postfix queue and a double value stack */
  LinkedQueue<std::string> postFixQueue;
  LinkedQueue<std::string> eval;
  double value;
  string tres;
  string before_double;
  /* declare utility functions */
  
public:
// save parser postFixQueue to Evaluator postFixQueue
  Evaluator(LinkedQueue<std::string> par); // constructor
  double getValue(); // returns the result of expression evaluation
  string switchCase(double a, double b,string cur_num);
  LinkedQueue<std::string> get_digits(LinkedQueue<std::string> in);
};

#endif
