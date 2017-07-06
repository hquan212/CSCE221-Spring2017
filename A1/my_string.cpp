/*	 Robert Quan
	 CSCE 221- 506
	 my_string.cpp   */

#include "my_string.h"


// Constructors

my_string::my_string() : cap(2), sz(0) 				//Default Constructor with no arguments
{				
	ptr = new char[sz];
}

my_string::my_string(int size)					//Constructor with int size argument
{
	sz = size;					
	ptr = new char[sz];
	cap = 2;
	if(cap <= sz){
		IncreaseCapacity();
	}
}

my_string::my_string(char* s)					//Actual Constructor for string input
{
	sz = 0;	
	cap = 2;
	ptr = new char[cap];						//create new pointer of size

	int i =0;	
	while(*s != '\0'){						//Add up elements in string
		ptr[i] = *s;
		sz++;
			if(cap <= sz){
				IncreaseCapacity();
			}
		s++;
		i++;
	}
}

my_string::my_string(const my_string& s)				//Copy Constructor
{
	sz = s.sz;
	cap = s.cap;
	ptr = new char[cap];
	
	for(int i=0; i< s.sz; i++){
		ptr[i] = s.ptr[i];
	}
}

my_string& my_string::operator=(my_string& q)				//Overlading the = operator to copy a contents from a my_string obejct
{
	if(cap < q.sz){
		IncreaseCapacity();
	}
	for(int i =0; i<q.sz;i++){
		ptr[i] = q.ptr[i];
	}
	return *this;
	
}

// Overloading operators

my_string& my_string::operator+=(char c)				//Constructor for character input
{
	if(cap < sz + 1 ) {
		this->IncreaseCapacity();
		}
	ptr[sz] = c;
	sz++;
	return *this;
}

my_string& my_string::operator+=(my_string& q)
{
	int sum = sz + q.sz;
	if(cap <= sum ) {
		IncreaseCapacity();
		}
	int k = 0;
	for(int i =sz; i <=sum; i++){					//assign character to new array 
		ptr[i] = q.ptr[k];
		k++;
	}
	sz = sum;
	return *this;
}

//Member Functions

my_string& my_string::insert(int i, my_string q)		//Extra credit that inserts a string at position i in another string
{


	int sum = q.size()+i;
	if(cap < sum){
		IncreaseCapacity();}
	char *temp = new char[cap];				//create a temporary array of larger size for the input
	int b=0;
	for(int k=0;k<i;k++){
		temp[k]=ptr[k];					//copy over contents of first until i
		b++;}
	int a=0;								
	for(int k=i;k<sum;k++){					//copy second string at i
		temp[k]=q.ptr[a++];}
	for(int k=sum;k<=size()+q.size();k++){
		temp[k]=ptr[b];					//continue copying the rest of the first string after i+q.size()
		b++;}
	sz = size()+q.size();					//update the new size
	delete[] ptr;
	ptr = temp;

	return *this;
}

char& my_string::operator[](int i) const			//Returns character at int i
{
	return ptr[i];	
}

char& my_string::operator[](int i)				//Returns character at int i
{
	return ptr[i];	
}

my_string::~my_string()
{								//default destructore
	delete[] ptr;
}


int my_string::size() const
{ 								//return size
	return sz; 
}	


int my_string::capacity()
{								//return capacity
	return cap; 		
}
	
bool& my_string::empty()
{								//return true if empty
	if(sz !=0){
		emp = false;}
	
	return emp;
}

char my_string::at(int i) const
{								//return element at index i
	 if(i > 0 || i < size())				
		 return ptr[i];					//Throw an error if the conditions arent met
	else {
	throw out_of_range ("Error");}
	 
}
	
void my_string::IncreaseCapacity()				//To double the capacity of the array. Very important function
{
	cap = (cap>0) ? cap*2 : 2;
	char *temp = new char[cap];
	for(int i =0; i<sz;i++){
		temp[i] = ptr[i];
	}
	delete[] ptr;						//delete the poitner to old array
	ptr = temp;				

}

//IOstreams

ostream& operator<<(ostream& os,const my_string& s){		//Output overloader operator.
	for(int i=0; i< s.size(); ++i){
		os << s.at(i);}
	return os;
}

istream& operator>>(istream& is, my_string& s){			//Input overloader operator.
	char c = getchar();
	while(c != '\t' && c != '\n' && c != ' '){
		s += c;
		c = getchar();
	}
	return is;
}
