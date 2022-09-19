#include <bits/stdc++.h>
using namespace std;

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 ...

// trailing_zeros = n/5 + n/25 + n/125 + n/625 + .....

// Idea :
// trailing zero is made from 2's and 5's
// number of 2's are more than 5's
// thus we only want the number of 5's in the prime factorization of factorial result
// but we only have n and from that we have to count the number of 5's
// so, expand the factorial and observe the pattern

// 1] Every 5th number is having 5
// 2] Every 25th number is having an extra 5
// 3] Every 125th number is having an extra 5 .. so on

// In this way, we can find the number of 5's that would be there in the factorial
// of the number and that itself is the answer.

// Time Complexity : O(logN)
// Space Complexity : O(1)
int trailZeros(int n)
{
    int zCnt = 0;
    for (int i = 5; n / i > 0; i *= 5)
        zCnt += (n / i);
    return zCnt;
}

int main()
{

    int n;
    cin >> n;

    int z = trailZeros(n);

    cout << z;

    return 0;
}