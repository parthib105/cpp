/*  
    Bellman Ford Algorithm {Can be applied on Directed Graph with -ve weight}

    -> Dijkstra Algorithm doesn't work for -vely weighted graph

    -> Using Bellman Ford Algorithm, we can find negative cycle in a graph

        # Algorithm to Find Negative Cycle in a Directed Weighted Graph Using Bellman-Ford:
            -> Initialize distance array dist[] for each vertex ‘v‘ as dist[v] = INFINITY.
            -> Assume any vertex (let’s say ‘0’) as source and assign dist = 0.
            -> Relax all the edges(u,v,weight) N-1 times as per the below condition:
                * dist[v] = minimum(dist[v], distance[u] + weight)
            -> Now, Relax all the edges one more time i.e. the Nth time and based on the below two cases we can detect the 
               negative cycle:
                * Case 1 (Negative cycle exists): For any edge(u, v, weight), if dist[u] + weight < dist[v]
                * Case 2 (No Negative cycle) : case 1 fails for all the edges.

    You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges. Each edge connecting 
    two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.
    Your task is to calculate the shortest distance of all vertices from the source vertex 'src'.

    Note:
    If there is no path between 'src' and 'ith' vertex, the value at 'ith' index in the answer array will be 10^8.
       
       2
      / \
     /   \ 
    1 --- 3

    3 3 1
    1 2 2
    1 3 2
    2 3 -1

    In the above graph: 

    The length of the shortest path between vertex 1 and vertex 1 is 1->1 and the cost is 0.

    The length of the shortest path between vertex 1 and vertex 2 is 1->2 and the cost is 2.

    The length of the shortest path between vertex 1 and vertex 3 is 1->2->3 and the cost is 1.

    Hence we return [0, 2, 1].
    Note :

    It's guaranteed that the graph doesn't contain self-loops and multiple edges. Also, the graph does not contain negative 
    weight cycles.

    Sample Input 1 :
    4 4 1
    1 2 4
    1 3 3
    2 4 7 
    3 4 -2
    Sample Output 1 :
    0 4 3 1
    Explanation For Sample Output 1 :

          2
         / \
        1   4
         \ /
          3

    In the above graph: 

    The length of the shortest path between vertex 1 and vertex 1 is 1->1 and the cost is 0.

    The length of the shortest path between vertex 1 and vertex 2 is 1->2 and the cost is 4.

    The length of the shortest path between vertex 1 and vertex 3 is 1->3 and the cost is 3.

    The length of the shortest path between vertex 1 and vertex 4 is 1->3->4 and the cost is 1.

    Hence we return [0, 4, 3, 1].
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) 
{
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    // apply n - 1 times
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + w) < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check for negative cycle
    bool negCycle = false;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e9 && (dist[u] + w) < dist[v])
        {
            negCycle = true;
        }
    }

    if (negCycle)
    {
        return vector<int>(n + 1, -1);
    }
    return dist;

}

int main()
{
    int n = 4, m = 4, src = 1;
    vector<vector<int>> edges = {{1, 2, 4}, {1, 3, 3}, {2, 4, 7}, {3, 4, -2}};

    vector<int> dist = bellmonFord(n, m, src, edges);

    for (int i = 1; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}