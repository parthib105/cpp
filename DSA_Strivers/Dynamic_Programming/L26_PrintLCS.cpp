/*
    Print Longest Common Subsequence
    
    You are given two strings ‘s1’ and ‘s2’.
    Return the longest common subsequence of these strings.
    If there’s no such string, return an empty string. If there are multiple possible answers, return any such string.


    Note:
    Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of ‘s1’ that is also a subsequence of ‘s2’. A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or more (possibly zero) characters from ‘s1’.


    Example:
    Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”

    Output: “bab”

    Explanation:
    “bab” is one valid longest subsequence present in both strings ‘s1’ , ‘s2’.


    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:
    5 6
    ababa
    cbbcad


    Expected Answer:
    "bba"


    Output on console:
    1


    Explanation of sample output 1:
    “bba” is only possible longest subsequence present in both s1 = “ababa” and s2 = “cbbcad”. '1' is printed if the returned string is equal to "bba". 


    Sample Input 2:
    3 3
    xyz
    abc


    Expected Answer:
    ""


    Output on console:
    1


    Explanation of sample output 2:
    There’s no subsequence of ‘s1’ that is also present in ‘s2’. Thus an empty string is returned and '1' is printed.


    Expected Time Complexity:
    Try to solve this in O(n*m). Where ‘n’ is the length of ‘s1’ and ‘m’ is the length of ‘s2’. 


    Constraints:
    1 <= n, m <= 10^3

    Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;

string LCS(string &s1, string &s2, int i, int j) 
{
    // base case
    if (i == s1.size() || j == s2.size()) return "";

    if (s1[i] == s2[j]) {
        // characters match -> include it
        return s1[i] + LCS(s1, s2, i + 1, j + 1);
    } else {
        // explore both options
        string option1 = LCS(s1, s2, i + 1, j);
        string option2 = LCS(s1, s2, i, j + 1);

        return (option1.size() > option2.size() ? option1 : option2);
    }
}

string usingTabDP(int n, int m, string &s1, string &s2)
{
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string ans = "";
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			ans = s1[i - 1] + ans;
			i --;
			j --;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
			i --;
		else	
			j --;
	}
	return ans;
}

string findLCS(int n, int m, string &s1, string &s2)
{
	// Using recursion
	return LCS(s1, s2, 0, 0);

	// Using DP table
	// return usingTabDP(n, m, s1, s2);
}

int main()
{
    int n = 14, m = 14;
    string s1 = "aplaufhkwygjdh", s2 = "vpyvskardasrnc";

    cout << findLCS(n, m, s1, s2) << endl;

    return 0;
}