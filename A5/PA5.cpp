/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 5		-
-			    -
-----------------------*/


#include <string>
#include <regex>
#include <fstream>
#include <iostream>
#include "HashTable.h"

using namespace std;

int main(){

    string names, emails, UIN, quizes;
    HashTable hash;     //create the hastable
    ofstream fout("output.csv");
    double totalCount;
    double quizCount;

    ifstream qui("input2.csv");     //input txt file into fstream
    regex pattern2(R"(([\s\S]+),([\s\S]+@[\s\S]+),(\d{9}),(\d{2}))"); 
    string UIN2;
    while(!qui.eof()){
        string to_search;
        getline(qui,to_search);
    
        smatch matches;     //store the matches found in regex
        regex_search(to_search, matches, pattern2);

        hash.insert(std::stoi(matches[3]),std::stoi(matches[4]));     //insert into the hash table
        quizCount ++;       //save number of times we take a quiz
    }   

    ifstream input("roster.csv");     //input txt file into fstream
    regex pattern(R"(([\s\S]+),([\s\S]+),(\d+))"); 
    int min = 0;    //minimum number of nodes in the linked list
    int max;        //save the maximum value
    while(!input.eof()){		//Get the matches from the Roster.csv
        string to_search;	
        getline(input,to_search);
    
        smatch matches;     //store the matches found in regex
        regex_search(to_search, matches, pattern);

        int quiz = hash.search(std::stoi(matches[3]));   //save the quiz value to int
        if(quiz!=-1){   //magic numer -1
        fout << matches[1] << "\t" << matches[2] << "\t" << matches[3] << "\t" << quiz << endl;}   //primout out with quizes
        else
        fout << matches[1] << "\t" << matches[2] << "\t" << matches[3] << endl;     //print out without quizes
        totalCount ++;  //add to total count

        if(min < hash.hashNodesNum(quiz)){      //compare the minimun value 
            max = hash.hashNodesNum(quiz);      //if min is smaller than nodes in linkedlist, replace with max
        }
    }

    fout.close();       //finish writing program

    cout << "HashTable minimum length in table: " << min << endl;       //Display the minimum
    cout << "HashTable maximum length in table: " << max << endl;       //Display Maximum
    cout << "HashTable average length in table: " << quizCount/totalCount << endl;      //Display the average

    return 0;
}
