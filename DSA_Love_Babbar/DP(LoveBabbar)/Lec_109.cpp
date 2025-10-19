/*
    Painting Fence Algorithm

    Ninja And The Fence

    Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja 
    wants to paint the fence so that not more than two adjacent posts have the same color.

    Ninja wonders how many ways are there to do the above task, so he asked for your help.

    Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

    Example:
    Input: 'N' = 3, 'K' = 2
    Output: 6

    Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.

    110
    001
    101
    100
    010
    011
    
    Constraints :
    1 <= 'N' <= 10^5
    1 <= 'K' <= 10^5
    Time Limit: 1 sec

    Sample Input 1 :
    1 1
    3 2
    Sample Output 1 :
    1
    6
    Explanation Of Sample Input 1 :
    For the first test case, there is only one way to paint the fence. 

    For the second test case, We can paint the fence with 3 posts with the following different combinations.

    110
    001
    101
    100
    010
    011

    Sample Input 2 :
    2 4
    4 2
    Sample Output 2 :
    16
    10
*/

#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

int add(int a, int b)
{
    return (a % m + b % m) % m;
}

int mult(int a, int b)
{
    return ((a % m) * (b % m)) % m;
}

// Recursive Approach
int solveRecur(int n, int k)
{
    if (n == 1)     // no. of ways to paint 1 fence
    {
        return k;
    }
    else if (n == 2)       // no. of ways to paint 2 fence = k + k(k - 1) = k^2
    {
        return mult(k, k);
    }

    int ans = mult(k - 1, add(solveRecur(n - 1, k), solveRecur(n - 2, k)));
    return ans;
}

// Recursion + Memoization
int solveRM(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    else if (n == 2)
    {
        return mult(k, k);
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = mult(k - 1, add(solveRM(n - 1, k, dp), solveRM(n - 2, k, dp)));
    return dp[n];
}

// Tabulation
int solveTab(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = mult(k, k);

    for (int i = 3; i <= n; i++)
    {
        dp[i] = mult(k - 1, add(dp[i - 1], dp[i - 2]));
    }
    return dp[n];
}

// Space Optimization
int solveSO(int n, int k)
{
    int prev2 = k;
    int prev1 = mult(k, k);

    for (int i = 3; i <= n; i++)
    {
        int curr = mult(k - 1, add(prev1, prev2));
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int numberOfWays(int n, int k) 
{
    // Recursive Apporach
    // return solveRecur(n, k);

    // Recursion + Memoization
    // vector<int> dp(n + 1, -1);
    // return solveRM(n, k, dp);

    // Tabulation
    // return solveTab(n, k);

    // Space Optimization
    return solveSO(n, k);
}

int main()
{
    int n = 2, k = 4;
    cout << "No. of ways to paint the fence : " << numberOfWays(n, k);
    return 0;
}