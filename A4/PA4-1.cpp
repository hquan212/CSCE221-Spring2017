/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 4		-
-			    -
-----------------------*/


#include <string>
#include <iostream>
#include <regex>


using namespace std;

int main(){

    regex pattern{R"((\d\d)(?:.+)(thanks))"};           //Patter to be found 
    string to_search = "I would like the number 98"" to be found and printed, thanks."; //input
    
    smatch matches;     //store the matches in an array
    regex_search(to_search, matches, pattern);
    for(auto match : matches) { //print out matches
        cout << match << endl;
    }

    return 0;
}