/*
    Kruskal’s Minimum Spanning Tree Algorithm 

    A minimum spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices without any cycles and with the minimum possible total edge weight.


    A spanning tree’s weight is the sum of the weights of each edge in the spanning tree.
    You have been given a connected undirected weighted graph having 'n' vertices, from 1 to 'n', and 'm' edges.
    You are given an array 'edges' of size 'm', containing the details of the edges of the graph.

    Each element of 'edges' contains three integers, the two vertices that are being connected and the weight of the edge.

    Find the weight of the minimum spanning tree of the given graph.

    Example :

    Input: 'n' = 5, 'm' = 6
    'edges' = [[1, 2, 6], [2, 3, 5], [3, 4, 4], [1, 4, 1], [1, 3, 2], [3, 5, 3]]

    Output: 11

    Explanation: The given graph is:

    The minimum spanning tree of the graph is:

    And its weight is 1 + 2 + 5 + 3 = 11.

    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:

    5 6
    1 2 6
    2 3 5
    3 4 4
    1 4 1
    1 3 2
    3 5 3


    Sample Output 1:

    11


    Explanation of sample input 1 :

    As shown in the example above, The minimum spanning tree of the graph is:

    And its weight is 1 + 2 + 5 + 3 = 11.


    Sample Input 2:

    2 1
    1 2 4


    Sample Output 2:

    4


    Explanation of sample input 2 :

    The graph has only one edge. So the minimum spanning will be the graph itself. And its weight is 4.


    Expected time complexity :

    The expected time complexity is O(m * log(m) + n).


    Constraints :

    2 <= 'n' <= 10000
    n - 1 <= 'm' <= min(10000, n * (n - 1) / 2)
    1 <= 'w' <= 10000
    1 <= 'u', 'v' <= n

    The graph is connected.

    Time limit: 1 sec

*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    int n;
    vector<int> rank, parent;

public:
    DisjointSet(int sz)
    {
        this->n = sz;
        this->rank.resize(this->n + 1, 0);
        this->parent.resize(this->n + 1);
        
        for (int i = 0; i < this->n; i++)
            this->parent[i] = i;
    }

    int findParent(int u)
    {
        if (u == this->parent[u])
            return u;

        this->parent[u] = findParent(this->parent[u]);
        return this->parent[u];
    }

    void unionByRank(int u, int v)
    {
        // find the ultimate parents
        int up_u = this->findParent(u);
        int up_v = this->findParent(v);

        if (up_u == up_v)   // same parent, return
            return;

        if (this->rank[up_u] < this->rank[up_v])
            this->parent[up_u] = up_v;
        else if (this->rank[up_v] < this->rank[up_u])
            this->parent[up_v] = up_u;
        else
        {
            this->parent[up_v] = up_u;
            this->rank[up_u] += 1;
        }
    }
};

int kruskalMST(int n, vector<vector<int>> &edges)
{
	// sort the edges according to the weights
	sort(edges.begin(), edges.end(), 
		[&](const vector<int>& a, const vector<int>& b) {
			return a[2] < b[2];
		});
	
	int mstSum = 0;
	DisjointSet ds(n);
	for (vector<int>& e : edges)
	{
		int u = e[0];
		int v = e[1];
		int w = e[2];

		if (ds.findParent(u) != ds.findParent(v))
		{
			mstSum += w;
			ds.unionByRank(u, v);
		}
	}
	return mstSum;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {{1, 2, 6}, {2, 3, 5}, {3, 4, 4}, {1, 4, 1}, {1, 3, 2}, {3, 5, 3}};

    int mstWeight = kruskalMST(n, edges);
    cout << mstWeight << endl;
}