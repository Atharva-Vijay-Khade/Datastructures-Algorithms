#include <bits/stdc++.h>
using namespace std;

// Given a number n we need to print its all divisors in increasing order
// Time Complexity : O(n)
// Space Complexity : O(1)
void bruteForce(int n)
{
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cout << i << "\n";
}

// Observation :
// 1] Divisors always occur in pairs
// 2] say divisors are x and y
// 3] x*y = n
// 4] say, x <= y, so, x*x <= n, so max(x) <= n
// 5] So, maximum we can till go till sqrt(x) and we can get all the divisors
// 6] So, to maintain the sorted order we can make 2 scans

// this prints them but not in sorted order
void optimized1(int n)
{

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << "\n";
            if (n / i != i)
                cout << n / i << "\n";
        }
    }
}

// this prints them in sorted order
// Time Complexity : O(sqrt(n))
// Space Complexity : O(1)
void optimized2(int n)
{
    int i;
    for (i = 1; i * i < n; i++)
        if (n % i == 0)
            cout << i << "\n";
    while (i > 0)
    {
        if (n % i == 0)
            cout << n / i << "\n";
        i--;
    }
}

int main()
{

    int n;
    cin >> n;

    // bruteForce(n);
    // optimized1(n);
    optimized2(n);

    return 0;
}