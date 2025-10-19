/*
    Maximum Occuring Character

    Given a string 's', return the maximum occuring character
*/

#include<bits/stdc++.h>
using namespace std;

char maxOccr(string s)
{
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i] - 'a'] ++;
    }
    
    int maxidx = 0;
    for (int i = 1; i < 26; i++)
    {
        if (arr[i] > arr[maxidx])
        {
            maxidx = i;
        }
    }
    return ((char)('a' + maxidx));
}

int main()
{
    string s = "testsample";
    cout << maxOccr(s) << endl;
    return 0;
}