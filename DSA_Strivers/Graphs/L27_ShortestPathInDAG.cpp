/*
    Shortest path in Directed Acyclic Graph

    Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M,
    where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

    Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return
    -1 for that vertex.

    Example1:

    Input:
    N = 4, M = 2
    edge = [[0,1,2],[0,2,1]]
    Output:
    0 2 1 -1
    Explanation:
    Shortest path from 0 to 1 is 0->1 with edge weight 2.
    Shortest path from 0 to 2 is 0->2 with edge weight 1.
    There is no way we can reach 3, so it's -1 for 3.

    Example2:

    Input:
    N = 6, M = 7
    edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
    Output:
    0 2 3 6 1 5
    Explanation:
    Shortest path from 0 to 1 is 0->1 with edge weight 2.
    Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
    Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
    Shortest path from 0 to 4 is 0->4 with edge weight 1.
    Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.

    Expected Time Complexity: O(N+M), where N is the number of nodes and M is edges
    Expected Space Complexity: O(N)

    Constraint:
    1 <= N <= 100
    1 <= M <= min((N*(N-1))/2,4000)
    0 <= edgei,0,edgei,1 < n
    0 <= edgei,2 <=10^5
*/

#include <bits/stdc++.h>
using namespace std;

void topoDFS(int src, stack<int> &st, vector<bool> &vis, vector<vector<pair<int, int>>> &adj)
{
    vis[src] = true;
    for (auto child : adj[src])
    {
        if (!vis[child.first])
        {
            topoDFS(child.first, st, vis, adj);
        }
    }
    st.push(src);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(N);
    vector<bool> vis(N, false);
    vector<int> dist(N, 1e9);
    stack<int> st;

    // make adjacency list (weighted graph)
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }

    // Apply topological sort
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topoDFS(i, st, vis, adj);
        }
    }

    dist[0] = 0; // here source = 0
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        for (auto child : adj[curr])
        {
            int v = child.first;
            int w = child.second;

            if (dist[curr] + w < dist[v])
            {
                dist[v] = dist[curr] + w;
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == 1e9)
        {
            dist[i] = -1;
        }
    }
    return dist;
}

int main()
{
    int N = 6, M = 7;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};\

    vector<int> sd = shortestPath(N, M, edges);

    for (auto i : sd)
    {
        cout << i << " ";
    }
    // cout << endl;
    return 0;
}