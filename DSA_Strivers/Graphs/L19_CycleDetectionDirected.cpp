/*
    Directed Graph Cycle

    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

    Expected Time Complexity: O(V + E)
    Expected Auxiliary Space: O(V)

    Constraints:
    1 <= V, E <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, vector<vector<int>>& adj, vector<bool> &vis, vector<bool> &dfsVis)
{
    vis[src] = true;
    dfsVis[src] = true;

    for (auto child : adj[src])
    {
        if (!vis[child])
        {
            bool cycle = dfs(child, adj, vis, dfsVis);
            if (cycle)
            {
                return true;
            }
        }
        else if (vis[child] && dfsVis[child])
        {
            return true;
        }
    }
    dfsVis[src] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>>& adj)
{
    vector<bool> vis(V, false);
    vector<bool> dfsVis(V, false);

    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            bool cycle = dfs(i, adj, vis, dfsVis);
            if (cycle)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 10;
    vector<vector<int>> adj(n + 1);
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4, 7};
    adj[4] = {5};
    adj[5] = {6};
    adj[6] = {};
    adj[7] = {5};
    adj[8] = {9};
    adj[9] = {10};
    adj[10] = {8};

    bool ans = isCyclic(n, adj);
    if (ans)
        cout << "Cycle present!" << endl;
    else
        cout << "Cycle not present" << endl;

    return 0;
}