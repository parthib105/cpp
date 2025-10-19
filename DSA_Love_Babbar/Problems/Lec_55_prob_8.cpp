/*
    Minimum Cost To Make String Valid

    Problem statement :
    Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the brackets are balanced.
    Formally for each opening bracket, there must be a closing bracket right to it.

    For Example:
    “{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
    Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or
    vice versa, and the cost of one such operation is 1.

    Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.

    For Example:
    Minimum operations to make ‘STR’ =  “{{“ valid is 1.
    In one operation, we can convert ‘{’ at index ‘1’ (0-based indexing) to ‘}’. The ‘STR’ now becomes "{}" which is a valid
    string.

    Note:
    Return -1 if it is impossible to make ‘STR’ valid.
*/

#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    // Write your code here
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    stack<char> st;

    // make valid paranthesis
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    // now we have invalid brackets
    // a -> count of {, b -> count of }
    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        st.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string str = "{{{{{}";
    cout << "Minimum cost : " << findMinimumCost(str) << endl;
    return 0;
}