
/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 5		-
-			-
-----------------------*/

#include <vector>
#include "DoublyLinkedList.h"

using namespace std;

class HashTable {
private:
      int prime = 100;		//lets create 100 buckets
      std::vector<DoublyLinkedList> vec;	//vector to hold the DLL ADT
public:
      HashTable() { 
            DoublyLinkedList temp;	//initialize
            for(int i=0;i<prime;i++){ vec.push_back(temp);} //insert lists in the vector
      }
      int hash(const unsigned long key);        //hash function
      void insert(const int key, int value);     //insert into list
      int search(const int key);                //search for the UIN in list and return quiz grade
      void print();                 //print out everything
      int hashNodesNum(const int key);          //number of nodes in the lists
};
