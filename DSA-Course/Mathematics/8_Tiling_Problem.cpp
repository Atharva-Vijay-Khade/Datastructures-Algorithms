#include <bits/stdc++.h>
using namespace std;

// GCD => Largest number that divides both a & b

// Brute Force => traverse from min(a,b) to 1 and which ever number divides both that is answer
// Time Complexity => O(min(a,b))
// Space Complexity => O(1)

// Better Approach => Euclidean Algorithm for GCD of two numbers
// Time Complexity => O(log(min(a,b)))
// Space Complexity => O(1) .. for Iterative
// Space Complexity => O(log(min(a,b))) .. for Recursive [ Check ]

// Euclidean Algorithm For GCD Idea and Proof :

// let a, b be two numbers such that a >= b and GCD(a,b) = g

// According to Euclidean Algorithm,
// GCD(a,b) = GCD(a-b,b)

// proof:
// GCD(a,b) = g
// thus, a = gx
//       b = gy  .... GCD(x,y) = 1

// Now, a-b = g(x-y)

// Now, GCD(a-b,b) is g, is to be proven

// if there was a GCD other than g then it would surely be greater than g
// which means x and y would have a common factor, which contradicts
// that GCD(x,y) is 1
// hence proved

// Thus, by Euclidean Algorithm

// gcd(a,b) = gcd(a-b,b) ... a >= b
//          = gcd(a,b-a) ... b > a
//          = b          ... a == 0
//          = a          ... b == 0

// Most Basic Implementation of Euclidean Algorithm for GCD
// Which is by repeated division
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a >= b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

// More Optimal Version of same approach is to use modular arithmetic
// We acutally use the remainder after division

// ie:
// a = 32 and b = 18

// Remainder Method to find GCD

// 32 = 1.18 + 14
// 18 = 1.14 + 4
// 14 = 3.4 + 2
// 4  = 2.2 + 0
// 2  = unf.0    ... stopping step a = GCD and b = 0

// Observation a = 32 and b = 18
// next step, a = 18 and b = 14
// means, for next step, a = b, and b = (a%b)
// and once, b reaches to zero we stop and return the value of a

// GCD of 32 and 18 is 2
// Iterative Version
int OpGcd(int a, int b)
{

    while (b > 0)
    {
        int r = (a % b);
        a = b;
        b = r;
    }
    return a;
}

// Recursive Version
int OpGcdRec(int a, int b)
{
    if (b == 0)
        return a;
    return OpGcdRec(b, a % b);
}

// GCD implementation is Tiling problem
// we are given a N*M area in which only
// N and M are given and we want to design a square
// Tile which will fit into the area perfectly
// also the dimension of the square tile should be
// maximum possible

// this suggest that dimension of square tile = GCD(N,M)

int main()
{

    int a, b;
    cin >> a >> b;

    int g = gcd(a, b);
    cout << g << "\n";
    g = OpGcd(a, b);
    cout << g << "\n";
    g = OpGcdRec(a, b);
    cout << g << "\n";

    return 0;
}