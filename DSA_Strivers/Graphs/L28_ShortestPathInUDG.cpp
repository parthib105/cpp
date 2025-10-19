/*
    Shortest path in Undirected Graph

    The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.

    A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.

    For example
    In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). You can also go from S=1 to T=8  via (1, 2, 5, 8)  or (1, 4, 6, 7, 8) but these paths are not shortest.

      2 --------- 5 
     /             \
    1 --- 3 ------- 8
     \             /
      4 --- 6 --- 7

    Detailed explanation ( Input/output format, Notes, Images )
    Constraints :
    1 <= T <= 100
    2 <= N <= 10 ^ 3
    1 <= M <= min( N *(N - 1) / 2 , 1000 )
    1 <= S, T <= N

    Time Limit: 1 sec
    Sample input 1 :
    1
    4 4
    1 4
    1 2
    2 3
    3 4
    1 3
    Sample Output 1 :
    ( 1 , 3 , 4 )
    Explanation of Sample input 1 :
    In the above graph there are two ways to go from 1 to 4 ,
    ( 1 , 2 , 3 , 4 ) and ( 1 , 3 , 4 ) but the second path is the shortest path.

    Sample input 2 :
    1
    8 9
    1 8
    1 2
    1 3
    1 4
    2 5
    5 8 
    3 8
    4 6
    6 7
    7 8
    Sample output 2 :
    ( 1 , 3 , 8 )
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, int s, int t, vector<pair<int, int>>& edges)
{
    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    // Build adjacency list
    for (pair<int, int> &edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS
    q.push(s);
    dist[s] = 0;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] == INT_MAX)
            {
                dist[v] = dist[u] + 1;
                parent[v] = u;   // keep track of path
                q.push(v);
            }
        }
    }

    // Reconstruct path from t → s
    vector<int> path;
    if (dist[t] == INT_MAX) 
        return path; // no path

    for (int cur = t; cur != -1; cur = parent[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());
    return path;
}

int main() 
{
    int n = 8, m = 9;
    int s = 1, t = 8;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 8}, {2, 5}, {5, 8}, {4, 6}, {6, 7}, {7, 8}};
    
    vector<int> path = shortestPath(n, m, s, t, edges);
    
    cout << "( ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i + 1 < path.size()) 
            cout << " , ";
    }
    cout << " )" << endl;
    return 0;
}