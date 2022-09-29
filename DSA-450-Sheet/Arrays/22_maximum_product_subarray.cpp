Given an array Arr[] that contains N integers (may be positive, negative or zero). 
Find the product of the maximum product subarray.

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.


class Solution{
public:
    long long int max(long long int a, long long int b) {
        if(a >= b)
            return a;
        return b;
    }
    long long int min(long long int a, long long int b) {
        if(a <= b)
            return a;
        return b;
    }
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    
	    long long int res = LLONG_MIN;
	    
	    for(int i=0;i<n;i++)
	        res = max(res, arr[i]);
	    
	    long long int cur_max = 1;
	    long long int cur_min = 1;
	    
	    for(int i=0;i<n;i++) {
	        
	        if(arr[i] == 0) {
	            cur_max = 1;
	            cur_min = 1;
	            continue;
	        }
	        
	        long long int temp = cur_max;
	        
	        cur_max = max(max(cur_max*arr[i], cur_min*arr[i]), arr[i]);
	        cur_min = min(min(temp*arr[i], cur_min*arr[i]), arr[i]);
	        
	        res = max(res, cur_max);
	        
	    }
	    
	    return res;
	    
	}
};