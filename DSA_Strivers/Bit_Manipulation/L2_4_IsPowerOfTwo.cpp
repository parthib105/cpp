/*
    Power of Two

    Given an integer n, return true if it is a power of two. Otherwise, return false.

    An integer n is a power of two, if there exists an integer x such that n == 2x.

    Example 1:

    Input: n = 1
    Output: true
    Explanation: 20 = 1
    Example 2:

    Input: n = 16
    Output: true
    Explanation: 24 = 16
    Example 3:

    Input: n = 3
    Output: false


    Constraints:

    -2^31 <= n <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

int no_bits(int n)
{
    int bits = 0;
    while (n != 0)
    {
        bits++;
        n = n >> 1;
    }
    return bits;
}

// counting number of bits
bool approach1(int n)
{
    int b = no_bits(n);
    if (n == (1 << (b - 1)))
    {
        return true;
    }
    return false;
}

// tricks
bool approach2(int n)
{
    int num = n & (n - 1);
    if (num == 0)
    {
        return true;
    }
    return false;
}

bool isPowerOfTwo(int n)
{
    // edge cases
    if (n == 1)
    {
        return true;
    }
    else if (n <= 0)
    {
        return false;
    }

    // option 1
    // return approach1(n);

    // option 2
    return approach2(n);
}

int main()
{
    int n = 43;
    bool ans = isPowerOfTwo(n);
    if (ans)
    {
        cout << n << " is a power of two." << endl;
    }
    else
    {
        cout << n << " is not a power of two." << endl;
    }
    return 0;
}