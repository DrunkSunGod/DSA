#include<bits/stdc++.h>
bool hasSetBit( int hash, int d ){
  return (hash & 1 << d ) ; 
}
void setBit( int &hash, int d ){
  hash = hash | 1 << d ; 
  return ;
}
int FindFirstRepeatingDigit(string digitpattern) {
  int hash = 0 ; 
  for( auto digit : digitpattern ){
    int d = digit - '0' ; 
    if( hasSetBit(hash,d) )
      return d ;
    else
      setBit(hash,d) ;  
  }
  return -1;
}
// Solved by using an integer as a hashset. We require 9 bits. If we encounter a digit k for the first time, we set the kth bit to 1.
// Now, if we see any digit k1 and the k1st bit is 1, that digit is being repeated.
