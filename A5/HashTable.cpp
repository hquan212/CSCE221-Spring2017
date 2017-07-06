
/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 5		-
-			-
-----------------------*/

#include "HashTable.h"

using namespace std;


int HashTable::hash(const unsigned long key) {
    return key%prime;       //hash function
}

void HashTable::insert(const int key, int value) {
    int h = hash(key);
    DoublyLinkedList *temp = &vec[h];
    temp->insertLast(key, value);   //call function from doubly linked list
}

int HashTable::search(const int key) {
    int h = hash(key);      //using hash function
    HashNode *node = vec[h].getFirst();
    if(vec[h].isEmpty()){       //return -1 if empty
            return -1;
    }
    while(node !=  vec[h].getAfterLast()){      //if node is not at trailer
            if(node->getKey() == key){
                return node->getValue();        //give me the value
            }
        node = node->getNext();     //move through the list
    }
}

void HashTable::print(){        //prints out everything
    for(int i=0;i<prime;i++){
            cout << vec[i];
    }
}

int HashTable::hashNodesNum(const int key){     //input the key
    double count;
    int h = hash(key);
    HashNode *node = vec[h].getFirst();     //create node that going to iterate through
    if(vec[h].isEmpty()){
            return 0;       //if empty return 0
    }
    while(node !=  vec[h].getAfterLast()){
        count++;       //add to the count
        node = node->getNext();
    }
    return count;
}