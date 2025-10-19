/*
    Remove K Digits

    Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

    Example 1:

    Input: num = "1432219", k = 3
    Output: "1219"
    Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
    Example 2:

    Input: num = "10200", k = 1
    Output: "200"
    Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
    Example 3:

    Input: num = "10", k = 2
    Output: "0"
    Explanation: Remove all the digits from the number and it is left with nothing which is 0.
    

    Constraints:

    1 <= k <= num.length <= 10^5
    num consists of only digits.
    num does not have any leading zeros except for the zero itself.
*/

#include<bits/stdc++.h>
using namespace std;

string removeLeadingZeros(int n, string s)
{
    int i = 0;
    while (i < n && s[i] == '0')
    {
        i ++;
    }
    if (i == n)
        return "0";
    return s.substr(i, string::npos);
}

string removeKdigits(string num, int k) 
{
    int n = num.size();
    string st = "";

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && k > 0 && (st.back() - '0') > (num[i] - '0'))
        {
            st.pop_back();
            k --;
        }
        st.push_back(num[i]);
    } 

    while (!st.empty() && k > 0)
    {
        st.pop_back();
        k --;
    }  

    if (st.empty())
        return "0";
    
    return removeLeadingZeros(st.size(), st);
}

int main()
{
    string num = "1029090";
    int k = 1;

    cout << removeKdigits(num, k) << endl;
    return 0;
}