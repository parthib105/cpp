/*
    BFS in Graph

    Given an adjacency list representation of a directed graph with ‘n’ vertices and ‘m’ edges. Your task is to return a list 
    consisting of Breadth-First Traversal (BFS) starting from vertex 0.

    In this traversal, one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'. The BFS traversal 
    should include all nodes directly or indirectly connected to vertex 0.

    Note:
    The traversal should proceed from left to right according to the input adjacency list.

    Adjacency list: { {1,2,3},{4}, {5}, {},{},{}}

    The interpretation of this adjacency list is as follows:
    Vertex 0 has directed edges towards vertices 1, 2, and 3.
    Vertex 1 has a directed edge towards vertex 4.
    Vertex 2 has a directed edge towards vertex 5.
    Vertices 3, 4, and 5 have no outgoing edges.

    We can also see this in the diagram below.

    BFS traversal: 0 1 2 3 4 5

    Sample Input 1:
    n = 8, m = 7
    0 1
    0 2
    0 3
    1 4
    1 7
    2 5
    3 6
    Sample Output 1:
    0 1 2 3 4 7 5 6

    Explanation for sample input 1:
    n = 8: There are 8 vertices in the graph, labeled from 0 to 7.
    m = 7: There are 7 directed edges in the graph.

    The directed edges are as follows:
    Vertex 0 has directed edges towards vertices 1, 2, and 3.
    Vertex 1 has directed edges towards vertices 4 and 7.
    Vertex 2 has a directed edge towards vertex 5.
    Vertex 3 has a directed edge towards vertex 6.
    Vertices 4, 5, 6, and 7 have no outgoing edges.

    Adjacency list: {{1,2,3}, {4,7}, {5}, {6}, {}, {}, {}, {}}. This is passed to the bfsTraversal function.
*/

#include<bits/stdc++.h>
using namespace std;

void makeAdjList(vector<vector<int>> &adj, map<int, set<int>>& adjList)
{
    for (int i = 0; i < adj.size(); i++)
    {
        adjList[adj[i][0]].insert(adj[i][1]);
        adjList[adj[i][1]].insert(adj[i][0]);
    }
}

void BFS(map<int, set<int>>& adjList, map<int, bool>& visited, vector<int>& ans, int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        ans.push_back(curr);

        for (int i : adjList[curr])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // to store adjacency list
    map<int, set<int>> adjList;

    // data structure to store visited
    map<int, bool> visited;
    
    // to store ans;
    vector<int> ans;

    makeAdjList(adj, adjList);

    // If graph has different disconnected components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    int n = 8, m = 7;

    vector<vector<int>> adj = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 7}, {2, 5}, {3, 6}};
    vector<int> bfs = bfsTraversal(n, adj);
    for (int i : bfs)
    {
        cout << i << " ";
    }
    return 0;
}