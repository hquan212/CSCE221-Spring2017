/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 3		-
-			-
-----------------------*/


#include "RuntimeException.h"
#include <string>
#include "Parser.h"
#include "Evaluator.h"

using namespace std;

void vari(string input){

    for(int i=0;i<input.length();i++){              //converts to ascii to check whether the input string is correct or incorrect!

        char x = input.at(i);
        int ascii = int(x);
        if(ascii == 35){        //Pound sign that ends the string
        }else if(ascii == 44){  //comma ,
            throw runtime_error("Invalid Input. Please try again");
        }else if(ascii == 32){
        }
        else if(ascii>=40 && ascii<=57){  //check numbers and operator
        }
        else if(ascii==94){//Exponential function
        }
        else if(ascii>=97&&ascii<=122){ //Lower case variables!
        }else
        throw runtime_error("Invalid Input!");
    }
}

int main() {
  cout << "Please enter only lower case varibales & numbers and the +,-,^,*,/ operators!" << endl;
  cout << "Enter the expression you want to parse:" << endl;
  string input;
  getline(cin, input);
  vari(input);
  Parser p(input);
  LinkedQueue<std::string> post = p.getPostFix();
  cout << "-------------------------------------------------" << endl;
  Evaluator eval(post);

  cout << "\nFinal Answer is: " << eval.getValue() << endl;     //Yay we are finally finished!
  return 0;  
}
