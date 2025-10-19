/*
    Topological Sort

    A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
    Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex 
    ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

    Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an 
    array of size ‘V’ representing the topological sort of the vertices of the given DAG.
*/

#include<bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int src, stack<int>& st, map<int, vector<int>>& adj, map<int, bool>& visited)
{
    visited[src] = true;

    for (auto child : adj[src])
    {
        if (!visited[child])
        {
            topologicalSortUtil(child, st, adj, visited);
        }
    }

    st.push(src);
}

// Works only for Directed Acyclic Graph
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    // make adjacency list
    map<int, vector<int>> adj;
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    // visited array
    map<int, bool> visited;
    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, st, adj, visited);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()
{
    int v = 4, e = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}};
    vector<int> tSrt = topologicalSort(edges, v, e);

    for (int i : tSrt)
    {
        cout << i << " ";
    }
    return 0;
}