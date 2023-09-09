class Solution {
public:
    bool canBeMade( vector<int>& bloomDay, int m, int k, int nDays ){
        int n = bloomDay.size() ; 
        int i = 0 ; 
        int j = 0 ; 
        int bouquets = 0 ; 
        while( i < n && j < n ){
            if( j - i == k - 1 && bloomDay[j] <= nDays ){
                bouquets++ ; 
                i = j + 1 ;
                j++ ; 
                if( bouquets == m )
                    return true ; 
            }
            else if( bloomDay[j] <= nDays ){
                j++ ; 
            }
            else if( bloomDay[j] > nDays ){
                i = j + 1 ; 
                j++ ; 
            }
        }
        return false ; 
    } 
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 1 ; 
        int e = 1e9 ; 
        int ans = -1 ; 
        while( s <= e ){
            int mid = s + (e - s)/2 ; 
            if( canBeMade(bloomDay, m, k, mid) ){
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
