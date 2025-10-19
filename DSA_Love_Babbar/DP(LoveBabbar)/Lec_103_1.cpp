/*
    Count Ways To Reach The N-th Stairs

    You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
    Each time, you can climb either one step or two steps.
    You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

    Example :
    N=3

    We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or we can climb the first two-step and then one step i.e. 
    {(0,2),(1, 3)} or we can climb first one step and then two step i.e. {(0,1), (1,3)}.

    Constraints :
    0 <= 'N' <= 10^5

    Where 'T' is the number of test cases, and 'N' is the number of stairs.

    It is guaranteed that sum of 'N' over all test cases is <= 10^5.

    Sample Input 1 :
    2
    3

    Sample Output 1 :
    2
    3

    Explanation Of Sample Input 1 :
    In the first test case, there are only two ways to climb the stairs, i.e. {1,1} and {2}.
    In the second test case, there are three ways to climb the stairs i.e. {1,1,1} , {1,2} and {2,1}.

    Sample Input 2 :
    4
    5

    Sample Output 2 :
    5
    8

    Explanation Of Sample Input 2 :
    In the first test case, there are five ways to climb the stairs i.e. {1,1,1,1} , {1,1,2} , {2,1,1} , {1,2,1} , {2,2}.
    In the second test case, there are eight ways to climb the stairs i.e. {1,1,1,1,1} , {1,1,1,2} , {1,1,2,1}, {1,2,1,1}, 
    {2,1,1},{2,2,1},{2,1,2} and {2,2,1}.
*/

#include<bits/stdc++.h>
using namespace std;
#define m 100000007;

// using recursion
int countDistinctWays(int nStairs) 
{
    if (nStairs == 0)
    {
        return 1;
    }

    if (nStairs < 0)
    {
        return 0;
    }

    return (countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2)) % m;
}

// Recursion + Memoization
int countDistinctWaysRM(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (countDistinctWaysRM(n - 1, dp) + countDistinctWaysRM(n - 2, dp)) % m;
    return dp[n];
}

// Tabulation
int countDistinctWaysTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimization
int countDistinctWaysSO(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int prev2 = 1;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = (prev1 + prev2) % m;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);

    cout << endl << "Solution using recursion : " << countDistinctWays(n) << endl;

    cout << endl << "Solution using recursion + memoization : " << countDistinctWaysRM(n, dp) << endl;

    cout << endl << "Solution using Tabulation : " << countDistinctWaysTab(n) << endl;

    cout << endl << "Solution using Space Optimized DP : " << countDistinctWaysSO(n) << endl;
    return 0;
}