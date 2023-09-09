class Solution {
public:
    vector<int>merge( vector<int>&a, vector<int>&b ){
        int i = 0 ; 
        int j = 0 ; 
        int n = a.size() ; 
        int m = b.size() ; 
        vector<int>ans ; 
        while( i < n && j < m ){
            if( a[i] < b[j] ){
                ans.push_back(a[i]) ; 
                i++ ; 
            }
            else{
                ans.push_back(b[j]) ; 
                j++ ; 
            }
        }
        while( i < n ){
            ans.push_back(a[i]) ; 
            i++ ; 
        }
        while( j < m ){
            ans.push_back(b[j]) ; 
            j++ ; 
        }
        return ans ; 
    }
    int countPairs( vector<int>&a, vector<int>&b ){
        int i = 0 ; 
        int j = 0 ; 
        int n = a.size() ; 
        int m = b.size() ; 
        int ans = 0 ; 
        while( i < n && j < m ){
            if( a[i] > 2*1ll*b[j] ){
                ans += n - i ;
                j++ ; 
            }
            else{
                i++ ; 
            }
        }
        return ans ; 
    }
    vector<int> mergeSort( vector<int>&a, int start, int end, int&ans ){
        if( start == end ){
            return {a[start]} ; 
        }
        int mid = start + ( end - start )/2 ; 
        vector<int>left = mergeSort(a, start, mid, ans ) ; 
        vector<int>right = mergeSort(a, mid+1, end, ans ) ; 
        ans += countPairs(left, right ) ; 
        return merge(left, right) ;  

    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size() ; 
        int ans = 0 ; 
        int start = 0 ; 
        int end = n - 1 ; 
        vector<int>b = mergeSort(nums, 0, n-1, ans ) ; 
        return ans ; 
    }
};
