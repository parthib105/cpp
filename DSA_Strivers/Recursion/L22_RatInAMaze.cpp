/*
    Rat In a Maze

    Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

    The matrix contains only two possible values:

    0: A blocked cell through which the rat cannot travel.
    1: A free cell that the rat can pass through.
    Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
    If no path exists, return an empty list.

    Note: Return the final result vector in lexicographically smallest order.

    Examples:

    Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
    Output: ["DDRDRR", "DRDDRR"]
    Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
    Input: mat[][] = [[1, 0], [1, 0]]
    Output: []
    Explanation: No path exists as the destination cell is blocked.
    Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    Output: ["DDRR", "RRDD"]
    Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
    Constraints:
    2 ≤ mat.size() ≤ 5
    0 ≤ mat[i][j] ≤ 1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, -1, 1, 0};

bool isValid(int x, int y, int n, vector<vector<int>> &mat, vector<vector<bool>> &vis)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && mat[x][y] == 1 && !vis[x][y])
        return true;
    return false;
}

void solveRecur(int x, int y, int n, string& path, vector<string> &ans, vector<vector<int>> &mat, vector<vector<bool>> &vis)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    string dir = "DLRU";
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, n, mat, vis))
        {
            vis[nx][ny] = true;
            path.push_back(dir[i]);
            solveRecur(nx, ny, n, path, ans, mat, vis);
            path.pop_back();
            vis[nx][ny] = false;
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat)
{
    if (mat[0][0] == 0)
        return {};
    
    int n = mat.size();
    string path = "";
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    vis[0][0] = true;
    solveRecur(0, 0, n, path, ans, mat, vis);

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = findPath(mat);

    for (auto s : ans)
        cout << s << endl;
    return 0;
}