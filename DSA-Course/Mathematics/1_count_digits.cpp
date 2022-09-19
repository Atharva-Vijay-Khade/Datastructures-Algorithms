#include <bits/stdc++.h>
using namespace std;

// O(log(n)) time + O(1) space
int countDigitsIt(int n)
{
    if (n == 0)
        return 1;
    int cnt = 0;
    while (n > 0)
    {
        n /= 10;
        cnt++;
    }
    return cnt;
}

// O(log(n)) time + O(log(n)) space
int countDigitsRec(int n)
{
    if (n / 10 == 0)
        return 1;
    return 1 + countDigitsRec(n / 10);
}

// O(1)
int countDigitsO1(int n)
{
    return int(log10(n) + 1);
}

int main()
{

    int n;
    cin >> n;

    // cout<<countDigitsIt(n);
    // cout<<countDigitsRec(n);
    // cout<<countDigitsO1(n);

    return 0;
}