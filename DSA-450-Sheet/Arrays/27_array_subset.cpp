Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. 
Task is to check whether a2[] is a subset of a1[] or not. 
Both the arrays can be sorted or unsorted. 


Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output:
Yes
Explanation:
a2[] is a subset of a1[]


int dp[1001][1001];

int lcs(int a1[], int a2[], int n, int m)
{

    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (a1[n - 1] == a2[m - 1])
        return dp[n][m] = lcs(a1, a2, n - 1, m - 1) + 1;
    else
        return dp[n][m] = max(lcs(a1, a2, n, m - 1),
                              lcs(a1, a2, n - 1, m));
}

string isSubset(int a1[], int a2[], int n, int m)
{

    // sort(a1, a1+n);
    // sort(a2, a2+m);
    // memset(dp,-1,sizeof(dp));

    if (m > n)
        return "No";

    // Approach 1
    // if(lcs(a1, a2, n, m) == m)
    //     return "Yes";

    // Approach 2
    // Here we just have to check if one array is subset of other or not
    // so essentially order doesn't matter

    int freq[int(1e6 + 1)];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < m; i++)
        freq[a2[i]]++;

    for (int i = 0; i < n; i++)
        freq[a1[i]]--;

    for (int i = 0; i < int(1e6 + 1); i++)
        if (freq[i] > 0)
            return "No";

    return "Yes";
}