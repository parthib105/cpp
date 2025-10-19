/*
    Rotting Oranges

    You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

    Example 1:

    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

    Example 2:

    Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1
    Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

    Example 3:

    Input: grid = [[0,2]]
    Output: 0
    Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

    Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.
*/

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(m, vector<int>(n, 0));

    // push all the rotten oranges into queue
    int countFresh = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else if (grid[i][j] == 1)
            {
                countFresh += 1;
            }
        }
    }

    int time = 0;
    int cntF = 0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = r + dx[i];
            int col = c + dy[i];
            if ((row >= 0 && row < m) && (col >= 0 && col < n) && vis[row][col] == 0 && grid[row][col] == 1)
            {
                vis[row][col] = 2;
                q.push({{row, col}, t + 1});
                cntF++;
            }
        }
    }
    if (cntF != countFresh)
    {
        return -1;
    }
    return time;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0},{0, 1, 1}};
    cout << orangesRotting(grid) << endl;
    return 0;
}