/*
    Introduction to graphs
*/

#include<bits/stdc++.h>
using namespace std;

template <class T>
class graph
{
private:
    vector<vector<T>> adj;
    int e;  // edges
    int v;  // vertices
    bool directed;

    void insertEdge(T u, T v, bool directed)     // directed = 0 : undirected 
    {
        this->adj[u].push_back(v);

        if (!directed)
        {
            this->adj[v].push_back(u);
        }
    }

public:
    graph(int ed, int vr, bool dir)
    {
        this->e = ed;
        this->v = vr;
        this->directed = dir;
        this->adj.resize(vr);
    }

    void insert()
    {
        for (int i = 0; i < this->e; i++)
        {
            int u, v;
            cout << "Enter u, v : ";
            cin >> u >> v;
            insertEdge(u, v, this->directed);
        }
    }

    void printGraph()
    {
        cout << endl << endl;
        for (int i = 0; i < this->v; i++)
        {
            cout << i << " -> ";
            for (auto j : adj[i])
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph<int> g(7, 8, false);
    g.insert();
    g.printGraph();
    return 0;
}