/*
    Longest Common Substring

    You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

    Examples:

    Input: s1 = "ABCDGH", s2 = "ACDGHR"
    Output: 4
    Explanation: The longest common substring is "CDGH" with a length of 4.
    Input: s1 = "abc", s2 = "acb"
    Output: 1
    Explanation: The longest common substrings are "a", "b", "c" all having length 1.
    Input: s1 = "YZ", s2 = "yz"
    Output: 0
    Constraints:
    1 <= s1.size(), s2.size() <= 103
    Both strings may contain upper and lower case alphabets.
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(m x n), S.C. : O(m x n)
int solveTab(int n, int m, string s1, string s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

// // T.C. : O(m x n), S.C. : O(m)
int solveSO(int n, int m, string s1, string s2)
{
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}

int longestCommonSubstr(string &s1, string &s2)
{
    // Tabulation
    // return solveTab(s1.length(), s2.length(), s1, s2);

    // Space Optimization
    return solveSO(s1.length(), s2.length(), s1, s2);
}

int main()
{
    string s1 = "abcdgh", s2 = "acdghr";
    cout << longestCommonSubstr(s1, s2) << endl;
    return 0;
}