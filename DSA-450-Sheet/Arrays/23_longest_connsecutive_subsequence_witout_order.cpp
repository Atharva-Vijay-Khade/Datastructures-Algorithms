Given an array of positive integers. 
Find the length of the longest sub-sequence such that elements in 
the subsequence are consecutive integers, the consecutive numbers can be in any order.


Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.


int findLongestConseqSubseq(int arr[], int N)
{
    int freq_size = (*max_element(arr, arr + N)) + 1;
    int freq[freq_size];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < N; i++)
        freq[arr[i]] = 1;

    int res = 0;

    for (int i = 1; i < freq_size; i++)
        if (freq[i] != 0)
            freq[i] += freq[i - 1], res = max(res, freq[i]);

    return res;
}