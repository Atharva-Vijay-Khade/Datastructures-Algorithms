N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.


class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        
        unordered_map<int,int> ump;
        int res = 0;
        
        for(int i=0;i<n;i++) {

            if(ump.find(k - arr[i]) != ump.end())
                res+=ump[k-arr[i]];
                
            ump[arr[i]]++;
            
        }
        
        return res;
        
    }
};