/*
    Distinct Subsequences

    Given two strings s and t, return the number of distinct subsequences of s which equals t.

    The test cases are generated so that the answer fits on a 32-bit signed integer.



    Example 1:

    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation:
    As shown below, there are 3 ways you can generate "rabbit" from s.
    rabbbit
    rabbbit
    rabbbit
    Example 2:

    Input: s = "babgbag", t = "bag"
    Output: 5
    Explanation:
    As shown below, there are 5 ways you can generate "bag" from s.
    babgbag
    babgbag
    babgbag
    babgbag
    babgbag


    Constraints:

    1 <= s.length, t.length <= 1000
    s and t consist of English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int j, string &s, string &t)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    // if match
    if (s[i] == t[j])
    {
        int opt1 = solveRecur(i - 1, j - 1, s, t);
        int opt2 = solveRecur(i - 1, j, s, t);
        return opt1 + opt2;
    }

    // if not match
    return solveRecur(i - 1, j, s, t);
}

int solveRM(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // if match
    if (s[i] == t[j])
    {
        int opt1 = solveRM(i - 1, j - 1, s, t, dp);
        int opt2 = solveRM(i - 1, j, s, t, dp);

        dp[i][j] = opt1 + opt2;
        return dp[i][j];
    }

    // if not match
    dp[i][j] = solveRM(i - 1, j, s, t, dp);
    return dp[i][j];
}

int solveTab(int n, int m, string &s, string &t)
{
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

    // base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1.0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return (int)dp[n][m];
}

int solveSO(int n, int m, string &s, string &t)
{
    vector<double> prev(m + 1, 0), curr(m + 1, 0);

    // base cases
    prev[0] = curr[0] = 1.0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = prev[j - 1] + prev[j];
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }
    return (int)prev[m];
}

int solveSO2(int n, int m, string &s, string &t)
{
    vector<double> prev(m + 1, 0);

    // base cases
    prev[0] = 1.0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
                prev[j] = prev[j - 1] + prev[j];
        }
    }
    return (int)prev[m];
}

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();

    // Recursion
    // return solveRecur(n - 1, m - 1, s, t);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return solveRM(n - 1, m - 1, s, t, dp);

    // Tabulation
    // return solveTab(n, m, s, t);

    // Space Optimizations
    return solveSO(n, m, s, t);
    // return solveSO2(n, m, s, t);
}

int main()
{
    string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s, t) << endl;
    return 0;
}