#include <bits/stdc++.h>
using namespace std;

// The positive numbers 1,2,3....
// are divided in 2 categories prime and composite

// 1 is neither of these .... [ IMP fact ]
// 2 is the only prime number which is even
// The numbers which are only divisible from 1 and itself
// are called prime numbers others are composite numbers

// given a number n check if its prime or not

// ie : 13 , op : yes
// ie : 14 , op : no ...
// inputs will be greater than 0 for sure

// Brute Force
// traverse from 2 to n-1, if its divisible by any in these range then its not prime
// else it will be prime number
// time complexity : O(n)
// space complexity : O(1)

// Optimized Approach 1
// Fact : Divisors in the above approach in range 2 to n-1 if exists
//        They allways exist in pairs, say if one divisor is x then n/x is its pair
//        So total divisors will always be even, so that they occur in pair (x,y)
//        such x*y = n

// Now, as x grows y will decrease, so maximum value that we can scan to claim on the
// number to be prime can be decided by this,
// that is, x*y = n
// so, at max, if x == y
// x^2 = n
// x = sqrt(n)

// also, if x*y = n
// and we say that x <= y
// then x*x <= n
// so max value of x will be sqrt(n) only

// so we actully have to go from 2 to sqrt(n) only to check if number is prime or not
// time complexity : O(sqrt(n))
// space complexity : O(1)

// Optimized Approach 2
// We observe the numbers from 2 to sqrt(n)
// 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 .... sqrt(n)
// we check for case of n = 1 and n = 2 earlier
// then we check if number is divisible by 2 or 3 then it won't be prime

// this makes the sequence reduced to
// 5,7,11,13,17,19,......sqrt(n)
// so we have to iterate on these numbers only if we already check for 2 and 3

// Solutions Code

bool bruteForce(int n)
{

    if (n == 1)
        return false;

    for (int i = 2; i <= n - 1; i++)
        if (n % i == 0)
            return false;

    return true;
}

bool optimized1(int n)
{

    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

// Optimized2 is 3 times faster than the Optimized1
bool optimized2(int n)
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
int main()
{
    int n;
    cin >> n;

    cout << bruteForce(n) << "\n";
    cout << optimized1(n) << "\n";
    cout << optimized2(n) << "\n";

    return 0;
}