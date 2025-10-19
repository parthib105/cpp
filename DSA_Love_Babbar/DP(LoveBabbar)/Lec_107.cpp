/*
    Cut Into Segments

    You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can 
    make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.

    Sample Input 1:
    7 5 2 2
    8 3 3 3
    Sample Output 1:
    2
    0
    Explanation For Sample Input 1:
    In the first test case, cut it into 2 parts of 5 and 2.

    In the second case, there is no way to cut into segments of 3 length only as the length of the rod is less than the given 
    length.

    Sample Input 2:
    7 3 2 2
    8 1 4 4
    Sample Output 2:
    3
    8
    Explanation For Sample Input 2:
    In the first test case, cut it into 3 parts of 3, 2 and 2.

    In the second case, cut it into 8 parts of length 1.
*/

#include<bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }
    
    if (n < 0)
    {
        return INT_MIN;
    }

    // check for all cases
    int a = solveRecur(n - x, x, y, z) + 1;
    int b = solveRecur(n - y, x, y, z) + 1;
    int c = solveRecur(n - z, x, y, z) + 1;

    return max(a, max(b, c));
}

// Recursion + Memoization
int solveRM(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // check for all cases
    int a = solveRM(n - x, x, y, z, dp) + 1;
    int b = solveRM(n - y, x, y, z, dp) + 1;
    int c = solveRM(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

// Tabulation
int solveTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    if (dp[n] < 0)
    {
        return 0;
    }
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) 
{
	// Recursive solution
    // int ans = solveRecur(n, x, y, z);
    // if (ans < 0)
    // {
    //     return 0;
    // }
    // return ans;

    // Recursion + Memoization
    vector<int> dp(n + 1, -1);
    int ans = solveRM(n, x, y, z, dp);
    if (ans < 0)
    {
        return 0;
    }
    return ans;

    // Tabulation
    return solveTab(n, x, y, z);
}

int main()
{
    int n = 8, x = 1, y = 4, z = 4;
    cout << cutSegments(n, x, y, z) << endl;
    return 0;
}