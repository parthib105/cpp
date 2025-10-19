/*
    Cheapest Flights Within K Stops

    There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

    You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

    Example 1:


    Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
    Output: 700
    Explanation:
    The graph is shown above.
    The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
    Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
    Example 2:


    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
    Output: 200
    Explanation:
    The graph is shown above.
    The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
    Example 3:


    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
    Output: 500
    Explanation:
    The graph is shown above.
    The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
    

    Constraints:

    1 <= n <= 100
    0 <= flights.length <= (n * (n - 1) / 2)
    flights[i].length == 3
    0 <= fromi, toi < n
    fromi != toi
    1 <= pricei <= 10^4
    There will not be any multiple flights between two cities.
    0 <= src, dst, k < n
    src != dst
*/

#include <bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<pair<int, int>> adj[n];
    vector<int> price(n, INT_MAX);
    queue<pair<int, pair<int, int>>> q; // {stops, {node, dist}}

    // make adjacency list
    for (auto flight : flights)
    {
        int from = flight[0];
        int to = flight[1];
        int price = flight[2];
        adj[from].push_back({to, price});
    }

    price[src] = 0;
    q.push({0, {src, price[src]}});
    while (!q.empty())
    {
        int currStops = q.front().first;
        int currNode = q.front().second.first;
        int currPrice = q.front().second.second;
        q.pop();

        if (currStops > K)
            continue;

        for (auto child : adj[currNode])
        {
            int adjNode = child.first;
            int adjPrice = child.second;

            if (currPrice + adjPrice < price[adjNode] && currStops <= K)
            {
                price[adjNode] = currPrice + adjPrice;
                q.push({currStops + 1, {adjNode, price[adjNode]}});
            }
        }
    }

    if (price[dst] == INT_MAX)
    {
        return -1;
    }
    return price[dst];
}

int main()
{
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3, K = 1;

    cout << CheapestFLight(n, flights, src, dst, K) << endl;
    return 0;
}