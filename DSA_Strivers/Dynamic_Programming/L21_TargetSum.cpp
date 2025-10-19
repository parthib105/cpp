/*
    Target Sum

    You are given an integer array nums and an integer target.

    You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
    Return the number of different expressions that you can build, which evaluates to target.



    Example 1:

    Input: nums = [1,1,1,1,1], target = 3
    Output: 5
    Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3
    Example 2:

    Input: nums = [1], target = 1
    Output: 1


    Constraints:

    1 <= nums.length <= 20
    0 <= nums[i] <= 1000
    0 <= sum(nums[i]) <= 1000
    -1000 <= target <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, int k, int currSum, int n, vector<int> &arr)
{
    if (i == n)
        return currSum == k;

    int ways = 0;

    // pick
    if (currSum + arr[i] <= k)
        ways += solveRecur(i + 1, k, currSum + arr[i], n, arr);

    // skip
    ways += solveRecur(i + 1, k, currSum, n, arr);

    return ways;
}

int solveRM(int i, int k, int currSum, int n, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == n)
        return currSum == k;
    if (dp[i][currSum] != -1)
        return dp[i][currSum];

    int ways = 0;

    // pick
    if (currSum + arr[i] <= k)
        ways += solveRM(i + 1, k, currSum + arr[i], n, arr, dp);

    // skip
    ways += solveRM(i + 1, k, currSum, n, arr, dp);

    dp[i][currSum] = ways;
    return dp[i][currSum];
}

int solveTab(int k, int n, vector<int> &arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[n][k] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int s = k; s >= 0; s--)
        {
            int ways = 0;
            if (s + arr[i] <= k)
                ways += dp[i + 1][s + arr[i]];
            ways += dp[i + 1][s];
            dp[i][s] = ways;
        }
    }
    return dp[0][0];
}

int findTargetSumWays(vector<int> &arr, int d)
{
    int n = arr.size();
    int totSum = accumulate(arr.begin(), arr.end(), 0);

    if ((totSum - d) < 0 || ((totSum - d) & 1))
        return 0;
    int k = (totSum - d) / 2;

    // Recursion
    // return solveRecur(0, k, 0, n, arr);

    // Recursion + Memoization
    // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    // return solveRM(0, k, 0, n, arr, dp);

    // Tabulation
    return solveTab(k, n, arr);
}

int main()
{
    int target = 3;
    vector<int> nums = {1, 1, 1, 1, 1};

    cout << findTargetSumWays(nums, target) << endl;
    return 0;
}