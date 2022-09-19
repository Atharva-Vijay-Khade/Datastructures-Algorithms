Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        
        // int pivote = 1;
        // int i = -1;
        
        // for(int j=0;j<n;j++) {
        //     if(a[j] <= pivote) {
        //         i++;
        //         swap(a[j],a[i]);
        //     }
        // }
        
        // int ii = 0, jj = i;
        // while(ii < jj) {
        //     while(ii < jj && a[ii] == 0)
        //         ii++;
        //     while(jj > ii && a[jj] == 1)
        //         jj--;
        //     swap(a[ii],a[jj]);
        // }
        
        // Most Optimal Dutch National Flag Algorithm
        int lo = 0, mid = 0, hi = n-1;
        // 0 to lo-1 are 0s
        // lo to mid-1 are 1s
        // mid to hi are unknowns
        // hi+1 to n-1 are 2s
        
        while(mid <= hi) {
            if(a[mid] == 1)
                mid++;
            else if(a[mid] == 2) {
                swap(a[mid],a[hi]);
                hi--;
            }
            else
                swap(a[lo++],a[mid++]);
        }
        
    }
    
};