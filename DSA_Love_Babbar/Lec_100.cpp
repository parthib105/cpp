/*
    Kosaraju’s Algorithm involves two main phases:

    1. Performing Depth-First Search (DFS) on the Original Graph:
        -> We first do a DFS on the original graph and record the finish times of nodes (i.e., the time at which the DFS finishes 
           exploring a node completely).
    
    2. Performing DFS on the Transposed Graph:
        -> We then reverse the direction of all edges in the graph to create the transposed graph.
        -> Next, we perform a DFS on the transposed graph, considering nodes in decreasing order of their finish times recorded 
           in the first phase.
        -> Each DFS traversal in this phase will give us one SCC.

    Here’s a simplified version of Kosaraju’s Algorithm:
        -> DFS on Original Graph: Record finish times.
        -> Transpose the Graph: Reverse all edges.
        -> DFS on Transposed Graph: Process nodes in order of decreasing finish times to find SCCs.

    Problem statement :

    Count Strongly Connected Components (Kosaraju’s Algorithm)

    You are given an unweighted directed graph having 'V' vertices and 'E' edges. Your task is to count the number of strongly 
    connected components (SCCs) present in the graph.
    A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. The strongly connected 
    components of a graph are the subgraphs which are themselves strongly connected.

    Note :
    Use zero-based indexing for the vertices.

    The given graph doesn’t contain any self-loops.

    Constraints :
    1 <= V <= 10^4
    0 <= E <= 10^4
    0 <= a, b < V

    Time Limit: 1 sec

    Sample Input 1 :
    5 6
    0 1
    1 2
    1 4
    2 3
    3 2
    4 0
    Sample Output 1 :
    2
    Explanation of sample input 1 :
    For the first test case, the graph is shown below. There are two SCCs in the graph, which are enclosed in the boxes as 
    shown in the image below.

            0---4
            |  /
            | /    
            1 --- 2 <-> 3 
*/

#include<bits/stdc++.h>
using namespace std;

void makeAdj(vector<vector<int>> &edges, vector<vector<int>> &adj)
{
    for (auto n : edges)
    {
        adj[n[0]].push_back(n[1]);
    }
}

void dfsTopo(int src, stack<int> &st, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[src] = true;
    for (auto child : adj[src])
    {
        if (!visited[child])
        {
            dfsTopo(child, st, visited, adj);
        }
    }
    st.push(src);
}

void transposeGraph(int v, vector<vector<int>> &trans, vector<vector<int>> &adj)
{
    for (int i = 0; i < v; i++)
    {
        for (auto child : adj[i])
        {
            trans[child].push_back(i);
        }
    }
}

void dfs(int src, vector<bool> &visited, vector<vector<int>> &trans)
{
    visited[src] = true;
    for (auto child : trans[src])
    {
        if (!visited[child])
        {
            dfs(child, visited, trans);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(v);
    vector<vector<int>> trans(v);
    vector<bool> visited(v);
    stack<int> st;

	// make adjacency list
    makeAdj(edges, adj);

    // topological sort
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfsTopo(i, st, visited, adj);
        }
    }

    // create a transpose graph ans reset the visited array
    transposeGraph(v, trans, adj);
    fill(visited.begin(), visited.end(), false);

    // call dfs using the transpose graph
    int countSSC = 0;
    while (!st.empty())
    {
        int topElm = st.top();
        st.pop();

        if (!visited[topElm])
        {
            countSSC ++;
            dfs(topElm, visited, trans);
        }
    }

    return countSSC;
}

int main()
{
    int v = 5, e = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 4}, {2, 3}, {3, 2}, {4, 0}};

    int SSC = stronglyConnectedComponents(v, edges);

    cout << "Number of strongly connected graph : " << SSC << endl;
    return 0;
}