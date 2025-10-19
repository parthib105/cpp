/*
    Frog Jump with K distances

    A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k

    To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.


    Examples:
    Input: heights = [10, 5, 20, 0, 15], k = 2

    Output: 15

    Explanation:
    0th step -> 2nd step, cost = abs(10 - 20) = 10
    2nd step -> 4th step, cost = abs(20 - 15) = 5
    Total cost = 10 + 5 = 15.

    Input: heights = [15, 4, 1, 14, 15], k = 3

    Output: 2

    Explanation:
    0th step -> 3rd step, cost = abs(15 - 14) = 1
    3rd step -> 4th step, cost = abs(14 - 15) = 1
    Total cost = 1 + 1 = 2.
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(k^n), S.C. : O(n)
int solveRecur(int i, int k, int n, vector<int>& heights)
{
    if (i >= n - 1)
        return 0;

    int steps = INT_MAX;

    // Try all possible jumps
    for (int j = 1; j <= k; j++)
    {
        if (i + j < n)
        {
            int jump = abs(heights[i] - heights[i + j]) + solveRecur(i + j, k, n, heights);
            steps = min(jump, steps);
        }
    }
    return steps;
}

// T.C. : O(n*k), S.C. : O(n)
int solveRM(int i, int k, int n, vector<int>& heights, vector<int>& dp)
{
    if (i >= n - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int steps = INT_MAX;

    // Try all possible jumps
    for (int j = 1; j <= k; j++)
    {
        if (i + j < n)
        {
            int jump = abs(heights[i] - heights[i + j]) + solveRM(i + j, k, n, heights, dp);
            steps = min(jump, steps);
        }
    }
    dp[i] = steps;
    return dp[i];
}

// T.C. : O(n*k), S.C. : O(n)
int solveTab(int k, int n, vector<int>& heights)
{
    vector<int> dp(n, -1);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int steps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i + j < n)
            {
                int jump = abs(heights[i] - heights[i + j]) + dp[i + j];
                steps = min(jump, steps);
            }
        }
        dp[i] = steps;
    }
    return dp[0];
}

int frogJumpWithK(int k, vector<int>& heights) 
{
    int n = heights.size();

    // recursive solution
    // return solveRecur(0, k, n, heights);

    // Recursion + Memoization
    // vector<int> dp(n, -1);
    // return solveRM(0, k, n, heights, dp);

    // Tabulation
    return solveTab(k, n, heights);
}

int main()
{
    int k = 2;
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    cout << frogJumpWithK(k, heights) << endl;
    return 0;
}