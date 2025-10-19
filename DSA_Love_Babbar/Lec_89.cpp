/*
    Detect Cycle In A Directed Graph

    You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges 
    such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].
    Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.

    Note :
    1. The cycle must contain at least two nodes.
    2. It is guaranteed that the given graph has no self-loops in the graph.
    3. The graph may or may not be connected.
    4. Nodes are numbered from 1 to N.
    5. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.

    Constraints :
    1 ≤ T ≤ 5
    2 <= N <= 100
    1 <= M <= min(100,N(N-1)/2)
    1 <= EDGES[i][0], EDGES[i][1] <= N

    Where ‘T’ is the number of test cases.
    Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;

bool isCyclicDirected(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, unordered_map<int, vector<int>>& adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto child : adj[node])
    {
        if (visited[child] && dfsVisited[child])
        {
            return true;
        }
        else if (!visited[child])
        {
            bool isCycleDetected = isCyclicDirected(child, visited, dfsVisited, adj);
            if (isCycleDetected)
            {
                return true;
            }
        }
    }
    
    dfsVisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector <pair<int, int>> & edges) 
{
    // create adj list
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    // to mark visited
    unordered_map<int, bool> visited;

    // to track visited while doing dfs
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDirected(i, visited, dfsVisited, adj);
            if (ans)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int v = 5, e = 6;
    vector<pair<int, int>> edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};

    bool isCycle = detectCycleInDirectedGraph(v, edges);

    if (isCycle)
    {
        cout << "Cycle present" << endl;
    }
    else
    {
        cout << "Cycle not present" << endl;
    }

    return 0;
}