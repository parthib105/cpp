/*
    Coin Change

    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.



    Example 1:

    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
    Example 2:

    Input: coins = [2], amount = 3
    Output: -1
    Example 3:

    Input: coins = [1], amount = 0
    Output: 0


    Constraints:

    1 <= coins.length <= 12
    1 <= coins[i] <= 2^31 - 1
    0 <= amount <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int target, vector<int> &coins)
{
    if (i == 0)
    {
        if (target % coins[i] == 0)
            return target / coins[i];
        return INT_MAX;
    }

    // skip the coin
    int exc = solveRecur(i - 1, target, coins);

    // pick the coin
    int inc = INT_MAX;
    if (coins[i] <= target)
    {
        int currInc = solveRecur(i, target - coins[i], coins);
        if (currInc != INT_MAX)
            inc = 1 + currInc;
    }

    return min(inc, exc);
}

int solveRM(int i, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (target % coins[i] == 0)
            return target / coins[i];
        return 1e9;
    }
    if (dp[i][target] != -1)
        return dp[i][target];

    // skip the coin
    int exc = solveRM(i - 1, target, coins, dp);

    // pick the coin
    int inc = INT_MAX;
    if (coins[i] <= target)
        inc = 1 + solveRM(i, target - coins[i], coins, dp);

    dp[i][target] = min(inc, exc);
    return dp[i][target];
}

int solveTab(int n, int amount, vector<int> &coins)
{
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // base case
    for (int t = 0; t <= amount; t++)
    {
        if (t % coins[0] == 0)
            dp[0][t] = t / coins[0];
        else
            dp[0][t] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= amount; t++)
        {
            // skip the coin
            int exc = dp[i - 1][t];

            // pick the coin
            int inc = INT_MAX;
            if (coins[i] <= t)
                inc = 1 + dp[i][t - coins[i]];

            dp[i][t] = min(inc, exc);
        }
    }
    return dp[n - 1][amount];
}

int solveSO(int n, int amount, vector<int> &coins)
{
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    // base case
    for (int t = 0; t <= amount; t++)
    {
        if (t % coins[0] == 0)
            prev[t] = t / coins[0];
        else
            prev[t] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= amount; t++)
        {
            // skip the coin
            int exc = prev[t];

            // pick the coin
            int inc = INT_MAX;
            if (coins[i] <= t)
                inc = 1 + curr[t - coins[i]];

            curr[t] = min(inc, exc);
        }
        prev = curr;
    }
    return prev[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size(), ans;

    // Recursion
    // ans = solveRecur(n - 1, amount, coins);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // ans = solveRM(n - 1, amount, coins, dp);

    // Tabulation
    // ans = solveTab(n, amount, coins);

    // Space Optimization
    ans = solveSO(n, amount, coins);

    if (ans >= 1e9)
        return -1;
    return ans;
}

int main()
{
    int amount = 11;
    vector<int> coins = {1, 2, 5};

    cout << coinChange(coins, amount) << endl;
    return 0;
}