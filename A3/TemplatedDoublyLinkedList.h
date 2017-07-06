/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 3		-
-			-
-----------------------*/


#ifndef TEMPLATED_DOUBLY_LINKED_LIST_H
#define TEMPLATED_DOUBLY_LINKED_LIST_H

//programming assignment 3 Templated Doubly Linked List

#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class DoublyLinkedList; // class declaration

// list node
template <typename T>
class DListNode {
private:
  T obj;
  DListNode<T> *prev, *next;
  friend class DoublyLinkedList<T>;
public:
  DListNode(T e=T(), DListNode<T> *p = nullptr, DListNode<T> *n = nullptr)
    : obj(e), prev(p), next(n) {}
  T getElem() const { return obj; }         //Return element
  DListNode<T> * getNext() const { return next; }    //Return next pointer
  DListNode<T> * getPrev() const { return prev; }    //Return previous pointer
};

//--------------------------------------------doubly linked list-----------------------
template <typename T>
class DoublyLinkedList {
protected:
  DListNode<T> header, trailer;   //Create two obejcts from DListNode? 
public:
  DoublyLinkedList() : // Default constructor
    header(T()), trailer(T()) 
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList(const DoublyLinkedList<T>& dll); // copy constructor
  ~DoublyLinkedList(); // destructor
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operaton  
  DListNode<T> *getFirst() const { return header.next; } // return the pointer to the first node
  const DListNode<T> *getAfterLast() const { return &trailer; }  // return the pointer to the trailer
  bool isEmpty() const { return header.next == &trailer; } // check if the list is empty
  T first() const ; // return the first object
  T last() const ; // return the last object
  void insertFirst(T newobj); // insert to the first of the list
  T removeFirst(); // remove the first node
  void insertLast(T newobj); // insert to the last of the list
  T removeLast();  // remove the last node
};
// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);


// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
  // Initialize the list
  header.next = &trailer;				//Make an empty list
  trailer.prev = &header;
  
  DListNode<T>* temp = dll.getFirst();			//Create a temporary node that will trace through
  while(temp != dll.getAfterLast()){			//Run through the elements to create copies and then move the list
    this->insertLast(temp->getElem());
    temp = temp->getNext();
  }
}

// assignment operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
  if(!isEmpty()){					//Cheack if list is not empty
    while(header.next != &trailer){
        removeFirst();
    } 
  }
  DListNode<T>* temp = dll.getFirst();			//Create a temporary node that will run though elements
  while(temp != dll.getAfterLast()){
   this->insertLast(temp->getElem());			//Copy each node over
   temp = temp->getNext();
    }
  return *this;						//Return pointer to new assigned list
}

// insert the object to the first of the linked list
template <typename T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{ 
  DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);	//Create a new Node with pointers
  header.next->prev = newNode;				//Insert a new node into the front of the Doubly linked list
  header.next = newNode;

}

// insert the object to the last of the linked list
template <typename T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
  DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer); 	//Create a new Node with pointers
  trailer.prev->next = newNode;					//Insert at the end of the Doubly Linked List.
  trailer.prev = newNode;
}

// remove the first object of the list
template <typename T>
T DoublyLinkedList<T>::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode<T> *node = header.next;          //Reference the deleted node
  node->next->prev = &header;           //move to next element after node and repoint to header
  header.next = node->next;             //Change header to second node
  T obj = node->obj;
  delete node;
  return obj;
}

// remove the last object of the list
template <typename T>
T DoublyLinkedList<T>::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode<T> *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  delete node;
  return obj;
}

// destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList<T>()
{
  DListNode<T> *prev_node, *node = header.next;			//Create two pointers
  while (node != &trailer) {
    prev_node = node;						//Assigne prev_node to point at node
    node = node->next;				
    delete prev_node;						//Go deleting the nodes at pre_node
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// return the first object
template <typename T>
T DoublyLinkedList<T>::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return header.next->obj;
}

// return the last object
template <typename T>
T DoublyLinkedList<T>::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev->obj;
}

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
  DListNode<T>* temp = dll.getFirst();				//Make temp point to the first element in dll
  while(temp != dll.getAfterLast()){				//Iterate through the list
    out << temp->getElem() << " ";				//Output the elements in the nodes
    temp = temp->getNext();
  }
  return out;
}

#endif
