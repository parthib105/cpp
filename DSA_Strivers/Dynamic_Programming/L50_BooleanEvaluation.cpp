/*
    Boolean Evaluation

    You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).

    Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.

    As the answer can be very large, return the output modulo 1000000007.

    Note :

    ‘T’ will represent the operand TRUE.
    ‘F’ will represent the operand FALSE.
    ‘|’ will represent the operator OR.
    ‘&’ will represent the operator AND.
    ‘^’ will represent the operator XOR.
    Example :

    Input: 'exp’ = "T|T & F".

    Output: 1

    Explanation:
    There are total 2  ways to parenthesize this expression:
        (i) (T | T) & (F) = F
        (ii) (T) | (T & F) = T
    Out of 2 ways, one will result in True, so we will return 1.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1 :
    T^T^F    
    Sample Output 1 :
    0
    Explanation For Sample Input 1:
    There are total 2  ways to parenthesize this expression:
    (i) (T^T)^(F) = F
    (ii) (T)^(T^F) = F
    Both ways will result in False, so we will return 0.
    Sample Input 2 :
    F|T^F
    Sample Output 2 :
    2
    Explanation For Sample Input 2:
    For the first test case:
    There are total 2  ways to parenthesize this expression:
    (i) (F|T)^(F) = T
    (ii) (F)|(T^F) = T
    Both ways will result in True, so we will return 2.
    Expected time complexity
    The expected time complexity is O(n ^ 3), where 'n' denotes the length of 'exp'.
    Constraints:
    3 <= |‘exp’| <= 200
    Where |'exp'| denotes the length of 'exp'.

    Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9 + 7;
int solveRecur(int i, int j, int isTrue, string& exp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    ll ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        ll lt = solveRecur(i, k - 1, 1, exp);
        ll lf = solveRecur(i, k - 1, 0, exp);
        ll rt = solveRecur(k + 1, j, 1, exp);
        ll rf = solveRecur(k + 1, j, 0, exp);

        if (exp[k] == '&')
        {
            if (isTrue)
                ways = (ways + (lt * rt)%MOD)%MOD;
            else
                ways = (ways + (lt * rf)%MOD + (lf * rt)%MOD + (lf * rf)%MOD)%MOD;
        }
        else if (exp[k] == '|')
        {
            if (isTrue)
                ways = (ways + (lt * rf)%MOD + (lf * rt)%MOD + (lt * rt)%MOD)%MOD;
            else
                ways = (ways + (lf * rf)%MOD)%MOD;
        }
        else
        {
            if (isTrue)
                ways = (ways + (lt * rf)%MOD + (lf * rt)%MOD)%MOD;
            else
                ways = (ways + (lt * rt)%MOD + (lf * rf)%MOD)%MOD;
        }
    }
    return ways;
}

int solveRM(int i, int j, int isTrue, string& exp, vector<vector<vector<ll>>>& dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    ll ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        ll lt = solveRM(i, k - 1, 1, exp, dp);
        ll lf = solveRM(i, k - 1, 0, exp, dp);
        ll rt = solveRM(k + 1, j, 1, exp, dp);
        ll rf = solveRM(k + 1, j, 0, exp, dp);

        if (exp[k] == '&')
        {
            if (isTrue)
                ways = (ways + (lt * rt)%MOD)%MOD;
            else
                ways = (ways + (lt * rf)%MOD + (lf * rt)%MOD + (lf * rf)%MOD)%MOD;
        }
        else if (exp[k] == '|')
        {
            if (isTrue)
                ways = (ways + (lt * rf)%MOD + (lf * rt)%MOD + (lt * rt)%MOD)%MOD;
            else
                ways = (ways + (lf * rf)%MOD)%MOD;
        }
        else
        {
            if (isTrue)
                ways = (ways + (lt * rf)%MOD + (lf * rt)%MOD)%MOD;
            else
                ways = (ways + (lt * rt)%MOD + (lf * rf)%MOD)%MOD;
        }
    }
    dp[i][j][isTrue] = ways;
    return dp[i][j][isTrue];
}

int solveTab(int n, string& exp)
{
    vector<vector<vector<ll>>>dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            if (i > j)  // Base case 1: i > j is an invalid case, so continue.
                continue;

            for (int isTrue = 0; isTrue <= 1; isTrue ++)
            {
                if (i == j)     // Base case 2: i == j, evaluate the single character.
                {
                    if (isTrue)
                        dp[i][j][isTrue] = exp[i] == 'T';
                    else
                        dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                ll ways = 0;
                for (int k = i + 1; k <= j - 1; k += 2)
                {
                    ll lt = dp[i][k - 1][1];
                    ll lf = dp[i][k - 1][0];
                    ll rt = dp[k + 1][j][1];
                    ll rf = dp[k + 1][j][0];

                    if (exp[k] == '&')
                    {
                        if (isTrue)
                            ways = (ways + (lt * rt)%MOD)%MOD;
                        else
                            ways = (ways + (lt * rf)%MOD + (lf * rt)%MOD + (lf * rf)%MOD)%MOD;
                    }
                    else if (exp[k] == '|')
                    {
                        if (isTrue)
                            ways = (ways + (lt * rf)%MOD + (lf * rt)%MOD + (lt * rt)%MOD)%MOD;
                        else
                            ways = (ways + (lf * rf)%MOD)%MOD;
                    }
                    else
                    {
                        if (isTrue)
                            ways = (ways + (lt * rf)%MOD + (lf * rt)%MOD)%MOD;
                        else
                            ways = (ways + (lt * rt)%MOD + (lf * rf)%MOD)%MOD;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}

int evaluateExp(string & exp) 
{
    int n = exp.size();

    // Recursion
    // return solveRecur(0, n - 1, 1, exp);

    // Recursion + Memoization
    // vector<vector<vector<ll>>>dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    // return solveRM(0, n - 1, 1, exp, dp);

    // Tabulation
    return solveTab(n, exp);
}

int main()
{
    string exp = "F^F^F^F&T|T|F|T|F|F|T|T|T|T&T|T|T&T|F&T|F|T|T|T^T|F^T|T&F^T|F|T|F|T&T|T^F|F^T&T^T&T^T&T^T&F&T^F|F^T|T|F|F^F|F&F|F|T&F&F";
    cout << evaluateExp(exp) << endl;
    return 0;
}