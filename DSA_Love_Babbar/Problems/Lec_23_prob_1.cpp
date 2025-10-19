/*
    Row-wise Sum
*/

#include<bits/stdc++.h>
using namespace std;

void printRowSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << "Row " << i + 1 << " : " << sum << endl;
    }
}

void printColSum(int arr[][3], int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += arr[i][j];
        }
        cout << "Column " << j + 1 << " : " << sum << endl;
    }
}

int main()
{
    int arr[3][3] = {{3, 4, 11}, {2, 12, 1}, {7, 8, 7}};
    printRowSum(arr, 3, 3);
    cout << endl;
    printColSum(arr, 3, 3);
    return 0;
}