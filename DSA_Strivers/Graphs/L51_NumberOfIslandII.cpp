/*
    Number of Island II

    You have a 2D grid of ‘N’ rows and ‘M’ columns which are initially filled with water. You are given ‘Q’ queries each consisting of two integers ‘X’ and ‘Y’ and in each query operation, you have to turn the water at position (‘X’, ‘Y’) into a land. You are supposed to find the number of islands in the grid after each query.

    An island is a group of lands surrounded by water horizontally, vertically, or diagonally.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:

    1 <= T <= 5
    1 <= N <= 1000
    1 <= M <= 1000
    1 <= Q <= 100000
    0 <= X < N
    0 <= Y < M

    Time limit: 1 sec

    Sample Input 1:

    2
    3 3
    4
    0 0
    0 1
    1 2
    2 1
    4 5
    4
    1 1
    0 1
    3 3
    3 4

    Sample Output 1:

    1 1 2 3
    1 1 2 2

    Explanation of Sample Output 1:

    In test case 1, 

    0.  000
        000
        000

    1.  100
        000
        000

    2.  110
        000
        000

    3. 110
        001
        000

    4. 110
        001
        100

    So, the answer is 1, 1, 2, 3.

    In test case 2,

    0.  00000
        00000
        00000
        00000

    1.  00000
        01000
        00000
        00000

    2.  01000
        01000
        00000
        00000

    3. 01000
        01000
        00000
        00010

    4. 01000
        01000
        00000
        00011

    So, the answer is 1, 1, 2, 2.

    Sample Input 2:

    2
    2 2
    2
    0 0
    1 1
    1 1
    1
    0 0

    Sample Output 2:

    1 2
    1

    Explanation of Sample Output 2:

    In test case 1, 

    0.  00
        00

    1.  10
        00

    2.  10
        01

    So, the answer is 1, 2.

    In test case 2,

    0.  0

    1.  1

    So, the answer is 1.
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    int n;
    vector<int> rank, parent;

public:
    DisjointSet(int sz)
    {
        this->n = sz;
        this->rank.resize(this->n + 1, 0);
        this->parent.resize(this->n + 1);
        
        for (int i = 0; i < this->n; i++)
            this->parent[i] = i;
    }

    int findParent(int u)
    {
        if (u == this->parent[u])
            return u;

        this->parent[u] = findParent(this->parent[u]);
        return this->parent[u];
    }

    void unionByRank(int u, int v)
    {
        // find the ultimate parents
        int up_u = this->findParent(u);
        int up_v = this->findParent(v);

        if (up_u == up_v)   // same parent, return
            return;

        if (this->rank[up_u] < this->rank[up_v])
            this->parent[up_u] = up_v;
        else if (this->rank[up_v] < this->rank[up_u])
            this->parent[up_v] = up_u;
        else
        {
            this->parent[up_v] = up_u;
            this->rank[up_u] += 1;
        }
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &queries)
{
    int cntIslands = 0;
	DisjointSet ds(n * m);
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    vector<int> ans;
    for (vector<int> q : queries)
    {
        int ux = q[0];
        int uy = q[1];

        if (vis[ux][uy])
        {
            ans.push_back(cntIslands);
            continue;
        }

        vis[ux][uy] = true;
        cntIslands ++;
        
        for (int i = 0; i < 4; i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if ((vx >= 0 && vx < n) && (vy >= 0 && vy < m) && vis[vx][vy])
            {
                int curNode = ux * m + uy;
                int adjNode = vx * m + vy;
                if (ds.findParent(curNode) != ds.findParent(adjNode))   // if not connected
                {
                    cntIslands --;
                    ds.unionByRank(curNode, adjNode);
                }
            }
        }
        ans.push_back(cntIslands);
    }
    return ans;
}

int main() 
{
    
    return 0;
}