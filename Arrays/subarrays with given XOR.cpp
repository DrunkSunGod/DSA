#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size() ; 
    vector<int>XOR(n,0) ;
    XOR[0] =  a[0] ; 
    map<int,int>freq ; 
    freq[XOR[0]]++ ; 
    for(int i = 1 ; i < n ; i++){
        XOR[i] = XOR[i-1] ^ a[i] ; 
        freq[XOR[i]]++ ; 
    }
    int ans = 0 ; 
    for( auto num : XOR ){
       if( num == b ){
           ans += 2 + freq[0] ; 
       }
       else{
           ans += freq[b^num] ; 
       }
    }
    return ans/2 ; 

}
