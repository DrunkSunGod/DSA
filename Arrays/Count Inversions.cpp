vector<int> merge(vector<int>&a, vector<int>&b ){
    vector<int>ans ; 
    int s1 = 0 ; 
    int s2 = 0 ; 
    int e1 = a.size() ; 
    int e2 = b.size() ; 
    int i = s1 ; 
    int j = s2 ; 
    while( i < e1 && j < e2 ){
        if( a[i] < b[j] ){
            ans.push_back(a[i]) ;
            i++ ;  
        }
        else{
            ans.push_back(b[j]) ;
            j++ ;  
        }
    }
    while( i < e1 ){
        ans.push_back(a[i]) ; 
        i++ ; 
    }
     while( j < e2 ){
        ans.push_back(b[j]) ; 
        j++ ; 
    }
    return ans ; 
}
int countInversions( vector<int>&a, vector<int>&b ){
    int s1 = 0 ; 
    int s2 = 0 ;
    int e1 = a.size() ; 
    int e2 = b.size() ; 
    int i = s1 ; 
    int j = s2 ; 
    int ans = 0 ; 
    while( i < e1 && j < e2 ){
        if( a[i] > b[j] ){
            ans += e1 - i  ; 
            j++ ; 
        }
        else{
            i++ ;
        }
    }
    return ans ; 
}
vector<int>mergeSort( vector<int>&a, int start, int end, int&ans){
    if( start == end ){
        return {a[start]} ; 
    }
    int mid = start + (end - start)/2 ; 
    vector<int>left = mergeSort(a, start, mid, ans ) ; 
    vector<int>right = mergeSort( a, mid+1, end, ans )  ;
    ans += countInversions(left, right) ; 
    return merge(left, right) ; 
}
int numberOfInversions(vector<int>&a, int n) {
    int ans = 0 ;
    vector<int>b = mergeSort(a, 0, n-1, ans) ; 
    return ans ; 
}
