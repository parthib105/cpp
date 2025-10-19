/*
    Ninja’s Training

    Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. 
    (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to 
    improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum 
    merit points Ninja can earn?

    You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to 
    calculate the maximum number of merit points that Ninja can earn.

    For Example
    If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
    
    Constraints:
    1 <= T <= 10
    1 <= N <= 100000.
    1 <= values of POINTS arrays <= 100 .

    Time limit: 1 sec
    Sample Input 1:
    2
    3
    1 2 5 
    3 1 1
    3 3 3
    3
    10 40 70
    20 50 80
    30 60 90
    Sample Output 1:
    11
    210
    Explanation of sample input 1:
    For the first test case,
    One of the answers can be:
    On the first day, Ninja will learn new moves and earn 5 merit points. 
    On the second day, Ninja will do running and earn 3 merit points. 
    On the third day, Ninja will do fighting and earn 3 merit points. 
    The total merit point is 11 which is the maximum. 
    Hence, the answer is 11.

    For the second test case:
    One of the answers can be:
    On the first day, Ninja will learn new moves and earn 70 merit points. 
    On the second day, Ninja will do fighting and earn 50 merit points. 
    On the third day, Ninja will learn new moves and earn 90 merit points. 
    The total merit point is 210 which is the maximum. 
    Hence, the answer is 210.
    
    Sample Input 2:
    2
    3
    18 11 19
    4 13 7
    1 8 13
    2
    10 50 1
    5 100 11
    Sample Output 2:
    45
    110
*/

#include<bits/stdc++.h>
using namespace std;

int solveRecur(int curr, int last, int n, vector<vector<int>> &points)
{
    if (curr >= n)
    {
        return 0;
    }

    int act = 0;

    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            act = max(act, points[curr][i] + solveRecur(curr + 1, i, n, points));
        }
    }

    return act;
}

int solveRM(int curr, int last, int n, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (curr >= n)
    {
        return 0;
    }
    if (dp[curr][last + 1] != -1)
    {
        return dp[curr][last + 1];
    }

    int act = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            act = max(act, points[curr][i] + solveRM(curr + 1, i, n, points, dp));
        }
    }

    dp[curr][last + 1] = act;
    return dp[curr][last + 1];
}

int solveTab(int n, vector<vector<int>> &points)
{
    // DP table initialization
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    // Base case: Fill the last day's points
    dp[n-1][0] = max(points[n-1][1], points[n-1][2]);
    dp[n-1][1] = max(points[n-1][0], points[n-1][2]);
    dp[n-1][2] = max(points[n-1][0], points[n-1][1]);
    dp[n-1][3] = max({points[n-1][0], points[n-1][1], points[n-1][2]});

    // Fill the table in bottom-up manner
    for (int day = n-2; day >= 0; day--) 
    {
        for (int last = 0; last < 4; last++) 
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) 
            {
                if (task != last) 
                {
                    dp[day][last] = max(dp[day][last], points[day][task] + dp[day + 1][task]);
                }
            }
        }
    }

    // The answer is the maximum points achievable starting on day 0 with no previous task
    return dp[0][3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Recursion
    // return solveRecur(0, -1, n, points);

    // Recursion + Memoization
    // vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    // return solveRM(0, -1, n, points, dp);

    // Tabulation
    return solveTab(n, points);
}

int main()
{
    int n = 3;
    vector<vector<int>> points = {{18, 11, 19}, {4, 13, 7}, {1, 8, 13}};

    cout << ninjaTraining(n, points) << endl;
    return 0;
}