/*
    Shortest Common Supersequence

    Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

    A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

    Example 1:

    Input: str1 = "abac", str2 = "cab"
    Output: "cabac"
    Explanation:
    str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
    str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
    The answer provided is the shortest such string that satisfies these properties.
    Example 2:

    Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
    Output: "aaaaaaaa"


    Constraints:

    1 <= str1.length, str2.length <= 1000
    str1 and str2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

void getLCSTable(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp)
{
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
}

string shortestCommonSupersequence(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    // get the LCS dp table
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    getLCSTable(n1, n2, str1, str2, dp);

    string ans = "";
    int i = n1, j = n2;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) // moving up
        {
            ans.push_back(str1[i - 1]);
            i--;
        }
        else
        {
            ans.push_back(str2[j - 1]);
            j--;
        }
    }

    while (i > 0)
    {
        ans.push_back(str1[i - 1]);
        i--;
    }

    while (j > 0)
    {
        ans.push_back(str2[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str1 = "abac", str2 = "cab";
    cout << shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}