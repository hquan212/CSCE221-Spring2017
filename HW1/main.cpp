#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int binary_search_ascending(vector<int> v, int n, int x, int &c) {
    int mid, low = 0, high = n-1;
    while ( low <= high ) {
        mid = ceil((low + high)/2);
        cout << "Low: " << low << "\tMid: " << mid << "\tHigh: " << high << endl;
        if (c++, v[mid] < x ) low = mid+1;
        else if(c++, v[mid] > x ) high =  mid-1;
        else return mid; // found
    }
    return -1;  // not found
}

int binary_search_descending(vector<int> v, int n, int x, int &c) {
    int mid, low = 0, high = n-1;
    while ( low <= high ) {
        mid = floor((low + high)/2);
        cout << "Low: " << low << "\tMid: " << mid << "\tHigh: " << high << endl;
        if (c++, v[mid] > x ) low = mid+1;
        else if(c++, v[mid] < x ) high =  mid-1;
        else return mid; // found
    }
    return -1;  // not found
}

int main()
    try{

        vector<int> v;
        bool ascending;
        bool descending;
	    int element;
	    int size;
        int c=0;

	    cout << "Please enter the range that you want your vector: ";
    	cin >> size;

        if(size ==1){
            v.push_back(size);
        }

        else{
            /*for(int i=0; i<=size-1;i++){               //create the ascending vector
                v.push_back(i+1);                        //add the elements
            }*/

             for(int i=size; i>0;i--){               //create the decreasing vector
                v.push_back(i);                        //add the elements
            }
            cout << "Vector is: \t";                //Print out the vector
            for(int i=0;i<size;i++){
                cout << v[i];
            }
            cout << endl;

            if(*(v.begin()) < *(v.begin()+1)){         //Check if overall ascending
                ascending = true;
                cout << "\nAscending Vector\n";
             }
            else if(*(v.begin()) > *(v.begin()+1)){     //Check if overall descending
                descending = true;
                cout << "\nDescending Vector\n";
            }
            
            for(int i=0;i<=size-1;i++){
                if(ascending && v[i]>v[i+1]){           //Check if correctly sorted
                    cerr << "Ascending Unsorted error!";
                    return -1;
                }

                else if(descending && v[i]<v[i+1]){     //Check if correctly sorted
                    cerr << "Descending Unsorted error!";
                    return -1;
                }
                else break;
            }
        }
        cout << "Please enter the element you want to find: ";
        cin >> element;
        int num;

        if(ascending){
            num = binary_search_ascending(v,v.size(),element,c);
        }

        if(descending){
            num = binary_search_descending(v,v.size(),element,c);
        }

        if(num == -1){
            throw("Error");
        }
        
        cout << "Your element was found after " << c << " comparisons.\n";

 }    
    
   
    
    catch(const out_of_range& e){
        cerr << "Out of range: " << e.what() << endl;
    }
    catch(const char e[]){
        cerr << e << endl;
        cerr << "Error!";
    }
    catch(...){
        cerr << "Uncaught error: " << endl;
    }
