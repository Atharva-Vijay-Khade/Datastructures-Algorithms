Input : 
N = 8
arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
Output : 
1  3  2  11  6  -1  -7  -5


class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Solution but changes the order of elements
        
        // int lo = 0, hi = n-1;
        // while(lo < hi) {
        //     while(lo < hi && arr[lo] >=0)
        //         lo++;
        //     while(lo < hi && arr[hi] < 0)
        //         hi--;
        //     if(lo < hi)
        //         swap(arr[lo],arr[hi]);
        // }
        
        int temp[n], in = 0;
        for(int i=0;i<n;i++)
            if(arr[i] > 0)
                temp[in++] = arr[i];
        for(int i=0;i<n;i++)
            if(arr[i] < 0)
                temp[in++] = arr[i];
            
        for(int i=0;i<n;i++)
            arr[i] = temp[i];
            
        // TODO : O(N) + O(1) order preserving approach 
        
    }
};