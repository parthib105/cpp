/*
    Longest Repeating Character Replacement

    You are given a string s and an integer k. You can choose any character of the string and change it to any other
    uppercase English character. You can perform this operation at most k times.
    Return the length of the longest substring containing the same letter you can get after performing the above operations.

    Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.

    Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achieve this answer too.

    Constraints:

    1 <= s.length <= 10^5
    s consists of only uppercase English letters.
    0 <= k <= s.length
*/

#include <bits/stdc++.h>
using namespace std;

int bruteForce(string s, int k)
{
    int maxLen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        vector<int> hash(26, 0);
        int maxRepeat = 0;
        for (int j = i; j < s.length(); i++)
        {
            hash[s[j] - 'A']++;
            maxRepeat = max(maxRepeat, hash[s[j] - 'A']);
            int change = (j - i + 1) - maxRepeat;
            if (change <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxLen;
}

int characterReplacement(string s, int k)
{
    // brute force
    // return bruteForce(s, k);

    // optimal
    unordered_map<char, int> mp;
    int maxLen = 0;
    int maxF = 0;

    int l = 0;
    for (int r = 0; r < s.length(); r++)
    {
        // update frequency
        mp[s[r]]++;

        // update maxF
        maxF = max(maxF, mp[s[r]]);

        if ((r - l + 1) - maxF > k)
        {
            mp[s[l]]--;
            // update maxF
            maxF = 0;
            unordered_map<char, int>::iterator it = mp.begin();
            while (it != mp.end())
            {
                maxF = max(maxF, it->second);
                it++;
            }
            l++;
        }
        else if ((r - l + 1) - maxF <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
    }
    return maxLen;
}

int main()
{
    string s = "AABABBA";
    int k = 1;
    cout << characterReplacement(s, k) << endl;
    return 0;
}