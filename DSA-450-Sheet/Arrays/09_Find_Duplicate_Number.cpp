Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Input: nums = [1,3,4,2,2]
Output: 2

Input: nums = [3,1,3,4,2]
Output: 3

Array can have more than 2 repeated numbers


int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;
        do {
            f = nums[nums[f]];
            s = nums[s];
        }
        while(s!=f);
        s = 0;
        do {
            s = nums[s];
            f = nums[f];
        }
        while(s!=f);
        return s;
    }