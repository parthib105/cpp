/*
    Remove All Occurrences of a Substring

    Given two strings 's' and 'part', perform the following operation on 's' untill all occurances of
    the substring 'part' are removed :
        Find the leftmost occurance of the substring 'part' and remove it from 's'
    Return 's' after removing all occurances of part. 
*/

#include <bits/stdc++.h>
using namespace std;

string removeOccurances(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

string Remove(string s, string part)
{
    int n = part.length();

    int i = 0;
    int j = n - 1;

    while (j < s.length())
    {
        string temp;
        int st = i;
        while (st <= j)
        {
            temp.push_back(s[st]);
            st ++;
        }
        if (temp == part)
        {
            s.erase(i, part.length());
            i = 0;
            j = n - 1;
        }
        else
        {
            i ++;
            j ++;
        }
    }
    return s;
}

int main()
{
    string s = "axxxxyyyyb";
    cout << Remove(s, "xy") << endl;
    return 0;
}