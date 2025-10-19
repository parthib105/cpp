/*
    Bridges In A Graph

    Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph. 
    A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases 
    the number of connected components in the graph).

    For Example :

    If the given graph is :

                2           5
                | \       / |
                |  0 --- 4  |
                | /       \ |
                1           3

    Then the edge between 0 and 4 is the bridge because if the edge between 0 and 4 is removed, then there will be no path left 
    to reach from 0 to 4.and makes the graph disconnected, and increases the number of connected components.
    
    Note :
    There are no self-loops(an edge connecting the vertex to itself) in the given graph.
    There are no parallel edges i.e no two vertices are directly connected by more than 1 edge.

    Constraints :
    1 <= V <= 10 ^ 3
    V-1 <= E <= 3 * 10^3
    0 <= a, b < V

    Time Limit: 1 sec

    Sample Input 1 :
    2
    5 4
    0 1
    3 1
    1 2
    3 4
    3 3
    0 1
    1 2
    2 0
    Sample Output 1 :
    4
    0 1
    1 2    
    1 3
    3 4
    0
    Explanation for Sample Input 1 :
    For the first test case, the graph will be represented as 

                2
                |    
                1 --- 3 --- 4
                |
                0

    There are four bridges((0-1),(1-2),(1-3),(3-4)) in the above-given graph denoted by red lines.
    For the second test case, there is no bridge present in the given graph.
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

void dfs(int src, int parent, int &timer, vector<int> &low, vector<int> &disc, vector<bool> &visited, vector<vector<int>> &res, vector<vector<int>> &adj)
{
    visited[src] = true;
    disc[src] = low[src] = timer ++;

    for (auto child : adj[src])
    {
        if (child == parent)
        {
            continue;
        }

        if (!visited[child])
        {
            dfs(child, src, timer, low, disc, visited, res, adj);

            // while returning, update low
            low[src] = min(low[child], low[src]);

            // check for edge
            if (low[child] > disc[src])
            {
                res.push_back({src, child});
            }
        }
        else
        {
            // back edge
            low[src] = min(low[src], disc[child]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) 
{
    vector<vector<int>> adj(v);
    vector<vector<int>> res;
    vector<bool> visited(v, false);
    vector<int> disc(v, -1);        // discovery time
    vector<int> low(v, -1);         // earliest possible time

    // make adj list
    makeAdjList(e, edges, adj);

    int timer = 0;
    int parent = -1;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, low, disc, visited, res, adj);
        }
    }

    return res;
}

int main()
{
    int v = 5, e = 4;
    vector<vector<int>> edges = {{0, 1}, {3, 1}, {1, 2}, {3, 4}};

    vector<vector<int>> res = findBridges(edges, v, e);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}