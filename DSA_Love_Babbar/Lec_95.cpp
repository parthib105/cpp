/*
    Dijkstra's algorithm

    Dijkstra's shortest path

    You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two 
    nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.
    Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices 
    given in the graph.

    Example:

    Input:
    4 5
    0 1 5
    0 2 8
    1 2 9
    1 3 2
    2 3 6

    In the given input, the number of vertices is 4, and the number of edges is 5.

    In the input, following the number of vertices and edges, three numbers are given. The first number denotes node ‘X’, the 
    second number denotes node ‘Y’ and the third number denotes the distance between node ‘X’ and ‘Y’.
    As per the input, there is an edge between node 0 and node 1 and the distance between them is 5.

    The vertices 0 and 2 have an edge between them and the distance between them is 8.
    The vertices 1 and 2 have an edge between them and the distance between them is 9.
    The vertices 1 and 3 have an edge between them and the distance between them is 2.
    The vertices 2 and 3 have an edge between them and the distance between them is 6.
    Note:

    1. There are no self-loops(an edge connecting the vertex to itself) in the given graph.

    2. There can be parallel edges i.e. two vertices can be directly connected by more than 1 edge.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int v, int e, int src) 
{
    vector<vector<pair<int, int>>> adj(v);   // [(node1, dist1), (node2, dist2), ...]
    vector<int> dist(v, INT_MAX);
    set<pair<int, int>> st;     // set<distance, node>

    // Make adjacency list
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adj[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }

    dist[src] = 0;
    st.insert(make_pair(0, src));      // push (dist, src)

    while (!st.empty())
    {
        // get the top record
        auto curr = *(st.begin());

        int currDist = curr.first;
        int currNode = curr.second;

        // remove the top element
        st.erase(st.begin());

        // traverse neighbours
        for (auto child : adj[currNode])
        {
            if (currDist + child.second < dist[child.first])
            {
                // if same node found with different dist, erase it
                auto record = st.find(make_pair(dist[child.first], child.first));
                if (record != st.end())
                {
                    st.erase(record);
                }

                // update distance
                dist[child.first] = currDist + child.second;
                st.insert(make_pair(dist[child.first], child.first));
            }
        }
    }
    return dist;
}

int main()
{
    int v = 5, e = 7;
    vector<vector<int>> edges = {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 1}, {3, 4, 7}};
    
    vector<int> dist = dijkstra(edges, v, e, 0);

    for (int i = 0; i < v; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}