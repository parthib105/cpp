/*
    Rat in a maze
*/
#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &m, int n, vector<vector<int>> &visited, pair<int, int> p)
{
    if ((p.first >= 0 && p.first < n) && (p.second >= 0 && p.second < n))
    {
        if (visited[p.first][p.second] == 0 && m[p.first][p.second] == 1)
        {
            return true;
        }
    }
    return false;
}

void pathfinder(vector<vector<int>> &m, int n, vector<vector<int>> &visited, vector<string> &ans, string path, pair<int, int> p)
{
    // base case
    if (p == make_pair(n - 1, n - 1))
    {
        ans.push_back(path);
        return;
    }

    visited[p.first][p.second] = 1;

    // left case
    pair<int, int> left = make_pair(p.first, p.second - 1);
    if (isValid(m, n, visited, left))
    {
        path.push_back('L');
        pathfinder(m, n, visited, ans, path, left);
        path.pop_back();
    }

    // right case
    pair<int, int> right = make_pair(p.first, p.second + 1);
    if (isValid(m, n, visited, right))
    {
        path.push_back('R');
        pathfinder(m, n, visited, ans, path, right);
        path.pop_back();
    }

    // up case
    pair<int, int> up = make_pair(p.first - 1, p.second);
    if (isValid(m, n, visited, up))
    {
        path.push_back('U');
        pathfinder(m, n, visited, ans, path, up);
        path.pop_back();
    }

    // down case
    pair<int, int> down = make_pair(p.first + 1, p.second);
    if (isValid(m, n, visited, down))
    {
        path.push_back('D');
        pathfinder(m, n, visited, ans, path, down);
        path.pop_back();
    }

    visited[p.first][p.second] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0)
    {
        return ans;
    }

    pair<int, int> p = make_pair(0, 0);

    vector<vector<int>> visited(n, vector<int>(n, 0));

    string path = "";

    pathfinder(m, n, visited, ans, path, p);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the maze : ";
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n, 0));
    cout << "Enter maze entries : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    vector<string> ans = findPath(m, n);

    if (ans.empty())
    {
        cout << "No path exists!" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    
    return 0;
}