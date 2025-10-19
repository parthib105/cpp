/*
    Number of Operations to Make Network Connected

    There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

    You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

    Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

    
    Example 1:

    Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    Output: 1
    Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

    Example 2:

    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
    Output: 2

    Example 3:

    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
    Output: -1
    Explanation: There are not enough cables.

    Constraints:
        1 <= n <= 10^5
        1 <= connections.length <= min(n * (n - 1) / 2, 10^5)
        connections[i].length == 2
        0 <= ai, bi < n
        ai != bi
        There are no repeated connections.
        No two computers are connected by more than one cable.

*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    int n;
    vector<int> rank, parent;

public:
    DisjointSet(int sz)
    {
        this->n = sz;
        this->rank.resize(this->n + 1, 0);
        this->parent.resize(this->n + 1);
        
        for (int i = 0; i < this->n; i++)
            this->parent[i] = i;
    }

    int findParent(int u)
    {
        if (u == this->parent[u])
            return u;

        this->parent[u] = findParent(this->parent[u]);
        return this->parent[u];
    }

    void unionByRank(int u, int v)
    {
        // find the ultimate parents
        int up_u = this->findParent(u);
        int up_v = this->findParent(v);

        if (up_u == up_v)   // same parent, return
            return;

        if (this->rank[up_u] < this->rank[up_v])
            this->parent[up_u] = up_v;
        else if (this->rank[up_v] < this->rank[up_u])
            this->parent[up_v] = up_u;
        else
        {
            this->parent[up_v] = up_u;
            this->rank[up_u] += 1;
        }
    }
};

int makeConnected(int n, vector<vector<int>>& connections)
{
    int conComp = 0;
    int extraEdges = 0;
    DisjointSet ds(n);
    
    // count the extra edges
    for (vector<int>& edge : connections)
    {
        int u = edge[0];
        int v = edge[1];

        if (ds.findParent(u) == ds.findParent(v))
            extraEdges ++;
        
        ds.unionByRank(u, v);
    }

    // count the components
    for (int u = 0; u < n; u++)
    {
        if (ds.findParent(u) == u)
            conComp ++;
    }

    int ans = conComp - 1;
    if (extraEdges >= ans)
        return ans;
    return -1;
}

int main()
{
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

    int ans = makeConnected(n, connections);
    cout << ans << endl;
}