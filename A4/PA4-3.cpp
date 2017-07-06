/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 4		-
-			    -
-----------------------*/


#include <string>
#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

int main(){

    ifstream out("stroustrup.txt");     //input txt file into fstream
    regex pattern("<a href=\"(.*ppt)\">");      //Pattern for problem 3
    string temp;
    while(!out.eof()){
        string to_search;
        getline(out,to_search);
    
        smatch matches;     //store the matches found in regex
        regex_search(to_search, matches, pattern);
        temp = matches[1];      //Create a temp to store and check size
        if (temp.size() > 0)
        {
            cout << temp  << endl;       //if the temp is not empty print
        }
    }

    return 0;
}