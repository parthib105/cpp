/*
    Minimum Insertion Steps to Make a String Palindrome

    Given a string s. In one step you can insert any character at any index of the string.

    Return the minimum number of steps to make s palindrome.

    A Palindrome String is one that reads the same backward as well as forward.



    Example 1:

    Input: s = "zzazz"
    Output: 0
    Explanation: The string "zzazz" is already palindrome we do not need any insertions.
    Example 2:

    Input: s = "mbadm"
    Output: 2
    Explanation: String can be "mbdadbm" or "mdbabdm".
    Example 3:

    Input: s = "leetcode"
    Output: 5
    Explanation: Inserting 5 characters the string becomes "leetcodocteel".


    Constraints:

    1 <= s.length <= 500
    s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

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

    // Space Optimization
    return solveSO(n, n, s, s2);
}

int minInsertions(string s)
{
    // get the longest palindromic subsequence
    int lps = longestPalindromeSubseq(s);
    return s.length() - lps;
}

int main()
{
    string s = "leetcode";
    cout << minInsertions(s) << endl;
    return 0;
}