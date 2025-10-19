/*
    Unbounded Knapsack

    You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.]

    You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.


    Example:
    Input: 
    'n' = 3, 'w' = 10, 
    'profit' = [5, 11, 13]
    'weight' = [2, 4, 6]

    Output: 27

    Explanation:
    We can fill the knapsack as:

    1 item of weight 6 and 1 item of weight 4.
    1 item of weight 6 and 2 items of weight 2.
    2 items of weight 4 and 1 item of weight 2.
    5 items of weight 2.

    The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.


    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:
    3 15
    7 2 4
    5 10 20


    Expected Answer:
    21


    Output on console:
    21


    Explanation of Sample Input 1
    The given knapsack capacity is 15. We can fill the knapsack as [1, 1, 1] giving us profit 21 and as [1,2] giving us profit 9. Thus maximum profit will be 21.


    Sample Input 2
    2 3
    6 12
    4 17


    Expected Answer:
    0


    Output on console:
    0


    Explanation of Sample Input 2:
    We can clearly see that no item has weight less than knapsack capacity. Therefore we can not fill knapsack with any item.


    Expected Time Complexity:
    Try to solve this in O(n*w).


    Constraints
    1 <= n <= 10^3
    1 <= w <= 10^3
    1 <= profit[i] , weight[i] <= 10^8

    Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;

int solveRecur(int i, int W, vector<int>& val, vector<int>& wt)
{
    if (i == 0)
        return (W/wt[i]) * val[i];

    // exclude
    int exc = solveRecur(i - 1, W, val, wt);

    // include
    int inc = INT_MIN;
    if (wt[i] <= W)
        inc = val[i] + solveRecur(i, W - wt[i], val, wt);
    
    return max(inc, exc);
}

int solveRM(int i, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp)
{
    if (i == 0)
        return (W/wt[i]) * val[i];
    if (dp[i][W] != -1)
        return dp[i][W];

    // exclude
    int exc = solveRM(i - 1, W, val, wt, dp);

    // include
    int inc = INT_MIN;
    if (wt[i] <= W)
        inc = val[i] + solveRM(i, W - wt[i], val, wt, dp);
    
    dp[i][W] = max(inc, exc);
    return dp[i][W];
}

int solveTab(int n, int W, vector<int>& val, vector<int>& wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // base case
    for (int w = 0; w <= W; w++)
        dp[0][w] = (w/wt[0]) * val[0];

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // exclude
            int exc = dp[i - 1][w];

            // include
            int inc = INT_MIN;
            if (wt[i] <= w)
                inc = val[i] + dp[i][w - wt[i]];
            
            dp[i][w] = max(inc, exc);
        }
    }
    return dp[n - 1][W];
}

int solveSO(int n, int W, vector<int>& val, vector<int>& wt)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    // base case
    for (int w = 0; w <= W; w++)
        prev[w] = (w/wt[0]) * val[0];

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // exclude
            int exc = prev[w];

            // include
            int inc = INT_MIN;
            if (wt[i] <= w)
                inc = val[i] + curr[w - wt[i]];
            
            curr[w] = max(inc, exc);
        }
        prev = curr;
    }
    return prev[W];
}

int solveSO2(int n, int W, vector<int>& val, vector<int>& wt)
{
    vector<int> prev(W + 1, 0);

    // base case
    for (int w = 0; w <= W; w++)
        prev[w] = (w/wt[0]) * val[0];

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // exclude
            int exc = prev[w];

            // include
            int inc = INT_MIN;
            if (wt[i] <= w)
                inc = val[i] + prev[w - wt[i]];
            
            prev[w] = max(inc, exc);
        }
    }
    return prev[W];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Recursion
    // return solveRecur(n - 1, w, profit, weight);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    // return solveRM(n - 1, w, profit, weight, dp);

    // Tabulation
    // return solveTab(n, w, profit, weight);

    // Space Optimization
    return solveSO(n, w, profit, weight);
}

int main()
{
    int n = 3, w = 15;
    vector<int> profit = {7, 2, 4};
    vector<int> weight = {5, 10, 20};

    cout << unboundedKnapsack(n, w, profit, weight) << endl;
    return 0;
}