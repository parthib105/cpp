/*
    Delete Operation for Two Strings

    Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

    In one step, you can delete exactly one character in either string.

    Example 1:

    Input: word1 = "sea", word2 = "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
    Example 2:

    Input: word1 = "leetcode", word2 = "etco"
    Output: 4


    Constraints:

    1 <= word1.length, word2.length <= 500
    word1 and word2 consist of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(int n1, int n2, string &s1, string &s2)
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

int minDistance(string word1, string word2)
{
    int n1 = word1.length(), n2 = word2.length();

    // get the max(m, n) - lcs
    int lcs = longestCommonSubsequence(n1, n2, word1, word2);

    return n1 + n2 - 2 * lcs;
}

int main()
{
    string word1 = "leetcode", word2 = "etco";
    cout << minDistance(word1, word2) << endl;
    return 0;
}