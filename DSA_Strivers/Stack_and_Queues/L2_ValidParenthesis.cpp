/*
    Valid Parentheses

    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    

    Example 1:

    Input: s = "()"
    Output: true

    Example 2:

    Input: s = "()[]{}"
    Output: true

    Example 3:

    Input: s = "(]"
    Output: false

    Example 4:

    Input: s = "([])"
    Output: true

    Example 5:

    Input: s = "([)]"
    Output: false


    Constraints:

    1 <= s.length <= 10^4
    s consists of parentheses only '()[]{}'.
*/


#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) 
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else
        {
            if (st.empty())
                return false;
            else if ((ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '['))
                st.pop();
            else
                return false;
        }
    }

    if (st.empty())
        return true;
    return false;
}

int main()
{
    string s = "()[]{}";
    bool ans = isValid(s);

    if (ans)
        cout << "Yes, it's a valid parenthesis" << endl;
    else
        cout << "No, it's not a valid parenthesis" << endl;
    return 0;
}