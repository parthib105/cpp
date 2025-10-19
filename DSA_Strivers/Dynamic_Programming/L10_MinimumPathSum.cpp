/*
    Minimum Path Sum

    Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid 
    has some cost associated with it.

    Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of 
    all the numbers along the path. You need to tell the minimum sum of that path.

    Note:
    You can only move down or right at any point in time.
    
    Constraints:
    1 <= T <= 100   
    1 <= N, M <= 10^2
    1 <= GRID[i][j] <= 10^5

    Where 'GRID[i][j]' denotes the value of the cell in the matrix.

    Time limit: 1 sec
    
    Sample Input 1:
    2
    2 3
    5 9 6
    11 5 2
    1 1
    5
    Sample Output 1:
    21
    5
    Explanation For Sample Output 1:
    In test case 1, Consider a grid of 2*3:

    For this the grid the path with minimum value is (0,0) -> (0,1) -> (1,1) -> (1,2). And the sum along this path is 5 + 9 + 5
     + 2 = 21. So the ans is 21.

    In test case 2, The given grid is:

    For this the grid the path with minimum value is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2).The sum along this path is 1 + 2
     + 3 + 4 + 9 = 19.
    
    Sample Input 2:
    2
    2 2
    5 6
    1 2
    3 3
    1 2 3
    4 5 4
    7 5 9
    Sample Output 2:
    8
    19
    Explanation For Sample Output 2:
    In test case 1, For this the grid the path with minimum value is (0,0) -> (1,0) -> (1,1). The sum along this path is 5 + 1
     + 2 = 8.

    In test case 2, The given grid is:

    For this the grid the path with minimum value is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2).The sum along this path is 1 +
     2 + 3 + 4 + 9 = 19.

*/

#include<bits/stdc++.h>
using namespace std;

int recurSol(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }

    int l = recurSol(i, j - 1, grid);
    int u = recurSol(i - 1, j, grid);
    return grid[i][j] + min(l, u);
}

int solveMemo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int left = solveMemo(i, j - 1, grid, dp);
    int up = solveMemo(i - 1, j, grid, dp);
    dp[i][j] = grid[i][j] + min(left, up);
    return dp[i][j];
}

int minSumPathTabulation(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
                int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                dp[i][j] = grid[i][j] + min(left, up);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int minSumPathSpaceOptimized(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = grid[i][j];
            }
            else
            {
                int left = (j > 0) ? curr[j - 1] : INT_MAX;
                int up = (i > 0) ? prev[j] : INT_MAX;
                curr[j] = grid[i][j] + min(left, up);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}

int solveRecur(int i, int j, int n, int m, vector<vector<int>> &grid)
{
    if (i == n - 1 && j == m - 1)
    {
        return grid[i][j];
    }
    if (i >= n || j >= m)
    {
        return INT_MAX;
    }

    int r = solveRecur(i, j + 1, n, m, grid);
    int d = solveRecur(i + 1, j, n, m, grid);
    return grid[i][j] + min(d, r);
}

int solveRM(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
    {
        return grid[i][j];
    }
    if (i >= n || j >= m)
    {
        return INT_MAX;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int r = solveRM(i, j + 1, n, m, grid, dp);
    int d = solveRM(i + 1, j, n, m, grid, dp);
    dp[i][j] = grid[i][j] + min(d, r);

    return dp[i][j];
}

int solveTab(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Base case: bottom-right cell
    dp[n-1][m-1] = grid[n-1][m-1];

    // Fill the last row and last column
    for (int i = n-2; i >= 0; i--)
    {
        dp[i][m-1] = dp[i+1][m-1] + grid[i][m-1];
    }

    for (int j = m-2; j >= 0; j--)
    {
        dp[n-1][j] = dp[n-1][j+1] + grid[n-1][j];
    }

    // Fill the rest of the dp table
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = m-2; j >= 0; j--)
        {
            dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
        }
    }

    return dp[0][0];
}

int solveSO(int n, int m, vector<vector<int>> &grid) 
{
    vector<int> prev(m, 0);
    vector<int> curr(m, 0);

    // Initialize the last cell in the bottom-right corner
    prev[m-1] = grid[n-1][m-1];

    // Fill the last row from right to left
    for (int j = m-2; j >= 0; j--)
    {
        prev[j] = grid[n-1][j] + prev[j+1];
    }

    // Fill the rest of the DP table row by row from bottom to top
    for (int i = n-2; i >= 0; i--)
    {
        // Start the last column separately
        curr[m-1] = grid[i][m-1] + prev[m-1];
        
        // Fill the rest of the row
        for (int j = m-2; j >= 0; j--)
        {
            curr[j] = grid[i][j] + min(prev[j], curr[j+1]);
        }

        // Move current row to previous for the next iteration
        prev = curr;
    }

    return prev[0];
}

int minSumPath(vector<vector<int>> &grid) 
{
    int n = grid.size();
    int m = grid[0].size();

    // Recursion
    // return solveRecur(0, 0, n, m, grid);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return solveRM(0, 0, n, m, grid, dp); 

    // Tabulation
    // return solveTab(n, m, grid);

    // Space Optimization
    return solveSO(n, m, grid);
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 4}, {7, 5, 9}};
    cout << minSumPath(grid) << endl;
    return 0;
}