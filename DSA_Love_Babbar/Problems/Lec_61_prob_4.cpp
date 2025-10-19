/*
    First non-repeating character in a stream

    Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream,
    you have to tell which character has appeared only once in the stream upto that point. If there are many characters that
    have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character
    then append '#' to the answer.

    NOTE:
    1. You need to find the answer for every i (0 <= i < n)
    2. In order to find the solution for every i you need to consider the string from starting position till ith position.

    Example 1 :

    Input: A = "aabc"
    Output: "a#bb"
    Explanation: For every ith character we will
    consider the string from index 0 till index i first non
    repeating character is as follow-
    "a" - first non-repeating character is 'a'
    "aa" - no non-repeating character so '#'
    "aab" - first non-repeating character is 'b'
    "aabc" - there are two non repeating characters 'b' and 'c',
    first non-repeating character is 'b' because 'b' comes before
    'c' in the stream.

    Example 2:

    Input: A = "zz"
    Output: "z#"
    Explanation: For every character first non
    repeating character is as follow-
    "z" - first non-repeating character is 'z'
    "zz" - no non-repeating character so '#'
*/

#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    unordered_map<char, int> mp;
    queue<char> q;

    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        // increase the count
        mp[A[i]] += 1;

        // push into queue
        q.push(A[i]);

        // checking nexessary conditions
        while (!q.empty())
        {
            // repeating character
            if (mp[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        // if queue is empty, no repeating characters
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    // string A = "aabc";
    string A = "yewaahkpuo";
    string ans = FirstNonRepeating(A);

    cout << ans << endl;
    return 0;
}