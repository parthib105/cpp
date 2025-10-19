/*
    For a string s which consists only characters '0' and '1', find the number of subsequences of length 5 which are palindromes. 
    As the answer can be really big, return the answer mod(10^9 + 7) 

    Note:
    1. A palindrome is a string the reads the same backward as forward.
    2. A subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements.
    3. Two subsequences are considered different if the indices of the string the forms the subsequences are different.

    Example:
    s = "0100110"

    5 subsequences are
    1. indices (0, 1, 2, 5, 6) -> 01010
    2. indices (0, 1, 2, 4, 6) -> 01010
    3. indices (0, 1, 3, 5, 6) -> 01010
    4. indices (0, 1, 3, 4, 6) -> 01010
    5. indices (0, 1, 4, 5, 6) -> 01110
*/

#include<bits/stdc++.h>
using namespace std;

int countPalindromes(string s)
{
    int n = s.length();
    const int m = 1e9 + 7;

    // count of 0's and 1's before current index
    vector<int> pre0(n, 0), pre1(n, 1);

    // count of 0's and 1's after current index
    vector<int> suf0(n, 0), suf1(n, 1);

    // calculate prefix counts
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            pre0[i] = pre0[i - 1];
            pre1[i] = pre1[i - 1];
        }

        if (s[i] == '0')
        {
            pre0[i] ++;
        }
        else
        {
            pre1[i] ++;
        }
    }

    // calculate suffix counts
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
        {
            suf0[i] = suf0[i + 1];
            suf1[i] = suf1[i + 1];
        }

        if (s[i] == '0')
        {
            suf0[i] ++;
        }
        else
        {
            suf1[i] ++;
        }
    }

    long long res = 0;

    // iterate over the middle elements
    for (int i = 2; i < n - 2; i++)
    {
        long long left0 = pre0[i - 1];
        long long left1 = pre1[i - 1];
        long long right0 = suf0[i + 1];
        long long right1 = suf1[i + 1];

        res = (res + (left0 * right0) % m) % m;
        res = (res + (left1 * right1) % m) % m;
    }
    return res;
}

int main()
{
    cout << countPalindromes("0100110") << endl;
    return 0;
}