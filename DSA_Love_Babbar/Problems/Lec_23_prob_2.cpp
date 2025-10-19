/*
    Largest Row sum
*/

#include<bits/stdc++.h>
using namespace std;

int largestRowSum(int arr[][3], int row, int col)
{
    int maxm = INT32_MIN;
    int rowIdx = -1;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxm)
        {
            maxm = sum;
            rowIdx = i;
        }
    }
    return rowIdx;
}

int main()
{
    int arr[3][3] = {{3, 4, 11}, {2, 12, 1}, {7, 8, 7}};
    cout << largestRowSum(arr, 3, 3) << endl;
    return 0;
}