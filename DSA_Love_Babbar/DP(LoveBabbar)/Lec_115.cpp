/*
    Largest square formed in a matrix

    Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.

    Examples:

    Input: n = 6, m = 5
    mat = [[0, 1, 1, 0, 1], 
        [1, 1, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [1, 1, 1, 1, 0],
        [1, 1, 1, 1, 1],
        [0, 0, 0, 0, 0]]
    Output: 3
    Explanation: 

    The maximum length of a side of the square sub-matrix is 3 where every element is 1.
    Input: n = 2, m = 2
    mat = [[1, 1], 
        [1, 1]]
    Output: 2
    Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
    Input: n = 2, m = 2
    mat = [[0, 0], 
        [0, 0]]
    Output: 0
    Explanation: There is no 1 in the matrix.
    Expected Time Complexity: O(n*m)
    Expected Auxiliary Space: O(n*m)

    Constraints:
    1 <= n, m <= 500
    0 <= mat[i][j] <= 1 
*/

#include<bits/stdc++.h>
using namespace std;

// Recursive element
int solveRecur(int i, int j, int &maxArea, vector<vector<int>> &mat)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    int rght = solveRecur(i, j + 1, maxArea, mat);
    int diag = solveRecur(i + 1, j + 1, maxArea, mat);
    int down = solveRecur(i + 1, j, maxArea, mat);

    if (mat[i][j] == 1)
    {
        int ans = 1 + min(rght, min(diag, down));
        maxArea = max(maxArea, ans);
        return ans;
    }
    return 0;
}

// Recursion + Memoization
int solveRM(int i, int j, int &maxArea, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int rght = solveRM(i, j + 1, maxArea, mat, dp);
    int diag = solveRM(i + 1, j + 1, maxArea, mat, dp);
    int down = solveRM(i + 1, j, maxArea, mat, dp);

    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(rght, min(diag, down));
        maxArea = max(maxArea, dp[i][j]);
        return dp[i][j];
    }
    return dp[i][j] = 0;
}

// Tabulation
int solveTab(int m, int n, int &maxArea, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int rght = dp[i][j + 1];
            int diag = dp[i + 1][j + 1];
            int down = dp[i + 1][j];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(rght, min(diag, down));
                maxArea = max(maxArea, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}

// Space Optimization
int solveSO(int m, int n, int &maxArea, vector<vector<int>> &mat)
{
    vector<int> curr = vector<int>(m + 1, 0);
    vector<int> next = vector<int>(m + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int rght = curr[j + 1];
            int diag = next[j + 1];
            int down = next[j];

            if (mat[i][j] == 1)
            {
                curr[j] = 1 + min(rght, min(diag, down));
                maxArea = max(maxArea, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return next[0];
}

int maxSquare(int n, int m, vector<vector<int>> mat) 
{
    int maxArea = 0;

    // Recursion
    // solveRecur(0, 0, maxArea, mat);

    // Recursion  + Memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // int area = solveRM(0, 0, maxArea, mat, dp);

    // Tabulation
    // int area = solveTab(m, n, maxArea, mat);

    // Space Optimization
    int area = solveSO(m, n, maxArea, mat);
    
    return maxArea;
}

int main()
{
    int n = 6, m = 5;
    vector<vector<int>> mat = {{0, 1, 1, 0, 1}, {1, 1, 0, 1, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}};

    cout << maxSquare(n, m, mat);
    return 0;
}