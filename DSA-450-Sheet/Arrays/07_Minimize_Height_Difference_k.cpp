Given an array arr[] denoting heights of 
N towers and a positive integer K.

For each tower, you must perform exactly 
one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between 
the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the 
height by K for each tower. After the operation, 
the resultant array should not contain any negative integers.

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.


class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {

        // code here
        sort(arr, arr + n);

        if (arr[n - 1] - k < 0)
            return arr[n - 1] - arr[0];

        int max_ = arr[n - 1];
        int min_ = arr[0];
        int res = max_ - min_;

        // a b c d
        for (int i = 1; i < n; i++)
        {
            max_ = max(arr[i - 1] + k, arr[n - 1] - k);
            min_ = min(arr[i] - k, arr[0] + k);
            if (min_ >= 0)
                res = min(res, max_ - min_);
        }

        return res;
    }
};