/*
    Cycle Detection In Undirected Graph

    You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
    Your task is to find if the graph contains a cycle or not.
    A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

    Example :
    In the below graph, there exists a cycle between vertex 1, 2 and 3.

                1
              /   \
             2 --- 3

    Note:
    1. There are no parallel edges between two vertices.
    2. There are no self-loops(an edge connecting the vertex to itself) in the graph.
    3. The graph can be disconnected.

    For Example :

    Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
    Output: Yes

    Explanation :
    There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3.
    So, there exists a cycle in the graph.

    Constraints:
    1 <= T <= 10
    1 <= N <= 5000
    0 <= M <= min(5000, (N * (N - 1)) / 2)
    1 <= edges[i][0] <= N
    1 <= edges[i][1] <= N
    Time Limit: 1 sec


*/

#include <bits/stdc++.h>
using namespace std;

// using BFS
bool isCycleBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj)
{
    // to store parents
    unordered_map<int, int> parent;
    parent[src] = -1;

    // queue to perform bfs
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto child : adj[curr])
        {
            if (visited[child] == true && child != parent[curr])
            {
                return true;
            }
            else if (!visited[child])
            {
                visited[child] = true;
                parent[child] = curr;
                q.push(child);
            }
        }
    }
    return false;
}

// using DFS
bool isCycleDFS(int node, int parent, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adj)
{
    // mark current node as visited
    visited[node] = true;

    // check for all child nodes of curr node
    for (auto child : adj[node])
    {
        if (!visited[node])
        {
            bool isCycleDetected = isCycleDFS(child, node, visited, adj);
            if (isCycleDetected)
            {
                return true;
            }
        }
        else if (visited[node] == true && child != parent)
        {
            return true;        // cycle present
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // make adjacency list
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to store visited nodes
    unordered_map<int, bool> visited;

    // for disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // bool ans = isCycleBFS(i, visited, adj);
            bool ans = isCycleDFS(i, -1, visited, adj);
            if (ans)
            {
                return "Yes";
            }
        }
    }
    return "No";
}


int main()
{
    int n = 3, m = 3;
    vector<vector<int>> edges =  {{1, 2}, {2, 3}, {1, 3}};
    cout << cycleDetection(edges, n, m) << endl;
    return 0;
}