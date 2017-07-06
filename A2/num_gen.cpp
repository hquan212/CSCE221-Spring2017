#include <vector>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int* generate_nums(int order = 3, const string& type = "random"){
	int list_size = pow(10,order);	
	int max_int = pow(2,15) - 1;
	int count = 0;				//Current elements in list, for asc and desc
	int* list = new int[list_size];		//List to be created
	ofstream out;				//File to write to
	out.open(type + "_listE" + to_string(order) + ".txt");
	out << list_size << '\n';
	int sign = 0;
	if(type == "random"){					//For "random" specification
		srand(time(NULL));
		for(int i = 0; i < list_size; i++){
			(rand()%2 == 0) ? sign = 1: sign = -1;	//Random sign selection
			int temp = rand()%max_int*sign;		//Random int selection
			out <<  temp << '\n';
			list[i] = temp;
		}
	}

	if(type == "ascending"){				//For "ascending" specification
		srand(time(NULL));
		int i = max_int*-1;
		while(i <= max_int){
			if(rand()%15 == 1){			//Random inclusion coin-toss
				out <<  i  << '\n';
				list[count] = i;
				count++;
			if(rand()%2 != 0){
				i++;				//Random repetition coin-toss
			}
			if(count >= list_size){			//If list is full, quit
				return list;
			}
			}
		}
	}
	if(type == "descending"){				//For "descending" specification
		srand(time(NULL));
		int i = max_int;
		while(i >= (max_int*-1)){
			if(rand()%15 == 1){			//Random inclusion coin-toss
				out <<  i  << '\n';
				list[count] = i;
				count++;
			if(rand()%2 != 0){
				i--;				//Random repetition coin-toss
			}
			if(count >= list_size){
				return list;			//If list is full, quit
			}
			}
		}
	}
out.close();
return list;
}
