/*
    Articulation Point

    Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
    Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.
*/

#include<bits/stdc++.h>
using namespace std;

void makeAdjList(int n, vector<vector<int>> &edges, vector<vector<int>> &adj)
{
    for (int i = 0; i < n; i++)
    {
        int u1 = edges[i][0];
        int v1 = edges[i][1];

        adj[u1].push_back(v1);
        adj[v1].push_back(u1);
    }
}

void dfs(int src, int parent, int &timer, vector<int> &low, vector<int> &disc, vector<bool> &visited, vector<int> &ap, vector<vector<int>> &adj)
{
    visited[src] = true;
    disc[src] = low[src] = timer ++;

    int childCount = 0;
    for (auto child : adj[src])
    {
        if (child == parent)
        {
            continue;
        }

        if (!visited[child])
        {
            dfs(child, src, timer, low, disc, visited, ap, adj);

            // update low
            low[child] = min(low[child], low[src]);

            // check for AP
            if (low[child] >= disc[src] && parent != -1)
            {
                ap.push_back(src);
            }
            childCount ++;
        }
        else
        {
            low[src] = min(low[src], disc[child]);
        }
    }

    if (parent == -1 && childCount > 1)
    {
        ap.push_back(src);
    }
}

vector<int> articulationPoints(int v, int e, vector<vector<int>> &edges) 
{
    vector<vector<int>> adj(v);
    vector<bool> visited(v, false);
    vector<int> disc(v, -1);        // discovery time
    vector<int> low(v, -1);         // earliest possible time
    vector<int> ap;

    // make adj list
    makeAdjList(e, edges, adj);

    int timer = 0;
    int parent = -1;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, low, disc, visited, ap, adj);
        }
    }
    return ap;
}

int main()
{
    int v = 5, e = 5;
    vector<vector<int>> edges = {{0, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}};

    vector<int> ap = articulationPoints(v, e, edges);

    for (auto i : ap)
    {
        cout << i << " ";
    }
    return 0;
}