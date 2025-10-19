/*
    The N - Queens Puzzle

    The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.

    Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.

    Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
    1. They share a row. 
    2. They share a column. 
    3. They share a diagonal. 

    Sample Input 1:
    1
    4   
    Sample Output 1:
    0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
    0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 

    Explanation for Sample Input 1:
    The chessboard matrix for the first configuration looks as follows:-
    0 0 1 0
    1 0 0 0
    0 0 0 1
    0 1 0 0
    Queen contained cell is depicted by 1. As we can see, No queen is in the same row, column or diagonal of the other queens.
    Hence this is a valid configuration.

    Similarly, the chessboard matrix for the second configuration looks as follows:-
    0 1 0 0
    0 0 0 1
    1 0 0 0
    0 0 1 0
    Queen contained cell is depicted by 1. As we can see, No queen is in the same row, column or diagonal of the other queens. 
    Hence this is also a valid configuration.

    These are the only two valid configurations for 4-Queens.
*/

#include <bits/stdc++.h>
using namespace std;

void add_to_ans(int n, vector<vector<int>> &ans, vector<vector<int>> &board)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, int n, vector<vector<int>> &board, map<int, int> &row1, map<int, int> &diag1, map<int, int> &diag2)
{
    // check row
    if (row1[row] == 1)
    {
        return false;
    }

    // check diagonal
    if (diag1[row + col] == 1)
    {
        return false;
    }

    // check diagonal
    if (diag2[n - 1 + col - row] == 1)
    {
        return false;
    }

    return true;
}

void placeQueens(int col, int n, vector<vector<int>> &ans, vector<vector<int>> &board, map<int, int> &row1, map<int, int> &diag1, map<int, int> &diag2)
{
    if (col == n)
    {
        add_to_ans(n, ans, board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, board, row1, diag1, diag2))
        {
            // mark visit
            board[row][col] = 1;
            row1[row] = 1;
            diag1[row + col] = 1;
            diag2[n - 1 + col - row] = 1;

            placeQueens(col + 1, n, ans, board, row1, diag1, diag2);

            // backtrack
            board[row][col] = 0;
            row1[row] = 0;
            diag1[row + col] = 0;
            diag2[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    // make board
    vector<vector<int>> board(n, vector<int>(n, 0));

    // to store ans
    vector<vector<int>> ans;

    // to store visited rows
    map<int, int> row1;

    // to store visited diagonals
    map<int, int> diag1;
    map<int, int> diag2;

    placeQueens(0, n, ans, board, row1, diag1, diag2);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> nqueens = nQueens(n);

    for (int i = 0; i < nqueens.size(); i++)
    {
        for (int j = 0; j < nqueens[i].size(); j++)
        {
            cout << nqueens[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}