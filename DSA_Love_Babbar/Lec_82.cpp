/*
    Rat in a maze

    You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the maze can be thought 
    of as a 2-dimensional plane). The maze would be given in the form of a square matrix of order 'N' * 'N' where the cells 
    with value 0 represent the maze’s blocked locations while value 1 is the open/available path that the rat can take to 
    reach its destination. The rat's destination is at ('N' - 1, 'N' - 1). Your task is to find all the possible paths that 
    the rat can take to reach from source to destination in the maze. The possible directions that it can take to move in the 
    maze are 'U'(up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).

    Note:
    Here, sorted paths mean that the expected output should be in alphabetical order.

    Given a square matrix of size 4*4 (i.e. here 'N' = 4):
    1 0 0 0
    1 1 0 0
    1 1 0 0
    0 1 1 1 
    Expected Output:
    DDRDRR DRDDRR 
    i.e. Path-1: DDRDRR and Path-2: DRDDRR

    The rat can reach the destination at (3, 3) from (0, 0) by two paths, i.e. DRDDRR and DDRDRR when printed in sorted 
    order, we get DDRDRR DRDDRR.
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& arr, vector<vector<bool>>& visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && !visited[x][y] && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

void storePath(int x, int y, int n, string path, vector<string>& ans, vector<vector<int>>& arr, vector<vector<bool>>& visited)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // D  L  R  U
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    vector<char> v = {'D', 'L', 'R', 'U'};

    // mark current position as visited
    visited[x][y] = true;

    // traverse other paths
    for (int i = 0; i < 4; i++)
    {
        if (isSafe(x + dx[i], y + dy[i], n, arr, visited))
        {
            storePath(x + dx[i], y + dy[i], n, path + v[i], ans, arr, visited);
        }
    }

    // backtrack
    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>>& arr, int n)
{
    // to store path
    string path = "";

    // to store final answer
    vector<string> ans;

    // to store if the current position is visited or not
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // if starting position is 0, return
    if (arr[0][0] == 0)
    {
        return ans;
    }

    // function to do the final ans
    storePath(0, 0, n, path, ans, arr, visited);

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;

    vector<string> paths = searchMaze(arr, n);
    cout << "Unique paths : " << endl;
    for (string str : paths)
    {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}