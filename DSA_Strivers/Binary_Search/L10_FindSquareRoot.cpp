/*
    Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

    Floor value of any number is the greatest Integer which is less than or equal to that number

    Examples:

    Input: n = 4
    Output: 2
    Explanation: Since, 4 is a perfect square, so its square root is 2.
    Input: n = 11
    Output: 3
    Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.
    Input: n = 1
    Output: 1
    Constraints:
    1 ≤ n ≤  3 x 10^4
*/

#include <bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int n)
{
    if (n == 1)
    {
        return 1;
    }

    long long int s = 1;
    long long int e = n / 2;
    long long int ans = 0;
    while (s <= e)
    {
        long long int m = s + (e - s) / 2;
        if (m * m == n)
        {
            return m;
        }
        else if (m * m < n)
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

int main()
{
    long long int n = 4096;
    cout << floorSqrt(n) << endl;
    return 0;
}