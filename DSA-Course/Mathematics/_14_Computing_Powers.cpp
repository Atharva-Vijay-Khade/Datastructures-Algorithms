#include <bits/stdc++.h>
using namespace std;

// Given x and n we need to compute x^n

// Brute force algorithm is multiplying x, n times
// Time Complexity : O(n)
// Space Complexity : O(1)

// Optimal Solution1

// pow(x,n) = {
//                  if(n%2 == 0)
//                      pow(x,n/2)*pow(x,n/2)
//                  else
//                      pow(x,n-1)*x
//            }
// above can be optimized to O(logN)
// the calls can be further optimized as follows:
// temp = pow(x,n/2)
// so, pow(x,n-1) = temp*temp, if if n is odd,
// thus making it a O(LogN) solution

int pow1(int x, int n)
{
    if (n == 0)
        return 1;
    int temp = pow1(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else
        return temp * temp * x;
}

// Optimal Solution2

// using bit magic, traversing on the bits of n and multiplying x
// as and when required.....

// ie : n = 10 = (1010)2 in binary

// ie : 3^10 = 3^8*3^2

// thus,
// scanning on bits of n from right to left

// for 0, res = 1 but iterator = 3^1
// iterator becomes 3^2

// for 1, res = 3^2
// iterator becomes 3^4

// for 0, res = 3^2
// iterator becomes 3^8

// for 1, res = 3^2 * 3^8
// iterator becomes 3^16

// now when we multiply the results
// actually we are constructing the value of n
// in power using its binary representation

// essentially what we do is, multiply A = x
// with itself as we traverse from the bits of n
// with this we get the power of A as sum or powers of 2
// and sum of powers of 2 can generate any n
// so to generate that n, we multiply A with res
// only when that very bit of n is set

// A^1, A^2, A^4, A^8, A^16.......
// the powers can make any n
// so just multiply them as an when required

// ie :
// n = 5 = (101)2
// x = 2
// power = 2^1*2^4

int mod = 1e9 + 7;
int pow2(int x, int n)
{

    if (n == 0)
        return 1;

    int res = 1, a = x;

    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % mod;
        n = (n >> 1);
        a = (a * a) % mod;
    }

    return res % mod;
}

int main()
{
    int x, n;
    cin >> x >> n;

    cout << pow1(x, n) << "\n";
    cout << pow2(x, n) << "\n";

    return 0;
}