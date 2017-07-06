/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 3		-
-			-
-----------------------*/


#include "Parser.h"


using namespace std;

/* initialize constants here */

LinkedQueue<std::string> Parser::tokenize(string input){
    LinkedQueue<std::string> lq;
    input += '#';               //Push a pound to the end of the string

    string digit = "";               //Store double digits
    string operators = "";           //Store the operators
    string inFix = "";              //Print to infix

   for(int i=0;i<input.length();i++){
       if(input[i]!=' '){
         while(input[i]!='('&&input[i]!=')'&&input[i]!='+'&&input[i]!='*'&&input[i]!='/'&&input[i]!='-'&&input[i]!='^'&&input[i]!='#'){
             digit += input[i];
             i++;
                if(input[i]=='#'){              //Hit the end of the string to break out of while loop.
                    break;
                }
         }
         lq.enqueue(digit);              //Enqueue the double digits
            if(input[i]!='#'){
                operators += input[i];          //Add the input operator charater to string
                lq.enqueue(operators);          //Enqueue operator
            }
         digit = "";                     //clear temporary string
         operators ="";
       }
   }
    inFixQueue = lq;
    if(!isBalanced()){
        throw runtime_error("Error, the parenthesis in your equation are not balanced! Please re enter your equation.");
    }
    cout << endl;
    printInfix();
    toPostFix(lq);
    return lq;
}

LinkedQueue<std::string> Parser::toPostFix(LinkedQueue<std::string> in){      //rewrite all as strings
    LinkedQueue<std::string> output;
    LinkedStack<std::string> opStack;
    opStack.push("#");
    string cur_op;      


    while(!in.isEmpty()){

        string temp = in.first();
        int num = inputPriority(temp); // prompt user for value of variable, push that variable to queue

        if(num == -2){          //Magic number.
            output.enqueue(temp);
        }

        else{
            if(num > stackPriority(opStack.top())){
                opStack.push(temp);
                }
            else{
                while(num <= stackPriority(opStack.top())){
                    cur_op = opStack.pop();
                    if(cur_op!="("&&cur_op!=")"&&cur_op!="#"){
                        output.enqueue(cur_op);}
                    }
                opStack.push(temp);           
                }
            } 
        in.dequeue();
        }
        while(!opStack.isEmpty()){
            cur_op = opStack.pop();
            if(cur_op!="("&&cur_op!=")"&&cur_op!="#"){
                   output.enqueue(cur_op);}
        }
    
        postFixQueue = output;
        printPostfix();
    return output;
}
LinkedQueue<std::string> Parser::getPostFix(){
    return postFixQueue;
}

int Parser::inputPriority(string temp){ //case for the input priority associated number
    if(temp == "#"){
            return 0;               
    }else if(temp == "+" || temp == "-"){
            return 1;
    }else if(temp == "*" || temp == "/"){
            return 3;
    }else if(temp == "^"){
            return 6;
    }else if(temp == "("){
            return 100;
    }else if(temp == ")"){
            return 0;
    }else
        return -2;
}

int Parser::stackPriority(string temp){ // case for the stack priority associated number
    if(temp == "#"){
            return -1;           
    }else if(temp == "+" || temp == "-"){
            return 2;
    }else if(temp == "*" || temp == "/"){
            return 4;
    }else if(temp == "^"){
            return 5;
    }else if(temp == "("){
            return 0;
    }else if(temp == ")"){
            return 99;
    }else
        return -2;
}

void Parser::printPostfix(){
    cout << "Postfix is: \t" << postFixQueue << endl;
}

void Parser::printInfix(){
    cout << "Infix is: \t" << inFixQueue << endl;
}

bool Parser::isBalanced(){
    LinkedQueue<std::string> balanced = inFixQueue;             //Make a copy of the input queue
    int lparen=0;
    int rparen=0;
    bool balan = false;
    while(!balanced.isEmpty()){                 //Count the number of intances that ( and ) appear in equation.
        if(balanced.first() == "("){
            lparen++;
        }
        else if(balanced.first() == ")"){
            rparen++;
        }
        balanced.dequeue();
    }
    if(lparen == rparen){                                 //If balanced, return true.
        balan = true;
    }
    return balan;
}

