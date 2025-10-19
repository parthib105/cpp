/*
    Valid Palindrome

    A phrase is PALINDROME if after converting all uppercase letters into
    lowercase letters ans removing all non-alphanumeric characters, it reads
    the same forward and backward. Alphanumeric characters include letters and numbers

    Given a string s, return true if it is a palindrome, or false otherwise
*/

#include<bits/stdc++.h>
using namespace std;

char toLower(char ch)
{
    return (ch - 'A' + 'a');
}

bool isValid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    string cpy;

    for (int i = 0; i < s.length(); i++)
    {
        if (isValid(s[i]))
        {
            cpy.push_back(toLower(s[i]));
        }
    }
    
    int i = 0;
    int j = cpy.length() - 1;

    while (i < j)
    {
        if (cpy[i] != cpy[j])
        {
            return false;
        }
        else
        {
            i ++;
            j --;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << endl;
    return 0;
}