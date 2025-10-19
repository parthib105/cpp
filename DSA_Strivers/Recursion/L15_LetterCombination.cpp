/*
    Letter Combinations of a Phone Number

    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


    Example 1:

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    Example 2:

    Input: digits = ""
    Output: []
    Example 3:

    Input: digits = "2"
    Output: ["a","b","c"]
    
    Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
*/

#include<bits/stdc++.h>
using namespace std;

void solveRecur(int i, string digits, string combs, vector<string>& res, vector<string>& ref)
{
    if (i >= digits.length())
    {
        res.push_back(combs);
        return;
    }

    int currDigit = digits[i] - '0';
    string ref_str = ref[currDigit];
    for (char ch : ref_str)
    {
        combs.push_back(ch);
        solveRecur(i + 1, digits, combs, res, ref);
        combs.pop_back();
    }

}

vector<string> letterCombinations(string digits)
{
    vector<string> ref = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> res;
    string combs;

    if (digits.length() == 0)
        return res;

    solveRecur(0, digits, combs, res, ref);
    return res;
    
}

int main()
{
    string digits = "23";
    vector<string> res = letterCombinations(digits);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        if (i == res.size() - 1)
            cout << res[i];
        else
            cout << res[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}