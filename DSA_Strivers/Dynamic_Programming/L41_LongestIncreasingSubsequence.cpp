/*
    Longest Increasing Subsequence

    Given an integer array nums, return the length of the longest strictly increasing subsequence.

    Example 1:

    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
    Example 2:

    Input: nums = [0,1,0,3,2,3]
    Output: 4
    Example 3:

    Input: nums = [7,7,7,7,7,7,7]
    Output: 1

    Constraints:

    1 <= nums.length <= 2500
    -10^4 <= nums[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int curr, int prev, int n, vector<int> &nums)
{
    if (curr >= n)
        return 0;

    // not take
    int exc = solveRecur(curr + 1, prev, n, nums);

    // take
    int inc = 0;
    if (prev == -1 || nums[curr] > nums[prev])
        inc = 1 + solveRecur(curr + 1, curr, n, nums);

    return max(inc, exc);
}

int solveRM(int curr, int prev, int n, vector<int> &nums, vector<vector<int>> &dp)
{
    if (curr >= n)
        return 0;
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // not take
    int exc = solveRM(curr + 1, prev, n, nums, dp);

    // take
    int inc = 0;
    if (prev == -1 || nums[curr] > nums[prev])
        inc = 1 + solveRM(curr + 1, curr, n, nums, dp);

    dp[curr][prev + 1] = max(inc, exc);
    return dp[curr][prev + 1];
}

int solveTab(int n, vector<int> &nums)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // not take
            int exc = dp[curr + 1][prev + 1];

            // take
            int inc = 0;
            if (prev == -1 || nums[curr] > nums[prev])
                inc = 1 + dp[curr + 1][curr + 1];

            dp[curr][prev + 1] = max(inc, exc);
        }
    }
    return dp[0][0];
}

int solveTab2(int n, vector<int>& nums)
{
    vector<int> dp(n, 1);

    int lis = 0;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev ++)
        {
            if (nums[prev] < nums[i])
                dp[i] = max(dp[i], 1 + dp[prev]);
        }
        lis = max(dp[i], lis);
    }
    return lis;
}

int solveSO(int n, vector<int> &nums)
{
    vector<int> nextRow(n + 1, 0), currRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // not take
            int exc = nextRow[prev + 1];

            // take
            int inc = 0;
            if (prev == -1 || nums[curr] > nums[prev])
                inc = 1 + nextRow[curr + 1];

            currRow[prev + 1] = max(inc, exc);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

// T.C. : O(n log(n)), S.C. : O(n)
int LISUsingBS(vector<int>& nums)
{
    vector<int> arr;
    arr.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > arr.back())
            arr.push_back(nums[i]);
        else
        {
            // find index to replace 
            vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), nums[i]);
            int ind = it - arr.begin();
            arr[ind] = nums[i];
        }
    }
    return arr.size();
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    // Recursion
    // return solveRecur(0, -1, n, nums);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return solveRM(0, -1, n, nums, dp);

    // Tabulation
    // return solveTab(n, nums);
    // return solveTab2(n, nums);

    // Space Optimization
    // return solveSO(n, nums);
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;  
    return 0;
}