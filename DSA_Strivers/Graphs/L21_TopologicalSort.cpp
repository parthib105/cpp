/*
    Topological sort

    Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that
    there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid
    topological sorting of the graph.

    In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

    Example 1:

    Input:

    Output:
    1
    Explanation:
    The output 1 denotes that the order is
    valid. So, if you have, implemented
    your function correctly, then output
    would be 1 for all test cases.
    One possible Topological order for the
    graph is 3, 2, 1, 0.
    Example 2:

    Input:

    Output:
    1
    Explanation:
    The output 1 denotes that the order is
    valid. So, if you have, implemented
    your function correctly, then output
    would be 1 for all test cases.
    One possible Topological order for the
    graph is 5, 4, 2, 1, 3, 0.

    Expected Time Complexity: O(V + E).
    Expected Auxiliary Space: O(V).

    Constraints:
    2 ≤ V ≤ 104
    1 ≤ E ≤ (N*(N-1))/2
*/
#include <bits/stdc++.h>
using namespace std;

void topoDFS(int src, vector<bool> &vis, stack<int> &st, vector<int> adj[])
{
    vis[src] = true;
    for (auto child : adj[src])
    {
        if (!vis[child])
        {
            topoDFS(child, vis, st, adj);
        }
    }
    st.push(src);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> vis(V, 0);
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            topoDFS(i, vis, st, adj);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> topoSortBFS(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    vector<int> ts;
    queue<int> q;

    // find indegree
    for (int i = 0; i < V; i++)
    {
        for (auto child : adj[i])
        {
            indegree[child] ++;
        }
    }

    // the node with indegree 0, push into q
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ts.push_back(node);

        for (auto child : adj[node])
        {
            indegree[child] --;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }

    return ts;
}

int main()
{
    int V = 6;
    vector<int> adj[] = {{}, {3}, {3}, {}, {0, 1}, {0, 2}};
    vector<int> ts = topoSort(V, adj);
    for (auto it : ts)
    {
        cout << it << " ";
    } 
    return 0;
}