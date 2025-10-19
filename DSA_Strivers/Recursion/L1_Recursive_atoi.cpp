/*
    String to Integer (atoi)

    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

    The algorithm for myAtoi(string s) is as follows:

    Whitespace: Ignore any leading whitespace (" ").
    Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
    Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
    Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
    Return the integer as the final result.

    
    Example 1:

    Input: s = "42"

    Output: 42

    Explanation:

    The underlined characters are what is read in and the caret is the current reader position.
    Step 1: "42" (no characters read because there is no leading whitespace)
            ^
    Step 2: "42" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "42" ("42" is read in)
            ^
    Example 2:

    Input: s = " -042"

    Output: -42

    Explanation:

    Step 1: "   -042" (leading whitespace is read and ignored)
                ^
    Step 2: "   -042" ('-' is read, so the result should be negative)
                ^
    Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
                ^
    Example 3:

    Input: s = "1337c0d3"

    Output: 1337

    Explanation:

    Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
            ^
    Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
                ^
    Example 4:

    Input: s = "0-1"

    Output: 0

    Explanation:

    Step 1: "0-1" (no characters read because there is no leading whitespace)
            ^
    Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
            ^
    Example 5:

    Input: s = "words and 987"

    Output: 0

    Explanation:

    Reading stops at the first non-digit character 'w'.


    Constraints:

    0 <= s.length <= 200
    s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/

#include<bits/stdc++.h>
using namespace std;

string removeWhiteSpaces(int n, string s)
{
    int i = 0;
    for (; i < n; i++)
    {
        if (s[i] != ' ')
            break;
    }
    return s.substr(i, string::npos);
}

pair<string, bool> makeValid(string s)
{
    bool isNeg = false;

    // Step 1 : remove leading white spaces
    s = removeWhiteSpaces(s.length(), s);

    // Step 2 : check for signed num
    if (s[0] == '-' || s[0] == '+')
    {
        if (s[0] == '-')
            isNeg = true;
        s = s.substr(1, string::npos);
    }

    return {s, isNeg};
}

bool isValid(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

int iterSol(int i, int n, bool isNeg, string& s)
{
    int res = 0;
    while (i < n)
    {
        if (!isValid(s[i]))
            break;

        int d = s[i] - '0';
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && d > INT_MAX % 10)) {
            return isNeg ? INT_MIN : INT_MAX;
        }
        res = 10 * res + d;
        i += 1;
    }
    if (isNeg)
        return (-1) * res;
    return res;
}

long long recurSol(int i, int n, bool isNeg, long long num, string& s)
{
    if (i >= n || !isValid(s[i]))
    {
        if (isNeg)
            return (-1) * num;
        else
            return num;
    }

    int d = s[i] - '0';
    num = num * 10 + d;

    long long val = num;
    if (isNeg)
        val = (-1) * num;
    if (val > INT_MAX)
        return INT_MAX;
    if (val < INT_MIN)
        return INT_MIN;
    
        return recurSol(i + 1, n, isNeg, num, s);
}

int myAtoi(string s)
{
    pair<string, bool> clean = makeValid(s);

    string str = clean.first;
    bool isNeg = clean.second;

    int i = 0;
    int n = str.length();

    // ignore the leading zeros
    for (; i < n; i++)
    {
        if (str[i] != '0')
            break;
    }

    // Iterative solution
    // return iterSol(i, n, isNeg, str);

    // Recursive Solution
    return recurSol(0, n, isNeg, 0, str);
}

int main()
{
    string s = "1337c0d3";
    cout << myAtoi(s) << endl;
    return 0;
}