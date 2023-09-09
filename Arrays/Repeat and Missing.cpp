vector<int> findMissingRepeatingNumbers(vector < int > a) {
    long long sum = 0 ;
    int n = a.size() ;  
    for( auto num : a ){
        sum += 1ll*num ; 
    }
    int diff = -n*(n+1)/2 + sum ;
    long long sumSquare = 0 ; 
    for( auto num : a ){
        sumSquare += 1ll*num*num ; 
    }
    int add = (sumSquare - 1ll*n*1ll*(n+1)*(2*n+1)/6)/diff ; 
    vector<int>ans(2,0) ; 
    ans[0] = (diff + add)/2 ; 
    ans[1] =add - ans[0] ; 
    return ans ; 

}
