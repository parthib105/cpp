/*
    Number of Distinct Islands

    Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected
    1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is
    not equal to another (not rotated or reflected).

    Example 1:

    Input:
    grid[][] = {{1, 1, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 0, 0, 1, 1},
                {0, 0, 0, 1, 1}}
    Output:
    1
    Explanation:
    grid[][] = {{1, 1, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 0, 0, 1, 1},
                {0, 0, 0, 1, 1}}
    Same colored islands are equal.
    We have 2 equal islands, so we
    have only 1 distinct island.

    Example 2:

    Input:
    grid[][] = {{1, 1, 0, 1, 1},
                {1, 0, 0, 0, 0},
                {0, 0, 0, 0, 1},
                {1, 1, 0, 1, 1}}
    Output:
    3
    Explanation:
    grid[][] = {{1, 1, 0, 1, 1},
                {1, 0, 0, 0, 0},
                {0, 0, 0, 0, 1},
                {1, 1, 0, 1, 1}}
    Same colored islands are equal.
    We have 4 islands, but 2 of them
    are equal, So we have 3 distinct islands.

    Expected Time Complexity: O(n * m)
    Expected Space Complexity: O(n * m)

    Constraints:
    1 <= n, m <= 500
    grid[i][j] == 0 or grid[i][j] == 1
*/

#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int x, int y, int x0, int y0, int m, int n, vector<pair<int, int>> &island, vector<vector<bool>> &vis, vector<vector<int>> &grid)
{
    vis[x][y] = true;
    island.push_back({x - x0, y - y0});

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if ((nx >= 0 && nx < m) && (ny >= 0 && ny < n) && !vis[nx][ny] && grid[nx][ny] == 1)
        {
            dfsUtil(nx, ny, x0, y0, m, n, island, vis, grid);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    set<vector<pair<int, int>>> s;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> island;
                dfsUtil(i, j, i, j, m, n, island, vis, grid);
                s.insert(island);
            }
        }
    }
    return s.size();
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};
    cout << countDistinctIslands(grid) << endl;
    return 0;
}