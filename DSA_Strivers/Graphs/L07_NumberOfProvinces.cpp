/*
    Number of Provinces

    Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path 
    from u to v or v to u. Your task is to find the number of provinces.

    Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

    Example 1:

    Input:
    [
    [1, 0, 1],
    [0, 1, 0],
    [1, 0, 1]
    ]

    Output:
    2
    Explanation:
    The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single 
    province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
    Example 2:
    Input:
    [
    [1, 1],
    [1, 1]
    ]

    Output :
    1

    Expected Time Complexity: O(V^2)
    Expected Auxiliary Space: O(V)


    Constraints:
    1 ≤ V ≤ 500
    */

#include<bits/stdc++.h>
using namespace std;

void dfs_util(int src, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[src] = true;

    for (int j = 0; j < adj[src].size(); j++)
    {
        if (adj[src][j] == 1 && !vis[j])
        {
            dfs_util(j, vis, adj);
        }
    }
}

int numProvinces(vector<vector<int>> &adj, int V) 
{
    int provinces = 0;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs_util(i, vis, adj);
            provinces ++;
        }
    }
    return provinces;
}

int main()
{
    vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    int V = 3;

    cout << numProvinces(adj, V) << endl;
    return 0;
}