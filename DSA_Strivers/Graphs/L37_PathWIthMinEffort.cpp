/*
    Path With Minimum Effort

    You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

    Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

    

    Example 1:



    Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
    Output: 2
    Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
    This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
    Example 2:



    Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
    Output: 1
    Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
    Example 3:


    Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
    Output: 0
    Explanation: This route does not require any effort.
    

    Constraints:

    rows == heights.length
    columns == heights[i].length
    1 <= rows, columns <= 100
    1 <= heights[i][j] <= 10^6
*/

#include<bits/stdc++.h>
using namespace std;

class solution
{
private:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size(), n = heights[0].size();
        int dx = m - 1, dy = n - 1;    
        int sx = 0, sy = 0;

        set<vector<int>> st;    // {effort, r, c}
        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        dist[sx][sy] = 0;
        st.insert({dist[sx][sy], sx, sy});
        while (!st.empty())
        {
            set<vector<int>>::iterator it = st.begin();
            int currEffort = (*it)[0];
            int ux = (*it)[1];
            int uy = (*it)[2];
            st.erase(it);
            
            if (ux == dx && uy == dy)
                return currEffort;
            
            for (int i = 0; i < 4; i++)
            {
                int vx = ux + dr[i];
                int vy = uy + dc[i];

                if ((vx >= 0 && vx < m) && (vy >= 0 && vy < n))
                {
                    int newEffort = max(currEffort, abs(heights[vx][vy] - heights[ux][uy]));
                    if (newEffort < dist[vx][vy])
                    {
                        if (dist[vx][vy] != INT_MAX)
                            st.erase({dist[vx][vy], vx, vy});
                        
                        dist[vx][vy] = newEffort;
                        st.insert({dist[vx][vy], vx, vy});
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};

    solution Sol;
    cout << Sol.minimumEffortPath(heights) << endl;
    return 0;
}