Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int num1 = -1e9-1, num2 = -1e9-1, cnt1 = 0, cnt2 = 0, n = nums.size();
        
        for(int i=0;i<n;i++) {
            
            if(num1 == nums[i])
                cnt1++;
            else if(num2 == nums[i])
                cnt2++;
            else if(cnt1 == 0) {
                cnt1 = 1;
                num1 = nums[i];
            }
            else if(cnt2 == 0) {
                cnt2 = 1;
                num2 = nums[i];
            }
            else {
                cnt1--;
                cnt2--;
            }
            
        }
        
        int count1 = 0, count2 = 0;
        
        for(int i=0;i<n;i++) {
            if(nums[i] == num1)
                count1++;
            else if(nums[i] == num2)
                count2++;
        }
        
        vector<int> res;
        
        if(count1 > n/3)
            res.push_back(num1);
        if(count2 > n/3)
            res.push_back(num2);
        
        return res;
        
    }
};