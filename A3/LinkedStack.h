/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 3		-
-			-
-----------------------*/


#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
#include <stdexcept>
#include "RuntimeException.h"
#include "TemplatedDoublyLinkedList.h"

template<typename T> class LinkedStack;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack);
    
template<typename T>
class LinkedStack
{
private:
  DoublyLinkedList<T> ll;      //Create a default DoublyLinkedList
  
public:
  
   LinkedStack () : ll() { }     //Default Constructor
   bool isEmpty() const {return ll.isEmpty();}	//Returns tru if empty
   void push(const T elem);		//Push element onto stack
   T pop();			//pop off 
   T top() const;		//get the first
      
};

/*------------------Functions-----------------------*/
template <typename T>
T LinkedStack<T>::pop() {
  if (ll.isEmpty())
    throw runtime_error("Stack is empty");
  return ll.removeFirst();
}

template <typename T>
T LinkedStack<T>::top() const  {
  if(ll.isEmpty())
    throw runtime_error("Stack is empty");
  return ll.first();
}

template <typename T>
void LinkedStack<T>::push(const T elem)  {
  return ll.insertFirst(elem);
}


//-----------------Overloading Operators----------------------

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack) {
  LinkedStack<T> st = stack;
  while(!st.isEmpty()) {
    out << st.top();
    st.pop();
  }
   return out;
}

#endif
