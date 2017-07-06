/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 3		-
-			-
-----------------------*/


#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include "RuntimeException.h"
#include "TemplatedDoublyLinkedList.h"

template<typename T> class LinkedQueue;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue);

template<typename T>
class LinkedQueue {
private:
   //DListNode *front, *rear;   
   DoublyLinkedList<T> ll;
  //void deleteLinkedQueue();    //Delete?

public:
   LinkedQueue() { }    //Constructor, default points to NULL
   T first() const;
   T dequeue();
   bool isEmpty() const {return ll.isEmpty();}
   void enqueue(const T elem);
};

/*----------------Functions---------------*/

template<typename T>
T LinkedQueue<T>::first() const  {
  if(ll.isEmpty())
    throw runtime_error("Stack is empty");
  return ll.first();
}

template<typename T>
void LinkedQueue<T>::enqueue(const T elem)  {
    ll.insertLast(elem);
}


template<typename T>
T LinkedQueue<T>::dequeue(){
  if(ll.isEmpty())
      throw runtime_error("Stack is empty");
  return ll.removeFirst();
}

//----------------Overloading Operator----------------------------------

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue){
  LinkedQueue<T> que = queue;
  while(!que.isEmpty()) {
    out << que.first();
    que.dequeue();
  }
   return out;
}
#endif
