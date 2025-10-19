/*
    Reverse a string using a stack
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string : ";
    getline(cin, s);

    stack<char> st;
    for(int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    int i = 0;
    while (!st.empty())
    {
        s[i] = st.top();
        i++;
        st.pop();
    }

    cout << s << endl;
    return 0;
}