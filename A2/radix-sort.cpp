//============================================================================
// Name        : radix-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of radix sort in C++
//============================================================================
#include "sort.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string.h>

void RadixSort::sort(int* A, int size){
	int max_int = std::pow(2,16) - 1;			//Max int possible 
	long* B = new long[size];			//To hold numbers larger than int could contain

	for(int i = 0; i < size; i++){
		B[i] = A[i] + max_int;			//Add max int value to get rid of negatives, put in long for storage
	}

	int shift = 0;					//Initialize shift to 0, 
	long* tmp_array = new long[size];		//Temp holding array

	
	while(shift < 32){				//Enough shift to hold max int, 32 bits
		long count[256] = {0};			//Empty vocabulary array
		for(int i = 0; i < size; i++){
			int bits = (B[i] >> shift) & 255;//Isolate bytes
			count[bits] += 1;		//Increment selected byte in vocab array
		}

	for(int i = 1; i < 256; ++i){
		count[i] += count [i - 1];    //Cascading add to designate number of indices below to fill
	}
	
	for(int i = size - 1; i >= 0; --i){
		int bits = (B[i] >> shift) & 255; //Get highest index bit from B, for stability
		count[bits]--;
		tmp_array[count[bits]] = B[i];    //Reverse indexing to assign sorted bytes and fill
		}
	memcpy(B, tmp_array, size*sizeof(B[0]));//Move tmp_array to B
	shift += 8;				//Increment shift to get next byte
	}

	for(int i = 0; i < size; i++){
		A[i] = B[i] - max_int; //Backshift for negatives
	}

delete[] B; //Clear memory for B
}
