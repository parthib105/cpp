/*
    Distance of nearest cell having 1

    Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
    The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current
    cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1
    in the grid.

    Example 1:

    Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
    Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
    Explanation: The grid is-
    0 1 1 0
    1 1 0 0
    0 0 1 1
    0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
    (2,1) are at a distance of 1 from 1's at (0,1),
    (0,2), (0,2), (2,3), (1,0) and (1,1)
    respectively.

    Example 2:

    Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
    Output: {{0,1,0},{0,0,1},{0,1,2}}
    Explanation: The grid is-
    1 0 1
    1 1 0
    1 0 0
    0's at (0,1), (1,2), (2,1) and (2,2) are at a
    distance of 1, 1, 1 and 2 from 1's at (0,0),
    (0,2), (2,0) and (1,1) respectively.

    Expected Time Complexity: O(n*m)
    Expected Auxiliary Space: O(n*m)

    Constraints:
    1 ≤ n, m ≤ 500
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m, vector<vector<bool>> &vis)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < m) && !vis[x][y])
    {
        return true;
    }
    return false;
}

vector<vector<int>> nearest(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;     // {{i, j}, d}

    // Store all 1s in queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }
        }
    } 

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();

        dist[r][c] = d;

        // visit neighbours
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (isValid(nr, nc, n, m, vis))
            {
                vis[nr][nc] = true;
                q.push({{nr, nc}, d + 1});
            }
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
    vector<vector<int>> ans = nearest(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}