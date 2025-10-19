/*
    Making A Large Island

    You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

    Return the size of the largest island in grid after applying this operation.

    An island is a 4-directionally connected group of 1s.

    
    Example 1:

    Input: grid = [[1,0],[0,1]]
    Output: 3
    Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

    Example 2:

    Input: grid = [[1,1],[1,0]]
    Output: 4
    Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

    Example 3:

    Input: grid = [[1,1],[1,1]]
    Output: 4
    Explanation: Can't change any 0 to 1, only one island with area = 4.


    Constraints:

        n == grid.length
        n == grid[i].length
        1 <= n <= 500
        grid[i][j] is either 0 or 1.

*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    int n;
    vector<int> parent;

public:
    vector<int> size;

    DisjointSet(int sz)
    {
        this->n = sz;
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

    void unionBySize(int u, int v)
    {
        // find the ultimate parents
        int up_u = this->findParent(u);
        int up_v = this->findParent(v);

        if (up_u == up_v)   // same parent, return
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

int largestIsland(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    DisjointSet ds(m * n);
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    // connect the node to form components
    for (int ux = 0; ux < m; ux++)
    {
        for (int uy = 0; uy < n; uy++)
        {
            if (grid[ux][uy] == 0)
                continue;
            
            for (int i = 0; i < 4; i++)
            {
                int vx = ux + dx[i];
                int vy = uy + dy[i];
                if ((vx >= 0 && vx < m) && (vy >= 0 && vy < n) && grid[vx][vy] == 1)
                {
                    int curNode = ux * n + uy;
                    int adjNode = vx * n + vy;
                    ds.unionBySize(curNode, adjNode);
                }
            }
        }
    }

    // try converting and counting
    int maxSize = INT_MIN;
    for (int ux = 0; ux < m; ux++)
    {
        for (int uy = 0; uy < n; uy++)
        {
            if (grid[ux][uy] == 1)
                continue;
            
            unordered_set<int> currComp;
            for (int i = 0; i < 4; i++)
            {
                int vx = ux + dx[i];
                int vy = uy + dy[i];
                if ((vx >= 0 && vx < m) && (vy >= 0 && vy < n) && grid[vx][vy] == 1)
                {
                    int adjNode = vx * n + vy;
                    int adjPar = ds.findParent(adjNode);
                    currComp.insert(adjPar);
                }
            } 

            int currSize = 1;
            for (auto up : currComp)
                currSize += ds.size[up];

            maxSize = max(maxSize, currSize); 
        }
    }

    // edge case : if all ones
    for (int node = 0; node < m * n; node ++)
    {
        int par = ds.findParent(node);
        maxSize = max(maxSize, ds.size[par]);
    }

    return maxSize;
}

int main() 
{
    
    return 0;
}