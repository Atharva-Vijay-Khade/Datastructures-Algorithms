
Given an unsorted array of integers and a sum. 
The task is to count the number of subarray which adds to the given sum.


Input:
n = 5
arr[] = {10,2,-2,-20,10}
sum = -10
Output: 3
Explanation: Subarrays with sum -10 are: 
[10, 2, -2, -20], [2, -2, -20, 10] and 
[-20, 10].


int subArraySum(int arr[], int n, int sum)
{
    unordered_map<int, int> s;
    int prefix[n];
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {

        if (prefix[i] == sum)
            cnt++;

        if (s.find(prefix[i] - sum) != s.end())
            cnt += (s[prefix[i] - sum]);

        s[prefix[i]]++;
    }

    return cnt;
}