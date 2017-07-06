/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 3		-
-			-
-----------------------*/

#include "Evaluator.h"

using namespace std;

Evaluator::Evaluator(LinkedQueue<std::string> par){
  LinkedQueue<std::string> digi;
  digi = get_digits(par);       //Return a string that has the digits instead of varibales
  digi.enqueue("#");          //put default character on queue
  LinkedStack<std::string> stack;
  string cur_num;
  string tres;

  cout << "Postfix with digits: \t" << digi << endl;
    while(!digi.isEmpty()){       //Iterate through the new digit postfix queue
        cur_num = digi.first();
          if(cur_num=="+"||cur_num=="-"||cur_num=="/"||cur_num=="^"||cur_num=="*"){   //If we encounter an operator
              string one = stack.pop();         //Pop off the first item on stack
              string two = stack.pop();         //take off the second one from the stack
              double b = stod(one);        //convert string to double
              double a = stod(two);
              tres = switchCase(a,b,cur_num);   //return string 
              stack.push(tres);       //push new string onto stack
          }else if(cur_num == "#"){   //if we see the pound we end operation
            break;
          }

          else{
            stack.push(cur_num);    //if digit or number, push onto stack
          }
        digi.dequeue();
    }
 
      before_double = stack.top();
}

LinkedQueue<std::string> Evaluator::get_digits(LinkedQueue<std::string> in){    //Request the user to input digits for variables


  LinkedQueue<std::string> digits;
  string x;

  while(!in.isEmpty()){
    string tem = in.first();
    switch(tem[0]){         //If character is a letter 
      case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h':
      case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': 
      case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x':
      case 'y': case 'z':
      cout << endl;
      cout << "Enter a value for " << tem << ": ";      //replace letter with digit value
      cin>>x;
      digits.enqueue(x);          //enqueue the new digit in place of the letter
      break;

      case '+': case '-': case '*': case '/': case '^': 
      digits.enqueue(tem);        //if operator just enqueue
      break;

      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
      case '8': case '9':             //Error here, need to figure out how to introduce double digits...
      digits.enqueue(tem);
      break;

    }
    in.dequeue();
  }
  cout << endl;
  return digits;      //return a queue of string digits
}


double Evaluator::getValue() {
    value = stod(before_double);      //conver the final string to a double
  return value;             //return the double
}  

string Evaluator::switchCase(double a, double b,string cur_num){    //switches each operation case
  stringstream third;
  double c;

  if(cur_num=="*"){
    c = a*b;
  }else if(cur_num=="/"){
    c = a/b;
  }else if(cur_num=="+"){
    c = a+b;
  }else if(cur_num=="-"){
    c = a-b;
  }else if(cur_num=="^"){
    c = pow(a,b);
  }else{cout << "Operation failed!" << endl;}

  third << c;       //convert the double to a string
  third >> tres;    //using stringstream
  return tres;
}
