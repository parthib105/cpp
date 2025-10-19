/*
    Palindrome Partitioning

    Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

    Example 1:

    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
    Example 2:

    Input: s = "a"
    Output: [["a"]]


    Constraints:

    1 <= s.length <= 16
    s contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int l, int r, string &s)
{
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l += 1;
        r -= 1;
    }
    return true;
}

void backtrackRecur(int i, string &s, vector<string> &sub, vector<vector<string>> &res)
{
    if (i == s.length())
    {
        res.push_back(sub);
        return;
    }

    for (int j = i; j < s.length(); j++)
    {
        if (isPalindrome(i, j, s))
        {
            sub.push_back(s.substr(i, j - i + 1));
            backtrackRecur(j + 1, s, sub, res);
            sub.pop_back();
        }
    }
}

void backtrackDP(int i, string &s, vector<string> &sub, vector<vector<string>> &res, vector<vector<bool>> &dp)
{
    if (i == s.length())
    {
        res.push_back(sub);
        return;
    }

    for (int j = i; j < s.length(); j++)
    {
        if (dp[i][j])
        {
            sub.push_back(s.substr(i, j - i + 1));
            backtrackDP(j + 1, s, sub, res, dp);
            sub.pop_back();
        }
    }
}

// T.C. : O(N * 2^N), S.C. : O(N * 2^N)
vector<vector<string>> solveRecur(string s)
{
    vector<string> sub;
    vector<vector<string>> res;
    backtrackRecur(0, s, sub, res);
    return res;
}

// T.C. : O(N * 2^N), S.C. : O(N^2)
vector<vector<string>> solveDP(string s)
{
    int n = s.length();
    // dp[i][j] = true if the substring s[i...j] is a palindrome, and false otherwise.
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // All single characters are valid substring
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j])
            {
                // If length is 2 or the inner substring is a palindrome
                if (len == 2 || dp[i + 1][j - 1])
                    dp[i][j] = true;
            }
        }
    }

    vector<vector<string>> res;
    vector<string> sub;
    backtrackDP(0, s, sub, res, dp);
    return res;
}

vector<vector<string>> partition(string s)
{
    // Recursion + Backtracking
    // return solveRecur(s);

    // Recursion + memoization
    return solveDP(s);
}

int main()
{

    return 0;
}