// Calculate n th fibonacci number

#include<bits/stdc++.h>
using namespace std;

int solveRecur(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return solveRecur(n - 1) + solveRecur(n - 2);
}

int solveRM(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = solveRM(n - 1, dp) + solveRM(n - 2, dp);
}

int solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int solveSO(int n)
{
    int prev1 = 0;
    int prev2 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int fib(int n)
{
    // Recursion
    // return solveRecur(n);

    // Recursion + Memoization
    // vector<int> dp(n + 1, -1);
    // return solveRM(n, dp);

    // Tabulation
    // return solveTab(n);

    // Space Optimization
    return solveSO(n);
}

int main()
{
    cout << fib(10) << endl;
    return 0;
}