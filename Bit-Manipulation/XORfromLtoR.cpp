int XORfrom1( int x ){
    if( x%4 == 0 )
        return x ; 
    if( x%4 == 1 )
        return 1 ; 
    if( x%4 == 2 )
        return x + 1 ; 
    if( x%4 == 3 )
        return 0 ; 
}
int findXOR(int L, int R){
    int a = XORfrom1(L-1) ; 
    int b = XORfrom1(R) ; 
    return a ^ b ;    
}
