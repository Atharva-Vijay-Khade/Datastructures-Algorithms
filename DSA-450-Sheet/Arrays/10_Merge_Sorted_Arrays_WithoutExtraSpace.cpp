https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1


public:
        void swap(long long &a, long long &b) {
            long long temp = a;
            a = b;
            b = temp;
        }
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        {

            int gap = (n+m);
            
            while(gap > 1) {
                
                gap = ceil(gap/2.0);
               
                
                int i = 0, j = gap;
                
                while(j < n+m) {
        
                    if( i < n && j < n) {
                        if(arr1[i] > arr1[j])
                            swap(arr1[i],arr1[j]);
                    }
                    else if(i < n && j >= n) {
                        if(arr1[i] > arr2[j-n])
                            swap(arr1[i],arr2[j-n]);
                    }
                    else if(i >= n && j < n) {
                        if(arr2[i-n] > arr1[j])
                            swap(arr2[i-n],arr1[j]);
                    }
                    else {
                        if(arr2[i-n] > arr2[j-n])
                            swap(arr2[i-n],arr2[j-n]);
                    }
                    
                    i++;j++;
                    
                }
                
            }
            
        }