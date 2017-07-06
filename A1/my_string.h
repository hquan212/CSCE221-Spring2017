/*	 Robert Quan
	 CSCE 221- 506
	 my_string.h   */
	 
#include <stdexcept>
#include <iostream>


using namespace std;
class my_string
{
	
	public:
	//Constructors
	my_string(); 					//default constructor
	~my_string();					//destructor
	my_string(char* s);				//constructor that takes a string 
	my_string(const my_string& s);			//Copy constructor
	my_string(int s);				//Constructor that creates a new array of size s
	
	//Member functions
	int size() const;
	int capacity();					//return sieze of array sb_type
	bool& empty();					//returns true if empty, false otherwise
	char at(int i) const; 				//returns element by index in string
	void IncreaseCapacity();			//doubles size of capacity
	my_string& insert(int i, my_string q);		//Insert function for extra credit

	//Overloaded operators
	my_string& operator+=(my_string& q);		//Concatenates a my_string string to another
	my_string& operator+=(char c);			//Concatenates a char to a my_string object
	my_string& operator=(my_string& q);		//Copies a my_string object to another
	char& operator[](int i);			//Return character at index i of s
	char& operator[](int i) const;

	//IOstreams
	friend ostream& operator<<(ostream& os, const my_string& s);
	friend istream& operator>>(istream& is, my_string& s);	
	
	private:
	char *ptr;					//pointer to the address of the array
	int sz, cap;					//sz is size, cap is capacity of array
	bool emp = true;				//Returns true if object is empty
};
