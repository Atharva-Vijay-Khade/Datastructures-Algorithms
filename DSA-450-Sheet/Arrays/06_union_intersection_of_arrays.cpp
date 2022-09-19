Input:
5 3
1 2 3 4 5
1 2 3
Output: 
5
Explanation: 
1, 2, 3, 4 and 5 are the
elements which comes in the union set
of both arrays. So count is 5.


class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> s;
        for(int i=0;i<n;i++)
            s.insert(a[i]);
        for(int i=0;i<m;i++)
            s.insert(b[i]);
        return s.size();
    }
};


// this question can be extended to cases when arrays are sorted
// for intersection of two sorted array we use approach as used 
// in the merge function of the mergeSort
