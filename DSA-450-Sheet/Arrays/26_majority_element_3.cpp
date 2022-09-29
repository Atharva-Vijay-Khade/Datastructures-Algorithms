Given an array arr[] of size N and an element k. 
The task is to find all elements in array that appear more than n/k times.

Input:
N = 8
arr[] = {3,1,2,2,1,2,3,3}
k = 4
Output: 2
Explanation: In the given array, 3 and
 2 are the only elements that appears 
more than n/k times.


class Solution
{
public:
    vector<int> countTheNumber(vector<int> &arr, int n, int k)
    {

        if (k == 1)
        {
            int check_ele = arr[0];
            int cnt = 1;
            for (int i = 1; i < n; i++)
                if (check_ele == arr[i])
                    cnt++;
            if (cnt == n)
                return {check_ele};
            else
                return {};
        }

        vector<int> nums(k - 1, -1e9 - 1);
        vector<int> cnt(k - 1, 0);

        for (int i = 0; i < n; i++)
        {

            // check if any nums[i] matches with arr[i];
            bool ccnt = false;

            for (int j = 0; j < k - 1; j++)
            {
                if (arr[i] == nums[j])
                {
                    cnt[j]++;
                    ccnt = true;
                    break;
                }
            }

            if (ccnt)
                continue;

            // check if any cnt[i] is zero
            for (int j = 0; j < k - 1; j++)
            {
                if (cnt[j] == 0)
                {
                    cnt[j] = 1;
                    nums[j] = arr[i];
                    ccnt = true;
                    break;
                }
            }

            if (ccnt)
                continue;

            // decrement all cnt[i]'s
            for (int j = 0; j < k - 1; j++)
                cnt[j]--;
        }

        // confirm the result
        vector<int> res;

        for (int i = 0; i < k - 1; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
                if (nums[i] == arr[j])
                    count++;
            if (count > n / k)
                res.push_back(nums[i]);
        }

        return res;
    }
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k)
    {
        vector<int> arr1;
        for (int i = 0; i < n; i++)
            arr1.push_back(arr[i]);
        vector<int> res = countTheNumber(arr1, n, k);
        return res.size();
    }
};