n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.



class Solution
{
    public:    
       vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
        {
            
            vector<int> res;
            
            int i = 0, j = 0, k = 0;
            
            while(i < n1 && j < n2 && k < n3) {
                
                int min_ = min({A[i], B[j], C[k]});
                
                if(min_ == A[i] && min_ == B[j] && min_ == C[k]) {
                    res.push_back(min_);
                    while(i < n1 && A[i] == min_)
                        i++;
                    while(j < n2 && B[j] == min_)
                        j++;
                    while(k < n3 && C[k] == min_)
                        k++;
                }
                else {
                    if(min_ == A[i])
                        i++;
                    else if(min_ == B[j])
                        j++;
                    else 
                        k++;
                }
                
            }
            
            return res;
            
        }

};