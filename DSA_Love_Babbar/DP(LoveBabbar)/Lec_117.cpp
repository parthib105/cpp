/*
    Minimum Sideway Jumps

    There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the 
    second lane and wants to jump to point n. However, there could be obstacles along the way.

    You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on 
    the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one 
    obstacle in the 3 lanes at each point.

    For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.

    The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point 
    i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) 
    at the same point if there is no obstacle on the new lane.

    For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
    Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

    Note: There will be no obstacles on points 0 and n.

    
    Example 1:

    Input: obstacles = [0,1,2,3,0]
    Output: 2 
    Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
    Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
    
    Example 2:

    Input: obstacles = [0,1,1,3,3,0]
    Output: 0
    Explanation: There are no obstacles on lane 2. No side jumps are required.
    
    Example 3:

    Input: obstacles = [0,2,1,0,3,0]
    Output: 2
    Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
    
    Constraints:

    obstacles.length == n + 1
    1 <= n <= 5 * 105
    0 <= obstacles[i] <= 3
    obstacles[0] == obstacles[n] == 0
*/

#include<bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(int n, int currLane, int currPos, vector<int>& obstacles)
{
    // base case
    if (currPos == n)
    {
        return 0;
    }
    if (currPos + 1 <= n && obstacles[currPos + 1] != currLane)
    {
        return solveRecur(n, currLane, currPos + 1, obstacles);
    }

    int ans = INT_MAX;
    for (int i = 1; i <= 3; i++)
    {
        if (currLane != i && obstacles[currPos] != i)
        {
            ans = min(ans, 1 + solveRecur(n, i, currPos, obstacles));
        }
    }
    return ans;
}

// Recursion + Memoization
int solveRM(int n, int currLane, int currPos, vector<int>& obstacles, vector<vector<int>> &dp)
{
    // base case
    if (currPos == n)
    {
        return 0;
    }
    if (dp[currLane][currPos] != -1)
    {
        return dp[currLane][currPos];
    }
    if (currPos + 1 <= n && obstacles[currPos + 1] != currLane)
    {
        return solveRM(n, currLane, currPos + 1, obstacles, dp);
    }

    int ans = INT_MAX;
    for (int i = 1; i <= 3; i++)
    {
        if (currLane != i && obstacles[currPos] != i)
        {
            ans = min(ans, 1 + solveRM(n, i, currPos, obstacles, dp));
        }
    }
    dp[currLane][currPos] = ans;
    return dp[currLane][currPos];
}

// Tabulation
int solveTab(vector<int>& obstacles)
{
    int n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(n + 1, INT_MAX));

    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for (int pos = n - 1; pos >= 0; pos --)
    {
        for (int lane = 1; lane <= 3; lane++)
        {
            if (obstacles[pos + 1] != lane)
            {
                dp[lane][pos] = dp[lane][pos + 1];
            }
            else
            {
                int ans = 1e9;
                for (int l = 1; l <= 3; l++)
                {
                    if (lane != l && obstacles[pos] != l)
                    {
                        ans = min(ans, 1 + dp[l][pos + 1]);
                    }
                }
                dp[lane][pos] = ans;
            }
        }
    }

    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

// Space Optimization
int solveSO(vector<int>& obs)
{
    int n = obs.size() - 1;

    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int pos = n - 1; pos >= 0; pos --)
    {
        for (int lane = 1; lane <= 3; lane++)
        {
            if (obs[pos + 1] != lane)
            {
                curr[lane] = next[lane];
            }
            else
            {
                int ans = 1e9;
                for (int l = 1; l <= 3; l++)
                {
                    if (lane != l && obs[pos] != l)
                    {
                        ans = min(ans, 1 + next[l]);
                    }
                }
                curr[lane] = ans;
            }
        }
        next = curr;
    }
    return min(next[2], min(1 + next[1], 1 + next[3]));
}

int minSideJumps(vector<int>& obstacles) 
{
    int n = obstacles.size();
    // Recursive Solution
    // return solveRecur(obstacles.size() - 1, 2, 0, obstacles);

    // Recursion + memoization
    // vector<vector<int>> dp(4, vector<int>(n, -1));
    // return solveRM(n - 1, 2, 0, obstacles, dp);

    // Tabulation
    return solveTab(obstacles);
}

int main()
{
    vector<int> obstacles = {0,1,2,3,0};

    cout << minSideJumps(obstacles) << endl;
    return 0;
}