/*
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    Find the maximum profit you can achieve. You may complete at most two transactions.

    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    

    Example 1:

    Input: prices = [3,3,5,0,0,3,1,4]
    Output: 6
    Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
    Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
    Example 2:

    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
    Example 3:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.
    

    Constraints:

    1 <= prices.length <= 10^5
    0 <= prices[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(vector<int> &prices, int i, int buy, int limit)
{
    if (i >= prices.size() || limit == 0)
    {
        return 0;
    }

    int profit = 0;
    if (buy)
    {
        int buyStock = -prices[i] + solveRecur(prices, i + 1, 0, limit);
        int skipStock = solveRecur(prices, i + 1, 1, limit);
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] + solveRecur(prices, i + 1, 1, limit - 1);
        int skipStock = solveRecur(prices, i + 1, 0, limit);
        profit = max(sellStock, skipStock);
    }
    return profit;
}

// Recursion + Memoization
int solveRM(vector<int> &prices, vector<vector<vector<int>>> &dp, int i, int buy, int limit)
{
    if (i >= prices.size() || limit == 0)
    {
        return 0;
    }
    if (dp[i][buy][limit] != -1)
    {
        return dp[i][buy][limit];
    }

    int profit = 0;
    if (buy == 1)
    {
        int buyStock = -prices[i] + solveRM(prices, dp, i + 1, 0, limit);
        int skipStock = solveRM(prices, dp, i + 1, 1, limit);
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] + solveRM(prices, dp, i + 1, 1, limit - 1);
        int skipStock = solveRM(prices, dp, i + 1, 0, limit);
        profit = max(sellStock, skipStock);
    }
    return dp[i][buy][limit] = profit;
}

// Tabulation
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < 3; limit++)
            {
                int profit = 0;
                if (buy == 1)
                {
                    int buyStock = -prices[i] + dp[i + 1][0][limit];
                    int skipStock = dp[i + 1][1][limit];
                    profit = max(buyStock, skipStock);
                }
                else
                {
                    int sellStock = prices[i] + dp[i + 1][1][limit - 1];
                    int skipStock = dp[i + 1][0][limit];
                    profit = max(sellStock, skipStock);
                }
                dp[i][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}

// Space Optimization
int solveSO(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < 3; limit++)
            {
                int profit = 0;
                if (buy == 1)
                {
                    int buyStock = -prices[i] + next[0][limit];
                    int skipStock = next[1][limit];
                    profit = max(buyStock, skipStock);
                }
                else
                {
                    int sellStock = prices[i] + next[1][limit - 1];
                    int skipStock = next[0][limit];
                    profit = max(sellStock, skipStock);
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][2];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // Recursion
    // return solveRecur(prices, 0, 1, 2);

    // Recursion + Memoization
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // return solveRM(prices, dp, 0, 1, 2);

    // Tabulation
    // return solveTab(prices);

    // Space Optimization
    return solveSO(prices);
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}