/*
    Bipartite Graph

    Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

    Know more about Bipartite Graph: - https://www.geeksforgeeks.org/what-is-bipartite-graph/

    Example 1:

    Input: 

    Output: 1
    Explanation: The given graph can be colored 
    in two colors so, it is a bipartite graph.
    Example 2:

    Input:

    Output: 0
    Explanation: The given graph cannot be colored 
    in two colors such that color of adjacent 
    vertices differs. 

    Expected Time Complexity: O(V + E)
    Expected Space Complexity: O(V)

    Constraints:
    1 ≤ V, E ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;

bool bfsCall(int src, vector<int> &colored, vector<int> adj[])
{
    queue<int> q;
    q.push(src);
    colored[src] = 0;

    while (!q.empty())
    {
        int src = q.front();
        q.pop();

        for (auto child : adj[src])
        {
            if (colored[child] == -1)
            {
                colored[child] = !colored[src];
                q.push(child);
            }
            else if (colored[child] == colored[src])
            {
                return false;
            }
        }
    }
    return true;
}

// using dfs
bool dfsCall(int src, int col, vector<int> &colored, vector<int> adj[])
{
    colored[src] = col;
    for (auto child : adj[src])
    {
        if (colored[child] == -1)
        {
            bool ans = dfsCall(child, !col, colored, adj);
            if (!ans)
            {
                return false;
            }
        }
        else if (colored[child] == col)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    // using bfs
    vector<int> colored(V, -1);

    for (int v = 0; v < V; v++)
    {
        bool ans = bfsCall(v, colored, adj);
        if (ans == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int V = 4;
    vector<int> adj[] = {{2, 3}, {3}, {0, 3}, {0, 1, 2}};
    bool ans = isBipartite(V, adj);
    if (ans)
    {
        cout << "The graph is bipartite" << endl;
    }
    else
    {
        cout << "The graph is not bipartite" << endl;
    }
    return 0;
}