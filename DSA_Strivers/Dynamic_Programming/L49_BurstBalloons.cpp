/*
    Burst Balloons

    You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

    If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

    Return the maximum coins you can collect by bursting the balloons wisely.

    Example 1:

    Input: nums = [3,1,5,8]
    Output: 167
    Explanation:
    nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
    coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
    Example 2:

    Input: nums = [1,5]
    Output: 10


    Constraints:

    n == nums.length
    1 <= n <= 300
    0 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int j, vector<int> &nums)
{
    if (i > j)
        return 0;

    int maxCoins = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        int left = solveRecur(i, k - 1, nums);
        int right = solveRecur(k + 1, j, nums);
        int currCoins = nums[i - 1] * nums[k] * nums[j + 1] + left + right;
        maxCoins = max(maxCoins, currCoins);
    }
    return maxCoins;
}

int solveRM(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int maxCoins = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        int left = solveRM(i, k - 1, nums, dp);
        int right = solveRM(k + 1, j, nums, dp);
        int currCoins = nums[i - 1] * nums[k] * nums[j + 1] + left + right;
        maxCoins = max(maxCoins, currCoins);
    }
    dp[i][j] = maxCoins;
    return dp[i][j];
}

int solveTab(int n, vector<int> &nums)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;

            int maxCoins = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int currCoins = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                maxCoins = max(maxCoins, currCoins);
            }
            dp[i][j] = maxCoins;
        }
    }
    return dp[1][n];
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    // recursion
    // return solveRecur(1, n, nums);

    // Recursion + Memoization
    // vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    // return solveRM(1, n, nums, dp);/

    // Tabulation
    return solveTab(n, nums);
}

int main()
{
    vector<int> nums = {3, 1, 5, 8};
    cout << maxCoins(nums) << endl;
    return 0;
}