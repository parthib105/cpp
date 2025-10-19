/*
    Min Cost Climbing Stairs

    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can 
    either climb one or two steps.
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor.

    Example 1:

    Input: cost = [10,15,20]
    Output: 15
    Explanation: You will start at index 1.
    - Pay 15 and climb two steps to reach the top.
    The total cost is 15.

    Example 2:

    Input: cost = [1,100,1,1,1,100,1,1,100,1]
    Output: 6
    Explanation: You will start at index 0.
    - Pay 1 and climb two steps to reach index 2.
    - Pay 1 and climb two steps to reach index 4.
    - Pay 1 and climb two steps to reach index 6.
    - Pay 1 and climb one step to reach index 7.
    - Pay 1 and climb two steps to reach index 9.
    - Pay 1 and climb one step to reach the top.
    The total cost is 6.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion
int solveRecur(int n, vector<int> &cost)
{
    if (n <= 1)
    {
        return cost[n];
    }

    int ans = cost[n] + min(solveRecur(n - 1, cost), solveRecur(n - 2, cost));
    return ans;
}

// Recursion + Memoization : T.C. -> O(n), S.C. -> O(n) + O(n)
int solveRM(int n, vector<int> &cost, vector<int> &dp)
{
    if (n <= 1)
    {
        return cost[n];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = cost[n] + min(solveRM(n - 1, cost, dp), solveRM(n - 2, cost, dp));
    return dp[n];
}

// Tabulation : T.C. -> O(n), S.C. -> O(n)
int solveTab(int n, vector<int> &cost)
{
    vector<int> dp(n + 1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}

int minCostClimbingStairs(vector<int>& cost) 
{
    int n = cost.size();

    /******************** Using recursion (TLE) ********************/
    // int ans = min(solveRecur(n - 1, cost), solveRecur(n - 2, cost));
    // return ans; 
    /***************************************************************/
    

    /******************** Using Memoization + Recursion ********************/
    // vector<int> dp(n + 1, -1);
    // return solveRM(n, cost, dp);
    /***********************************************************************/

    /******************** Using Tabulation ********************/
    // return solveTab(n, cost);
    /**********************************************************/

    /******************** Space Optimization ********************/
    // T.C. -> O(n), S.C. -> O(1)
    int prev2 = cost[0];
    int prev1 = cost[1];
    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
    /************************************************************/

}

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost to climb stairs : " << minCostClimbingStairs(cost) << endl;
    return 0;
}