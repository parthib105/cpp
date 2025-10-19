/*
    Unique Binary Search Trees

    Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of
    unique values from 1 to n.

    Example 1:

    Input: n = 3
    Output: 5

    Example 2:

    Input: n = 1
    Output: 1

    Constraints:

    1 <= n <= 19
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solveRecur(i - 1) * solveRecur(n - i);
    }
    return ans;
}

// Recursion + Memoization
int solveRM(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solveRM(i - 1, dp) * solveRM(n - i, dp);
    }
    return dp[n] = ans;
}

// Tabulation
int solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    // i -> no. of node
    for (int i = 2; i <= n; i++)
    {
        // j -> root node
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

int numTrees(int n)
{
    // Recursive solution
    return solveRecur(n);

    // Recursion + Memoization
    vector<int> dp(n + 1, -1);
    return solveRM(n, dp);
}

int main()
{

    return 0;
}