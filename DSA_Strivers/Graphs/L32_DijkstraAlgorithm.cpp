/*
    Dijkstra Algorithm

    Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
    You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

    Note: The Graph is connected and doesn't contain any negative weight edge.

    Examples:

    Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
    Output: [4, 3, 0]
    Explanation:

    Shortest Paths:
    For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
    For 2 to 1 minimum distance will be 3. By following path 2 -> 1
    For 2 to 2 minimum distance will be 0. By following path 2 -> 2
    Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
    Output: [0, 4, 8, 10, 10]
    Explanation: 

    Shortest Paths: 
    For 0 to 1 minimum distance will be 4. By following path 0 -> 1
    For 0 to 2 minimum distance will be 8. By following path 0 -> 2
    For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
    For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
    Constraints:
    1 ≤ V ≤ 10^5
    1 ≤ E = edges.size() ≤ 10^5
    0 ≤ edges[i][j] ≤ 10^4
    0 ≤ src < V

*/

#include <bits/stdc++.h>
using namespace std;

void buildAdj(vector<vector<vector<int>>> &adj, vector<vector<int>> &edges)
{
    for (vector<int> &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

// T.C. : O((V + E) log(V)), S.C. : O(V + E)
vector<int> dijkstraPQ(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, INT_MAX);
    vector<vector<vector<int>>> adj(V);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Build the adj list
    buildAdj(adj, edges);

    dist[src] = 0;
    pq.push({dist[src], src});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (vector<int> &nbd : adj[u])
        {
            int v = nbd[0];
            int w = nbd[1];

            if (d + w < dist[v])
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// T.C. : O((V + E) log(V)), S.C. : O(V + E)
vector<int> dijkstraSet(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, INT_MAX);
    vector<vector<vector<int>>> adj(V);
    set<pair<int, int>> st;

    // Build the adj list
    buildAdj(adj, edges);

    dist[src] = 0;
    st.insert({dist[src], src});
    while (!st.empty())
    {
        set<pair<int, int>>::iterator it = st.begin();
        int d = it->first;
        int u = it->second;
        st.erase(it);

        for (vector<int> &nbd : adj[u])
        {
            int v = nbd[0];
            int w = nbd[1];

            if (d + w < dist[v])
            {
                if (dist[v] != INT_MAX) // erase if present
                    st.erase({dist[v], v});

                dist[v] = d + w;
                st.insert({dist[v], v});
            }
        }
    }
    return dist;
}

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    // Using Priority Queue
    // return dijkstraPQ(V, edges, src);

    // Using set
    return dijkstraSet(V, edges, src);
}

int main()
{
    int V = 5, src = 0;
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 1}};

    vector<int> dist = dijkstra(V, edges, src);
    for (auto it : dist)
    {
        cout << it << " ";
    }
    return 0;
}