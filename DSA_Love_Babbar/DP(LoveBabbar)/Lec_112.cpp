/*
    Get Minimum Squares

    Given a number N. Find the minimum number of squares of any number that sums equal to N. For Example: If N = 100, N can be
    expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as the minimum number of square is 1, i.e
    (10*10).


    Example 1:

    Input: N = 100
    Output: 1
    Explanation: 10 * 10 = 100
    Example 2:

    Input: N = 6
    Output: 3
    Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6

    Expected Time Complexity: O(N * sqrt(N) )
    Expected Space Complexity: O(N)


    Constraints:
    1 <= N <= 10000
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solveRecur(n - i * i));
    }
    return ans;
}

int solveRM(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solveRM(n - i * i, dp));
    }

    dp[n] = ans;
    return dp[n];
}

int solveTab(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            if (i - j * j >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
    }
    return dp[n];
}

int MinSquares(int n)
{
    // Recursive solution
    return solveRecur(n);

    // Recursion + Memoization
    // vector<int> dp(n + 1, -1);
    // return solveRM(n, dp);

    // Tabulation
    return solveTab(n);
}

int main()
{
    int n = 100;
    cout << MinSquares(n) << endl;
    return 0;
}