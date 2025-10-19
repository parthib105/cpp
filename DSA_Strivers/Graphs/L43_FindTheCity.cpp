/*
    Find the City With the Smallest Number of Neighbors at a Threshold Distance

    There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

    Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

    Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

    

    Example 1:



    Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
    Output: 3
    Explanation: The figure above describes the graph. 
    The neighboring cities at a distanceThreshold = 4 for each city are:
    City 0 -> [City 1, City 2] 
    City 1 -> [City 0, City 2, City 3] 
    City 2 -> [City 0, City 1, City 3] 
    City 3 -> [City 1, City 2] 
    Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
    Example 2:



    Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
    Output: 0
    Explanation: The figure above describes the graph. 
    The neighboring cities at a distanceThreshold = 2 for each city are:
    City 0 -> [City 1] 
    City 1 -> [City 0, City 4] 
    City 2 -> [City 3, City 4] 
    City 3 -> [City 2, City 4]
    City 4 -> [City 1, City 2, City 3] 
    The city 0 has 1 neighboring city at a distanceThreshold = 2.
    

    Constraints:

    2 <= n <= 100
    1 <= edges.length <= n * (n - 1) / 2
    edges[i].length == 3
    0 <= fromi < toi < n
    1 <= weighti, distanceThreshold <= 10^4
    All pairs (fromi, toi) are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<vector<int>>> adj;

    void dijkstraUtil(int src, int n, vector<vector<int>> &dist)
    {
        set<pair<int, int>> st;

        dist[src][src] = 0;
        st.insert({dist[src][src], src});
        while (!st.empty())
        {
            set<pair<int, int>>::iterator it = st.begin();
            int d = it->first;
            int u = it->second;
            st.erase(it);

            for (vector<int> &nbd : this->adj[u])
            {
                int v = nbd[0];
                int w = nbd[1];

                if (d + w < dist[src][v])
                {
                    dist[src][v] = d + w;
                    st.insert({dist[src][v], v});
                }
            }
        }
    }

    int findTheCityDA(int n, int dT, vector<vector<int>> &edges, vector<vector<int>> &dist)
    {
        this->adj = vector<vector<vector<int>>>(n);

        // fill the adj mat
        for (vector<int> &e : edges)
        {
            this->adj[e[0]].push_back({e[1], e[2]});
            this->adj[e[1]].push_back({e[0], e[2]});
        }

        // for each node, apply the dijkstra algo
        for (int u = 0; u < n; u++)
            dijkstraUtil(u, n, dist);

        int cntMin = n, city = n - 1;
        for (int u = n - 1; u >= 0; u--)
        {
            int cnt = 0;
            for (int v = 0; v < n; v++)
            {
                if (dist[u][v] <= dT)
                    cnt++;
            }

            if (cnt < cntMin)
            {
                cntMin = cnt;
                city = u;
            }
        }
        return city;
    }

    int findTheCityFW(int n, int dT, vector<vector<int>> &edges, vector<vector<int>> &dist)
    {
        for (vector<int> &e : edges)
        {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Floyd Warsall
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == 1e9 || dist[k][j] == 1e9)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntMin = n, city = n - 1;
        for (int u = n - 1; u >= 0; u--)
        {
            int cnt = 0;
            for (int v = 0; v < n; v++)
            {
                if (dist[u][v] <= dT)
                    cnt++;
            }

            if (cnt < cntMin)
            {
                cntMin = cnt;
                city = u;
            }
        }
        return city;
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // Using Dijkstra
        // return findTheCityDA(n, distanceThreshold, edges, dist);

        // Using Floyd Warsall
        return findTheCityFW(n, distanceThreshold, edges, dist);
    }
};

int main()
{
    int n = 4, distanceThreshold = 4;
    vector<vector<int>> edges = {{0, 1, 3},{1, 2, 1},{1, 3, 4},{2, 3, 1}};

    Solution sol;
    int city = sol.findTheCity(n, edges, distanceThreshold);

    cout << city << endl;
    return 0;
}