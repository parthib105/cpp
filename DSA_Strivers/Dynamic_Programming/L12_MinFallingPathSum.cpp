/*
    Minimum Falling Path Sum

    Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

    A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).



    Example 1:


    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
    Explanation: There are two falling paths with a minimum sum as shown.
    Example 2:


    Input: matrix = [[-19,57],[-40,-5]]
    Output: -59
    Explanation: The falling path with a minimum sum is shown.


    Constraints:

    n == matrix.length == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int j, int n, vector<vector<int>> &mat)
{
    if (j < 0 || j >= n)
        return INT_MAX;
    if (i == n - 1)
        return mat[i][j];

    int db = solveRecur(i + 1, j, n, mat);
    int ld = solveRecur(i + 1, j - 1, n, mat);
    int rd = solveRecur(i + 1, j + 1, n, mat);
    return mat[i][j] + min(ld, min(db, rd));
}

int solveRM(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
        return INT_MAX;
    if (i == n - 1)
        return mat[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int db = solveRM(i + 1, j, n, mat, dp);
    int ld = solveRM(i + 1, j - 1, n, mat, dp);
    int rd = solveRM(i + 1, j + 1, n, mat, dp);

    dp[i][j] = mat[i][j] + min(ld, min(db, rd));
    return dp[i][j];
}

int solveTab(int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // fill the last row
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = mat[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int db = dp[i + 1][j];
            int ld = (j - 1 >= 0) ? dp[i + 1][j - 1] : INT_MAX;
            int rd = (j + 1 < n) ? dp[i + 1][j + 1] : INT_MAX;

            dp[i][j] = mat[i][j] + min(ld, min(db, rd));
        }
    }

    // take minimum among all first-row entries
    int minPath = INT_MAX;
    for (int j = 0; j < n; j++)
        minPath = min(minPath, dp[0][j]);

    return minPath;
}

int solveSO(int n, vector<vector<int>> &mat)
{
    vector<int> prev(n, 0), curr(n, 0);

    // fill the last row
    for (int j = 0; j < n; j++)
        prev[j] = mat[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int db = prev[j];
            int ld = (j - 1 >= 0) ? prev[j - 1] : INT_MAX;
            int rd = (j + 1 < n) ? prev[j + 1] : INT_MAX;

            curr[j] = mat[i][j] + min(ld, min(db, rd));
        }
        prev = curr;
    }

    // take minimum among all first-row entries
    int minPath = INT_MAX;
    for (int j = 0; j < n; j++)
        minPath = min(minPath, prev[j]);

    return minPath;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Using recursion
    // int minPath = INT_MAX;
    // for (int j = 0; j < n; j++)
    // {
    //     int currPath = solveRecur(0, j, n, matrix);
    //     minPath = min(currPath, minPath);
    // }
    // return minPath;

    // Recursion + Memoization
    // int minPath = INT_MAX;
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // for (int j = 0; j < n; j++)
    // {
    //     int currPath = solveRM(0, j, n, matrix, dp);
    //     minPath = min(currPath, minPath);
    // }
    // return minPath;

    // Tabulation
    // return solveTab(n, matrix);

    // Space Optimization
    return solveSO(n, matrix);
}

int main()
{
    vector<vector<int>> matrix = {{2, 1, 3},{6, 5, 4},{7, 8, 9}};
    cout << minFallingPathSum(matrix) << endl;
    return 0;
}