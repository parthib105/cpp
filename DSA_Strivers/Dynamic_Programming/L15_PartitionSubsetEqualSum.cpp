/*
    Partition Equal Subset Sum

    Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

    Example 1:

    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].
    Example 2:

    Input: nums = [1,2,3,5]
    Output: false
    Explanation: The array cannot be partitioned into equal sum subsets.


    Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(2^N), S.C. : O(N) (stack space)
bool solveRecur(int i, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (i == 0)
        return arr[i] == target;

    // include
    bool exc = solveRecur(i - 1, target, arr);

    // exclude
    bool inc = false;
    if (arr[i] <= target)
        inc = solveRecur(i - 1, target - arr[i], arr);

    return inc || exc;
}

// T.C. : O(N x sum), S.C. : O(N x sum) + O(N) (stack space)
bool solveRM(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (i == 0)
        return arr[i] == target;

    if (dp[i][target] != -1)
        return dp[i][target];

    // include
    bool exc = solveRM(i - 1, target, arr, dp);

    // exclude
    bool inc = false;
    if (arr[i] <= target)
        inc = solveRM(i - 1, target - arr[i], arr, dp);

    dp[i][target] = inc || exc;
    return dp[i][target];
}

// T.C. : O(N x sum), S.C. : O(N x sum)
bool solveTab(int target, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // base case
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int t = 1; t <= target; t++)
        {
            // include
            bool exc = dp[i - 1][t];

            // exclude
            bool inc = false;
            if (arr[i] <= t)
                inc = dp[i - 1][t - arr[i]];

            dp[i][t] = inc || exc;
        }
    }
    return dp[n - 1][target];
}

// T.C. : O(N x sum), S.C. : O(2 x sum)
bool solveSO(int target, vector<int> &arr)
{
    int n = arr.size();

    vector<bool> prev(target + 1, false), curr(target + 1, false);

    // base case
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int t = 1; t <= target; t++)
        {
            // include
            bool exc = prev[t];

            // exclude
            bool inc = false;
            if (arr[i] <= t)
                inc = prev[t - arr[i]];

            curr[t] = inc || exc;
        }
        prev = curr;
    }
    return prev[target];
}

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += nums[i];

    if (totalSum & 1)
        return false;

    int target = totalSum / 2;

    // Recursive solution
    return solveRecur(n - 1, target, nums);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    // return solveRM(n - 1, target, nums, dp);

    // Tabulation
    // return solveTab(target, nums);

    // Space Optimization
    // return solveSO(target, nums);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    bool ans = canPartition(nums);

    if (ans)
        cout << "True" << endl;
    else   
        cout << "False" << endl;
    return 0;
}