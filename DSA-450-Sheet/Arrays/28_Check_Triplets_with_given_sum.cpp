Given an array arr of size n and an integer X. 
Find if there's a triplet in the array which sums up to the given integer X.

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool pairSum(int a[], int i, int j, int sum) {
    
        while(i < j) {
            
            if(a[i] + a[j] == sum)
                return true;
            
            if(a[i] + a[j] > sum)
                j--;
            else
                i++;0
                
        }
        
        return false;
        
    }
    bool find3Numbers(int a[], int n, int X)
    {
        
        sort(a, a+n);
        
        for(int i=0;i<n;i++)
            if(pairSum(a, i+1, n-1, X-a[i]))
                return true;
        
        return false;
        
    }

};