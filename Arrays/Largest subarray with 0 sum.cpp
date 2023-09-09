#include<bits/stdc++.h>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	int n = arr.size() ; 
	vector<long long >prefix(n,0) ; 
	prefix[0] = arr[0] ; 
	for( int i = 1 ; i < n ; i++ ){
		prefix[i] = prefix[i-1] + 1ll*arr[i] ; 
	}
	map<long long ,int>last ; 
	for( int i = 0 ; i < n ; i++ ){
		long long p = prefix[i] ; 
		last[p] = i ; 
	}
	int ans = 0 ; 
	for( int i = n-1 ; i >= 0 ; i-- ){
		long long p = prefix[i] ; 
		if( arr[i] == 0 ){
			ans = max(ans, 1) ; 
		}
		if( p == 0 ){
			ans = max( ans, i + 1 ) ; 
		}
		ans = max( ans, last[p] - i ) ; 
	}
	return ans  ;
	
}
