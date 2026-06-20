/*
    N-Queens

    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

    Example 1:


    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
    Example 2:

    Input: n = 1
    Output: [["Q"]]


    Constraints:

    1 <= n <= 9
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n, vector<string> &board)
{
    int row, col;

    // check upper left diagonal
    row = i;
    col = j;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // check left columns
    row = i;
    col = j;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    // check bottm left diagonl
    row = i;
    col = j;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solveRecur1(int col, int n, vector<string> &board, vector<vector<string>> &ans)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 'Q';
            solveRecur1(col + 1, n, board, ans);
            board[row][col] = '.';
        }
    }
}

void solveRecur2(int col, int n, vector<string>& board, vector<bool>& LR, vector<bool>& UD, vector<bool>& LD, vector<vector<string>>& ans)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row ++)
    {
        if (!LR[row] && !LD[row + col] && !UD[n - 1 + col - row])
        {
            board[row][col] = 'Q';
            LR[row] = true;
            LD[row + col] = true;
            UD[n - 1 + col - row] = true;

            solveRecur2(col + 1, n, board, LR, UD, LD, ans);

            UD[n - 1 + col - row] = false;
            LD[row + col] = false;
            LR[row] = false;
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueensBrute(int n)
{
    string s(n, '.');
    vector<string> board(n, s);
    vector<vector<string>> ans;
    
    solveRecur1(0, n, board, ans);
    return ans;
}

vector<vector<string>> solveNQueensSO(int n)
{
    string s(n, '.');   
    vector<string> board(n, s);
    vector<vector<string>> ans;
    vector<bool> LR(n, false), UD(2*n - 1, false), LD(2*n - 1, false);

    solveRecur2(0, n, board, LR, UD, LD, ans);
    return ans;
}

vector<vector<string>> solveNQueens(int n)
{
    // Brute Force solution
    // return solveNQueensBrute(n);

    // Space Optimized solution
    return solveNQueensSO(n);
}

int main()
{
    int n = 5;
    vector<vector<string>> ans = solveNQueens(n);

    for (vector<string> row : ans)
    {
        cout << "[";
        for (int i = 0; i < row.size(); i++)
        {
            if (i == row.size() - 1)
                cout << row[i] << "]" << endl;
            else
                cout << row[i] << endl;
        } 
        cout << endl;
    }
    return 0;
}