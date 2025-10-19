/*
    Search a 2D Matrix II

    Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.
    

    Example 1:


    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    Output: true
    Example 2:


    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    Output: false
    

    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -109 <= matrix[i][j] <= 109
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -10^9 <= target <= 10^9
*/

#include<bits/stdc++.h>
using namespace std;

int _bsUtil(int x, int n, vector<int> &arr)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l)/2;
        if (arr[m] == x)
            return m;
        else if (arr[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}


// T.C. : O(mn), S.C. : O(1)
pair<int, int> bruteForce(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == target)
                return {i, j};
        }
    }
    return {-1, -1};
}


// T.C. : O(m + log(n)), S.C. : O(1)
pair<int, int> betterApproach(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        if (target >= mat[i][0] && target <= mat[i][n - 1])
        {
            int j = _bsUtil(target, n, mat[i]);
            if (j == -1)
                return {};
            else
                return {i, j};
        }
    }
    return {-1, -1};
}

// T.C.: O(m + n), S.C. : O(1)
pair<int, int> optimalApproach(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();

    int row = 0, col = n - 1;
    while (row < m && col >= 0)
    {
        int elm = mat[row][col];

        if (elm == target)
            return {row, col};
        else if (target > elm)
            row ++;
        else
            col --;
    }
    return {-1, -1};
}

pair<int, int> searchMatrix(vector<vector<int>>& matrix, int target)
{
    // Brute force approach
    // return bruteForce(matrix, target);

    // Better Approaach
    // return betterApproach(matrix, target);

    // Optimal approach
    return optimalApproach(matrix, target);
}

int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
    int target = 19;

    pair<int, int> ans = searchMatrix(matrix, target);
    if (ans.first != -1 && ans.second != -1)
        cout << "Target found at: " << "(" << ans.first << ", " << ans.second << ")" << endl;
    else
        cout << "Target not found!" << endl;
    return 0;
}