/*
    M-Coloring Problem

    You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

    Note: The graph is indexed with 0-based indexing.

    Examples:

    Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
    Output: true
    Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

    Vertex 0: Color 1
    Vertex 1: Color 2
    Vertex 2: Color 2
    Vertex 3: Color 3
    Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
    Output: false
    Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
    Constraints:
    1 <= V <= 10
    1 <= E = edges.size() <= (V*(V-1))/2
    0 <= edges[i][j] <= V-1
    1 <= m <= V
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int c, int v, vector<int> &color, vector<vector<int>> &adj)
{
    for (int child : adj[node])
    {
        if (color[child] == c)
            return false;
    }
    return true;
}

bool solveRecur(int node, int m, int v, vector<int> &color, vector<vector<int>> &adj)
{
    if (node == v)
        return true;

    // try all possible colors
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(node, c, v, color, adj))
        {
            color[node] = c;
            bool ans = solveRecur(node + 1, m, v, color, adj);
            if (ans)
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(int v, vector<vector<int>> &edges, int m)
{
    vector<vector<int>> adj(v);
    for (vector<int> e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> color(v, 0);
    return solveRecur(0, m, v, color, adj);
}

int main()
{
    int v = 4, m = 3; 
    vector<vector<int>> edges = {{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}};

    bool ans = graphColoring(v, edges, m);
    if (ans)
        cout << "Possible" << endl;
    else
        cout << "Not possible" << endl;
    return 0;
}