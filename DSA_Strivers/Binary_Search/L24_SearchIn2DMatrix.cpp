/*
    Search a 2D Matrix

    You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.

    

    Example 1:


    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true
    Example 2:


    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
    

    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -10^4 <= matrix[i][j], target <= 10^4
*/

#include<bits/stdc++.h>
using namespace std;

bool _bsUtil(int x, int n, vector<int> &arr)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l)/2;
        if (arr[m] == x)
            return true;
        else if (arr[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return false;
}


// T.C. : O(mn), S.C. : O(1)
bool bruteForce(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == target)
                return true;
        }
    }
    return false;
}

// T.C. : O(m + log(n)), S.C. : O(1)
bool betterApproach(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        if (target >= mat[i][0] && target <= mat[i][n - 1])
            return _bsUtil(target, n, mat[i]);
    }
    return false;
}

// T.C. : O(log(mn)), S.C. : O(1)
bool optimizedApproach(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();

    int l = 0, r = m * n - 1;
    while (l <= r)
    {
        int mid = l + (r - l)/2;

        int row = mid / n;
        int col = mid % n;
        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    // Brute force approach
    // return bruteForce(matrix, target);

    // Better Approaach
    return betterApproach(matrix, target);

    // Optimal approach
    // return optimizedApproach(matrix, target);
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;

    bool found = searchMatrix(matrix, target);
    if (found)
        cout << "Target found" << endl;
    else
        cout << "Target not found" << endl;
    return 0;
}