/*
    Longest Substring with At Most K Distinct Characters

    You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

    For example:
    You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.
    
    Constraints:
    1 <= T <= 10
    1 <= K <= 26
    1 <= |str| <= 10^6

    The string str will contain only lowercase alphabets.    

    Time Limit: 1 sec
    Note:
    You do not need to print anything. It has already been taken care of. Just implement the function.
    Sample Input 1:
    2
    2
    abbbbbbc
    3
    abcddefg
    Sample Output 1:
    7
    4
    Explanation:
    For the first test case, ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.

    For the second test case, ‘str’ = ‘abcddefg’ and ‘K’ = 3, then the substrings that can be formed is [‘cdde’, ‘ddef’]. Hence the answer is 4.
    Sample Input 2:
    2
    3
    aaaaaaaa
    1
    abcefg
    Sample Output 2:
    8   
    1   
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kDistinctChars(int k, string& str)
    {
        int n = str.size();
        int maxLen = 0, l = 0;
        unordered_map<char, int> freq;
        
        for (int r = 0; r < n; r++)
        {
            freq[str[r]] ++;

            while (freq.size() > k)
            {
                freq[str[l]] --;
                if (freq[str[l]] == 0)
                    freq.erase(str[l]);
                l ++;
            }

            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

int main()
{
    int k = 3;
    string str = "abcddefg";

    Solution sol;
    int ans = sol.kDistinctChars(k, str);
    cout << ans << endl;
    return 0;
}