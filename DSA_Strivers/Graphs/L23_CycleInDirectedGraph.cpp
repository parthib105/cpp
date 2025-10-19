/*
    Directed Graph Cycle

    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

    Example 1:

    Input:

    Output: 1
    Explanation: 3 -> 3 is a cycle

    Example 2:

    Input:

    Output: 0
    Explanation: no cycle in the graph

    Expected Time Complexity: O(V + E)
    Expected Auxiliary Space: O(V)

    Constraints:
    1 <= V, E <= 10^5
*/
#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    queue<int> q;

    // indegree
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    // push nodes with 0 indegree
    for (int i = 0; i < V; i++)
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

        count++;

        for (auto child : adj[curr])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }

    return (count != V);
}

int main()
{
    int V = 4;
    vector<int> adj[] = {{1}, {2}, {3}, {3}};
    bool ans = isCyclic(V, adj);
    if (ans)
    {
        cout << "Cycle present" << endl;
    }
    else
    {
        cout << "Cycle not present" << endl;
    }
    return 0;
}