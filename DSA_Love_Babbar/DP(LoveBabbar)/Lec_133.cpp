/*
    Best Time to Buy and Sell Stock IV

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

    Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and
    sell at most k times.

    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    Example 1:

    Input: k = 2, prices = [2,4,1]
    Output: 2
    Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

    Example 2:

    Input: k = 2, prices = [3,2,6,5,0,3]
    Output: 7
    Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and
    sell on day 6 (price = 3), profit = 3-0 = 3.

    Constraints:

    1 <= k <= 100
    1 <= prices.length <= 1000
    0 <= prices[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(int i, int transaction, int k, vector<int> &prices)
{
    if (i == prices.size() || transaction == 2 * k)
    {
        return 0;
    }

    int profit = 0;
    // buy at even transaction, sell at odd transaction
    if (!(transaction & 1))
    {
        int buyStock = -prices[i] + solveRecur(i + 1, transaction + 1, k, prices);
        int skipStock = solveRecur(i + 1, transaction, k, prices);
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] + solveRecur(i + 1, transaction + 1, k, prices);
        int skipStock = solveRecur(i + 1, transaction, k, prices);
        profit = max(sellStock, skipStock);
    }
    return profit;
}

// Recursion + Memoization
int solveRM(int i, int transaction, int k, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == prices.size() || transaction == 2 * k)
    {
        return 0;
    }
    if (dp[i][transaction] != -1)
    {
        return dp[i][transaction];
    }

    int profit = 0;
    // buy at even transaction, sell at odd transaction
    if (!(transaction & 1))
    {
        int buyStock = -prices[i] + solveRM(i + 1, transaction + 1, k, prices, dp);
        int skipStock = solveRM(i + 1, transaction, k, prices, dp);
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] + solveRM(i + 1, transaction + 1, k, prices, dp);
        int skipStock = solveRM(i + 1, transaction, k, prices, dp);
        profit = max(sellStock, skipStock);
    }
    return dp[i][transaction] = profit;
}

// Tabulation
int solveTab(int k, int n, vector<int> &prices)
{
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
        {
            int profit = 0;
            // buy at even transaction, sell at odd transaction
            if (!(transaction & 1))
            {
                int buyStock = -prices[i] + dp[i + 1][transaction + 1];
                int skipStock = dp[i + 1][transaction];
                profit = max(buyStock, skipStock);
            }
            else
            {
                int sellStock = prices[i] + dp[i + 1][transaction + 1];
                int skipStock = dp[i + 1][transaction];
                profit = max(sellStock, skipStock);
            }
            dp[i][transaction] = profit;
        }
    }
    return dp[0][0];
}

// Space Optimization
int solveSO(int k, int n, vector<int> &prices)
{
    vector<int> next(2 * k + 1, 0);
    vector<int> curr(2 * k + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
        {
            int profit = 0;
            // buy at even transaction, sell at odd transaction
            if (!(transaction & 1))
            {
                int buyStock = -prices[i] + next[transaction + 1];
                int skipStock = next[transaction];
                profit = max(buyStock, skipStock);
            }
            else
            {
                int sellStock = prices[i] + next[transaction + 1];
                int skipStock = next[transaction];
                profit = max(sellStock, skipStock);
            }
            curr[transaction] = profit;
        }
        next = curr;
    }
    return next[0];
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    // Recursion
    // return solveRecur(0, 0, k, prices);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(2*k, -1));
    // return solveRM(0, 0, k, prices, dp);

    // Tabulation
    // return solveTab(k, n, prices);

    // Space Optimization
    return solveSO(k, n, prices);
}

int main()
{
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << maxProfit(k, prices) << endl;
    return 0;
}