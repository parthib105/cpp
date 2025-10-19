/*
    Wildcard Matching

    Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).



    Example 1:

    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    Example 2:

    Input: s = "aa", p = "*"
    Output: true
    Explanation: '*' matches any sequence.
    Example 3:

    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


    Constraints:

    0 <= s.length, p.length <= 2000
    s contains only lowercase English letters.
    p contains only lowercase English letters, '?' or '*'.
*/

#include <bits/stdc++.h>
using namespace std;

// i -> pattern, j -> text
bool solveRecur(int i, int j, string &p, string &s)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return p.substr(0, i + 1) == string(i + 1, '*');

    // if matches
    if (p[i] == s[j] || p[i] == '?')
        return solveRecur(i - 1, j - 1, p, s);
    if (p[i] == '*')
        return solveRecur(i - 1, j, p, s) || solveRecur(i, j - 1, p, s);

    return false;
}

bool solveRM(int i, int j, string &p, string &s, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return p.substr(0, i + 1) == string(i + 1, '*');

    if (dp[i][j] != -1)
        return dp[i][j];

    // if matches
    if (p[i] == s[j] || p[i] == '?')
    {
        dp[i][j] = solveRM(i - 1, j - 1, p, s, dp);
        return dp[i][j];
    }
    if (p[i] == '*')
    {
        bool opt1 = solveRM(i - 1, j, p, s, dp);
        bool opt2 = solveRM(i, j - 1, p, s, dp);
        dp[i][j] = opt1 || opt2;
        return dp[i][j];
    }

    dp[i][j] = false;
    return dp[i][j];
}

int solveTab(int n, int m, string &p, string &s)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // base case
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
        dp[i][0] = p.substr(0, i) == string(i, '*');

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // if matches
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

int solveSO(int n, int m, string &p, string &s)
{
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    // base case
    prev[0] = true;
    for (int i = 1; i <= n; i++)
    {
        curr[0] = p.substr(0, i) == string(i, '*');
        for (int j = 1; j <= m; j++)
        {
            // if matches
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                curr[j] = prev[j - 1];
            else if (p[i - 1] == '*')
                curr[j] = prev[j] || curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}

bool isMatch(string& s, string& p)
{
    int m = s.length(), n = p.length();

    // Recursion
    // return solveRecur(n - 1, m - 1, p, s);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return solveRM(n - 1, m - 1, p, s, dp);

    // Tabulation
    // return solveTab(n, m, p, s);

    // Space Optimization
    return solveSO(n, m, p, s);
}

int main()
{
    string s = "cb", p = "?a";
    cout << isMatch(s, p) << endl;
    return 0;
}