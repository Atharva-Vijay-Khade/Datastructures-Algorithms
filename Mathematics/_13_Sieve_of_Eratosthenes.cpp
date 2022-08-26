#include <bits/stdc++.h>
using namespace std;

// Given a number n, we want to print the prime numbers less than or equal to n

// Brute Force Solution:
// 1] traverse for all numbers from 2 to n and check for each one if its prime or not
// Time Complexity : O(sqrt(n)*n)
// Space Complexity : O(1)

// Optimized Solution:
// 1] Sieve of Eratosthenes
// Time Complexity : O(n*log(log(n))) ... Almost Linear
// Space Complexity : O(n)

void BasicSieve(int n)
{
    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = false;
    }

    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            cout << i << "\n";
}

// we only have to scan till sqrt(n)... proved earlier
void OptmSieve1(int n)
{

    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = false;
    }

    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            cout << i << "\n";
}

// we can start j from i*i
// reason :
// 2*i 3*i 4*i .... (i-1)i i*i
// ie: say i = 5
// so we have sequence as, 2*5 3*5 4*5 5*5 { numbers before i*i are actually multiples of previous numbers so they will be already marked }
// generalizing:
// 2i 3i 4i 5i .... (i-3)i (i-2)i (i-1)i ii
// 2i to (i-1)i would have been already marked!
// so it is always safe to start from i*i
void OptmSieve2(int n)
{

    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    }

    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            cout << i << "\n";
}

// We can optimize the code more by making the outer loop to run n times
// and printing the elements on the go without a seperate loop
// this is saving O(sqrt(n)) iterations
void OptmSieve3(int n)
{

    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << "\n";
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}
int main()
{

    int n;
    cin >> n;

    // BasicSieve(n);
    // OptmSieve1(n);
    // OptmSieve2(n);
    OptmSieve3(n);

    return 0;
}
