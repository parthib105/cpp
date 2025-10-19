/*
    Given a string as an input, reverse the string using recursion 
*/

#include<bits/stdc++.h>
using namespace std;

void reverseString(string& str, int s, int e)
{
    if (s > e)
    {
        return;
    }

    char temp = str[s];
    str[s] = str[e];
    str[e] = temp;

    s++;
    e--;

    reverseString(str, s, e);
}

int main()
{
    string str;
    cout << "Enter the string : ";
    cin >> str;

    reverseString(str, 0, str.length() - 1);

    cout << "Reversed string = " << str << endl;

    return 0;
}