/*
    Coin Change II

    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

    You may assume that you have an infinite number of each kind of coin.

    The answer is guaranteed to fit into a signed 32-bit integer.

    Example 1:

    Input: amount = 5, coins = [1,2,5]
    Output: 4
    Explanation: there are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1
    Example 2:

    Input: amount = 3, coins = [2]
    Output: 0
    Explanation: the amount of 3 cannot be made up just with coins of 2.
    Example 3:

    Input: amount = 10, coins = [10]
    Output: 1


    Constraints:

    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int target, vector<int> &coins)
{
    if (i == 0) // can I form a target with the given element
        return target % coins[0] == 0;

    // exclude the coin
    int exc = solveRecur(i - 1, target, coins);

    // include the coin
    int inc = 0;
    if (coins[i] <= target)
        inc = solveRecur(i, target - coins[i], coins);

    return inc + exc;
}

int solveRM(int i, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    if (i == 0) // can I form a target with the given element
        return target % coins[0] == 0;
    if (dp[i][target] != -1)
        return dp[i][target];

    // exclude the coin
    int exc = solveRM(i - 1, target, coins, dp);

    // include the coin
    int inc = 0;
    if (coins[i] <= target)
        inc = solveRM(i, target - coins[i], coins, dp);

    dp[i][target] = inc + exc;
    return dp[i][target];
}

int solveTab(int n, int k, vector<int> &coins)
{
    // use long long to avoid overflow
    vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

    // base case
    for (int t = 0; t <= k; t++)
        dp[0][t] = (t % coins[0] == 0);

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= k; t++)
        {
            long long exc = dp[i - 1][t];
            long long inc = 0;
            if (coins[i] <= t)
                inc = dp[i][t - coins[i]];

            dp[i][t] = inc + exc;
        }
    }
    return (int)dp[n - 1][k]; // safe cast at the end
}

int solveSO(int n, int k, vector<int> &coins)
{
    // use long long to avoid overflow
    vector<long long> prev(k + 1, 0), curr(k + 1, 0);

    // base case
    for (int t = 0; t <= k; t++)
        prev[t] = (t % coins[0] == 0);

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= k; t++)
        {
            long long exc = prev[t];
            long long inc = 0;
            if (coins[i] <= t)
                inc = curr[t - coins[i]];

            curr[t] = inc + exc;
        }
        prev = curr;
    }
    return (int)prev[k]; // safe cast at the end
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();

    // Recursion
    // return solveRecur(n - 1, amount, coins);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // return solveRM(n - 1, amount, coins, dp);

    // Tabulation
    // return solveTab(n, amount, coins);

    // Space optimization
    return solveSO(n, amount, coins);
}

int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    cout << change(amount, coins) << endl;
    return 0;
}