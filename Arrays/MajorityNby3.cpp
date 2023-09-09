class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() ; 
        int cnt1 = 0 ; 
        int cnt2 = 0 ; 
        int ele1 ; 
        int ele2 = nums[0] - 1 ; 
        for( int i = 0 ; i < n ; i++ ){
            if( cnt1 == 0 && nums[i] != ele2 ){
                ele1 = nums[i] ; 
                cnt1++ ; 
            }
            else if( cnt2 == 0 && nums[i] != ele1 ){
                ele2 = nums[i] ; 
                cnt2++  ;
            }
            else if( nums[i] == ele1 ){
                cnt1++ ; 
            }
            else if( nums[i] == ele2 ){
                cnt2++ ; 
            }
            else{
                cnt1-- ;
                cnt2-- ; 
            }
        }
        vector<int>ans ; 
        cnt1 = 0 ; 
        cnt2 = 0 ;
        for( auto num : nums ){
            if( num == ele1 ){
                cnt1++ ; 
            }
            if( num == ele2 ){
                cnt2++ ; 
            }
        }
        if( cnt1 > n/3 ){
            ans.push_back(ele1) ; 
        }
        if( cnt2 > n/3 ){
            ans.push_back(ele2) ; 
        }
        return ans ; 
    }
};
