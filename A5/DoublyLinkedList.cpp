/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 5		-
-			-
-----------------------*/

// extend range_error from <stdexcept>
#include "DoublyLinkedList.h"

struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer;				//Make an empty list
  trailer.prev = &header;
  
  HashNode* temp = dll.getFirst();			//Create a temporary node that will trace through
  while(temp != dll.getAfterLast()){			//Run through the elements to create copies and then move the list
    this->insertLast(temp->getKey(), temp->getValue());
    temp = temp->getNext();
  }
}

// assignment operator

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  if(!isEmpty()){					//Cheack if list is not empty
    while(header.next != &trailer){
        removeFirst();
    } 
  }
  HashNode* temp = dll.getFirst();			//Create a temporary node that will run though elements
  while(temp != dll.getAfterLast()){
   this->insertLast(temp->getKey(), temp->getValue());			//Copy each node over
   temp = temp->getNext();
    }
  return *this;						//Return pointer to new assigned list
}

// insert the object to the first of the linked list

void DoublyLinkedList::insertFirst(int newobj, int value)
{ 
  HashNode *newNode = new HashNode(newobj, value, &header, header.next);	//Create a new Node with pointers
  header.next->prev = newNode;				//Insert a new node into the front of the Doubly linked list
  header.next = newNode;
}

// insert the object to the last of the linked list

void DoublyLinkedList::insertLast(int newobj, int value)
{
  HashNode *newNode = new HashNode(newobj, value, trailer.prev,&trailer); 	//Create a new Node with pointers
  trailer.prev->next = newNode;					//Insert at the end of the Doubly Linked List.
  trailer.prev = newNode;
}

// remove the first object of the list

int DoublyLinkedList::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  HashNode *node = header.next;          //Reference the deleted node
  node->next->prev = &header;           //move to next element after node and repoint to header
  header.next = node->next;             //Change header to second node
  int key = node->key;
  int value = node->value;
  delete node;
  return key;
}

// remove the last object of the list

int DoublyLinkedList::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  HashNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int key = node->key;
  int value = node->value;
  delete node;
  return key;
}

// destructor

DoublyLinkedList::~DoublyLinkedList()
{
  HashNode *prev_node, *node = header.next;			//Create two pointers
  while (node != &trailer) {
    prev_node = node;						//Assigne prev_node to point at node
    node = node->next;				
    delete prev_node;						//Go deleting the nodes at pre_node
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// return the first object

int DoublyLinkedList::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return header.next->key;
}

// return the last object

int DoublyLinkedList::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev->key;
}

// output operator

ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
  HashNode* temp = dll.getFirst();				//Make temp point to the first element in dll
  while(temp != dll.getAfterLast()){				//Iterate through the list
    out  << temp->getKey() << ",\t" << temp->getValue() << endl;				//Output the elements in the nodes
    temp = temp->getNext();
  }
  return out;
}

