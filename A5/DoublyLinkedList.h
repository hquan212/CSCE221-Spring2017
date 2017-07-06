/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 5		-
-			-
-----------------------*/


#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

// list node

class HashNode {
private:
  HashNode *prev, *next;
  int key;
  int value;
  friend class DoublyLinkedList;
public:
  HashNode(int e=0, int v=0, HashNode *p = nullptr, HashNode *n = nullptr)
    : key(e), value(v), prev(p), next(n) {}
  int getKey() const { return key; }         //Return element
  int getValue() const { return value;} //returns value
  void changeValue(int in) { value = in;}
  HashNode * getNext() const { return next; }    //Return next pointer
  HashNode * getPrev() const { return prev; }    //Return previous pointer
};

// doubly linked list

class DoublyLinkedList {
protected:
  HashNode header, trailer;   //Create two obejcts from HashNode? 
public:
  DoublyLinkedList() : header(0), trailer(0) 
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList(const DoublyLinkedList& dll); // copy constructor
  ~DoublyLinkedList(); // destructor
  DoublyLinkedList& operator=(const DoublyLinkedList& dll); // assignment operaton  
  HashNode *getFirst() const { return header.next; } // return the pointer to the first node
  const HashNode *getAfterLast() const { return &trailer; }  // return the pointer to the trailer
  bool isEmpty() const { return header.next == &trailer; } // check if the list is empty
  int first() const ; // return the first object
  int last() const ; // return the last object
  void insertFirst(int newobj, int value); // insert to the first of the list
  int removeFirst(); // remove the first node
  void insertLast(int newobj, int value); // insert to the last of the list
  int removeLast();  // remove the last node
};
// output operator

ostream& operator<<(ostream& out, const DoublyLinkedList& dll);