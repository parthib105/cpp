/*
    0/1 Knapsack

    A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item 
    weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to 
    find and return the maximum value that a thief can generate by stealing items.

    Constraints:
    1 <= N <= 10^2
    1<= wi <= 50
    1 <= vi <= 10^2
    1 <= W <= 10^3

    Time Limit: 1 second

    Sample Input: 
    4
    1 2 4 5
    5 4 8 6
    5
    Sample Output:
    13
*/

#include<bits/stdc++.h>
using namespace std;

// Recursion (Include - Exclude)
int solveRecur(vector<int> &weight, vector<int> &value, int idx, int maxWeight)
{
    // base case
    if (idx == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    // include or exclude
    int incl = 0;
    if (weight[idx] <= maxWeight)
    {
        incl = value[idx] + solveRecur(weight, value, idx - 1, maxWeight - weight[idx]);
    }

    int excl = solveRecur(weight, value, idx - 1, maxWeight);

    return max(incl, excl);
}

// Recursion + Memoization
int solveRM(int idx, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    // base case
    if (idx == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[idx][maxWeight] != -1)
    {
        return dp[idx][maxWeight];
    }

    // include or exclude
    int incl = 0;
    if (weight[idx] <= maxWeight)
    {
        incl = value[idx] + solveRM(idx - 1, maxWeight - weight[idx], weight, value, dp);
    }

    int excl = solveRM(idx - 1, maxWeight, weight, value, dp);

    dp[idx][maxWeight] = max(incl, excl);
    return dp[idx][maxWeight];
}

// Tabulation
int solveTab(int n, int maxWeight, vector<int> &weight, vector<int> &value)
{
    // Create dp array
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // set initial values
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            dp[0][w] = value[0];
        }
    }

    // for rest of the rows
    for (int row = 1; row < n; row ++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int incl = 0;
            if (weight[row] <= w)
            {
                incl = value[row] + dp[row - 1][w - weight[row]];
            }

            int excl = dp[row - 1][w];

            dp[row][w] = max(incl, excl);
        }
    }

    return dp[n - 1][maxWeight];
}

// Space Optimization : Using two arrays
int solveSO1(int n, int maxWeight, vector<int> &weight, vector<int> &value)
{
    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);

    // set prev values
    if (weight[0] <= maxWeight)
    {
        for (int w = weight[0]; w <= maxWeight; w++)
        {
            prev[w] = value[0];
        }
    }

    // for the rest of the rows
    for (int row = 1; row < n; row++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int incl = 0;
            if (weight[row] <= w)
            {
                incl = value[row] + prev[w - weight[row]];
            }

            int excl = prev[w];

            curr[w] = max(excl, incl);
        }
        prev = curr;
    }

    return prev[maxWeight];
}

// Space Optimization : Using one array
int solveSO2(int n, int maxWeight, vector<int> &weight, vector<int> &value)
{
    vector<int> prev(maxWeight + 1, 0);

    // set prev values
    if (weight[0] <= maxWeight)
    {
        for (int w = weight[0]; w <= maxWeight; w++)
        {
            prev[w] = value[0];
        }
    }

    // for the rest of the rows
    for (int row = 1; row < n; row++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int incl = 0;
            if (weight[row] <= w)
            {
                incl = value[row] + prev[w - weight[row]];
            }

            int excl = prev[w];

            prev[w] = max(excl, incl);
        }
    }

    return prev[maxWeight];

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Recursive approach
    // return solveRecur(weight, value, n - 1, maxWeight);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solveRM(n - 1, maxWeight, weight, value, dp);

    // Tabulation
    // return solveTab(n, maxWeight, weight, value);

    // Space Optimization : Using two arrays
    // return solveSO1(n, maxWeight, weight, value);

    // Space Optimization : Using one array
    return solveSO2(n, maxWeight, weight, value);
}

int main()
{
    int n = 4, maxWeight = 5;
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};

    cout << knapsack(weight, value, n, maxWeight) << endl;
    return 0;
}