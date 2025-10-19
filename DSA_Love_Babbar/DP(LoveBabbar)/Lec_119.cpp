/*
    Longest Increasing Subsequence

    Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence.

    A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the term that comes
    after it.

    Example 1:

    Input: n = 6, a[ ] = {5,8,3,7,9,1}
    Output: 3
    Explanation: There are more than one LIS in this array.
    One such Longest increasing subsequence is {5,7,9}.
    Example 2:

    Input: n = 16, a[ ] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
    Output: 6
    Explanation: There are more than one LIS in this array.
    One such Longest increasing subsequence is {0,2,6,9,13,15}.

    Expected Time Complexity : O( n*log(n) )
    Expected Auxiliary Space: O(n)

    Constraints:
    1 <= n <= 10^4
    0 <= a[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
int solveRecur(int n, vector<int> &a, int curr, int prev)
{
    if (curr == n)
    {
        return 0;
    }

    // include
    int incl = 0;
    if (prev == -1 || a[curr] > a[prev])
    {
        incl = 1 + solveRecur(n, a, curr + 1, curr);
    }

    // exclude
    int excl = 0 + solveRecur(n, a, curr + 1, prev);

    return max(incl, excl);
}

// Recursion + Memoization
int solveRM(int n, vector<int> &a, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr == n)
    {
        return 0;
    }

    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }

    // include
    int incl = 0;
    if (prev == -1 || a[curr] > a[prev])
    {
        incl = 1 + solveRM(n, a, curr + 1, curr, dp);
    }

    // exclude
    int excl = 0 + solveRM(n, a, curr + 1, prev, dp);

    dp[curr][prev + 1] = max(incl, excl);
    return dp[curr][prev + 1];
}

// Tabulation
int solveTab(int n, vector<int> &a)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {

            int incl = 0, excl = 0;
            if (prev == -1 || a[curr] > a[prev])
            {
                incl = 1 + dp[curr + 1][curr + 1];
            }
            excl = dp[curr + 1][prev + 1];

            dp[curr][prev + 1] = max(incl, excl);
        }
    }
    return dp[0][0];
}

// Space Optimization
int solveSO(int n, vector<int> &a)
{
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {

            int incl = 0, excl = 0;
            if (prev == -1 || a[curr] > a[prev])
            {
                incl = 1 + nextRow[curr + 1];
            }
            excl = nextRow[prev + 1];

            currRow[prev + 1] = max(incl, excl);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

// DP + Binary Search
int lowerBound(vector<int> &dp, int x)
{
    int i = 0;
    int j = dp.size() - 1;
    int pos = -1;

    while (i <= j)
    {
        int m = i + (j - i)/2;
        if (dp[m] == x)
        {
            return m - 1;
        }
        else if (dp[m] > x)
        {
            j = m - 1;
        }
        else
        {
            i = m + 1;
            pos = m;
        }
    }

    if (pos == -1)
    {
        return 0;
    }
    return pos;
}

int solveDPBS(int n, vector<int> &a)
{
    vector<int> dp;
    dp.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (a[i] > dp.back())
        {
            dp.push_back(a[i]);
        }
        else
        {
            int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[pos] = a[i];
        }
    }
    return dp.size();
}

int longestSubsequence(int n, vector<int> &a)
{
    // Recursive solution
    // return solveRecur(n, a, 0, -1);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return solveRM(n, a, 0, -1, dp);

    // Tabulation
    // return solveTab(n, a);

    // Space Optimization
    return solveSO(n, a);
}

int main()
{
    // vector<int> a = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    // int n = 16;

    // cout << longestSubsequence(n, a) << endl;

    vector<int> arr = {0, 3, 4, 5, 8, 9, 10, 23, 45, 76};
    cout << lowerBound(arr, 22) << endl;
    return 0;
}