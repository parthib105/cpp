/*
    Given two strings 's1' and 's2', return true if 's2' contains a permutation of 
    's1' or false otherwise

    In other words, return true if one if s1's permutations is the substring of 's2'
*/

#include <bits/stdc++.h>
using namespace std;

bool checkEqual(int arr1[26], int arr2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    // character count array
    int count1[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        count1[s1[i] - 'a'] ++;
    }

    // traverse s2 string in window of size s1 length and compare
    int i = 0;
    int winSize = s1.length();
    int count2[26] = {0};

    // running first window
    while (i < winSize && i < s2.length())
    {
        int idx = s2[i] - 'a';
        count2[idx] ++;
        i++;
    }

    if (checkEqual(count1, count2))
    {
        return true;
    }
    
    // now traverse s2 window wise
    // update the new character count and minus the old character count
    while (i < s2.length())
    {
        char newChar = s2[i];
        int idx = newChar - 'a';
        count2[idx] ++;

        char oldChar = s2[i - winSize];
        idx = oldChar - 'a';
        count2[idx] --;

        if (checkEqual(count1, count2))
        {
            return 1;
        }

        i++;
    }
    return 0;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidboaoo";
    cout << checkInclusion(s1, s2) << endl;
    return 0;
}