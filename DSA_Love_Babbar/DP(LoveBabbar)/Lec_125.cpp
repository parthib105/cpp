/*
    Longest Arithmetic Subsequence

    Given an array arr[] of sorted and distinct positive integers. The task is to find the length of the longest arithmetic 
    progression in a given array.

    Note: A sequence seq is an arithmetic progression if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

    Examples:

    Input:arr[] = [1, 7, 10, 13, 14, 19]
    Output: 4
    Explanation: The longest arithmetic progression is [1, 7, 13, 19].
    Input:arr[] = [2, 4, 6, 8, 10]
    Output: 5
    Explanation: The whole array is in AP.

    Expected Time Complexity: O(n^2)
    Expected Auxiliary Space: O(n^2)

    Constraints:
    1 <= arr.size() <= 1000
    1 <= arr[i] <= 10^4
*/

#include<bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(int i, int diff, vector<int> &arr)
{
    if (i < 0)
    {
        return 0;
    }

    int ans = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[i] - arr[j] == diff)
        {
            ans = max(ans, 1 + solveRecur(j, diff, arr));
        }
    }
    return ans;
}

// Tabulation
int solveTab(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 2)
    {
        return n;
    }

    int ans = 0;
    unordered_map<int, int> dp[n + 1];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = arr[i] - arr[j];
            int cnt = 1;

            // check if answer is present
            if (dp[j].count(diff))
            {
                cnt = dp[j][diff];
            }

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

// Recursion + Memoization
int solveRM(int i, int diff, vector<int> &arr, unordered_map<int, int> dp[])
{
    if (i < 0)
    {
        return 0;
    }

    if (dp[i].count(diff))
    {
        return dp[i][diff];
    }

    int ans = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[i] - arr[j] == diff)
        {
            ans = max(ans, 1 + solveRM(j, diff, arr, dp));
        }
    }
    return dp[i][diff] = ans;
}

int lengthOfLongestAP(vector<int>& arr) 
{
    int n = arr.size();
    int ans = 0;

    if (n <= 2)
    {
        return n;
    }

    // Recursion
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         ans = max(ans, 2 + solveRecur(i, arr[j] - arr[i], arr));
    //     }
    // }

    // Recursion + Memoization
    unordered_map<int, int> dp[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, 2 + solveRM(i, arr[j] - arr[i], arr, dp));
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 10};
    cout << lengthOfLongestAP(arr) << endl;
    return 0;
}