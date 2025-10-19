/*
    Longest Palindromic Subsequence

    Given a string s, find the longest palindromic subsequence's length in s.

    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


    Example 1:

    Input: s = "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".
    Example 2:

    Input: s = "cbbd"
    Output: 2
    Explanation: One possible longest palindromic subsequence is "bb".


    Constraints:

    1 <= s.length <= 1000
    s consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;

    // if matches
    if (s1[i] == s2[j])
        return 1 + solveRecur(i - 1, j - 1, s1, s2);

    int opt1 = solveRecur(i - 1, j, s1, s2);
    int opt2 = solveRecur(i, j - 1, s1, s2);
    return max(opt1, opt2);
}

int solveRM(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    // if matches
    if (s1[i] == s2[j])
        return 1 + solveRM(i - 1, j - 1, s1, s2, dp);

    int opt1 = solveRM(i - 1, j, s1, s2, dp);
    int opt2 = solveRM(i, j - 1, s1, s2, dp);

    dp[i][j] = max(opt1, opt2);
    return dp[i][j];
}

int solveTab(int n, int m, string &s1, string &s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int solveSO(int n, int m, string &s1, string &s2)
{
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}

int longestPalindromeSubseq(string s)
{
    string s2 = s;
    int n = s.length();
    reverse(s2.begin(), s2.end());

    // Recursion
    // return solveRecur(n - 1, n - 1, s, s2);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return solveRM(n - 1, n - 1, s, s2, dp);

    // Tabulation
    // return solveTab(n, n, s, s2);

    // Space Optimization
    return solveSO(n, n, s, s2);
}

int main()
{
    string s = "bbbab";
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}