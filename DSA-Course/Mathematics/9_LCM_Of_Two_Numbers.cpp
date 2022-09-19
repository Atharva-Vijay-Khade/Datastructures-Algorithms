#include <bits/stdc++.h>
using namespace std;

// LCM of a, b is the smallest number that is divisible by both a and b

// Fact:
// If two numbers are co-prime then GCD of those is 1 and LCM is their product

// ie : a = 4, b = 6
// op : 12

// ie : a = 3, b = 7
// op : 21

// Brute Force :
// start from max(a,b) and go till a*b
// whichever is divisible by both a and b
// that is the answer

// Time Complexity : O(a*b - max(a,b))
// Space Complexity : O(1)

// Better Approach :
// a * b = GCD(a,b) * LCM(a,b)
// thus, LCM(a,b) = (a * b) / GCD(a,b)

// int gcd(int a,int b) {
//     if(b == 0)
//         return a;
//     return gcd(b,a%b);
// }

int gcd(int a, int b)
{
    while (b > 0)
    {
        int r = (a % b);
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{

    int a, b;
    cin >> a >> b;
    int l = lcm(a, b);

    cout << l << "\n";

    return 0;
}