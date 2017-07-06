//============================================================================
// Name        : bubble-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void 
BubbleSort::sort(int A[], int size)			// main entry point
{
  resetNumCmps();   //reset the number of comparisons for other algorithms

    for(int k=1; k< size; k++){
      bool cont = false;
      for(int j=0;j<size-k;j++){
        if(++num_cmps,A[j+1] < A[j]){              //Count once for comparsion
          int temp=A[j];
          A[j] = A[j+1];            		  //Swap elements                 
          A[j+1] = temp;			  //Reassign bigger element to next
          cont = true;
        }
      }
        if(!cont)break;
    }
}
