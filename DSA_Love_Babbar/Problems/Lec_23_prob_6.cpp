/*
    Write an efficient algorithm that searches for a value target in an m x n integer matrix 'matrix'. 
    
    This matrix has the following properties:

        1. Integers in each row are sorted in ascending from left to right.
        2. Integers in each column are sorted in ascending from top to bottom
*/

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0;
    int col = n - 1;

    while (row < m && col >= 0)
    {
        int elm = matrix[row][col];

        if (elm == target)
        {
            return 1;
        }
        else if (elm < target)
        {
            row ++;
        }
        else
        {
            col --;
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;

    cout << searchMatrix(matrix, target) << endl;
    return 0;
}