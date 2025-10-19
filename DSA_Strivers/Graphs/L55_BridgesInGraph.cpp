/*
    Critical Connections in a Network

    There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

    A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

    Return all critical connections in the network in any order.



    Example 1:


    Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
    Output: [[1,3]]
    Explanation: [[3,1]] is also accepted.
    Example 2:

    Input: n = 2, connections = [[0,1]]
    Output: [[0,1]]


    Constraints:

    2 <= n <= 10^5
    n - 1 <= connections.length <= 105
    0 <= ai, bi <= n - 1
    ai != bi
    There are no repeated connections.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer;
    vector<int> time, low;
    vector<vector<int>> bridges;

    void dfsUtil(int u, int p, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[u] = true;
        this->time[u] = this->low[u] = this->timer;
        this->timer++;

        for (int v : adj[u])
        {
            if (p == v)
                continue;

            if (!vis[v])
            {
                dfsUtil(v, u, vis, adj);
                this->low[u] = min(this->low[u], this->low[v]);
                if (this->low[v] > this->time[u])
                    this->bridges.push_back({u, v});
            }
            else
                this->low[u] = min(this->low[u], this->low[v]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        this->timer = 0;
        this->time.resize(n);
        this->low.resize(n);
        this->bridges.clear();
        vector<vector<int>> adj(n);
        for (vector<int> conn : connections)
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<bool> vis(n, false);
        dfsUtil(0, -1, vis, adj);
        return bridges;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    Solution sol;
    vector<vector<int>> cc = sol.criticalConnections(n, connections);

    for (vector<int> row : cc)
    {
        for (int i : row)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}