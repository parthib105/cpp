/*
    Topological sort using Kahn Algorithm

    applicable only for Directed Acyclic Graph
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    vector<int> indegree(v, 0);
    queue<int> q;
    vector<int> ans;

    // adjacency list
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
    }

    // indegree
    for (auto i : edges)
    {
        indegree[i[1]] ++;
    }

    // store nodes with indegree 0
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // bfs
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        ans.push_back(curr);

        for (auto child : adj[curr])
        {
            indegree[child] --;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
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