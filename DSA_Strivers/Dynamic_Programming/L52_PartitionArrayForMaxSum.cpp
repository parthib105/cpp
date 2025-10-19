/*
    Partition Array for Maximum Sum

    Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

    Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.



    Example 1:

    Input: arr = [1,15,7,9,2,5,10], k = 3
    Output: 84
    Explanation: arr becomes [15,15,15,9,10,10,10]
    Example 2:

    Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
    Output: 83
    Example 3:

    Input: arr = [1], k = 1
    Output: 1


    Constraints:

    1 <= arr.length <= 500
    0 <= arr[i] <= 10^9
    1 <= k <= arr.length
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int n, int k, vector<int> &arr)
{
    if (i >= n)
        return 0;

    int maxSum = 0, maxElm = INT_MIN;
    for (int j = i; j < min(n, i + k); j++)
    {
        maxElm = max(maxElm, arr[j]);
        int currSum = maxElm * (j - i + 1) + solveRecur(j + 1, n, k, arr);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int solveRM(int i, int n, int k, vector<int> &arr, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int maxSum = 0, maxElm = INT_MIN;
    for (int j = i; j < min(n, i + k); j++)
    {
        maxElm = max(maxElm, arr[j]);
        int currSum = maxElm * (j - i + 1) + solveRM(j + 1, n, k, arr, dp);
        maxSum = max(maxSum, currSum);
    }
    dp[i] = maxSum;
    return dp[i];
}

int solveTab(int n, int k, vector<int> &arr)
{
    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        int maxSum = 0, maxElm = INT_MIN;
        for (int j = i; j < min(n, i + k); j++)
        {
            maxElm = max(maxElm, arr[j]);
            int currSum = maxElm * (j - i + 1) + dp[j + 1];
            maxSum = max(maxSum, currSum);
        }
        dp[i] = maxSum;
    }
    return dp[0];
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();

    // Recursion
    // return solveRecur(0, n, k, arr);

    // Recursion + Memoization
    // vector<int> dp(n, -1);
    // return solveRM(0, n, k, arr, dp);

    // Tabulation
    return solveTab(n, k, arr);
}

int main()
{
    int k = 3;
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    cout << maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}