/*
    https://leetcode.com/problems/number-of-islands/

    Number of Islands

    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume
    all four edges of the grid are all surrounded by water.

    Example 1:

    Input: grid = [["1","1","1","1","0"],
                   ["1","1","0","1","0"],
                   ["1","1","0","0","0"],
                   ["0","0","0","0","0"]
                  ]
    Output: 1
    Example 2:

    Input: grid = [
                   ["1","1","0","0","0"],
                   ["1","1","0","0","0"],
                   ["0","0","1","0","0"],
                   ["0","0","0","1","1"]
                  ]
    Output: 3


    Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &adj)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < m) && !vis[x][y] && adj[x][y] == '1')
    {
        return true;
    }
    return false;
}

void bfsUtil(int x, int y, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &adj)
{
    queue<pair<int, int>> q;
    vis[x][y] = true;
    q.push({x, y});

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!q.empty())
    {
        pair<int, int> f = q.front();
        int x1 = f.first;
        int y1 = f.second;
        q.pop();

        // check for the neighbours
        for (int i = 0; i < 4; i++)
        {
            int newX = x1 + dx[i];
            int newY = y1 + dy[i];
            if (isValid(newX, newY, n, m, vis, adj))
            {
                vis[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}

int numIslands(vector<vector<char>> &adj)
{
    int n = adj.size();
    int m = adj[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int islands = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && adj[i][j] == '1')
            {
                bfsUtil(i, j, n, m, vis, adj);
                islands++;
            }
        }
    }
    return islands;
}

int main()
{
    vector<vector<char>> grid = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
    cout << numIslands(grid) << endl;
    return 0;
}