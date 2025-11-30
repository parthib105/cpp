/*
    Minimum Window Substring

    Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

    The testcases will be generated such that the answer is unique.



    Example 1:

    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
    Example 2:

    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.
    Example 3:

    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    Since the largest window of s only has one 'a', return empty string.


    Constraints:

    m == s.length
    n == t.length
    1 <= m, n <= 10^5
    s and t consist of uppercase and lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // T.C. : O(N^2), S.C. : O(N)
    string brute(string s, string t)
    {
        int minLen = INT_MAX, sIdx;
        int n = s.length(), m = t.length();

        unordered_map<char, int> t_freq;
        for (char tc : t)
            t_freq[tc]++;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            unordered_map<char, int> freq = t_freq;
            for (int j = i; j < n; j++)
            {
                if (freq[s[j]] > 0)
                    cnt += 1;

                freq[s[j]]--;
                if (cnt == m && j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    sIdx = i;
                    break;
                }
            }
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(sIdx, minLen);
    }

    string optimal(string s, string t)
    {
        int n = s.length(), m = t.length();
        int l = 0, cnt = 0, sIdx = -1, minLen = 1e6;

        unordered_map<char, int> freq;
        for (char ti : t)
            freq[ti]++;

        for (int r = 0; r < n; r++)
        {
            if (freq[s[r]] > 0)
                cnt += 1;

            freq[s[r]] -= 1;
            while (cnt == m)
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    sIdx = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0)
                    cnt -= 1;

                l++;
            }
        }
        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }

public:
    string minWindow(string s, string t)
    {
        // brute force
        // return brute(s, t);

        // Optimal
        return optimal(s, t);
    }
};

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";

    Solution sol;
    cout << sol.minWindow(s, t) << endl;
    return 0;
}