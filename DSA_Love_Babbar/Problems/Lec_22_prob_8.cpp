/*
    Remove All Adjacent Duplicates in String

    You are given a string 's' consisting of lowercase English letters.
    A duplicate removal consists of choosing two adjacent and equal letters and removing them.

    We repeatedly make duplicate removals on 's' untill we no longer can

    Return the final string after all such duplicate removals have been made. It can be proven that
    answer is unique
*/

#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s)
{
    int i = 0;

    while (i < s.length())
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            i = i - 1;
            if (i < 0)
            {
                i = 0;
            }
        }
        else
        {
            i++;
        }
    }
    return s;
}

int main()
{
    string s = "abbaca";
    cout << removeDuplicate(s) << endl;
    return 0;
}