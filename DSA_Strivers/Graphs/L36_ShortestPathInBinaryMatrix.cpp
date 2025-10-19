/*
    Shortest Distance in a Binary Maze

    Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given
    source cell to a destination cell. The path can only be created out of a cell if its value is 1.

    If the path is not possible between source cell and destination cell, then return -1.

    Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they
    share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and
    destination cell are based on the zero based indexing. The destination cell should be 1.

    Example 1:

    Input:
    grid[][] = {{1, 1, 1, 1},
                {1, 1, 0, 1},
                {1, 1, 1, 1},
                {1, 1, 0, 0},
                {1, 0, 0, 1}}
    source = {0, 1}
    destination = {2, 2}
    Output:
    3
    Explanation:
    1 1 1 1
    1 1 0 1
    1 1 1 1
    1 1 0 0
    1 0 0 1
    The highlighted part in the matrix denotes the
    shortest path from source to destination cell.
    Example 2:

    Input:
    grid[][] = {{1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 0},
                {1, 0, 1, 0, 1}}
    source = {0, 0}
    destination = {3, 4}
    Output:
    -1
    Explanation:
    The path is not possible between source and
    destination, hence return -1.

    Expected Time Complexity: O(n * m)
    Expected Space Complexity: O(n * m)

    Constraints:

    1 ≤ n, m ≤ 500
    grid[i][j] == 0 or grid[i][j] == 1
    The source and destination cells are always inside the given matrix.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m, vector<vector<int>> &grid)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < m) && grid[x][y] == 1)
    {
        return true;
    }
    return false;
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> dst)
{
    int n = grid.size();
    int m = grid[0].size();
    int sx = src.first, sy = src.second;
    int dx = dst.first, dy = dst.second;
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    // dist matrix
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[sx][sy] = 0;

    // Queue data structure to traverse
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {sx, sy}});
    while (!q.empty())
    {
        int d = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == dx && y == dy)
        {
            return d;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dr[i];
            int newY = y + dc[i];
            if (isValid(newX, newY, n, m, grid) && (d + 1) < dist[newX][newY])
            {
                q.push({d + 1, {newX, newY}});
                dist[newX][newY] = d + 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}, {1, 0, 0, 1}};
    pair<int, int> src = {0, 1};
    pair<int, int> dst = {2, 2};

    cout << shortestPath(grid, src, dst) << endl;
    return 0;
}