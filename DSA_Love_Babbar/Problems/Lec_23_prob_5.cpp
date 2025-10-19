/*
    Search in 2-D matrix

    You are given an m x n integer matrix matrix with the following two properties:

        1. Each row is sorted in non-decreasing order.
        2. The first integer of each row is greater than the last integer of the previous row.
    
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.
*/

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int st = 0;
    int ed = row * col - 1;

    while (st < ed)
    {
        int mid = st + (ed - st) / 2;

        if (matrix[mid / col][mid % col] == target)
        {
            return true;
        }
        else if (matrix[mid / col][mid % col] < target)
        {
            st = mid + 1;
        }
        else
        {
            ed = mid - 1;
        }
    }
    return false;
}

int main()
{
    
    return 0;
}