/*
    You are given a positive integer n.

    A binary string x is valid if all substrings of x of length 2 contain at least one "1".
    Return all valid strings with length n, in any order.


    Example 1:
    Input: n = 3

    Output: ["010","011","101","110","111"]

    Explanation:
    The valid strings of length 3 are: "010", "011", "101", "110", and "111".

    Example 2:
    Input: n = 1

    Output: ["0","1"]

    Explanation:
    The valid strings of length 1 are: "0" and "1".

    Constraints:
    1 <= n <= 18
*/

#include<bits/stdc++.h>
using namespace std;

void solveRecur(int i, int n, string s, vector<string>& strs)
{
    if (i >= n)
    {
        strs.push_back(s);
        return;
    }

    if (s.empty() || s.back() == '1')
        solveRecur(i + 1, n, s + "0", strs);
    solveRecur(i + 1, n, s + "1", strs);
}

vector<string> validStrings(int n) {
    vector<string> strs;
    solveRecur(0, n, "", strs);
    return strs;
}

int main()
{
    int n = 5;
    vector<string> ans = validStrings(n);
    for (auto s : ans)
        cout << s << " ";
    return 0;
}