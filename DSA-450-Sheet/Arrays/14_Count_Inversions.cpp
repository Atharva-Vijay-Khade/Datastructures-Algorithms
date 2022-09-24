Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far 
(or close) the array is from being sorted. If array is already 
sorted then the inversion count is 0. If an array is sorted in 
the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.


Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).


class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], int l, int mid, int h, long long int &res) {
        
        int l1 = mid - l + 1;
        int l2 = h - mid;
        
        int temp1[l1], temp2[l2];
        
        for(int i=l;i<=mid;i++)
            temp1[i-l] = arr[i];
        for(int i=mid+1;i<=h;i++)
            temp2[i-mid-1] = arr[i];
            
        int ii = 0, jj = 0, index = l;
        
        while(ii < l1 && jj < l2) {
            
            if(temp1[ii] <= temp2[jj])
                arr[index++] = temp1[ii++];
            else {
                res = res + (l1-ii);
                arr[index++] = temp2[jj++];
            }
            
        }
        
        while(ii < l1)
            arr[index++] = temp1[ii++];
        
        while(jj < l2)
            arr[index++] = temp2[jj++];
        
    }
    void mergeSort(long long arr[], int l, int h, long long int &res) {
        
        if(l >= h)
            return;
        
        int mid = (l + h)/2;
        
        mergeSort(arr,l,mid,res);
        mergeSort(arr,mid+1,h,res);
        merge(arr,l,mid,h,res);
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int res = 0;
        mergeSort(arr,0,N-1,res);
        return res;
    }

};