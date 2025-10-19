/*
    Surrounded Regions

    You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

    Connect : A cell is connected to adjacent cells horizontally or vertically.
    Region  : To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region
              cells are on the edge of the board.

    A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

    Example 1:

    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

    Explanation:


    In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

    Example 2:

    Input: board = [["X"]]

    Output: [["X"]]

    Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.
*/

#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int i, int j, int m, int n, vector<vector<bool>> &vis, vector<vector<char>> &board)
{
    vis[i][j] = true;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    for (int k = 0; k < 4; k++)
    {
        int r = i + dx[k];
        int c = j + dy[k];
        if ((r >= 0 && r < m) && (c >= 0 && c < n) && board[r][c] == 'O' && !vis[r][c])
        {
            dfsUtil(r, c, m, n, vis, board);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));

    // check first and last row
    for (int j = 0; j < n; j++)
    {
        if (board[0][j] == 'O')
        {
            dfsUtil(0, j, m, n, vis, board);
        }
        if (board[m - 1][j] == 'O')
        {
            dfsUtil(m - 1, j, m, n, vis, board);
        }
    }

    // check first column
    for (int i = 0; i < m; i++)
    {
        if (board[i][0] == 'O')
        {
            dfsUtil(i, 0, m, n, vis, board);
        }
        if (board[i][n - 1] == 'O')
        {
            dfsUtil(i, n - 1, m, n, vis, board);
        }
    }

    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (board[i][j] == 'O' && !vis[i][j])
            {
                board[i][j] = 'X';
            }
        }
    }
}

int main()
{
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    
    cout << "Before modification :" << endl;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    solve(board);

    cout << "After modification :" << endl;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}