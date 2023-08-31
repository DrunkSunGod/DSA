#include<bits/stdc++.h>
int getXOR(vector<int>&arr ){
    int ans = 0 ; 
    for( auto num : arr ){
        ans ^= num ; 
    }
    return ans ; 
}
int getFirstSetBit(int x ){
    for( int i = 0 ; i < 32 ; i++ ){
        if( x & 1<<i ){
            return i ; 
        }
    }
    return -1 ; 
}
bool bitIsSet( int k, int x ){
    return (x & 1<<k) ; 
}
vector<int> twoOddNum(vector<int> arr){
     int arrayXOR = getXOR(arr) ;
     int k = getFirstSetBit(arrayXOR) ; 
     vector<int>ans ; 
     int bit0 = 0 ; 
     int bit1 = 0 ; 
     for( auto num : arr ){
         if( bitIsSet(k, num ) ){
             bit1 ^= num ; 
         }
         else{
             bit0 ^= num ; 
         }
     }
     ans.push_back( max(bit0,bit1))  ;
     ans.push_back( min( bit1, bit0 ) ) ; 
     return ans  ;
}
