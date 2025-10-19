/*
    Best Time to Buy and Sell Stock with Transaction Fee

    You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

    Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

    Note:

    You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
    The transaction fee is only charged once for each stock purchase and sale.
    

    Example 1:

    Input: prices = [1,3,2,8,4,9], fee = 2
    Output: 8
    Explanation: The maximum profit can be achieved by:
    - Buying at prices[0] = 1
    - Selling at prices[3] = 8
    - Buying at prices[4] = 4
    - Selling at prices[5] = 9
    The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
    Example 2:

    Input: prices = [1,3,7,5,10,3], fee = 3
    Output: 6
    

    Constraints:

    1 <= prices.length <= 5 * 10^4
    1 <= prices[i] < 5 * 10^4
    0 <= fee < 5 * 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(int i, int buy, int fee, vector<int> &prices)
{
    if (i >= prices.size())
    {
        return 0;
    }

    int profit = 0;
    if (buy == 1)
    {
        int buyStock = -prices[i] + solveRecur(i + 1, 0, fee, prices);
        int skipStock = solveRecur(i + 1, 1, fee, prices);
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] - fee + solveRecur(i + 1, 1, fee, prices);
        int skipStock = solveRecur(i + 1, 0, fee, prices);
        profit = max(sellStock, skipStock);
    }
    return profit;
}

// Recursion + Memoization
int solveRM(int i, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp)
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
    if (buy == 1)
    {
        int buyStock = -prices[i] + solveRM(i + 1, 0, fee, prices, dp);
        int skipStock = solveRM(i + 1, 1, fee, prices, dp);
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] - fee + solveRM(i + 1, 1, fee, prices, dp);
        int skipStock = solveRM(i + 1, 0, fee, prices, dp);
        profit = max(sellStock, skipStock);
    }
    return dp[i][buy] = profit;
}

// Tabulation
int solveTab(int n, int fee, vector<int> &prices)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy == 1)
            {
                int buyStock = -prices[i] + dp[i + 1][0];
                int skipStock = dp[i + 1][1];
                profit = max(buyStock, skipStock);
            }
            else
            {
                int sellStock = prices[i] - fee + dp[i + 1][1];
                int skipStock = dp[i + 1][0];
                profit = max(sellStock, skipStock);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

// Space Optimization
int solveSO(int n, int fee, vector<int> &prices)
{
    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy == 1)
            {
                int buyStock = -prices[i] + next[0];
                int skipStock = next[1];
                profit = max(buyStock, skipStock);
            }
            else
            {
                int sellStock = prices[i] - fee + next[1];
                int skipStock = next[0];
                profit = max(sellStock, skipStock);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();

    // Recursion
    // return solveRecur(0, 1, fee, prices);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return solveRM(0, 1, fee, prices, dp);

    // Tabulation
    // return solveTab(n, fee, prices);

    // Space Optimization
    return solveSO(n, fee, prices);
}

int main()
{
    int fee = 3;
    vector<int> prices = {1, 3, 7, 5, 10, 3};

    cout << maxProfit(prices, fee) << endl;
    return 0;
}