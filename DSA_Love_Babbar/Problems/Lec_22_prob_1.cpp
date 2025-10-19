// Check Palindrome

#include<bits/stdc++.h>
using namespace std;

// converts upper case to lower case
char toLower(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        return (ch - 'A' + 'a');
    }
}

bool checkPalindrome(string s)
{
    int n = s.length();
    int i = 0;
    int j = n - 1;

    bool ans = true;
    while (i < j)
    {
        if (toLower(s[i]) == toLower(s[j]))
        {
            i ++;
            j --;
        }
        else
        {
            ans = false;
            break;
        }
    }
    return ans;
}

int main()
{
    string s = "Noon";
    cout << checkPalindrome(s) << endl;
    return 0;
}