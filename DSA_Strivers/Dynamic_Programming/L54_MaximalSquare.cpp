/*
    Maximal Square

    Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

    Example 1:


    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 4
    Example 2:


    Input: matrix = [["0","1"],["1","0"]]
    Output: 1
    Example 3:

    Input: matrix = [["0"]]
    Output: 0


    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 300
    matrix[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    int maxLen = 0;
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = matrix[0][j];
        maxLen = max(maxLen, dp[0][j]);
    }
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = matrix[i][0];
        maxLen = max(maxLen, dp[i][0]);
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            maxLen = max(maxLen, dp[i][j]);
        }
    }

    return maxLen * maxLen;
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 1, 0, 0},
                                  {1, 0, 1, 1, 1},
                                  {1, 1, 1, 1, 1},
                                  {1, 0, 0, 1, 0}};

    cout << maximalSquare(matrix) << endl;
    return 0;
}