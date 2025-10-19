#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(int i, int j, string a, string b)
{
    if (i >= a.length()) // b's length > a's length
    {
        return b.length() - j;
    }
    if (j >= b.length()) // a's length > b's length
    {
        return a.length() - i;
    }

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = solveRecur(i + 1, j + 1, a, b);
    }
    else
    {
        int ins = 1 + solveRecur(i, j + 1, a, b);     // insert
        int del = 1 + solveRecur(i + 1, j, a, b);     // delete
        int rep = 1 + solveRecur(i + 1, j + 1, a, b); // replace
        ans = min(ins, min(del, rep));
    }
    return ans;
}

// Recursion + Memoization
int solveRM(int i, int j, string a, string b, vector<vector<int>> &dp)
{
    if (i >= a.length()) // b's length > a's length
    {
        return b.length() - j;
    }
    if (j >= b.length()) // a's length > b's length
    {
        return a.length() - i;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = solveRM(i + 1, j + 1, a, b, dp);
    }
    else
    {
        int ins = 1 + solveRM(i, j + 1, a, b, dp);     // insert
        int del = 1 + solveRM(i + 1, j, a, b, dp);     // delete
        int rep = 1 + solveRM(i + 1, j + 1, a, b, dp); // replace
        ans = min(ins, min(del, rep));
    }
    return dp[i][j] = ans;
}

// Tabulation
int solveTab(string a, string b)
{
    int m = a.length();
    int n = b.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j = 0; j < n; j++)
    {
        dp[m][j] = n - j;
    }
    for (int i = 0; i < m; i++)
    {
        dp[i][n] = m - i;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = dp[i + 1][j + 1];
            }
            else
            {
                int ins = 1 + dp[i][j + 1];     // insert
                int del = 1 + dp[i + 1][j];     // delete
                int rep = 1 + dp[i + 1][j + 1]; // replace
                ans = min(ins, min(del, rep));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

// Space Optimization
int solveSO(string a, string b)
{
    int m = a.length();
    int n = b.length();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int j = 0; j < n; j++)
    {
        next[j] = n - j;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            curr[n] = m - i;
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = next[j + 1];
            }
            else
            {
                int ins = 1 + curr[j + 1]; // insert
                int del = 1 + next[j];     // delete
                int rep = 1 + next[j + 1]; // replace
                ans = min(ins, min(del, rep));
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int minDistance(string word1, string word2)
{
    // Recursion
    // return solveRecur(0, 0, word1, word2);

    // Recursion + Memoization
    //  int m = word1.length();
    //  int n = word2.length();
    //  vector<vector<int>> dp(m, vector<int>(n, -1));
    //  return solveRM(0, 0, word1, word2, dp);

    // Tabulation
    // return solveTab(word1, word2);

    // Space Optimization
    if (word1.length() == 0)
    {
        return word2.length();
    }
    else if (word2.length() == 0)
    {
        return word1.length();
    }
    return solveSO(word1, word2);
}

int main()
{
    string word1 = "intention";
    string word2 = "execution";
    cout << minDistance(word1, word2) << endl;
    return 0;
}