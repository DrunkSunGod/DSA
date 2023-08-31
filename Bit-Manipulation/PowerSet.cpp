#include <bits/stdc++.h> 
string getStr( string str, int k ){
    string ans = "" ; 
    int n = str.size() ; 
    for( int i = 0 ; i < n ; i++ ){
        if( 1<<i & k ){
            ans.push_back( str[i] ) ; 
        }
    }
    return ans ; 
}
vector<string> subsequences(string str){
    int n = str.size() ; 
	int bin = pow( 2, n) - 1 ;
    vector<string>ans ; 
    for( int i = 1 ; i <= bin ; i++ ){
        ans.push_back( getStr(str,i) ) ; 
    } 
    return ans ; 
	
}
