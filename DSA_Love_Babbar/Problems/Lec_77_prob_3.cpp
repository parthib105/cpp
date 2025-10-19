/*
    Reorganize String

    Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

    Return any possible rearrangement of s or return "" if not possible.

    Example 1:

    Input: s = "aab"
    Output: "aba"
    Example 2:

    Input: s = "aaab"
    Output: ""
*/

#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    string str = "";

    // count frequency and store it
    map<char, int> freqMap;
    for (char ch : s)
    {
        freqMap[ch]++;
    }

    // priority queue to arrange them in maxorder
    priority_queue<pair<int, char>> pq;

    map<char, int>::iterator it = freqMap.begin();
    while (it != freqMap.end())
    {
        pq.push(make_pair(it->second, it->first));
        it++;
    }

    // to store prev values
    pair<int, char> prev = make_pair(-1, '*');

    while (!pq.empty())
    {
        // pick the top element
        pair<int, char> curr = pq.top();
        pq.pop();

        // append it to temporary strinf=g
        str += curr.second;

        // if prev frequency is valid put it to heap
        if (prev.first > 0)
        {
            pq.push(prev);
        }

        // decrease the freq
        curr.first -= 1;
        prev = curr;
    }

    return (str.size() == s.size()) ? str : "";
}

int main()
{
    string s = "aaabc";
    cout << reorganizeString(s) << endl;
    return 0;
}