/*
    Best Time to Buy and Sell Stock II

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

    On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
    However, you can buy it then immediately sell it on the same day.

    Find and return the maximum profit you can achieve.

    Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Total profit is 4 + 3 = 7.

    Example 2:

    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Total profit is 4.

    Example 3:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

    Constraints:

    1 <= prices.length <= 3 * 10^4
    0 <= prices[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(vector<int> &prices, int i, int buy)
{
    if (i >= prices.size())
    {
        return 0;
    }

    int profit = 0;
    if (buy == 1) // buy stock
    {
        int buyStock = -prices[i] + solveRecur(prices, i + 1, 0); // buy
        int skipStock = solveRecur(prices, i + 1, 1);             // skip
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] + solveRecur(prices, i + 1, 1); // sell
        int skipStock = solveRecur(prices, i + 1, 0);
        profit = max(sellStock, skipStock);
    }
    return profit;
}

// Recursion + Memoization
int solveRM(vector<int> &prices, vector<vector<int>> &dp, int i, int buy)
{
    if (i >= prices.size())
    {
        return 0;
    }
    if (dp[i][buy] != -1)
    {
        return dp[i][buy];
    }

    int profit = 0;
    if (buy == 1) // buy stock
    {
        int buyStock = -prices[i] + solveRM(prices, dp, i + 1, 0); // buy
        int skipStock = solveRM(prices, dp, i + 1, 1);             // skip
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] + solveRM(prices, dp, i + 1, 1); // sell
        int skipStock = solveRM(prices, dp, i + 1, 0);
        profit = max(sellStock, skipStock);
    }
    return dp[i][buy] = profit;
}

// Tabulation
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy == 1) // buy stock
            {
                int buyStock = -prices[i] + dp[i + 1][0]; // buy
                int skipStock = dp[i + 1][1];             // skip
                profit = max(buyStock, skipStock);
            }
            else
            {
                int sellStock = prices[i] + dp[i + 1][1]; // sell
                int skipStock = dp[i + 1][0];
                profit = max(sellStock, skipStock);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

// Space Optimization
int solveSO(vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy == 1) // buy stock
            {
                int buyStock = -prices[i] + next[0]; // buy
                int skipStock = next[1];             // skip
                profit = max(buyStock, skipStock);
            }
            else
            {
                int sellStock = prices[i] + next[1]; // sell
                int skipStock = next[0];
                profit = max(sellStock, skipStock);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    // Recursive
    // return solveRecur(prices, 0, 1);

    // Recursion + Memoization
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solveRM(prices, dp, 0, 1);

    // Tabulation
    // return solveTab(prices);

    // Space Optimization
    return solveSO(prices);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}