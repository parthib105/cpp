/*
    Generate Parentheses

    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    Example 1:

    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
    Example 2:

    Input: n = 1
    Output: ["()"]
    

    Constraints:

    1 <= n <= 8
*/

#include<bits/stdc++.h>
using namespace std;

void backtrack(int open, int close, int n, string& curr, vector<string>& res)
{
    if (curr.length() == 2*n)
    {
        res.push_back(curr);
        return;
    }

    if (open < n)
    {
        curr.push_back('(');
        backtrack(open + 1, close, n, curr, res);
        curr.pop_back();
    }

    if (close < open)
    {
        curr.push_back(')');
        backtrack(open, close + 1, n, curr, res);
        curr.pop_back();
    }
}

vector<string> generateParenthesis(int n) 
{
    vector<string> res;
    string curr = "";
    backtrack(0, 0, n, curr, res);
    return res;
}

int main()
{
    int n = 4;
    vector<string> res = generateParenthesis(n);
    for (string s : res)
        cout << s << " ";
    return 0;
}