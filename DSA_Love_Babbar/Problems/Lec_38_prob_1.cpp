/*
    Phone Keypad problem

    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the
    number could represent. Return the answer in any order.
    A mapping of digits to letters (just like on the telephone buttons) is given below.
    Note that 1 does not map to any letters.

    Example :

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Input: digits = ""
    Output: []

    Input: digits = "2"
    Output: ["a","b","c"]
*/

#include <bits/stdc++.h>
using namespace std;

void letterCombinationsRecur(string digits, int idx, string out, vector<string> &ans, vector<string> &reff)
{
    // base case
    if (idx >= digits.length())
    {
        ans.push_back(out);
        return;
    }

    int num = digits[idx] - '0';
    string ref_str = reff[num];

    for (int i = 0; i < ref_str.length(); i++)
    {
        out.push_back(ref_str[i]);
        letterCombinationsRecur(digits, idx + 1, out, ans, reff);
        out.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string out;
    int idx = 0;

    // reference string
    vector<string> reff = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (digits.length() == 0)
    {
        return ans;
    }

    letterCombinationsRecur(digits, idx, out, ans, reff);

    return ans;
}

int main()
{
    string digits;
    cout << "Enter the digits between 2 to 9 : ";
    getline(cin, digits);

    vector<string> A = letterCombinations(digits);

    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}