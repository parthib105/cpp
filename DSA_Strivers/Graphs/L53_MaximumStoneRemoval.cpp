/*
    Most Stones Removed with Same Row or Column

    On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
    A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
    Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

    Example 1:

    Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
    Output: 5
    Explanation: One way to remove 5 stones is as follows:
    1. Remove stone [2,2] because it shares the same row as [2,1].
    2. Remove stone [2,1] because it shares the same column as [0,1].
    3. Remove stone [1,2] because it shares the same row as [1,0].
    4. Remove stone [1,0] because it shares the same column as [0,0].
    5. Remove stone [0,1] because it shares the same row as [0,0].
    Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

    Example 2:

    Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
    Output: 3
    Explanation: One way to make 3 moves is as follows:
    1. Remove stone [2,2] because it shares the same row as [2,0].
    2. Remove stone [2,0] because it shares the same column as [0,0].
    3. Remove stone [0,2] because it shares the same row as [0,0].
    Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

    Example 3:

    Input: stones = [[0,0]]
    Output: 0
    Explanation: [0,0] is the only stone on the plane, so you cannot remove it.



    Constraints:

        1 <= stones.length <= 1000
        0 <= xi, yi <= 104
        No two stones are at the same coordinate point.

*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    int n;
    vector<int> rank, size, parent;

public:
    DisjointSet(int sz)
    {
        this->n = sz;
        this->rank.resize(this->n + 1, 0);
        this->size.resize(this->n + 1);
        this->parent.resize(this->n + 1);

        for (int i = 0; i < this->n; i++)
        {
            this->parent[i] = i;
            this->size[i] = 1;
        }
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

        if (up_u == up_v) // same parent, return
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

    void unionBySize(int u, int v)
    {
        // find the ultimate parents
        int up_u = this->findParent(u);
        int up_v = this->findParent(v);

        if (up_u == up_v) // same parent, return
            return;

        if (this->size[up_u] < this->size[up_v])
        {
            this->parent[up_u] = up_v;
            this->size[up_v] += this->size[up_u];
        }
        else
        {
            this->parent[up_v] = up_u;
            this->size[up_u] += this->size[up_v];
        }
    }
};

void dfsUtil(int u, int n, vector<bool> &vis, vector<vector<int>> &stones)
{
    vis[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (!vis[v] && (stones[v][0] == stones[u][0] || stones[v][1] == stones[u][1]))
            dfsUtil(v, n, vis, stones);
    }
}

int removeStonesDFS(vector<vector<int>> &stones)
{
    int comp = 0;
    int n = stones.size();
    vector<bool> vis(n, false);

    for (int u = 0; u < n; u++)
    {
        if (!vis[u])
        {
            comp++;
            dfsUtil(u, n, vis, stones);
        }
    }
    return n - comp;
}

int removeStonesDSU(vector<vector<int>>& stones)
{
    int n = stones.size();
    int maxRow = 0, maxCol = 0;
    for (vector<int>& stone : stones)
    {
        maxRow = max(maxRow, stone[0]);
        maxCol = max(maxCol, stone[1]);
    }

    DisjointSet ds(maxRow + maxCol);
    unordered_set<int> uniqueNodes;
    for (vector<int>& s : stones)
    {
        int u = s[0];
        int v = s[1] + maxRow + 1;
        ds.unionByRank(u, v);

        uniqueNodes.insert(u);
        uniqueNodes.insert(v);
    }

    int comp = 0;
    unordered_set<int>::iterator it = uniqueNodes.begin();
    while (it != uniqueNodes.end())
    {
        if (ds.findParent(*it) == *it)
            comp ++;
        it ++;
    }
    return n - comp;
}

int removeStones(vector<vector<int>> &stones)
{
    // DFS solution
    // return removeStonesDFS(stones);

    // DSU solution
}

int main()
{

    return 0;
}