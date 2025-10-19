/*
    Shortest path in an undirected graph

    The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively 
    and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from 
    ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house from any other house via some combination of roads. 
    Two houses are directly connected by at max one road.

    A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ 
    and the ending house is ‘T’ and there is a road connecting two consecutive houses. Basically, the path looks like this: 
    (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.

    For example
    In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). You can also go 
    from S=1 to T=8  via (1, 2, 5, 8)  or (1, 4, 6, 7, 8) but these paths are not shortest.

                  2 -------- 5 
                 /             \
                1 --- 3 ------- 8  
                 \             /
                  4 --- 6 --- 7

    Constraints :
    2 <= N <= 10 ^ 3
    1 <= M <= min( N *(N - 1) / 2 , 1000 )
    1 <= S, T <= N

    Time Limit: 1 sec

    Sample input 1 :
    v = 4, e = 4
    s = 1, t = 4
    edges = {{0, 1}, {1, 2}, {2, 3}, {0, 2}}

    Sample Output 1 :
    ( 0 , 2 , 3 )
    Explanation of Sample input 1 :
    In the above graph there are two ways to go from 0 to 3 ,
    ( 0 , 1 , 2 , 3 ) and ( 0 , 2 , 3 ) but the second path is the shortest path.

               1
             / |
            0  |
             \ |
               2 --- 3
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t)
{
	
	vector<vector<int>> adj(n);
	vector<bool> visited(n, false);
	vector<int> parent(n, -1);
	queue<int> q;
	
	// make adj list
	for (int i = 0; i < m; i++)
	{
		adj[edges[i].first].push_back(edges[i].second);
		adj[edges[i].second].push_back(edges[i].first);
	}
	
	// bfs
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (auto child : adj[curr])
		{
			if (!visited[child])
			{
				parent[child] = curr;
				q.push(child);
				visited[child] = true;
			}
		}
	}

	// prepare sortest path
	vector<int> ans;
	int currNode = t;

	while (currNode != s)
	{
		ans.push_back(currNode);
		currNode = parent[currNode];
	}
	ans.push_back(currNode);

	// reverse the answer
	reverse(ans.begin(), ans.end());

	return ans;
}

int main()
{
    int v = 8, e = 9;
    int s = 0, t = 7;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {4, 7}, {2, 7}, {3, 5}, {5, 6}, {6, 7}};

    vector<int> path = shortestPath(edges, v, e, s, t);

    for (auto i : path)
    {
        cout << i << " ";
    }
    return 0;
}