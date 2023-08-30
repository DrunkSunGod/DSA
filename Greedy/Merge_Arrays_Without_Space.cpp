#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i = m - 1 ; 
	int j = n - 1 ; 
	int lastidx = m + n - 1 ; 
	while( i >= 0 && j >= 0 ){
		if( arr1[i] >= arr2[j] ){
			arr1[lastidx] = arr1[i] ; 
			i-- ; 
			lastidx-- ; 
		}
		else{
			arr1[lastidx] = arr2[j] ; 
			j-- ; 
			lastidx-- ; 
		}
	}
	while( j >= 0 ){
		arr1[lastidx] = arr2[j] ; 
		j-- ; 
		lastidx-- ; 
	}
	while( i >= 0 ){
		arr1[lastidx] = arr1[i] ; 
		i-- ; 
		lastidx-- ; 
	}
	return arr1 ; 
}
