#include <bits/stdc++.h>
using namespace std;

// Time : O(n)
// Space : O(1)
int factorial(int n)
{

    if (n == 0)
        return 1;

    int fact = 1;

    for (int i = 2; i <= n; i++)
        fact = (fact * i);

    return fact;
}

// Time : O(n)
// Space : O(n)
int factRec(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return (n * factRec(n - 1));
}

int main()
{

    int n;
    cin >> n;

    // int fact = factorial(n);
    int fact = factRec(n);

    cout << fact << "\n";

    return 0;
}