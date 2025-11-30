/*
    Number of Substrings Containing All Three Characters

    Given a string s consisting only of characters a, b and c.

    Return the number of substrings containing at least one occurrence of all these characters a, b and c.

    Example 1:

    Input: s = "abcabc"
    Output: 10
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
    Example 2:

    Input: s = "aaacb"
    Output: 3
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
    Example 3:

    Input: s = "abc"
    Output: 1

    Constraints:

    3 <= s.length <= 5 x 10^4
    s only consists of a, b or c characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int nos(string s)
    {
        int n = s.length();
        vector<int> count(3, 0);
        int l = 0, subs = 0;

        for (int r = 0; r < n; r++)
        {
            count[s[r] - 'a'] += 1;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0)
            {
                subs += (n - r);
                count[s[l] - 'a']--;
                l++;
            }
        }
        return subs;
    }

public:
    int numberOfSubstrings(string s)
    {
        int cnt = 0;
        vector<int> lastSeen(3, -1);
        for (int i = 0; i < s.length(); i++)
        {
            lastSeen[s[i] - 'a'] = i;

            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
                cnt += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
        return cnt;
    }
};

int main()
{
    string s = "abcabc";

    Solution sol;
    int len = sol.numberOfSubstrings(s);
    cout << len << endl;
    return 0;
}