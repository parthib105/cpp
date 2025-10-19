/*
    Partition Equal Subset Sum

    Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts 
    is the same.

    Example 1:

    Input: N = 4
    arr = {1, 5, 11, 5}
    Output: YES
    Explanation: 
    The two parts are {1, 5, 5} and {11}.
    Example 2:

    Input: N = 3
    arr = {1, 3, 5}
    Output: NO
    Explanation: This array can never be 
    partitioned into two such parts.
*/
#include<bits/stdc++.h>
using namespace std;

// Recursive Solution
bool solveRecur(int idx, int target, int N, vector<int> arr)
{
    if (target < 0 || idx >= N)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }

    bool incl = solveRecur(idx + 1, target - arr[idx], N, arr);
    bool excl = solveRecur(idx + 1, target, N, arr);
    return incl or excl;
}

// Recursion + Memoization
bool solveRM(int idx, int target, int N, vector<int> arr, vector<vector<int>> &dp)
{
    if (target < 0 || idx >= N)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }
    
    if (dp[idx][target] != -1)
    {
        return dp[idx][target];
    }

    bool incl = solveRM(idx + 1, target - arr[idx], N, arr, dp);
    bool excl = solveRM(idx + 1, target, N, arr, dp);
    dp[idx][target] = incl or excl;
    return dp[idx][target];
}

// Tabulation
bool solveTab(int n, int target, vector<int> &arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int t = 0; t <= target; t++)
        {
            bool incl = 0;
            if (t - arr[i] >= 0)
            {
                incl = dp[i + 1][t - arr[i]];
            }
            bool excl = dp[i + 1][t];

            dp[i][t] = incl or excl;
        }
    }
    return dp[0][target];
}

bool equalPartition(int N, vector<int> arr)
{
    int sumArr = 0;
    for (auto i : arr)
    {
        sumArr += i;
    }
    if (sumArr & 1)
    {
        return false;
    }

    int target = sumArr / 2;

    // Recursive Solution
    // return solveRecur(0, target, N, arr);

    // Recursion + Memoization
    // vector<vector<int>> dp(N, vector<int>(target + 1, -1));
    // return solveRM(0, target, N, arr, dp);

    // Tabulation
    return solveTab(N, target, arr);
}

int main()
{
    int N = 4;
    vector<int> arr = {1, 5, 11, 5};
    if (equalPartition(N, arr))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}