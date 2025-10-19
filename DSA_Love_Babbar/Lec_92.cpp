/*
    Cycle Detection in Directed Graph using BFS

    You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges 
    such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

    Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.
*/

#include<bits/stdc++.h>
using namespace std;

bool detectCycleInDirectedGraph(vector <pair<int, int>> &edges, int e, int v)
{
    vector<vector<int>> adj(v);
    vector<int> indegree(v, 0);
    queue<int> q;

    // adjacency list
    for (int i = 0; i < e; i++)
    {
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
    }

    // indegree
    for (int i = 0; i < v; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j] ++;
        }
    }

    // push nodes with 0 indegree
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        count ++;

        for (auto child : adj[curr])
        {
            indegree[child] --;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }

    return (count != v);
}

int main()
{
    int v = 5, e = 6;
    vector<pair<int, int>> edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};

    bool isCycle = detectCycleInDirectedGraph(edges, e, v);

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