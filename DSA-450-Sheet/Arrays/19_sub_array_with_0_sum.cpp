Given an array of positive and negative numbers. 
Find if there is a subarray (of size at-least one) with 0 sum.

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.


bool subArrayExists(int arr[], int n)
{
    unordered_set<int> s;
    int prefix[n];
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    for (int i = 0; i < n; i++)
    {

        if (prefix[i] == 0)
            return true;

        if (s.find(prefix[i]) != s.end())
            return true;

        s.insert(prefix[i]);
    }

    return false;
}