class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() ; 
        map<int,int>freq ; 
        vector<int>prefix(n,0) ; 
        prefix[0] = nums[0] ; 
        for( int i = 1 ; i < n ; i++ ){
            prefix[i] = prefix[i-1] + nums[i] ; 
        }
        int ans = 0 ; 
        for( int i = 0 ; i < n ; i++ ){
            int a = prefix[i] ; 
            int residual = a - k ; 
            if( residual == 0 ){
                ans++ ; 
            }
            if( freq.find(residual) != freq.end() ){
                ans += freq[residual] ; 
            }
            freq[a]++ ; 
        }
        return ans ; 
    }
};
