/*
    Minimum Spanning Tree

    Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is provided as a list of edges, where each edge is represented as [u, v, w], indicating an edge between vertex u and vertex v with edge weight w.

    Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]

    Output: 4
    Explanation:

    The Spanning Tree resulting in a weight
    of 4 is shown above.

    Input: V = 2, E = 1, Edges = [[0 1 5]]



    Output: 5
    Explanation: Only one Spanning Tree is possible which has a weight of 5.

    Constraints:
    2 ≤ V ≤ 1000
    V-1 ≤ E ≤ (V*(V-1))/2
    1 ≤ w ≤ 1000
    The graph is connected and doesn't contain self-loops & multiple edges.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mst;

    // T.C. : E log(E), S.C. : O(E)
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        int mstSum = 0;
        vector<bool> vis(V, false);
        vector<vector<vector<int>>> adj(V);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // build the adj list
        for (vector<int> &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        pq.push({0, 0, -1}); // {wt, node, parent}
        while (!pq.empty())
        {
            int w = pq.top()[0];
            int u = pq.top()[1];
            int p = pq.top()[2];
            pq.pop();

            if (vis[u])
                continue;

            vis[u] = true;
            mstSum += w;
            if (p != -1)
                this->mst.push_back({p, u});

            for (vector<int> &nbd : adj[u])
            {
                int v = nbd[0];
                int wt = nbd[1];
                if (!vis[v])
                    pq.push({wt, v, u});
            }
        }
        return mstSum;
    }
};

int main()
{
    int V = 3;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};

    Solution sol;
    cout << sol.spanningTree(V, edges) << endl;

    for (vector<int>& e : sol.mst)
        cout << "[" << e[0] << ", " << e[1] << "]" << endl;
    return 0;
}