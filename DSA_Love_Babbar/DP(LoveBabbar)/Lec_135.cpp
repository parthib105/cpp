/*
    Longest Common Subsequence

    Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence,
    return 0.
    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted
    without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".
    A common subsequence of two strings is a subsequence that is common to both strings.

    Example 1:

    Input: text1 = "abcde", text2 = "ace"
    Output: 3
    Explanation: The longest common subsequence is "ace" and its length is 3.

    Example 2:

    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.

    Example 3:

    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.

    Constraints:

    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(int i, int j, string text1, string text2)
{
    if (i >= text1.size() || j >= text2.size())
    {
        return 0;
    }

    int lcs = 0;
    if (text1[i] == text2[j])
    {
        lcs = 1 + solveRecur(i + 1, j + 1, text1, text2);
    }
    else
    {
        int next1 = solveRecur(i + 1, j, text1, text2);
        int next2 = solveRecur(i, j + 1, text1, text2);
        lcs = max(next1, next2);
    }
    return lcs;
}

// Recursion + Memoization
int solveRM(int i, int j, string text1, string text2, vector<vector<int>> &dp)
{
    if (i >= text1.length() || j >= text2.length())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int lcs = 0;
    if (text1[i] == text2[j])
    {
        lcs = 1 + solveRM(i + 1, j + 1, text1, text2, dp);
    }
    else
    {
        int op1 = solveRM(i, j + 1, text1, text2, dp);
        int op2 = solveRM(i + 1, j, text1, text2, dp);
        lcs = max(op1, op2);
    }
    return dp[i][j] = lcs;
}

// Tabulation
int solveTab(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int lcs = 0;
            if (text1[i] == text2[j])
            {
                lcs = 1 + dp[i + 1][j + 1];
            }
            else
            {
                lcs = max(dp[i][j + 1], dp[i + 1][j]);
            }
            dp[i][j] = lcs;
        }
    }
    return dp[0][0];
}

// Space Optimization
int solveSO(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int lcs = 0;
            if (text1[i] == text2[j])
            {
                lcs = 1 + next[j + 1];
            }
            else
            {
                lcs = max(curr[j + 1], next[j]);
            }
            curr[j] = lcs;
        }
        next = curr;
    }
    return next[0];
}

int longestCommonSubsequence(string text1, string text2)
{
    // Recursion
    // return solveRecur(text1, text2, 0, 0);

    // Recursion + Memoization
    // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    // return solveRM(text1, text2, dp, 0, 0);

    // Tabulation
    // return solveTab(text1, text2);

    // Space Optimization
    return solveSO(text1, text2);
}

int main()
{
    string text1 = "ffrdugtyvrcttb";
    string text2 = "bfvrdbfydvrtddnjggbf";
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}