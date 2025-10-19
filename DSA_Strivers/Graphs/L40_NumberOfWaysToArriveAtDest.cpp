/*
    Number of Ways to Arrive at Destination

    You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

    You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

    Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

    Example 1:

    Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
    Output: 4
    Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
    The four ways to get there in 7 minutes are:
    - 0 ➝ 6
    - 0 ➝ 4 ➝ 6
    - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
    - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
    Example 2:

    Input: n = 2, roads = [[1,0,10]]
    Output: 1
    Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.


    Constraints:

    1 <= n <= 200
    n - 1 <= roads.length <= n * (n - 1) / 2
    roads[i].length == 3
    0 <= ui, vi <= n - 1
    1 <= timei <= 10^9
    ui != vi
    There is at most one road connecting any two intersections.
    You can reach any intersection from any other intersection.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<vector<int>>> adj(n);
        for (vector<int>& road : roads)
        {
            int u = road[0];
            int v = road[1];
            int t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        int src = 0, dst = n - 1;
        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

        dist[src] = 0;
        ways[src] = 1;
        pq.push({dist[src], src});  // {time, node}
        while (!pq.empty())
        {
            long long d = pq.top()[0];
            int u = pq.top()[1];
            pq.pop();

            for (vector<int>& node : adj[u])
            {
                int v = node[0];
                int t = node[1];
                long long newDist = 1LL*d + 1LL*t;

                if (newDist < dist[v])   // first time
                {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (newDist == dist[v])
                    ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
        return ways[dst] % MOD;
    }
};

int main()
{
    int n = 7;
    vector<vector<int>> roads = {{0, 6, 7},{0, 1, 2},{1, 2, 3},{1, 3, 3},{6, 3, 3},{3, 5, 1},{6, 5, 1},{2, 5, 1},{0, 4, 5},{4, 6, 2}};

    Solution sol;
    cout << sol.countPaths(n, roads) << endl;
    return 0;
}