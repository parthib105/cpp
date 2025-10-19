/*
    Number of Enclaves

    You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
    A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary
    of the grid.
    Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

    Example 1:

    Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    Output: 3
    Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

    Example 2:

    Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
    Output: 0
    Explanation: All 1s are either on the boundary or can reach the boundary.

    Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 500
    grid[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

void bfsUtil(int m, int n, queue<pair<int, int>> &q, vector<vector<int>> &grid, vector<vector<bool>> &vis)
{
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if ((nx >= 0 && nx < m) && (ny >= 0 && ny < n) && grid[nx][ny] == 1 && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    // for first and last rows, first and last columns
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
    }

    bfsUtil(m, n, q, grid, vis);

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == false)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << numEnclaves(grid) << endl;
    return 0;
}