Given an integer N, find its factorial.


Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

1<=N<=1000

To return the factorial in a vector as it's' computed

// Time complexity = O(n*log10(n))
class Solution {
public:
    vector<int> factorial(int n) {
        
        vector<int> fact(1,1);
        
        for(int i=2;i<=n;i++) {
            
            long long int carry = 0;
            
            for(int j=0;j<fact.size();j++) {
                
                int cur_num = i*fact[j] + carry;
                carry = cur_num/10;
                fact[j] = (cur_num%10);
                
            }
            
            while(carry != 0)
                fact.push_back(carry%10), carry/=10;
            
        }
        
        reverse(fact.begin(), fact.end());
        
        return fact;
        
    }
};