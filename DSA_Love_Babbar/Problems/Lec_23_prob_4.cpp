/*
    Sprial Print

    Given an m x n matrix, return all elements of the matrix in spiral order.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int total = m * n;

    int stRow = 0;
    int edRow = n - 1;
    int stCol = 0;
    int edCol = m - 1;
    int count = 0;
    while (count < total)
    {
        // starting row
        for (int j = stCol; j <= edCol; j++)
        {
            ans.push_back(matrix[stRow][j]);
            count ++;
        }

        // move to next row
        stRow ++;

        // ending column
        for (int i = stRow; i <= edRow; i++)
        {
            ans.push_back(matrix[i][edCol]);
            count ++;
        }
        
        // move to prev col
        edCol --;

        // ending row
        for (int j = edCol; j >= stCol; j--)
        {
            ans.push_back(matrix[edRow][j]);
            count ++;
        }

        // move to prev row
        edRow --;

        // starting col
        for (int i = edRow; i >= stRow; i--)
        {
            ans.push_back(matrix[i][stCol]);
            count ++;
        }

        // move to next col
        stCol ++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = spiralOrder(matrix);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}