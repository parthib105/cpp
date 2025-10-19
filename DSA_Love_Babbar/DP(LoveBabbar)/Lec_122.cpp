/*
    Dice throw

    Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when
    all the dice are thrown.

    Example:

    Input: m = 6, n = 3, x = 12
    Output: 25
    Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.

    Input: m = 2, n = 3, x = 6
    Output: 1
    Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land
    on 2.

    Expected Time Complexity: O(m*n*x)
    Expected Auxiliary Space: O(n*x)

    Constraints:
    1 <= m,n,x <= 50
*/

#include <bits/stdc++.h>
using namespace std;

long long solveRecur(int dice, int faces, int target)
{
    if (target < 0)
    {
        return 0;
    }
    else if (dice == 0 && target == 0)
    {
        return 1;
    }
    else if (dice == 0 && target != 0)
    {
        return 0;
    }
    else if (dice != 0 && target == 0)
    {
        return 0;
    }

    long long ans = 0;
    for (int face = 1; face <= faces; face++)
    {
        ans += solveRecur(dice - 1, faces, target - face);
    }
    return ans;
}

long long solveRM(int dice, int faces, int target, vector<vector<long long>> &dp)
{
    if (target < 0)
    {
        return 0;
    }
    else if (dice == 0 && target == 0)
    {
        return 1;
    }
    else if (dice == 0 && target != 0)
    {
        return 0;
    }
    else if (dice != 0 && target == 0)
    {
        return 0;
    }

    if (dp[dice][target] != -1)
    {
        return dp[dice][target];
    }

    long long ans = 0;
    for (int face = 1; face <= faces; face++)
    {
        ans += solveRM(dice - 1, faces, target - face, dp);
    }
    dp[dice][target] = ans;
    return dp[dice][target];
}

// Tabulation
long long solveTab(int n, int m, int x)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
    dp[0][0] = 1;

    for (int dice = 1; dice <= n; dice ++)
    {
        for (int target = 1; target <= x; target++)
        {
            long long ans = 0;
            for (int face = 1; face <= m; face++)
            {
                if (target - face >= 0)
                {
                    ans = ans + dp[dice - 1][target - face];
                }
            }
            dp[dice][target] = ans;
        }
    }
    return dp[n][x];
}

// Space Optimization
long long solveSO(int n, int m, int x)
{
    vector<long long> prev(x + 1, 0);
    vector<long long> curr(x + 1, 0);
    prev[0] = 1;

    for (int dice = 1; dice <= n; dice ++)
    {
        for (int target = 1; target <= x; target++)
        {
            long long ans = 0;
            for (int face = 1; face <= m; face++)
            {
                if (target - face >= 0)
                {
                    ans = ans + prev[target - face];
                }
            }
            curr[target] = ans;
        }
        prev = curr;
    }
    return prev[x];
}

long long noOfWays(int m, int n, int x)
{
    // Recursive Solution
    // return solveRecur(n, m, x);

    // Recursion + Memoization
    // vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, -1));
    // return solveRM(n, m, x, dp);

    // Tabulation
    return solveTab(n, m, x);
}

int main()
{
    int m = 6, n = 3, x = 12;
    cout << noOfWays(m, n, x) << endl;
    return 0;
}