/*
    Best Time to Buy and Sell Stock with Cooldown

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



    Example 1:

    Input: prices = [1,2,3,0,2]
    Output: 3
    Explanation: transactions = [buy, sell, cooldown, buy, sell]
    Example 2:

    Input: prices = [1]
    Output: 0


    Constraints:

    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int buy, int n, vector<int> &prices)
{
    if (i >= n)
        return 0;

    int profit = 0;
    if (buy) // if already bought
    {
        int buyStock = -prices[i] + solveRecur(i + 1, 0, n, prices); // sell
        int skipStock = solveRecur(i + 1, 1, n, prices);             // skip
        profit = max(buyStock, skipStock);
    }
    else // if not bought
    {
        int sellStock = prices[i] + solveRecur(i + 2, 1, n, prices); // buy
        int skipStock = solveRecur(i + 1, 0, n, prices);             // skip
        profit = max(sellStock, skipStock);
    }
    return profit;
}

int solveRM(int i, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;
    if (buy) // if already bought
    {
        int buyStock = -prices[i] + solveRM(i + 1, 0, n, prices, dp); // sell
        int skipStock = solveRM(i + 1, 1, n, prices, dp);             // skip
        profit = max(buyStock, skipStock);
    }
    else // if not bought
    {
        int sellStock = prices[i] + solveRM(i + 2, 1, n, prices, dp); // buy
        int skipStock = solveRM(i + 1, 0, n, prices, dp);             // skip
        profit = max(sellStock, skipStock);
    }

    dp[i][buy] = profit;
    return dp[i][buy];
}

int solveTab(int n, vector<int> &prices)
{
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy) // if already bought
            {
                int buyStock = -prices[i] + dp[i + 1][0]; // sell
                int skipStock = dp[i + 1][1];             // skip
                profit = max(buyStock, skipStock);
            }
            else // if not bought
            {
                int sellStock = prices[i] + dp[i + 2][1]; // buy
                int skipStock = dp[i + 1][0];             // skip
                profit = max(sellStock, skipStock);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    // Recursion
    // return solveRecur(0, 1, n, prices);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return solveRM(0, 1, n, prices, dp);

    // Tabulation
    return solveTab(n, prices);
}

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}