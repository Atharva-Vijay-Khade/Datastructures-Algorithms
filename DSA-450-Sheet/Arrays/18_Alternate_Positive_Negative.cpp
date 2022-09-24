Given an unsorted array Arr of N positive and negative numbers. 
Your task is to create an array of alternate positive and negative 
numbers without changing the relative order of positive and negative numbers.
Note: Array should start with a positive number.

Input: 
N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output:
9 -2 4 -1 5 -5 0 -3 2
Explanation : Positive elements : 9,4,5,0,2
Negative elements : -2,-1,-5,-3
As we need to maintain the relative order of
postive elements and negative elements we will pick
each element from the positive and negative and will
store them. If any of the positive and negative numbers
are completed. we will continue with the remaining signed
elements.The output is 9,-2,4,-1,5,-5,0,-3,2.


Input:
N = 10
Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output:
5 -5 2 -2 4 -8 7 1 8 0
Explanation : Positive elements : 5,2,4,7,1,8,0
Negative elements : -5,-2,-8
As we need to maintain the relative order of
postive elements and negative elements we will pick
each element from the positive and negative and will
store them. If any of the positive and negative numbers
are completed. we will continue with the remaining signed
elements.The output is 5,-5,2,-2,4,-8,7,1,8,0.


class Solution{
public:
// Order Preserving approach but Gives TLE

//     void shUpdate(int arr[], int l, int h) {
//         int x = arr[h];
//         for(int i=h;i>l;i--)
//             arr[i] = arr[i-1];
//         arr[l] = x;
//     }
// 	void rearrange(int arr[], int n) {
	    
// 	    int p1 = 0, p2;
	    
// 	    do {
	        
// 	        if((p1%2 == 0) && (arr[p1] < 0)) {
// 	            for(p2 = p1+1; p2 < n && arr[p2] < 0; p2++);
// 	            if(p2 >= n)
// 	                return;
// 	            shUpdate(arr, p1, p2);
// 	        }
// 	        else if((p1%2 == 1) && (arr[p2] >= 0)) {
// 	            for(p2 = p1+1; p2 < n && arr[p2] >= 0; p2++);
// 	            if(p2 >= n)
// 	                return;
// 	            shUpdate(arr, p1, p2);
// 	        }
	        
// 	        p1++;
// 	        p2 = p1;
	        
// 	    }
// 	    while(p2 < n);
	    
// 	}   
// Brute Force solution which givers AC
    void rearrange(int arr[], int n) {
        
        vector<int> pos, neg;
        for(int i=0;i<n;i++) {
            if(arr[i] < 0)
                neg.push_back(arr[i]);
            else 
                pos.push_back(arr[i]);
        }
        
        int n1 = pos.size(), n2 = neg.size(), ii = 0, jj = 0, in = 0;
        
        while(ii < n1 && jj < n2) {
            
            if(in%2 == 0)
                arr[in++] = pos[ii++];
            else
                arr[in++] = neg[jj++];
                
        }
        
        while(ii < n1)
            arr[in++] = pos[ii++];
        while(jj < n2)
            arr[in++] = neg[jj++];
        
    }
};