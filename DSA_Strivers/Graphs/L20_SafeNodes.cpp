/*
    Find Eventual Safe States

    There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D
    integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i
    to each node in graph[i].
    A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that
    node leads to a terminal node (or another safe node).
    Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

    Example 1:

    Illustration of graph
    Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    Output: [2,4,5,6]
    Explanation: The given graph is shown above.
    Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
    Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

    Example 2:

    Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    Output: [4]
    Explanation:
    Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.

    Constraints:

    n == graph.length
    1 <= n <= 10^4
    0 <= graph[i].length <= n
    0 <= graph[i][j] <= n - 1
    graph[i] is sorted in a strictly increasing order.
    The graph may contain self-loops.
    The number of edges in the graph will be in the range [1, 4 * 10^4].
*/

#include <bits/stdc++.h>
using namespace std;

bool dfsUtil(int src, vector<bool> &vis, vector<bool> &dfsVis, vector<bool> &check, vector<vector<int>> &graph)
{
    vis[src] = true;
    dfsVis[src] = true;
    check[src] = false;

    for (auto child : graph[src])
    {
        if (!vis[child])
        {
            bool cycle = dfsUtil(child, vis, dfsVis, check, graph);
            if (cycle)
            {
                check[src] = false;
                return true;
            }
        }
        else if (vis[child] == true && dfsVis[child] == true)
        {
            check[src] = false;
            return true;
        }
    }
    check[src] = true;
    dfsVis[src] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<bool> vis(v, false);
    vector<bool> check(v, false); // to check if it is a safe node
    vector<bool> dfsVis(v, false);
    vector<int> safe;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfsUtil(i, vis, dfsVis, check, graph);
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (check[i])
        {
            safe.push_back(i);
        }
    }
    return safe;
}

// Using topo sort
vector<int> safeNodesTopo(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<vector<int>> adj(v);
    vector<int> indegree(v, 0);
    vector<int> safe;
    queue<int> q;

    // reverse the graph
    for (int i = 0; i < v; i++)
    {
        for (auto child : graph[i])
        {
            adj[child].push_back(i);
            indegree[i] ++;
        }
    }

    // node with indegree 0, push into queue
    for (int i = 0; i < v; i++)
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

        safe.push_back(node);

        for (auto child : adj[node])
        {
            indegree[child] --;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    return safe;
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> safe = eventualSafeNodes(graph);
    for (auto it : safe)
    {
        cout << it << " ";
    }
    return 0;
}