/*
    Unique Paths II

    You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
    The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or 
    right at any point in time.

    An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square 
    that is an obstacle.

    Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

    The testcases are generated so that the answer will be less than or equal to 2 * 109.

    Example 1:

    Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    Output: 2
    Explanation: There is one obstacle in the middle of the 3x3 grid above.
    There are two ways to reach the bottom-right corner:
    1. Right -> Right -> Down -> Down
    2. Down -> Down -> Right -> Right
    
    Example 2:
    Input: obstacleGrid = [[0,1],[0,0]]
    Output: 1
    
    Constraints:

    m == obstacleGrid.length
    n == obstacleGrid[i].length
    1 <= m, n <= 100
    obstacleGrid[i][j] is 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int j, vector<vector<int>> &obstacleGrid)
{
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }

    int up = solveRecur(i - 1, j, obstacleGrid);
    int left = solveRecur(i, j - 1, obstacleGrid);
    return up + left;
}

int solveRM(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = solveRM(i - 1, j, obstacleGrid, dp);
    int left = solveRM(i, j - 1, obstacleGrid, dp);
    dp[i][j] = up + left;

    return dp[i][j];
}

int solveTab(int m, int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0, left = 0;

                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (m == 1 && n == 1 && obstacleGrid[0][0] == 1)
    {
        return 0;
    }
    else if (m == 1 && n == 1 && obstacleGrid[0][0] == 0)
    {
        return 1;
    }

    // Recursion
    // return solveRecur(m - 1, n - 1, obstacleGrid);

    // Recursion + Memoiazation
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return solveRM(m - 1, n - 1, obstacleGrid, dp);

    // Tabulation
    return solveTab(m, n, obstacleGrid);
}

int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << uniquePathsWithObstacles(mat) << endl;
    return 0;
}