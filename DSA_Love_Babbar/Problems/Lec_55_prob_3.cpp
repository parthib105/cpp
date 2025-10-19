/*
    Valid Parentheses

    Problem statement :

    You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .

    Return true if the given string 'S' is balanced, else return false.

    For example:
    'S' = "{}()".

    There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
    So the 'S' is Balanced.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                char topElm = st.top();
                if ((ch == ')' && topElm == '(') || (ch == '}' && topElm == '{') || (ch == ']' && topElm == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "[{()}][{]}";
    if (isValidParenthesis(s))
    {
        cout << "The string is balanced" << endl;
    }
    else
    {
        cout << "The string is not balanced" << endl;
    }
    return 0;
}