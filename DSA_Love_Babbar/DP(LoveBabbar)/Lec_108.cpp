/*
    Count derangements

    A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an 
    instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which 
    is 2 and similarly for other elements of the sequence.

    Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

    Note:
    The answer could be very large, output answer %(10 ^ 9 + 7).

    Constraints:
    1 <= N <= 3000

    Time limit: 1 sec

    Sample Input 1:
    2
    3
    Sample Output 1:
    1
    2
    Explanation of Sample Output 1:
    In test case 1, For two elements say {0, 1}, there is only one possible derangement {1, 0}. 1 is present at index 0 and 
    not at its actual position, that is, 1. Similarly, 0 is present at index 1 and not at its actual position, that is, 0.

    In test case 2, For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}. In both 
    the derangements, no element is present at its actual position.
*/

#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

// Recursive solution
long long int solveRecur(int n)
{
    if (n <= 2)
    {
        return n - 1;
    }

    long long int ans = ((n - 1) * (solveRecur(n - 1) % m + solveRecur(n - 2) % m)) % m;
    return ans;
}

// Recursion + Memoization
long long int solveRM(int n, vector<long long int> &dp)
{
    if (n <= 2)
    {
        return n - 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = ((n - 1) * (solveRecur(n - 1) % m + solveRecur(n - 2) % m)) % m;
    return dp[n];
}

// Tabulation
long long int solveTab(int n)
{
    vector<long long int> dp(n + 1, -1);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((i - 1) * (dp[i - 1] % m + dp[i - 2] % m)) % m;
    }
    return dp[n];
}

// Space Optimization
long long int solveSO(int n)
{
    long long int prev2 = 0;
    long long int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int curr = ((i - 1) * (prev1 % m + prev2 % m)) % m;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long int countDerangements(int n) 
{
    // Recursive solution
    // return solveRecur(n);

    // Recursion + Memoization
    // vector<long long int> dp(n + 1, -1);
    // return solveRM(n, dp);

    // Tabulation
    // return solveTab(n);

    // Space Optimization
    return solveSO(n);
}

int main()
{
    int n = 10;
    cout << "Number of derangements : " << countDerangements(n) << endl;
    return 0;
}