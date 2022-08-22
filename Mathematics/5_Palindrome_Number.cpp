// return true if given number is palindrome else return false
// Idea : Find the Reverse of a given number and compare with original number
//      : Time Complexity => O(logN)

#include <bits/stdc++.h>
using namespace std;

int revNum(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev *= 10;
        rev += (n % 10);
        n /= 10;
    }
    return rev;
}

bool isPalin(int n)
{
    if (n / 10 == 0)
        return true;
    int revNumber = revNum(n);
    return (revNumber == n);
}

int main()
{

    int n;
    cin >> n;

    cout << isPalin(n);

    return 0;
}
