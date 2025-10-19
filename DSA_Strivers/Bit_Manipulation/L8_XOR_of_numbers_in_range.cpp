/*
    Find XOR of numbers from L to R

    You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

    Example:

    Input:
    L = 4, R = 8
    Output:
    8
    Explanation:
    4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
    Your Task:

    Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

    Expected Time Complexity: O(1).

    Expected Auxiliary Space: O(1).

    Constraints:

    1<=l<=r<=10^9
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(l - r + 1), S.C. : O(1)
int brute(int l, int r)
{
    int xr = 0;
    for (int n = l; n <= r; n++)
    {
        xr = (xr ^ n);
    }
    return xr;
}

int xorTillN(int n)
{
    if (n % 4 == 1)
    {
        return 1;
    }
    else if (n % 4 == 2)
    {
        return n + 1;
    }
    else if (n % 4 == 3)
    {
        return 0;
    }
    return n;
}

// T.C. : O(1), S.C. : O(1)
int optimal(int l, int r)
{
    int xorL = xorTillN(l - 1);
    int xorR = xorTillN(r);

    return xorL ^ xorR;
}

int findXOR(int l, int r)
{
    // Brute Force
    // return brute(l, r);

    // Optimal
    return optimal(l, r);
}

int main()
{
    int l = 4, r = 8;
    cout << findXOR(l, r) << endl;
    return 0;
}