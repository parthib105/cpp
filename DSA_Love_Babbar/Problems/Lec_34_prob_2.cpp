/*
    Check palindrome using recursion
*/

#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string& str, int s)
{
    if (s > (str.length() - s - 1))
    {
        return true;
    }

    if (str[s] != str[str.length() - s - 1])
    {
        return false;
    }
    else
    {
        return checkPalindrome(str, s + 1);
    }
}

int main()
{
    string str;
    cout << "Enter the string : ";
    cin >> str;

    bool check = checkPalindrome(str, 0);
    if (check)
    {
        cout << str << " is palindrome" << endl;
    }
    else
    {
        cout << str << " is not palindrome" << endl;
    }

    return 0;
}