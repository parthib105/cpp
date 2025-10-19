/*
    0 - 1 Knapsack Problem

    Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized.

    Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

    Examples :

    Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
    Output: 3
    Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
    Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6]
    Output: 0
    Explanation: Every item has a weight exceeding the knapsack's capacity (3).
    Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3]
    Output: 80
    Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
    Constraints:
    2 ≤ val.size() = wt.size() ≤ 10^3
    1 ≤ W ≤ 10^3
    1 ≤ val[i] ≤ 10^3
    1 ≤ wt[i] ≤ 10^3
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(2^n), S.C. : O(n) (stack space)
int solveRecur(int i, int W, vector<int> &val, vector<int> &wt)
{
    if (i == 0)
    {
        if (wt[i] <= W)
            return val[i];
        return 0;
    }

    // exclude the item
    int exc = solveRecur(i - 1, W, val, wt);

    // include
    int inc = INT_MIN;
    if (wt[i] <= W)
        inc = val[i] + solveRecur(i - 1, W - wt[i], val, wt);

    return max(inc, exc);
}

// T.C. : O(N x W), S.C. : O(N x W) + O(N) (stack space)
int solveRM(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (wt[i] <= W)
            return val[i];
        return 0;
    }
    if (dp[i][W] != -1)
        return dp[i][W];

    // exclude the item
    int exc = solveRM(i - 1, W, val, wt, dp);

    // include
    int inc = INT_MIN;
    if (wt[i] <= W)
        inc = val[i] + solveRM(i - 1, W - wt[i], val, wt, dp);

    dp[i][W] = max(inc, exc);
    return dp[i][W];
}

// T.C. : O(N x W), S.C. : O(N x W)
int solveTab(int W, int n, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // base case
    for (int w = wt[0]; w <= W; w++)
        dp[0][w] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // exclude the item
            int exc = dp[i - 1][w];

            // include
            int inc = INT_MIN;
            if (wt[i] <= w)
                inc = val[i] + dp[i - 1][w - wt[i]];

            dp[i][w] = max(inc, exc);
        }
    }
    return dp[n - 1][W];
}

// T.C. : O(N x W), S.C. : O(W)
int solveSO(int W, int n, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    // base case
    for (int w = wt[0]; w <= W; w++)
        prev[w] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // exclude the item
            int exc = prev[w];

            // include
            int inc = INT_MIN;
            if (wt[i] <= w)
                inc = val[i] + prev[w - wt[i]];

            curr[w] = max(inc, exc);
        }
        prev = curr;
    }
    return prev[W];
}

// T.C. : O(N x W), S.C. : O(W)
int solveSO2(int W, int n, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(W + 1, 0);

    // base case
    for (int w = wt[0]; w <= W; w++)
        prev[w] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int w = W; w >= 0; w--)
        {
            // exclude the item
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

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();

    // Recursive Approach
    // return solveRecur(n - 1, W, val, wt);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    // return solveRM(n - 1, W, val, wt, dp);

    // Tabulation
    // return solveTab(W, n, val, wt);

    // Space optimization
    // return solveSO(W, n, val, wt);

    // Space Optimization 2 (single array)
    return solveSO2(W, n, val, wt);
}

int main()
{
    int W = 5;
    vector<int> val = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 2, 3}; 

    cout << knapsack(W, val, wt) << endl;
    return 0;
}