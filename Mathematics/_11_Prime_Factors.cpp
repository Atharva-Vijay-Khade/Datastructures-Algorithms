#include <bits/stdc++.h>
using namespace std;

// Prime Factors

// ie : 12 => 2 2 3 => 2^2 * 3^1
// Any number can be expressed as a product of its prime factors
// NUM = 2^x * 3^y * 5^z .....
// task is to print the prime factors of a given number n

// Brute Force:
// traverse from i =  2 to  i = n
// chech if i is prime
// if yes then check if it divides n
// if yes then check how many times it divides n and that many times print i

// Time Complexity : O(n*sqrt(n)*log(n))
// Space Complexity : O(1)
bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void bruteForce(int n)
{
    if (n <= 1)
        return;
    for (int i = 2; i <= n; i++)
    {
        if ((n % i == 0) && (isPrime(i)))
        {
            int x = i;
            while (n % x == 0)
            {
                cout << i << "\n";
                x = x * i;
            }
        }
    }
}

// Optimized Solution1:
// Observation
// 1] Divisors always occur in pairs
// x*y = n .. x and y are divisors of n
// if x <= y
// x*x <= n
// max(x) = sqrt(n)
// Thus it is sure that we will get all the prime factors in the range 2 to sqrt(n)

// 2] n = 2^x * 3^y * 5^z .... any number can be expressed as a product of its primes

// thus we will get the prime factors of a number n in the range 2 to sqrt(n)
// so for each number in this range we will check if it divides n, if yes
// then we will remove its all factors from n and continue on numbers ahead
// it ensures that we only remove the prime factors very elegantly

// Time Complexity : O(sqrt(n)) ... for prime numbers and less than that for compsite numbers
// Space Complexity : O(1)
void optimized1(int n)
{
    if (n <= 1)
        return;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            cout << i << "\n";
        }
    }
    // this is the corner case which is very important
    // this is to handel the case when the last prime factor
    // has power 1, ie : 84 = 2^2 * 3^1 * 7
    // at last using this algorithm 7 will be left out which will
    // fall in this case.....
    if (n > 1)
        cout << n << "\n";
    return;
}

// Optimized Solution2:
// if we remove prime factors such as 2 and 3 entirely from the number n
// then we will be only have to check for numbers such as
// 5,7,11,17,19.....
// this is same as the optimized version of checking for prime number

// Time Complexity : O(sqrt(n)/6) for primes and less than that for composite numbers
// Space Complexity : O(1)
void optimized2(int n)
{
    if (n <= 1)
        return;
    while (n % 2 == 0)
    {
        cout << 2 << "\n";
        n /= 2;
    }
    while (n % 3 == 0)
    {
        cout << 3 << "\n";
        n /= 3;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        while (n % i == 0)
        {
            cout << i << "\n";
            n /= i;
        }
        while (n % (i + 2) == 0)
        {
            cout << i + 2 << "\n";
            n /= (i + 2);
        }
    }
    if (n > 3)
        cout << n << "\n";
    return;
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