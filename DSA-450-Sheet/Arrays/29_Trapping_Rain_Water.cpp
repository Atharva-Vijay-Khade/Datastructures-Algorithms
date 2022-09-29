Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water 
can be trapped between the blocks during the rainy season. 

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10


Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.



class Solution{

    // Function to find the trapped water between the blocks.
    public:
    void preprocess(int rmax[], int lmax[], int arr[], int n) {
        
        rmax[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--)
            rmax[i] = max(rmax[i+1], arr[i]);
            
        lmax[0] = arr[0];
        for(int i=1;i<n;i++)
            lmax[i] = max(lmax[i-1], arr[i]);
        
    } 
    long long trappingWater(int arr[], int n){
        
        long long result = 0;
        int rmax[n], lmax[n];
        
        preprocess(rmax, lmax, arr, n);
        
        for(int i=0;i<n;i++)
            result+=(min(rmax[i], lmax[i]) - arr[i]);
        
        return result;
        
    }
};
