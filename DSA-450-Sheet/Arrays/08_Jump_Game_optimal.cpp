Given an array of N integers arr[] where 
each element represents the max length of 
the jump that can be made forward from that element. 
Find the minimum number of jumps to reach the end of the 
array (starting from the first element). If an element is 0, 
then you cannot move through that element.

Note: Return -1 if you can't' reach the end of the array.

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to the last.

// int solve(int arr[],int n,int start) {
        
        
    //     // if(start >= n-1)
    //     //     return 0;
        
    //     // if(arr[start] == 0)
    //     //     return -1;
        
    //     // if(dp[start+1] != -2)
    //     //     return dp[start+1];
        
    //     // int res = INT_MAX;
    //     // for(int i=1;i<=arr[start];i++) {
    //     //     int njc = solve(arr,n,start+i);
    //     //     if(njc != -1)
    //     //         res = min(res,njc+1);
    //     // }
        
    //     // return dp[start+1] = ((res == INT_MAX) ? -1 : res);
        
    // }
    // int minJumps(int arr[], int n){
        
    //     int dp[n],i,j;
        
    //     dp[n-1] = 0;
        
    //     for(i=n-2;i>=0;i--) {
    //         if(arr[i] == 0)
    //             dp[i] = -1;
    //         else {
    //             dp[i] = INT_MAX;
    //             for(j=1;j<=arr[i];j++)
    //                 if(i+j < n && dp[i+j] != -1)
    //                     dp[i] = min(dp[i+j]+1,dp[i]);
    //             if(dp[i] == INT_MAX)
    //                 dp[i] = -1;
    //         }
    //     }
        
    //     return dp[0];
        
    // }
    // DP Solution [ O(N^2) ]
    // int minJumps(int arr[], int n){
        
    //     int dp[n];
    //     dp[n-1] = 0;
        
    //     for(int i=n-2;i>=0;i--) {
    //         if(i+arr[i] >= n-1)
    //             dp[i] = 1;
    //         else if(arr[i] == 0)
    //             dp[i] = -1;
    //         else {
    //             dp[i] = INT_MAX;
    //             for(int j=1;j<=arr[i];j++)
    //                 if(dp[i+j]!=-1)
    //                     dp[i] = min(dp[i], dp[i+j] + 1);
    //             if(dp[i] == INT_MAX)
    //                 dp[i] = -1;
    //         }
    //     }
        
    //     return dp[0];
        
    // }
    int minJumps(int arr[], int n){
        
        int d = 0, p = 0, j = 0;
        for(int i=0;i<n-1;i++) {
            d = max(d, i+arr[i]);
            if(p == i) {
                p = d;
                j++;
            }
        }
        
        return ((p < n-1) ? -1 : j);
        
    }