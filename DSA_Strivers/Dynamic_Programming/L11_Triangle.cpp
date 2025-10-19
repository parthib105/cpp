/*
    Triangle

    Given a triangle array, return the minimum path sum from top to bottom.

    For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

    Example 1:

    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    Output: 11
    Explanation: The triangle looks like:
    2
    3 4
    6 5 7
    4 1 8 3
    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
    Example 2:

    Input: triangle = [[-10]]
    Output: -10


    Constraints:

    1 <= triangle.length <= 200
    triangle[0].length == 1
    triangle[i].length == triangle[i - 1].length + 1
    -10^4 <= triangle[i][j] <= 10^4

*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int j, int n, vector<vector<int>> &triangle)
{
    if (i == n - 1)
        return triangle[i][j];

    int d = solveRecur(i + 1, j, n, triangle);
    int r = solveRecur(i + 1, j + 1, n, triangle);
    return triangle[i][j] + min(r, d);
}

int solveRM(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int d = solveRM(i + 1, j, n, triangle, dp);
    int r = solveRM(i + 1, j + 1, n, triangle, dp);
    dp[i][j] = triangle[i][j] + min(r, d);

    return dp[i][j];
}

int solveTab(int n, vector<vector<int>> &triangle)
{
    vector<vector<int>> dp(n + 1, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
        dp[n - 1][j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = dp[i + 1][j];
            int r = dp[i + 1][j + 1];
            dp[i][j] = triangle[i][j] + min(d, r);
        }
    }
    return dp[0][0];
}

// T.C. : O(nxn), S.C. : O(nxn)
int solveSO(int n, vector<vector<int>> &triangle)
{
    vector<int> prev(n, 0), curr(n, 0);

    // base case
    for (int j = 0; j < n; j++)
        prev[j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = prev[j];
            int r = prev[j + 1];
            curr[j] = triangle[i][j] + min(d, r);
        }
        prev = curr;
    }
    return prev[0];
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    // Recursion
    // return solveRecur(0, 0, n, triangle);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return solveRM(0, 0, n, triangle, dp);

    // Tabulation
    // return solveTab(n, triangle);

    // Space Optimization
    return solveSO(n, triangle);
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}