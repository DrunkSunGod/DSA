class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int k = nums.size() ; 
        vector<int>ans(k,0) ; 
        int i = 0 ; 
        int j = 1 ;
        int idx = 0 ; 
        while( idx < k ){
            if( nums[idx] > 0 && i < k ){
                ans[i] = nums[idx] ; 
                i += 2 ; 
            }
            else if( nums[idx] < 0 && j < k ){
                ans[j] = nums[idx] ; 
                j += 2 ; 
            }
            idx++ ; 
        }
        return ans ; 
    }
};
