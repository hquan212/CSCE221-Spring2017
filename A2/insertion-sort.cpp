//============================================================================
// Name        : insertion-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"

void
InsertionSort::sort(int A[], int size)				// main entry point
{

  resetNumCmps();   //reset the number of comparisons for other algorithms

  for(int i =1;i<size;i++){
    int tmp = A[i];
    int j = i;
    while(++num_cmps, j>0 && tmp < A[j-1]){     //we count once per comparison
        A[j] = A[j-1];                          //Switch elements in the array!
        j--;
    }
    A[j] = tmp;
  }
}
