/*
    Number of Provinces

    There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

    A province is a group of directly or indirectly connected cities and no other cities outside of the group.

    You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

    Return the total number of provinces.

    Example 1:

    Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    Output: 2

    Example 2:

    Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
    Output: 3



    Constraints:

        1 <= n <= 200
        n == isConnected.length
        n == isConnected[i].length
        isConnected[i][j] is 1 or 0.
        isConnected[i][i] == 1
        isConnected[i][j] == isConnected[j][i]


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

int findCircleNum(vector<vector<int>> &isConnected)
{
    int numComp = 0;
    int n = isConnected.size();

    DisjointSet ds(n);
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (isConnected[u][v] == 1)
                ds.unionByRank(u, v);
        }
    }

    for (int u = 0; u < n; u++)
    {
        if (ds.findParent(u) == u)
            numComp++;
    }
    return numComp;
}

int main()
{
    vector<vector<int>> isConnected = {{1 , 1, 0},{1 , 1, 0},{0 , 0, 1}};

    int comp = findCircleNum(isConnected);
    cout << comp << endl;
    return 0;
}