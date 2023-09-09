int findMin(vector<int>& arr)
{
	int n = arr.size() ; 
        if( n == 1 ){
            return arr[0] ; 
        }
        if( arr[0] < arr[n-1] ){
            return arr[0] ; 
        }
        if( arr[n-1] < arr[n-2] ){
            return arr[n-1] ; 
        }
        int s = 0 ; 
        int e = n - 1 ; 
        while( s <= e ){
            int mid = s + (e-s)/2 ; 
            // cout << " mid is " << mid << endl ;
            // cout << " standing on " << nums[mid] << endl ;  
            if( arr[mid] < arr[mid-1] && arr[mid] < arr[mid+1] ){
                return arr[mid] ; 
            }
            else if( arr[mid] < arr[0] ){
                // cout << " on the second line " << endl ; 
                e = mid - 1 ; 
            }
            else{
                // cout << " On the first line " << endl ; 
                s = mid + 1 ; 
            }
        }
        return -1 ; 
}
