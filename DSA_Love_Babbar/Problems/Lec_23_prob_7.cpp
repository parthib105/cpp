/*
    Rotate Image

    You are given an nxn 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

    You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
    DO NOT allocate another 2D matrix and do the rotation.
*/

#include <bits/stdc++.h>
using namespace std;

// using another matrix
void rotate(vector<vector<int>> &matrix)
{
    vector<vector<int>> ans;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int j = 0; j < m; j++)
    {
        vector<int> temp;
        for (int i = n - 1; i >= 0; i--)
        {
            temp.push_back(matrix[i][j]);
        }
        ans.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = ans[i][j];
        }
    }
}

// without using any array
void rotate_2(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < row; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    rotate_2(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}