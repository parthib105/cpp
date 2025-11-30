/*
    Longest Substring Without Repeating Characters

    Given a string s, find the length of the longest substring without duplicate characters.

    Example 1:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
    Example 2:

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    Example 3:

    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

    Constraints:

    0 <= s.length <= 5 * 10^4
    s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int lengthOfLongestSubstringBrute(string s)
    {
        int n = s.size(), maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> hash;
            for (int j = i; j < n; j++)
            {
                if (hash.count(s[j]))
                    break;

                hash.insert(s[j]);

                int len = j - i + 1;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }

    int lengthOfLongestSubstringOptimal(string s)
    {
        unordered_map<char, int> mp;
        int maxLen = 0, l = 0, n = s.length();

        for (int r = 0; r < n; r++)
        {
            if (mp.find(s[r]) != mp.end())
                l = max(l, mp[s[r]] + 1);

            maxLen = max(maxLen, r - l + 1);
            mp[s[r]] = r;
        }
        return maxLen;
    }

public:
    int lengthOfLongestSubstring(string s)
    {
        // brute force
        // return lengthOfLongestSubstringBrute(s);

        // Optimal
        return lengthOfLongestSubstringOptimal(s);
    }
};

int main()
{
    string s = "abcabcbb";

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}