/*
    Edit Distance

    Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

    You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character


    Example 1:

    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation:
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')
    Example 2:

    Input: word1 = "intention", word2 = "execution"
    Output: 5
    Explanation:
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')


    Constraints:

    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(exp), S.C. : O(m + n)
int solveRecur(int i, int j, string &s1, string &s2)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    // if matches
    if (s1[i] == s2[j])
        return solveRecur(i - 1, j - 1, s1, s2);

    int ins = 1 + solveRecur(i, j - 1, s1, s2);     // insert
    int del = 1 + solveRecur(i - 1, j, s1, s2);     // delete
    int rep = 1 + solveRecur(i - 1, j - 1, s1, s2); // replace

    return min(rep, min(ins, del));
}

// T.C. : O(m * n), S.C. : O(m * n) + stack space
int solveRM(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    // if matches
    if (s1[i] == s2[j])
    {
        dp[i][j] = solveRM(i - 1, j - 1, s1, s2, dp);
        return dp[i][j];
    }

    int ins = 1 + solveRM(i, j - 1, s1, s2, dp);     // insert
    int del = 1 + solveRM(i - 1, j, s1, s2, dp);     // delete
    int rep = 1 + solveRM(i - 1, j - 1, s1, s2, dp); // replace

    dp[i][j] = min(rep, min(ins, del));
    return dp[i][j];
}

// T.C. : O(m * n), S.C. : O(m * n)
int solveTab(int n, int m, string &s1, string &s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base cases
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int ins = 1 + dp[i][j - 1];     // insert
                int del = 1 + dp[i - 1][j];     // delete
                int rep = 1 + dp[i - 1][j - 1]; // replace

                dp[i][j] = min(rep, min(ins, del));
            }
        }
    }
    return dp[n][m];
}

int solveSO(int n, int m, string &s1, string &s2)
{
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // base cases
    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1];
            else
            {
                int ins = 1 + curr[j - 1]; // insert
                int del = 1 + prev[j];     // delete
                int rep = 1 + prev[j - 1]; // replace

                curr[j] = min(rep, min(ins, del));
            }
        }
        prev = curr;
    }
    return prev[m];
}

int minDistance(string word1, string word2)
{
    int n = word1.size(), m = word2.size();

    // Recursion
    // return solveRecur(n - 1, m - 1, word1, word2);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return solveRM(n - 1, m - 1, word1, word2, dp);

    // Tabulation
    // return solveTab(n, m, word1, word2);

    // Space Optimization
    return solveSO(n, m, word1, word2);
}

int main()
{
    string word1 = "intention", word2 = "execution";
    cout << minDistance(word1, word2) << endl;
    return 0;
}