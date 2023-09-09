class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size() ; 
       int prefix ; 
       int suffix ;  
       int prevmul = 1 ; 
       int ans = INT_MIN ; 
       for( int i = 0 ; i < n ; i++ ){
           prefix = prevmul * nums[i] ; 
           ans = max( ans, prefix ) ; 
           if( nums[i] == 0 ){
               prevmul = 1 ; 
           }
           else{
               prevmul = prefix ; 
           }
       }
       prevmul = 1 ; 
       for( int i = n-1 ; i >= 0 ; i-- ){
           suffix = prevmul * nums[i] ;
           ans = max( ans, suffix) ; 
           if( nums[i] == 0 ){
               prevmul = 1 ;
           }
           else{
               prevmul = suffix ; 
           }
       }
       return ans ; 
    }
};
