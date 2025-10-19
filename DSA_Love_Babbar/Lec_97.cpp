/*
    Disjoint set, Union by rank, path compression

    Minimum Spanning Tree

    You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) 
    and E number of edges.
    Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.
    By definition, a minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph 
    that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

    Constraints :
    2 <= V <= 10^5
    1 <= E <= 3 * 10^5
    0 <= X < N
    0 <= Y < N
    1 <= W <= 10^4

    where V and E represent the number of vertices and edges respectively.
    X and Y represent the vertices between which there is an edge.
    W is the weight of the edge.

    Time limit: 1sec

    Sample Input 1 :
    4 4
    0 1 3
    0 3 5
    1 2 1
    2 3 8
    Sample Output 1 :
    9
    Explanation for Sample Input 1:
    The edge (2,3) having weight 8 will be excluded from the MST. The total weight of the MST then will be 1 + 3 + 5 = 9.
*/

#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

void makeSet(vector<int>& parent, vector<int>& rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int>& parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void makeUnionSet(int u, int v, vector<int>& parent, vector<int>& rank)
{
    // find parents
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);

    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];

        if (u != v)
        {
            minWeight += w;
            makeUnionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {0, 3, 5}, {1, 2, 1}, {2, 3, 8}};

    cout << "Minimum Spanning Tree : " << minimumSpanningTree(edges, n) << endl;
    return 0;
}