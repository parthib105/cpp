/*
    Longest Palindromic Subsequence

    Given a string s, find the longest palindromic subsequence's length in s.
    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing 
    the order of the remaining elements.

    Example 1:

    Input: s = "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".

    Example 2:

    Input: s = "cbbd"
    Output: 2
    Explanation: One possible longest palindromic subsequence is "bb".
    
    Constraints:

    1 <= s.length <= 1000
    s consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int j, string a, string b)
{
    if (i >= a.size() || j >= b.size())
    {
        return 0;
    }

    int lcs = 0;
    if (a[i] == b[j])
    {
        lcs = 1 + solveRecur(i + 1, j + 1, a, b);
    }
    else
    {
        int op1 = solveRecur(i + 1, j, a, b);
        int op2 = solveRecur(i, j + 1, a, b);
        lcs = max(op1, op2);
    }
    return lcs;
}

// Space Optimization
int solveSO(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int lcs = 0;
            if (text1[i] == text2[j])
            {
                lcs = 1 + next[j + 1];
            }
            else
            {
                lcs = max(curr[j + 1], next[j]);
            }
            curr[j] = lcs;
        }
        next = curr;
    }
    return next[0];
}

int longestPalindromeSubseq(string s)
{
    // lps -> lcs of string, reverse string
    string a = s;
    reverse(s.begin(), s.end());
    string b = s;

    // Recursion
    // return solveRecur(0, 0, a, b);

    // Space Optimization
    return solveSO(a, b);
}

int main()
{
    string s = "yuhfnhuby";
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}