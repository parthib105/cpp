/*
    Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.

    Examples :

    Input: adj[][] = [[2, 3], [0], [1], [4], []]

    Output: 3
    Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.

    Input: adj[][] = [[1], [2], [0]]

    Output: 1
    Explanation: All of the nodes are connected to each other. So, there's only one SCC.
    Input: adj[][] = [[1], []]
    Output: 2
    Constraints:
    2<=adj.size()<=10^6
    0<=edges<=adj.size()-1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void _1_dfsUtil(int u, stack<int> &st, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[u] = true;
        for (int v : adj[u])
        {
            if (!vis[v])
                _1_dfsUtil(v, st, vis, adj);
        }
        st.push(u);
    }

    void _2_dfsUtil(int u, vector<int> &curScc, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[u] = true;
        curScc.push_back(u);
        for (int v : adj[u])
        {
            if (!vis[v])
                _2_dfsUtil(v, curScc, vis, adj);
        }
    }

public:
    vector<vector<int>> scc;

    int kosaraju(vector<vector<int>> &adj)
    {
        this->scc.clear();
        int n = adj.size();

        // step 1 : store the nodes according to the finishing time
        stack<int> st;
        vector<bool> vis(n, false);
        for (int u = 0; u < n; u++)
        {
            if (!vis[u])
                _1_dfsUtil(u, st, vis, adj);
        }

        // step 2 : reverse the graph
        vector<vector<int>> adjT(n);
        for (int u = 0; u < n; u++)
        {
            vis[u] = false;
            for (int v : adj[u])
                adjT[v].push_back(u);
        }

        // step 3 : dfs call to find scc
        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            if (!vis[u])
            {
                vector<int> curScc;
                _2_dfsUtil(u, curScc, vis, adjT);
                this->scc.push_back(curScc);
            }
        }
        return this->scc.size();
    }
};

int main()
{
    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};
    Solution sol;
    cout << sol.kosaraju(adj) << endl;

    for (vector<int> curScc : sol.scc)
    {
        for (int elm : curScc)
            cout << elm << " ";
        cout << endl;
    }
    return 0;
}