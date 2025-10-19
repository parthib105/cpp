/*
    Depth First Search

    Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is 
    given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.
    V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
    E is the number of edges present in graph G.

    Note :
    The Graph may not be connected i.e there may exist multiple components in a graph.

    Constraints :
    2 <= V <= 10^3
    1 <= E <= (5 * (10^3))
    Time Limit: 1sec

    Sample Input 1:
    V = 5, E = 4
    0 2
    0 1
    1 2
    3 4
    Sample Output 1:
    2
    0 1 2
    3 4
    Explanation For Sample Input 1:
    If we do a DFS traversal from vertex 0 we will get a component with vertices [0, 2, 1]. If we do a DFS traversal from 3 
    we will get another component with vertices [3, 4]

    Hence,  we have two disconnected components so on the first line, print 2. Now, print each component in increasing order. 
    On the first line print 0 1 2 and on the second line, print 3 4.

    [0 1 2] comes before [3 4] as the first vertex 0 from the first component is smaller than the first vertex 3 from the 
    second component.
    Sample Input 2:
    V = 9, E = 7
    0 1
    0 2
    0 5
    3 6
    7 4
    4 8
    7 8
    Sample Output 2:
    3
    0 1 2 5
    3 6
    4 7 8
*/

#include <bits/stdc++.h>
using namespace std;

void DFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &comp)
{
    comp.push_back(node);
    visited[node] = true;

    // for each connected node, recursive call
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            DFS(i, visited, adjList, comp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // make adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> comp;
            DFS(i, visited, adjList, comp);
            ans.push_back(comp);
        }
    }
    return ans;
}

int main()
{
    int V = 9, E = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 5}, {3, 6}, {7, 4}, {4, 8}, {7, 8}};
    vector<vector<int>> ans = depthFirstSearch(V, E, edges);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}