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

    //https://regex101.com/r/5ArkqS/2       Website that helped me find the pattern
    //regex pattern{R"(<title>([\s\S]+)</title>)"};

    regex pattern{R"(<head>((?:(?!<title>).)*)(<title>[^<]+</title>)?([\s\S]*)</head>)"};
    string to_search = "<html><head>Wow such a header <title>This is a title</title>"
                "So top</head>Much body</html>";
    
    smatch matches;     //store the matches found in regex
    regex_search(to_search, matches, pattern);

    cout << matches[1]  << endl;       //print out found matches
    cout << matches[3]  << endl;

    return 0;
}