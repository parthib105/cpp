#include<bits/stdc++.h>
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

int main()
{
    
    return 0;
}