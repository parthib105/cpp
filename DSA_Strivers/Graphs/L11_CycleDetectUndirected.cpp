/*
    Undirected Graph Cycle

    Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not.
    Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

    Example 1:

    Input:
    V = 5, E = 5
    adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
    Output: 1
    Explanation:

    1->2->3->4->1 is a cycle.

    Example 2:

    Input:
    V = 4, E = 2
    adj = {{}, {2}, {1, 3}, {2}}
    Output: 0
    Explanation:

    No cycle in the graph.

    NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is
    connected.

    Expected Time Complexity: O(V + E)
    Expected Space Complexity: O(V)

    Constraints:
    1 <= V, E <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Using BFS
bool detectCycleBFS(int src, vector<int> &vis, vector<int> adj[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;    // <node, parent>
    q.push({src, -1});

    while (!q.empty())
    {
        int currNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto child : adj[currNode])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                q.push({child, currNode});
            }
            else if (parent != child)
                return true;
        }
    }
    return false;
}

// Using DFS
bool detectCycleDFS(int src, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[src] = 1;
    for (auto child : adj[src])
    {
        if (!vis[child])
        {
            bool currState = detectCycleDFS(child, src, vis, adj);
            if (currState)
                return true;
        }
        else if (parent != child)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            bool cycle = detectCycleBFS(i, vis, adj);
            if (cycle)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int V = 4;
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    if (isCycle(V, adj))
    {
        cout << "Cycle present" << endl;
    } 
    else
    {
        cout << "Cycle not present" << endl;
    }
    return 0;
}