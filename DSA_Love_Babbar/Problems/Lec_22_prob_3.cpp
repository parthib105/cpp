/*
    Reverse Words in a string

    Given a character array 's', reverse the order of the words.

    A word is defined as a sequence of non-space characters. The words in 's' will be 
    separated by a single space.

    Your code must solve problem in-space i.e., without allocating extra space

    Ex.    s = ["t", "h", "e", " ", "s", "k", "y", " ", "i", "s", " ", "b", "l", "u", "e"]
           output = ["b", "l", "u", "e", " ", "i", "s", " ", "s", "k", "y", " ", "t", "h", "e"]
*/

#include<bits/stdc++.h>
using namespace std;

void rev(char s[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }

    int st = 0;
    for (int ed = 0; ed < n - 1; ed++)
    {
        if (s[ed + 1] == ' ')
        {
            int itr1 = st;
            int itr2 = ed;
            while (itr1 < itr2)
            {
                swap(s[itr1], s[itr2]);
                itr1 ++;
                itr2 --;
            }

            st = ed + 2;
        }
        else if (ed + 1 == n - 1)
        {
            int itr1 = st;
            int itr2 = ed + 1;
            while (itr1 < itr2)
            {
                swap(s[itr1], s[itr2]);
                itr1 ++;
                itr2 --;
            }
        }
    }
}

int main()
{
    char s[15] = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    int n = 15;
    rev(s, n);
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    
    return 0;
}