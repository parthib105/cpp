/*
    You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the 
    bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.
    In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total 
    number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].

    To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], 
    you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

    Constraints:
    1 ≤ T ≤ 100
    1 ≤ M ≤ 15
    1 ≤ N ≤ 15

    Where ‘M’ is the number of rows and ‘N’ is the number of columns in the matrix. 

    Time limit: 1 sec
    Sample Input 1:
    2
    2 2
    1 1
    Sample Output 1:
    2
    1
    Explanation of Sample Output 1:
    In test case 1, we are given a 2 x 2 matrix, to move from matrix[0][0] to matrix[1][1] we have the following possible paths.

    Path 1 = (0, 0) -> (0, 1) -> (1, 1)
    Path 2 = (0, 0) -> (1, 0) -> (1, 1)

    Hence a total of 2 paths are available, so the output is 2.

    In test case 2, we are given a 1 x 1 matrix, hence we just have a single cell which is both the starting and ending point. Hence the output is 1.
    Sample Input 2:
    2
    3 2
    1 6
    Sample Output 2:
    3
    1
    Explanation of Sample Output 2:
    In test case 1, we are given a 3 x 2 matrix, to move from matrix[0][0] to matrix[2][1] we have the following possible paths.

    Path 1 = (0, 0) -> (0, 1) -> (1, 1) -> (2, 1)
    Path 2 = (0, 0) -> (1, 0) -> (2, 0) -> (2, 1)
    Path 3 =  (0, 0) -> (1, 0) -> (1, 1) -> (2, 1)

    Hence a total of 3 paths are available, so the output is 3.

    In test case 2, we are given a 1 x 6 matrix, hence we just have a single row to traverse and thus total path will be 1.
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int j, int m, int n)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }

    int up = solveRecur(i - 1, j, m, n);
    int left = solveRecur(i, j - 1, m, n);
    return up + left;
}

int solveRM(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = solveRecur(i - 1, j, m, n);
    int left = solveRecur(i, j - 1, m, n);
    dp[i][j] = up + left;

    return dp[i][j];
}

int solveTab(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
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

int solveSO(int m, int n)
{
    vector<int> prev(n, 0);
    vector<int> curr(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = 1;
            }
            else
            {
                int up = 0, left = 0;

                if (i > 0)
                {
                    up = prev[j];
                }
                if (j > 0)
                {
                    left = curr[j - 1];
                }

                curr[j] = up + left;
            }
        }
        prev = curr;
    }

    return prev[n - 1];
}

int uniquePaths(int m, int n)
{
    // Recursion
    // return solveRecur(m - 1, n - 1, m, n);

    // Recursion + Memoization
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return solveRM(m - 1, n - 1, m, n, dp);

    // Tabulation
    // return solveTab(m, n);

    // Space Optimization
    return solveSO(m, n);
}

int main()
{
    int m = 3, n = 2;

    cout << uniquePaths(m, n) << endl;
    return 0;
}