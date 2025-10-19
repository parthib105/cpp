/*
    Shortest Path in Weighted undirected graph

    You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights.
    Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers
    consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

    The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that
    edge.

    Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
    Output: [1, 4, 3, 5]
    Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5.

    Input: n = 2, m= 1, edges = [[1, 2, 2]]
    Output: [1, 2]
    Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2.

    Input: n = 2, m= 0, edges = [ ]
    Output: -1
    Explanation: Since there are no edges, so no answer is possible.

    Expected Time Complexity: O(m* log(n))
    Expected Space Complexity: O(n+m)

    Constraint:
    2 <= n <= 10^6
    0 <= m <= 10^6
    1 <= a, b <= n
    1 <= w <= 10^5
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

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<vector<int>>> adj(V + 1);
    
    // Build adj list
    buildAdj(adj, edges);

    int src = 1;
    set<pair<int, int>> st;
    vector<int> dist(V + 1, INT_MAX);
    vector<int> parent(V + 1);

    for (int i = 0; i <= V; i++)
        parent[i] = i;

    dist[src] = 0;
    st.insert({dist[src], src});
    while (!st.empty())
    {
        set<pair<int, int>>::iterator it = st.begin();
        int d = it->first;
        int u = it->second;
        st.erase(it);

        for (vector<int>& nbd : adj[u])
        {
            int v = nbd[0];
            int w = nbd[1];
            
            if (d + w < dist[v])
            {
                if (dist[v] != INT_MAX)
                    st.erase({dist[v], v});
                
                dist[v] = d + w;
                parent[v] = u;
                st.insert({dist[v], v});
            }
        }
    }

    // if not possible to reach
    if (dist[V] == INT_MAX)
        return {-1};
    
    int dest = V;
    vector<int> path;
    while (dest != parent[dest])
    {
        path.push_back(dest);
        dest = parent[dest];
    }
    path.push_back(src);
    path.push_back(dist[V]);    

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n = 5, m = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    vector<int> path = shortestPath(n, m, edges);

    cout << "Path length : " << path[0] << endl;

    cout << "Path : ";
    for (int i = 1; i < path.size(); i++)
        cout << path[i] << " ";
    
    return 0;
}