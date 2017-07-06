//============================================================================
// Name        : shell-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of shell sort in C++
//============================================================================

#include "sort.h"
#include <iostream>
#include <stdlib.h>


void
ShellSort::sort(int A[], int size)
{
  resetNumCmps();   //reset the number of comparisons for other algorithms
  
  int n = size;
  int increment = n/2;                //Select the location of the gaps
  while(increment >0){
    int last = increment;
    while(last < n){                    //Last must be smaller than n
      int current = last - increment;
      while(current >=0){
        if(++num_cmps, A[current] > A[current +increment]){     //Comparison of out the current vaue and the next block
          int temp = A[current];
          A[current] = A[current + increment];              //swap
          A[current + increment] = temp;                    //swap
          current -= increment;                           //Chage current by subtracting incremental size
        }
        else {break;}               //success
      }
      last++;                         //Move onto next value
    }
    increment /=2;            //Gap size again
  }
}
