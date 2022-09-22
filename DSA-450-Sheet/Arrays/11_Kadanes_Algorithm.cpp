Given an array Arr[] of N integers. 
Find the contiguous sub-array(containing at least one number) 
which has the maximum sum and return its sum.

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long max(long long a,long long b) {
        if(a < b)
            return b;
        return a;
    }
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long res = arr[0], curSum = arr[0];
        for(int i=1;i<n;i++) {
            curSum = max(curSum+arr[i], arr[i]);
            res = max(res, curSum);
        }
        
        return res;
    }

