Given an array nums of size n, return the majority element.

The majority element is the element that appears more 
than ⌊n / 2⌋ times. You may assume that the majority 
element always exists in the array.

https://leetcode.com/problems/majority-element/


Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maj = nums[0];
        int cnt = 1;
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == maj)
                cnt++;
            else {
                cnt--;
                if(cnt == 0) {
                    cnt = 1;
                    maj = nums[i];
                }
            }
        }
        
        return maj;
        
    }
};