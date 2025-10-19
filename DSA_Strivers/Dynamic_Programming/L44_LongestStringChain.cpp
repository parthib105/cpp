/*
    Longest String Chain

    You are given an array of words where each word consists of lowercase English letters.

    wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

    For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
    A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

    Return the length of the longest possible word chain with words chosen from the given list of words.


    Example 1:

    Input: words = ["a","b","ba","bca","bda","bdca"]
    Output: 4
    Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
    Example 2:

    Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
    Output: 5
    Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
    Example 3:

    Input: words = ["abcd","dbqca"]
    Output: 1
    Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
    ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


    Constraints:

    1 <= words.length <= 1000
    1 <= words[i].length <= 16
    words[i] only consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool check(string &s1, string &s2)
{
    if (s1.length() - s2.length() != 1)
        return false;

    int i1 = 0, i2 = 0;
    while (i1 < s1.length())
    {
        if (s1[i1] == s2[i2])
        {
            i1++;
            i2++;
        }
        else
            i1++;
    }
    if (i1 == s1.length() && i2 == s2.length())
        return true;
    return false;
}

int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), [&](const string &a, const string &b)
         { return a.length() < b.length(); });

    int lsc = 0;
    int n = words.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (check(words[i], words[j]) && 1 + dp[j] > dp[i])
                dp[i] = 1 + dp[j];
        }
        lsc = max(lsc, dp[i]);
    }
    return lsc;
}

int main()
{
    vector<string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << longestStrChain(words) << endl;
    return 0;
}