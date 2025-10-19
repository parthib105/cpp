/*
    Find a Peak Element II

    A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

    Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

    You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

    You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

    
    Example 1:


    Input: mat = [[1,4],[3,2]]
    Output: [0,1]
    Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
    Example 2:


    Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
    Output: [1,1]
    Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
    

    Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 500
    1 <= mat[i][j] <= 10^5
    No two adjacent cells are equal.
*/

#include<bits/stdc++.h>
using namespace std;

int getMaxIndex(int m, int col, vector<vector<int>> &mat)
{
    int maxElm = -1, maxRow = -1;
    for (int i = 0; i < m; i++)
    {
        if (mat[i][col] > maxElm)
        {
            maxElm = mat[i][col];
            maxRow = i;
        }
    }
    return maxRow;
}

// T.C. : O(mn), S.C. : O(1)
vector<int> _findPeakBrute(vector<vector<int>>& mat)
{
    int maxElm = INT_MIN;
    vector<int> ans = {-1, -1};
    int m = mat.size(), n = mat[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] > maxElm)
            {
                maxElm = mat[i][j];
                ans[0] = i;
                ans[1] = j;
            }
        }
    }
    return ans;
}

// T.C. : O(m log(n)), S.C. : O(1)
vector<int> _findPeakBS(vector<vector<int>>& mat)
{
    int m = mat.size(), n = mat[0].size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        int maxRowIdx = getMaxIndex(m, mid, mat);

        int leftCheck = mid - 1 >= 0 ? mat[maxRowIdx][mid - 1] : -1;
        int rightCheck = mid + 1 >= 0 ? mat[maxRowIdx][mid + 1] : -1;
        if (mat[maxRowIdx][mid] > leftCheck && mat[maxRowIdx][mid] > rightCheck)
            return {maxRowIdx, mid};
        else if (mat[maxRowIdx][mid] < leftCheck)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1};
}

vector<int> findPeakGrid(vector<vector<int>>& mat) 
{
    // Brute Force approach
    // return _findPeakBrute(mat);

    // Binary Search approach
    return _findPeakBS(mat);
}

int main()
{
    vector<vector<int>> mat = {{10,20,15},{21,30,14},{7,16,32}};
    vector<int> ans = findPeakGrid(mat);

    if (ans[0] != -1)
        cout << "Peak element found at (" << ans[0] << ", " << ans[1] << ") and the peak element is " << mat[ans[0]][ans[1]] << endl;
    else
        cout << "Peak element is not found!" << endl;
    return 0;
}