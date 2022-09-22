A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Input: nums = [1,2,3]
Output: [1,3,2]

Input: nums = [3,2,1]
Output: [1,2,3]

Input: nums = [1,1,5]
Output: [1,5,1]

// O(N*logN) + O(N)
class Solution {
public:
    void nextPermutation(vector<int> & nums)
    {

        if (nums.size() == 1)
            return;

        multiset<int> s;
        s.insert(nums[nums.size() - 1]);
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                auto upr = s.upper_bound(nums[i]);
                s.insert(nums[i]);
                nums[i] = (*upr);
                s.erase(upr);
                int index = i + 1;
                for (auto &x : s)
                    nums[index++] = x;
                return;
            }
            s.insert(nums[i]);
        }

        sort(nums.begin(), nums.end());
        return;
    }
};

// O(N) + O(1)
void reverse(vector<int> &nums, int i, int j)
{
    while (i < j)
        swap(nums[i++], nums[j--]);
}
void nextPermutation(vector<int> &nums)
{

    if (nums.size() == 1)
        return;

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            int index = -1;
            for (int j = nums.size() - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                {
                    index = j;
                    break;
                }
            }
            swap(nums[i], nums[index]);
            reverse(nums, i + 1, nums.size() - 1);
            return;
        }
    }

    reverse(nums, 0, nums.size() - 1);
}
