/*
    Prim's Algorithm, Minimum Spanning Tree

    You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 
    is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are 
    supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.

    Constraints :
    2 <= N <= 100
    1 <= M <= min(1000, N(N - 1) / 2)
    1 <= E[i][0], E[i][1] <= N

    Time Limit: 1 sec

    Sample Input 1 :
    v = 5, e = 14
    1 2 2
    1 4 6
    2 1 2
    2 3 3
    2 4 8
    2 5 5
    3 2 3
    3 5 7
    4 1 6
    4 2 8
    4 5 9
    5 2 5
    5 3 7
    5 4 9

    Sample Output 1 :
    1 2 2
    1 4 6
    2 3 3
    2 5 5
    Explanation of Input 1 :
    The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 2, (1,4) with weight 6, (2,3) 
    with weight 3 and (2,5) with weight 5.
*/

#include<bits/stdc++.h>
using namespace std;

void createAdjList(int e, vector<vector<pair<int, int>>> &adj, vector<vector<int>> &g)
{
    for (int i = 0; i < e; i++)
    {
        int u = g[i][0];
        int v = g[i][1];
        int w = g[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

vector<pair<pair<int, int>, int>> calculatePrimsMST1(int v, int e, vector<vector<int>> &g)
{
    vector<vector<pair<int, int>>> adj(v);

    // create adjacency list
    createAdjList(e, adj, g);

    // initialize required data structures
    vector<int> key(v, INT_MAX);
    vector<bool> mst(v, false);
    vector<int> parent(v, -1);

    // store source node properties
    int src = 0;
    key[src] = 0;

    for (int i = 0; i < v; i++)
    {
        int minElm = INT_MAX;
        int currNode;

        // find the min elm
        for (int j = 0; j < v; j++)
        {
            if (mst[j] == false && key[j] < minElm)
            {
                currNode = j;
                minElm = key[j];
            }
        }

        // mark min node as true
        mst[currNode] = true;

        // check its adjacent nodes
        for (auto child : adj[currNode])
        {
            int currChild = child.first;
            int childWght = child.second;

            // update parent
            if (mst[currChild] == false && childWght < key[currChild])
            {
                parent[currChild] = currNode;
                key[currChild] = childWght;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 1; i < v; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}

// Using priority queue
vector<vector<int>> calculatePrimsMST2(int v, int e, vector<vector<int>> &g)
{
    vector<vector<pair<int, int>>> adj(v);      // [(node, wght), (node, wght), ...]

    // create adjacency list
    createAdjList(e, adj, g);

    // initialize required data structures
    vector<int> key(v, INT_MAX);
    vector<bool> mst(v, false);
    vector<int> parent(v, -1);
    
    // priority queue to store {key, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // store source node properties
    int src = 0;
    key[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int currNode = pq.top().second;
        pq.pop();

        mst[currNode] = true;

        // check its adjacent nodes
        for (auto child : adj[currNode])
        {
            int currChild = child.first;
            int childWght = child.second;

            // update parent
            if (mst[currChild] == false && childWght < key[currChild])
            {
                parent[currChild] = currNode;
                key[currChild] = childWght;
                pq.push({key[currChild], currChild});
            }
        }
    }

    vector<vector<int>> ans;
    for (int i = 1; i < v; i++)
    {
        ans.push_back({parent[i], i, key[i]});
    }
    return ans;
}

int main()
{
    int v = 5, e = 14;
    vector<vector<int>> g = {{0, 1, 1}, {0, 3, 5}, {1, 0, 1}, {1, 2, 2}, {1, 3, 7}, {1, 4, 4}, {2, 1, 2}, {2, 4, 6},
                             {3, 0, 5}, {3, 1, 7}, {3, 4, 8}, {4, 1, 4}, {4, 2, 6}, {4, 3, 8}};
    
    vector<vector<int>> ans = calculatePrimsMST2(v, e, g);

    for (auto i : ans)
    {
        cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
    return 0;
}