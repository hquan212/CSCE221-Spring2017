// main.cpp
// Test all the functionality of the constructors, member functions, and operators of the my_string class
// The sample test is provided below. Use the patern to create your own test cases.

#include "my_string.h"

int main()
  try{
    cout << "Testing my_string class: \n";
    // declare a string v1 using a default constructor
    my_string v1;
    // declare two strings: v2, v3 and initialize them with C-strings
    my_string v2("first");
    my_string v3("second");
    // append the strings v2 and v3 to v1 and separate them by a whitespace
    v1 += v2;
    v1 += ' ';
    v1 += v3;
    //display the string v1 using the overloaded operator <<
    cout << "v1 = " << v1 << endl;
     //display the size and capacity of the string v1
    cout << "v1 size = " << v1.size() << endl;
    cout << "v1 capacity = " << v1.capacity() << endl;
  
    // display the string v1 characters separated by space using the overloaded operator []
    cout << "v1 as [] characters:\n";
    for (int i = 0; i < v1.size(); i++) {
      cout << v1[i] << ' ' ;
    }
    // display the string v1 characters separated by space using the overloaded operator at()
    cout << "\nv1 as at() characters:\n";
    for (int i = 0; i < v1.size(); i++) {
      cout << v1.at(i) << ' ' ;
    }
    cout << endl << endl;
      
    // declare and create a string v4 by allocating 4 bytes
    // and then initialize it by appending one single character at a time
    {
      my_string v4(4);
      v4 += 'a';
      v4 += 'b';
      v4 += 'c';
      v4 += 'd';
      // display the size and capacity of the string v4
      cout << "v4 = " << v4 << endl;
      cout << "v4 size = " << v4.size() << endl;
      cout << "v4 capacity = " << v4.capacity() << endl;
        
      // check if the string v4 is empty
      const char* empty = v4.empty() ? "true" : "false";
      cout << "is v4 empty: " << empty << endl;
      cout << endl;
    }
      
    // declare a string v5 and initialize it with v1 using the copy constructor
    my_string v5(v1);
    // display the string v5
    cout << "v5 = " << v5 << endl;
    // create an auxiliary string v5a and insert it in v5 in places at positions 5 and 14
    my_string v5a("ly");
    cout << "v5.insert(5, \"ly\") and v5.insert(14, \"ly\"): \n";
    v5.insert(5, v5a);
    v5.insert(14, v5a);
    // display v5
    cout << "v5 = " << v5 << endl;
    cout << endl;
      
    // declare and create an empty string v6 and initialize it with an input stream
    // a whitespace terminates the input stream
    my_string v6;
    cout << "Enter a string:\n";
    cin >> v6;
    // display v6
    cout << "v6 = " << v6 << endl;
      
    // create v7 and initialize it to v6
    my_string v7(v6);
    // append v2
    v7 += v2;
    // insert a whitespace
    v7.insert(v6.size(), my_string(" "));
    cout << "v6 + \" \" + v2 = " << v7 << endl;
      
    // create v8 and initialize it with v6
    my_string v8(v6);
    // append the last character of v6
    v8 += v6[v6.size()-1];
    // display v8
    cout << "v6 + last char of v6 = " << v8 << endl;
    cout << endl;
    return 0;
  }
  // catching an exception
  catch(const out_of_range& e) {
    cerr << "Out of range: " << e.what() << endl;
  }
  catch(...) {
    cerr << "Uncaught error: " << endl;
  }
