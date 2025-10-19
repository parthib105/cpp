/*
    Palindrome Partitioning II

    Given a string s, partition s such that every substring of the partition is a palindrome.

    Return the minimum cuts needed for a palindrome partitioning of s.

    Example 1:

    Input: s = "aab"
    Output: 1
    Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
    Example 2:

    Input: s = "a"
    Output: 0
    Example 3:

    Input: s = "ab"
    Output: 1


    Constraints:

    1 <= s.length <= 2000
    s consists of lowercase English letters only.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solveRecur(int i, int n, string &s)
{
    if (i >= n)
        return 0;

    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            int currCost = 1 + solveRecur(j + 1, n, s);
            minCost = min(minCost, currCost);
        }
    }
    return minCost;
}

int solveRM(int i, int n, string &s, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            int currCost = 1 + solveRM(j + 1, n, s, dp);
            minCost = min(minCost, currCost);
        }
    }
    dp[i] = minCost;
    return dp[i];
}

int solveTab(int n, string &s)
{
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int currCost = 1 + dp[j + 1];
                minCost = min(minCost, currCost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}

int minCut(string s)
{
    int n = s.length();

    // Recursion
    // return solveRecur(0, n, s) - 1;

    // Recursion + Memoization
    // vector<int> dp(n, -1);
    // return solveRM(0, n, s, dp) - 1;

    // Tabulation
    return solveTab(n, s);
}

int main()
{
    string s = "aab";
    cout << minCut(s) << endl;
    return 0;
}