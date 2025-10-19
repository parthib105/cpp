/*
    Longest Common Subsequence

    Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

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

int solveRecur(int i1, int i2, string s1, string s2)
{
    if (i1 < 0 || i2 < 0)
        return 0;

    // if matches
    if (s1[i1] == s2[i2])
        return 1 + solveRecur(i1 - 1, i2 - 1, s1, s2);

    // if not matches, take both possibilities
    int opt1 = solveRecur(i1 - 1, i2, s1, s2);
    int opt2 = solveRecur(i1, i2 - 1, s1, s2);
    return max(opt1, opt2);
}

int solveRM(int i1, int i2, string s1, string s2, vector<vector<int>> &dp)
{
    if (i1 < 0 || i2 < 0)
        return 0;

    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    // if matches
    if (s1[i1] == s2[i2])
        return 1 + solveRecur(i1 - 1, i2 - 1, s1, s2);

    // if not matches, take both possibilities
    int opt1 = solveRM(i1 - 1, i2, s1, s2, dp);
    int opt2 = solveRM(i1, i2 - 1, s1, s2, dp);
    dp[i1][i2] = max(opt1, opt2);

    return dp[i1][i2];
}

int solveTab(int n1, int n2, string s1, string s2)
{
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i1 = 1; i1 <= n1; i1++)
    {
        for (int i2 = 1; i2 <= n2; i2++)
        {
            if (s1[i1 - 1] == s2[i2 - 1])
                dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
            else
                dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
        }
    }
    return dp[n1][n2];
}

int solveSO(int n1, int n2, string s1, string s2)
{
    vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);

    for (int i1 = 1; i1 <= n1; i1++)
    {
        for (int i2 = 1; i2 <= n2; i2++)
        {
            if (s1[i1 - 1] == s2[i2 - 1])
                curr[i2] = 1 + prev[i2 - 1];
            else
                curr[i2] = max(prev[i2], curr[i2 - 1]);
        }
        prev = curr;
    }
    return prev[n2];
}

int longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.size(), n2 = text2.size();

    // Recursive
    // return solveRecur(n1 - 1, n2 - 1, text1, text2);

    // Recursion + Memoization
    // vector<vector<int>> dp(n1, vector<int>(n2, -1));
    // return solveRM(n1 - 1, n2 - 1, text1, text2, dp);

    // Tabulation
    // return solveTab(n1, n2, text1, text2);

    // Space Optimization
    return solveSO(n1, n2, text1, text2);
}

int main()
{
    string text1 = "abcde", text2 = "ace";
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}