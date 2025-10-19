/*
    Best Time to Buy and Sell Stock II

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

    On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

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

int solveRecur(int i, bool buy, int n, vector<int> &prices)
{
    if (i == n)
        return 0;

    int profit = 0;
    if (buy) // if already bought
    {
        int opt1 = -prices[i] + solveRecur(i + 1, false, n, prices); // sell
        int opt2 = solveRecur(i + 1, true, n, prices);               // skip
        profit = max(opt1, opt2);
    }
    else // if not bought
    {
        int opt1 = prices[i] + solveRecur(i + 1, true, n, prices); // buy
        int opt2 = solveRecur(i + 1, false, n, prices);            // skip
        profit = max(opt1, opt2);
    }
    return profit;
}

int solveRM(int i, bool buy, int n, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;
    if (buy) // if already bought
    {
        int opt1 = -prices[i] + solveRM(i + 1, false, n, prices, dp); // sell
        int opt2 = solveRM(i + 1, true, n, prices, dp);               // skip
        profit = max(opt1, opt2);
    }
    else // if not bought
    {
        int opt1 = prices[i] + solveRM(i + 1, true, n, prices, dp); // buy
        int opt2 = solveRM(i + 1, false, n, prices, dp);            // skip
        profit = max(opt1, opt2);
    }
    dp[i][buy] = profit;
    return dp[i][buy];
}

int solveTab(int n, vector<int> &prices)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            int profit = 0;
            if (buy) // if already bought
            {
                int opt1 = -prices[i] + dp[i + 1][0]; // sell
                int opt2 = dp[i + 1][1];              // skip
                profit = max(opt1, opt2);
            }
            else // if not bought
            {
                int opt1 = prices[i] + dp[i + 1][1]; // buy
                int opt2 = dp[i + 1][0];             // skip
                profit = max(opt1, opt2);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

int solveSO(int n, vector<int> &prices)
{
    vector<int> next(2, 0), curr(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            int profit = 0;
            if (buy) // if already bought
            {
                int opt1 = -prices[i] + next[0]; // sell
                int opt2 = next[1];              // skip
                profit = max(opt1, opt2);
            }
            else // if not bought
            {
                int opt1 = prices[i] + next[1]; // buy
                int opt2 = next[0];             // skip
                profit = max(opt1, opt2);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

// f(i, buy) -> starting on i-th day, with buy = true, what is the max profit?
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    // Recursion
    // return solveRecur(0, true, n, prices);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return solveRM(0, true, n, prices, dp);

    // Tabulation
    // return solveTab(n, prices);

    // Space Optimization
    return solveSO(n, prices);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}