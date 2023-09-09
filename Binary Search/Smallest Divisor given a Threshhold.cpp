class Solution {
public:
    int divisionSum( vector<int>&nums, int divisor ){
        int ans = 0 ; 
        for( auto num : nums ){
            ans += num/divisor ; 
            if( num%divisor )
                ans++ ; 
        }
        return ans ; 
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1 ; 
        int e = 1e6 ; 
        int ans = -1 ; 
        while( s <= e ){
            int mid = s + (e-s)/2 ; 
            if( divisionSum(nums, mid ) <= threshold ){
                ans = mid ; 
                e = mid - 1 ;
            }
            else{
                s = mid + 1 ; 
            }
        }
        return ans ; 
    }
};
